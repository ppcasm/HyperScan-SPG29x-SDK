#!/usr/bin/python3.8

import sys
import time
import serial
from datetime import datetime

CHUNK_SIZE = 8

def resolve_address(address):
    return address - 0xA00001FC

CHECKSUM_PATCH_OFFSET = resolve_address(0xa000f740)
BIN_OFFSET = resolve_address(0xa0000500)
PATCH_OFFSET = resolve_address(0xA0012370)

# Checksum func stuff at a000f740 needs to be patched
# and we do that by having it return 0x0C and never 0x0D (this goes to
# a switch case statement later on that signals failure)
#
# I propose turning the insn "ldi r5, 0xD" to a "ldi r5, 0xC"
# basically from 0x84b8801a to 0x84b88018

def show_progress(current, total):
    progress = (current / total) * 100
    sys.stdout.write('\rUploading: {0}%'.format(int(progress)+1))
    sys.stdout.flush()

def main():

    executable = open(sys.argv[2], 'rb').read()
    executable_size = len(executable);
    print(f"Sending {executable_size} bytes...");

    patch = open(sys.argv[3], 'rb').read()
    patch_size = len(patch)
    patch_end = int(BIN_OFFSET + patch_size)

    new_exec = bytearray(executable)
    # 0x88129001 -> jl 0xA0091000
    new_exec[PATCH_OFFSET + 0] = 0x01
    new_exec[PATCH_OFFSET + 1] = 0x90
    new_exec[PATCH_OFFSET + 2] = 0x12
    new_exec[PATCH_OFFSET + 3] = 0x88

    # 0x8801F6FD -> jl (Load from CD)
    # proper checksum fix = 0x84b88018
    new_exec[CHECKSUM_PATCH_OFFSET + 0] = 0x18
    new_exec[CHECKSUM_PATCH_OFFSET + 1] = 0x80
    new_exec[CHECKSUM_PATCH_OFFSET + 2] = 0xb8
    new_exec[CHECKSUM_PATCH_OFFSET + 3] = 0x84

    for i in range(0, patch_size):
        new_exec[BIN_OFFSET + i] = patch[i]

    with serial.Serial(sys.argv[1], baudrate=115200, parity='E', stopbits=1) as ser:
        ser.write(executable_size.to_bytes(4, byteorder='little'))
        ser.flush()
        ser.read(1)
        ser.flush()

        start_time = datetime.now()

        for i in range(0, len(executable), CHUNK_SIZE):
            ser.write(executable[i:i + CHUNK_SIZE])
            ser.flush()
            ser.flush()

            show_progress(i, executable_size)

        print('\nTime elapsed: {0} (hh:mm:ss)'.format(str(datetime.now() - start_time)).split('.')[0])

if __name__ == "__main__":
     if(len(sys.argv) != 4):
        print('Wrong usage: {0} <COM_PORT> <OFW> <BINARY>'.format(sys.argv[0]))
        exit()

     main()
