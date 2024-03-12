#!/usr/bin/python3.8
import sys
import time
import serial
from datetime import datetime

CHUNK_SIZE = 1

######################################################################################
# Mattel HyperScan Firmware Patcher Utility - ppcasm (ppcasm@gmail.com)              #
#                                                                                    #
# This utility is for live testing firmware patches from recovery mode, as well      #
# as being used during the "Upload firmware through UART" stage of the CFW           #
# installer in the examples folder of this repo. It's also capable of producing      #
# a CFW.bin file for distributing firmware hacks for the Mattel HyperScan.           #
#                                                                                    #
# It is required that you have Python installed, and the usage is as                 # 
# described below:                                                                   #
#                                                                                    #
# patcher.py <MODE> <COM_PORT> <OFW.bin> <BINARY>                                    #
#                                                                                    #
# Please note that "OFW.bin" is NOT the entire HyperScan firmware dump that          #
# you see floating around, it is ONLY THE RAM PORTION copied out of that file.       #
#                                                                                    #
# <MODE>:                                                                            #
# UART - live testing/FlashCFW patch testing)                                        #
# FILE - Output file for CFW distribution                                            # 
#                                                                                    #
# <COM_PORT/FILE>                                                                    #
# If "UART" is selected for <MODE> then this will be the path to your serial         #
# COM/TTY port (ex: COM3 on Windows OR /dev/ttyUSB0 on Linux.                        #
#                                                                                    #
# If "FILE" is selected for <MODE> then this will be the filename that you want      #
# to save your custom firmware output as.                                            #
#                                                                                    #
# <BINARY>:                                                                          #
# This is a file of binary code that you wish to inject into the OFW.bin file        #
# to create custom modifications.                                                    #
#                                                                                    # 
# The way this works is that if you have FlashRecovery installed from the            #
# examples folder, you will then be able to overwrite the original firmware          #
# from UART if you turn on the HyperScan with the CD door opened. This utility       #
# will resolve addresses based on the offet of the RAM portion of the HyperScan      #
# original firmware. This means that you can set your addresses and options in       #
# this utility, start recovery mode, and then while this utility is uploading        #
# it will recognize HyperScan memory offsets from original firmware space, and       #
# then proceed to change the values at those offsets, including instruction          #
# patches, and injecting binaries. This works without permanently installing         #
# because it's simply just overwriting what's already been copied to RAM from        #
# the NOR flash, and this let's you test that CFW patches are working without        #
# permanently applying them.                                                         #
#                                                                                    #
# This same concept also applies to the FlashCFW app from the examples folder        # 
# in this repo, because it uploads in the same manner, and patches in the same       #
# manner, with the difference being that after the UART upload, the code is          #
# permanently flashed into the NOR flash of the HyperScan console.                   #
#                                                                                    #
# This utility also lets you output a CFW.bin file so that if you want to share      #
# your modifications to the original firmware, you can do so, and the end-user       #
# will just use the FlashCFW app on their end, along with the uart_send.py           #
# script during the "Upload firmware through UART" stage of the FlashCFW             #
# installer.                                                                         #
######################################################################################

######################################################################################
# You can use this to change the firmware revision string in the CFW so that you     #
# can keep track of changes you've released through a custom versioning system.      #
#                                                                                    #
# This string can be accessed from the HyperScan "Test Menu" but this also has the   #
# added benefit of being able to be used as a signature marker in your own code so   #
# that you can create compatibility profiles for custom firmware releases.           #
#                                                                                    #
# CHANGE_FW_REVISION - Obvious                                                       #
# FW_REV_STRING - The string you want to replace the OFW revision string with.       #
######################################################################################
CHANGE_FW_REVISION = True
FW_REV_STRING = "UMOD 0.1 NTSC"

