#!/usr/bin/python3.8

import sys
import serial



def main():
    ser = serial.Serial("COM7", baudrate=115200, parity='E', stopbits=1)
    file_path = "test.bin" 
    
    i = 0

    with open(file_path, 'w') as file:
        try:
            while True:
                line = ser.readline().decode().strip()
                file.write(line + '\n')
                print(line)
                i = i+1
                if(i>=0x7fff):
                    file.close()
            
        except:
            pass

def hex_to_bytes(hex_string):
    byte_data = bytes.fromhex(hex_string.strip())
    return byte_data[::-1]

def main2():
    input_file_path = "test.bin"
    output_file_path = "outputn.bin"
    with open(input_file_path, 'r') as input_file:
        with open(output_file_path, 'wb') as output_file:
            for line in input_file:
                # Convert the hexadecimal string to bytes
                hex_data = line.strip()
                binary_data = hex_to_bytes(hex_data)
            
                # Write the binary data to the output file
                output_file.write(binary_data)    
if __name__ == "__main__":

     main2()
