#!/usr/bin/python3.8
import sys
import time
import serial
from datetime import datetime

# Checksum func stuff at A000F740 needs to be patched
# and we do that by having it return 0x0C and never 0x0D (this goes to
# a switch case statement later on that signals failure)
#
# I propose turning the insn "ldi r5, 0xD" to a "ldi r5, 0xC"
# basically from 0x84B8801A to 0x84B88018

# Set this to what addr to insert the j/jl insn
JUMP_PATCH_ADDR = 0xA0000800

# Set this to the address of where the embedded binary is to be injected
BIN_ADDR = 0xA00F5D00

# Set whether the jump to BIN_ADDR is j or jl
LINK = False

CHUNK_SIZE = 1

def resolve_address(address):
    return int(address - 0xA00001FC)

CHECKSUM_PATCH_OFFSET = resolve_address(0xA000F740)
BIN_OFFSET = resolve_address(BIN_ADDR)
JUMP_PATCH_OFFSET = resolve_address(JUMP_PATCH_ADDR)

def asm_j_insn(address, link):

	assembled_insn_l = (address & 0x7FFF)

	# set p-bit
	assembled_insn_l |= (1<<15)

	assembled_insn_h = ((address << 1) & 0x1FFF0000)
	
	assembled_insn_h |= (1<<31)
	assembled_insn_h |= (1<<27)

	assembled_j_insn = (assembled_insn_h & 0xFFFF0000) + (assembled_insn_l & 0xFFFF)

	assembled_j_insn = assembled_j_insn + link

	return assembled_j_insn

def show_progress(current, total):
    progress = (current / total) * 100
    sys.stdout.write('\rUploading: {0}%'.format(int(progress)+1))
    sys.stdout.flush()

def main():

    executable = open(sys.argv[2], 'rb').read()
    executable_size = len(executable);
    print(f"Sending {executable_size} bytes...");

    inject_bin = open(sys.argv[3], 'rb').read()
    inject_bin_size = len(inject_bin)
    inject_bin_end = int(BIN_OFFSET + inject_bin_size)

    new_exec = bytearray(executable)
    
    JUMP_INSN = asm_j_insn(BIN_ADDR, LINK)
    
    if((JUMP_INSN & 0x1)):
        print("""Patching "jl {0}" @ {1}""".format(hex(BIN_ADDR), hex(JUMP_PATCH_ADDR)))
    else:
        print("""Patching "j {0}" @ {1}""".format(hex(BIN_ADDR), hex(JUMP_PATCH_ADDR)))

    new_exec[JUMP_PATCH_OFFSET + 0] = (JUMP_INSN & 0xFF) 
    new_exec[JUMP_PATCH_OFFSET + 1] = ((JUMP_INSN & 0xFF00) >> 8) & 0xFF 
    new_exec[JUMP_PATCH_OFFSET + 2] = ((JUMP_INSN & 0xFF0000) >> 16) & 0xFF
    new_exec[JUMP_PATCH_OFFSET + 3] = ((JUMP_INSN & 0xFF000000) >> 24) & 0xFF

    # Checksum fix 0xA000F740 = 0x84B88018
    new_exec[CHECKSUM_PATCH_OFFSET + 0] = 0x18
    new_exec[CHECKSUM_PATCH_OFFSET + 1] = 0x80
    new_exec[CHECKSUM_PATCH_OFFSET + 2] = 0xB8
    new_exec[CHECKSUM_PATCH_OFFSET + 3] = 0x84

    for i in range(0, inject_bin_size):
        new_exec[BIN_OFFSET + i] = inject_bin[i]

    with serial.Serial(sys.argv[1], baudrate=115200, parity='E', stopbits=1) as ser:
        ser.write(executable_size.to_bytes(4, byteorder='little'))
        ser.flush()
        ser.read(1)
        ser.flush()

        start_time = datetime.now()

        for i in range(0, len(executable), CHUNK_SIZE):
            ser.write(new_exec[i:i + CHUNK_SIZE])
            ser.flush()

            show_progress(i, executable_size)

        print('\nTime elapsed: {0} (hh:mm:ss)'.format(str(datetime.now() - start_time)).split('.')[0])

if __name__ == "__main__":

     if(len(sys.argv) != 4):
        print('Wrong usage: {0} <COM_PORT> <OFW> <BINARY>'.format(sys.argv[0]))
        exit()

     main()