######################################################################################
# There's some checksum related code at A000F740 that could possibly need to be      #
# patched when running some types of custom firmware, and for now we do that by      #
# patching it to return 0x0C and to not return 0x0D in this area. This goes to a     #
# switch case statement later on that signals failure (0xD means failure, 0xC means  #
# success)                                                                           #
#                                                                                    #
# For simplicity, I propose turning the insn "ldi r5, 0xD" to a "ldi r5, 0xC" for    #
# now because it only requires a 1-byte change (basically changing the insn at       # 
# 0xA000F740 from 0x84B8801A to 0x84B88018)                                          #
#                                                                                    #
# ENABLE_CHECKSUM_PATCH - Obvious                                                    #
# CHECKSUM_PATCH_ADDR - The actual RAM address of where you want to patch the        #
# "ldi r5, 0xD" insn                                                                 #
######################################################################################
ENABLE_CHECKSUM_PATCH = False
CHECKSUM_PATCH_ADDR = 0xA000F740

######################################################################################
# Sometimes it's beneficial to patch a J/JL insn at a specific address that          #
# will redirect execution to a binary that you inject into the original firmware     #
# using this tool. An example of this is that say you want to make it so that        #
# when you go to the HyperScan "test menu" you want to make it so that when you      #
# select "System Test" from that menu, instead of running "System Test" it will      #
# execute a binary that you have injected from this tool. Well, we know that there   #
# is a jump table that handles this, and the address resolves to 0xA0012360, so      #
# by making "JUMP_PATCH_ADDR = 0xA0012360" and supplying our binary along with the   #
# OFW.bin file, when we go to "System Test" it will then run our custom code         #
#                                                                                    #
# ENABLE_JUMP_PATCH - Obvious                                                        #
# LINK - Force a JL insn instead of simply a J to the supplied JUMP_PATCH_ADDR       #
# JUMP_PATCH_ADDR - This is the actual RAM address of where you want the J/JL placed #
######################################################################################
ENABLE_JUMP_PATCH = False
LINK = True
JUMP_PATCH_ADDR = 0xA00010A4 

######################################################################################
# Set this to the actual RAM address of where the supplied binary is to be ran from  #
# after it's injected into the OFW.bin                                               #
#                                                                                    #
# BIN_ADDR - The actual RAM address of where you want to inject the supplied binary  #
# file into the OFW.                                                                 #
######################################################################################
BIN_ADDR = 0xA00F5D00

def resolve_address(address):
    return int(address - 0xA00001FC)

CHECKSUM_PATCH_OFFSET = resolve_address(CHECKSUM_PATCH_ADDR)

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

    executable = open(sys.argv[3], 'rb').read()
    executable_size = len(executable);
    print(f"FileSize: {executable_size} bytes...");

    inject_bin = open(sys.argv[4], 'rb').read()
    inject_bin_size = len(inject_bin)
    inject_bin_end = int(BIN_OFFSET + inject_bin_size)

    new_exec = bytearray(executable)
    
    if(CHANGE_FW_REVISION):
        print("Changing FW revision to {0}".format(FW_REV_STRING))
        REV_STRING_OFFSET = resolve_address(0xA00383E4)
        for i in range(0, len(FW_REV_STRING)):
            new_exec[REV_STRING_OFFSET + i] = ord(FW_REV_STRING[i])

    if(ENABLE_JUMP_PATCH):
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
    if(ENABLE_CHECKSUM_PATCH):
        print("Patching OFW checksum")
        new_exec[CHECKSUM_PATCH_OFFSET + 0] = 0x18
        new_exec[CHECKSUM_PATCH_OFFSET + 1] = 0x80
        new_exec[CHECKSUM_PATCH_OFFSET + 2] = 0xB8
        new_exec[CHECKSUM_PATCH_OFFSET + 3] = 0x84

    for i in range(0, inject_bin_size):
        new_exec[BIN_OFFSET + i] = inject_bin[i]

    # Check mode, then handle accordingly
    if(sys.argv[1] == "UART"):
        with serial.Serial(sys.argv[2], baudrate=115200, parity='E', stopbits=1) as ser:
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

    elif(sys.argv[1] == "FILE"):
        with open(sys.argv[2], "wb") as bin_filez:
            bin_filez.write(new_exec)

        print("Custom Firmware saved as {0}".format(sys.argv[2]))

    else:
        print("Unknown MODE ({0}) selected".format(sys.argv[1]));

if __name__ == "__main__":

     if(len(sys.argv) != 5):
        print('Wrong usage: {0} <MODE> <COM_PORT/FILE> <OFW> <BINARY>'.format(sys.argv[0]))
        exit()

     main()
