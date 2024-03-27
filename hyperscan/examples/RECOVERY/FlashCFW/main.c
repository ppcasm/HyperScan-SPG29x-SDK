/*

This is part of the Mattel HyperScan SDK by ppcasm (ppcasm@gmail.com)

This example is to show how it's possible to write a custom firmware installer for the HyperScan. By default this
doesn't run as a normal HYPER.EXE app, and it's meant to be run from recovery mode, and uploaded through the UART
interface. Please run the HYPER.EXE from the FlashRecovery example project first before attemping to run this.

This requires that you have a UART serial cable installed as well. Instructions on how to install a 
UART cable are found in the documentation section of this repo.

*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/TV/TV.h"
#include "../../include/SPG290_Registers.h"
#include "../../include/SPG290_Constants.h"
#include "../../include/NorFlash/NorFlash.h"
#include "../../include/HS_Controller/HS_Controller.h"

#define UPLOAD_ADDRESS 0x80600000

// Macro for controlling the HyperScan LEDs
#define HS_LEDS(value) (*P_CSI_GPIO_SETUP = (0x1FFE0000+(value<<5)))

#define SECTOR_SIZE 0x1000

// Stupid Framebuffer
unsigned short *fb = (unsigned short *) 0xA0400000;

#define BIT(n)	(1 << n)

#define SW_UART_UART	BIT(24)

#define UART_BUSY	BIT(3)
#define UART_TRANSMIT_EMPTY	BIT(7)
#define UART_TRANSMIT_FULL	BIT(5)
#define UART_RECEIVE_EMPTY	BIT(4)
#define UART_RECEIVE_FULL	BIT(6)

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef volatile u32 vu32;

static void uart_enable_interface() {
	*P_UART_INTERFACE_SEL |= SW_UART_UART;
}

static void uart_wait_nonbusy() {
	u32 status = *P_UART_TXRX_STATUS;
	while (status & UART_BUSY || status & UART_TRANSMIT_FULL || !(status & UART_TRANSMIT_EMPTY)) {
		status = *P_UART_TXRX_STATUS;
	}
}

static void uart_write_byte(u32 c) {
	*P_UART_TXRX_DATA = c;
	uart_wait_nonbusy();
}

static void print_string(const char *str) {
	while (*str) {
		uart_write_byte(*str++);
	}
}

static u8 uart_read_byte() {
	while (*P_UART_TXRX_STATUS & UART_RECEIVE_EMPTY);
	return *P_UART_TXRX_DATA;
}

int main()
{	

	int nExitCode = 0;
	/************************************************************************/
	/*   TODO: add your code here                                           */
	/************************************************************************/

	int i = 0;
	
	/* Initialize NOR flash GPIO for R/W */
	NorFlash_Init();
	
	/* Initalize Mattel HyperScan controller interface */
	HS_Controller_Init();
	
	/*
	Set TV output up with RGB565 color scheme and make set all framebuffers
	to stupid framebuffer address, TV_Init will select the first framebuffer
	as default.
	*/
	TV_Init(RESOLUTION_640_480, COLOR_RGB565, 0xA0400000, 0xA0400000, 0xA0400000);

	TV_Print(fb, (((640/8)-44)/2), 2, "HyperScan Custom Firmware Installer - ppcasm");
	TV_Print(fb, (((640/8)-47)/2), 3, "Join the Discord: https://discord.gg/rHh2nW9sue");
	TV_Print(fb, (((640/8)-41)/2), 26, "NOTE: Screen might glitch, this is normal");
	TV_Print(fb, (((640/8)-24)/2), 28, "Please use with CAUTION!");
	
	TV_Print(fb, (((640/8)-40)/2), 6, "Press START to install custom firmware");
	
	volatile unsigned int *chk_addr_data;
		
	while(1){
		
		HS_Controller_Read();

		if(controller[hs_controller_1].input.start && controller[hs_controller_1].input.joystick_x != 0xFF && controller[hs_controller_1].input.joystick_y != 0xFF){

			while(!controller[hs_controller_1].input.g && controller[hs_controller_1].input.joystick_x != 0xFF && controller[hs_controller_1].input.joystick_y != 0xFF){
				HS_Controller_Read();
				TV_Print(fb, (((640/8)-44)/2), 6, "Now press GREEN to install custom firmware");

				if(controller[hs_controller_1].input.g){
					TV_Print(fb, (((640/8)-44)/2), 6, "    Installing custom firmware patches    ");
					TV_Print(fb, (((640/8)-6)/2), 9, "Status");
					if(*(volatile unsigned int *)0x9E000740 == 0){
						while(1){
						TV_Print(fb, (((640/8)-40)/2), 10, "You need to install flash recovery first");
						}
					}
					
					TV_Print(fb, (((640/8)-25)/2), 10, "  Send firmware over UART ");		

					// Enable UART
					uart_enable_interface();
					
					// Print "Ready! " over UART
					print_string("Ready! ");

					// Get and pack the size bytes of the binary about to be uploaded (comes from the python send script)
					u32 size = 0;
					size |= uart_read_byte() << 0;
					size |= uart_read_byte() << 8;
					size |= uart_read_byte() << 16;
					size |= uart_read_byte() << 24;

					// Print "...GO!" to let us know we did receive the 4 size bytes 
					print_string("...GO!\n");
					
					if((size-4) > 0xFEFFC){
						while(1){
							TV_Print(fb, (((640/8)-27)/2), 10, "FAILED! The file is too big");
							TV_Print(fb, (((640/8)-45)/2), 12, "HINT: Don't try to flash a full firmware file");
						}
					}
					
					TV_Print(fb, (((640/8)-25)/2), 10, "        Uploading...      ");				

					// Set the destination and ending address we intend to upload to in SDRAM
					u8 *dest = (u8 *)UPLOAD_ADDRESS;
					u8 *end = (u8 *)UPLOAD_ADDRESS + size;
		
					// Define the LEDs value, and a count that we will use later
					u8 leds = 0;
					u32 counts = 0;
		
					// Download the binary data over UART, and "roll" the LEDs by 
					// having a count that ticks the LEDs forward by 1 for every 500
					// bytes received over UART
					while (dest < end) {
						counts++;
						HS_LEDS(1<<leds);
						*dest++ = uart_read_byte();
						if(counts % 500 == 0) leds++;
						if(leds>=8) leds = 0;
					}
					
					HS_LEDS(0);
					
					TV_Print(fb, (((640/8)-16)/2), 10, "Erasing Firmware");

					unsigned int flash_addr_start = 0x9E000000;
					unsigned int sector_chk = 0;
					unsigned int *flash_patch = (unsigned int *)UPLOAD_ADDRESS;
						
					for(i=0;i<=0xFE;i++){
						flash_addr_start += 0x1000;

						TV_Print(fb, (((640/8)-25)/2), 10, "Clearing data @ ");
						TV_PrintHex(fb, 43, 10, flash_addr_start);
						
						for(sector_chk=0;sector_chk<=(SECTOR_SIZE/4);sector_chk+=4){
							while((*(volatile unsigned int *)(flash_addr_start + sector_chk)) != 0xFFFFFFFF){
									NorFlash_SectorErase(flash_addr_start);
							}
						}
					}
					
					TV_Print(fb, (((640/8)-25)/2), 10, " Writing data @ ");
					
					for(i=0;i<=(size-4)/4;i++){
						if((i % 0x1000) == 0){
							TV_PrintHex(fb, 43, 10, 0x9E001000 + (i*4));
						}

						chk_addr_data = (volatile unsigned int *)0x9E001000 + i;

						while(*chk_addr_data != flash_patch[i]){
							NorFlash_Write32(0x9E001000 + (i*4), flash_patch[i]);
							chk_addr_data = (volatile unsigned int *)0x9E001000 + i;
						}
					}

					while(1){
						TV_Print(fb, (((640/8)-34)/2), 14, "DONE, Please reboot the HyperScan!");
					}
				}
			}
		}
	}
		
	return nExitCode;
}
