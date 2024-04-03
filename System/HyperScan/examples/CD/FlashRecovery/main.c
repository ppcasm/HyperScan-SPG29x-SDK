/*

This is part of the Mattel HyperScan SDK by ppcasm (ppcasm@gmail.com)

This example is to give an idea of how to write to NOR flash, and also give a way to recover from bad firmware flashes.
The way this works is that the SPG290 starts executing code from 0x9E000000 which is mapped to NOR flash by default on
the HyperScan. The NOR bootloader in NOR flash does some initializations of SDRAM and a few other parameters before ultimately
loading the HyperScan OS starting from 0x9E001000 in NOR flash to HyperScan RAM starting at address 0x800001FC (uncached)
and then ultimately resuming execution at 0xA0001000 (cached) which is the entry point for the HyperScan OS. The reason for this
is because 0xA00001FC is the start of the HyperScan OS exception vector, and 0xA0001000 is the HyperScan OS entry point.

What we do here is make some patches prior to 0x9E001000 in the NOR flash to check if the CD door is opened or not, and if it is NOT
opened (read: closed) then we resume execution as normal at 0xA0001000 since the OS is already technically loaded at the time we make our patches.

If the CD door IS opened, the LEDs will all turn on, and then it will run a specialized UART loader (see send_uart.py in the tools directory
of this repo for references on how to upload) that takes in a binary file that loads to the exact addresses that the HyperScan OS is expected to be 
loaded from, and during the upload the LEDs will "roll" to let you know the upload is still in progress and you should see an upload percentage status
on the PC side of things.

This project is actually built from 2 other separate projects that are nested in the FlashRescue project, one is called "RescuePatch" and one is a 
python script named "bintoheader.py" and these 3 work as follows.

FlashRescue:
This part is made to create the HYPER.EXE to actually install the RescuePatch onto the flash

RescuePatch:
This is the actual recovery mode sourcecode that checks the CD door status and either goes to the already loaded OS, or loads a new one from UART. This
ultimately gets embedded into the FlashRescue binary

bintoheader.py:
This modifies the flash_patch.h file of the FlashRescue project, effectively embedding the RescuePatch binary so that we don't have to link in any binaries,
and this builds the full instructions from the start of NOR flash at 0x9E000000 to our custom instructions which get patched in after 0x9E000740 in NOR flash.

It works like this:
When you compile RescuePatch in the S+Core IDE, this will create a HYPER.EXE that is the binary for the recovery mode logic. Then, when you build the
FlashRescue project, it's set up to run a pre-link python script, which in this case is the bintoheader.py script which writes to the flash_patch.h header file of
the FlashRescue project and embeds all of the necessary instructions starting from 0x9E000000 and ending at 0x9E00073C and that is patched to do the usual booting
and then a patch is made to resume execution at 0x9E000740 right before the bootloader goes to the HyperScan OS entry point at 0xA0001000, which is where our 
recovery mode code execution begins, starting from 0x9E000740.

This is very specifically structured so that should something go wrong, there is still a good chance you can still get the HyperScan to boot, for example if
you're running the FlashRescue binary and it happens to stop, it's structured in such a way that the first instructions added are the CD door check, so as long
as that remains intact then that would allow a normal boot with the CD door closed. Once recovery mode is installed you should NEVER touch anything in flash 
before 0x9E001000 so as to ensure that you retain the ability to at least load recovery mode, in which case you can upload a firmware flasher (see FlashCFW 
for an example)  
 
*/

#include <stdio.h>
#include <stdlib.h>
#include "./flash_patch.h"
#include "../../../../../SPG290/scorelibs/include/TV/TV.h"
#include "../../../../../SPG290/scorelibs/include/SPG290_Registers.h"
#include "../../../../../SPG290/scorelibs/include/SPG290_Constants.h"
#include "../../../../../SPG290/scorelibs/include/NorFlash/NorFlash.h"
#include "../../../hslibs/include/HS_Controller/HS_Controller.h"

// Stupid Framebuffer
unsigned short *fb = (unsigned short *) 0xA0400000;

int main()
{	

	int nExitCode = 0;
	/************************************************************************/
	/*   TODO: add your code here                                           */
	/************************************************************************/

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

	TV_Print(fb, (((640/8)-46)/2), 2, "HyperScan Firmware Recovery Installer - ppcasm");
	TV_Print(fb, (((640/8)-47)/2), 3, "Join the Discord: https://discord.gg/rHh2nW9sue");
	TV_Print(fb, (((640/8)-24)/2), 28, "Please use with CAUTION!");
	
	TV_Print(fb, (((640/8)-40)/2), 6, "Press START to install recovery firmware");
	
	int i = 0;
	
	volatile unsigned int *chk_addr_data;

	while(1){
		
		HS_Controller_Read();
		if(controller[hs_controller_1].input.start && controller[hs_controller_1].input.joystick_x != 0xFF && controller[hs_controller_1].input.joystick_y != 0xFF){
			while(!controller[hs_controller_1].input.g && controller[hs_controller_1].input.joystick_x != 0xFF && controller[hs_controller_1].input.joystick_y != 0xFF){
				HS_Controller_Read();
				TV_Print(fb, (((640/8)-44)/2), 6, "Now press GREEN to install recovery firmware");
				if(controller[hs_controller_1].input.g){
					TV_Print(fb, (((640/8)-44)/2), 6, "    Installing firmware recovery patches    ");
					TV_Print(fb, (((640/8)-6)/2), 9, "Status");
					TV_Print(fb, (((640/8)-19)/2), 10, "Erasing boot sector");

					// No this many isn't really needed :p 
					NorFlash_SectorErase(0x9E000000);
					NorFlash_SectorErase(0x9E000000);
					NorFlash_SectorErase(0x9E000000);
					NorFlash_SectorErase(0x9E000000);

					for(i=0;i<=(sizeof(flash_patch)/4);i++){
						TV_Print(fb, (((640/8)-25)/2), 10, "Writing data @ ");
						TV_PrintHex(fb, 42, 10, 0x9E000000+(i*4));
						chk_addr_data = (volatile unsigned int *)0x9E000000+i;
						while(*chk_addr_data != flash_patch[i]){
							NorFlash_Write32(0x9E000000+(i*4), flash_patch[i]);
							chk_addr_data = (volatile unsigned int *)0x9E000000+i;
						}
					}
					TV_Print(fb, (((640/8)-34)/2), 14, "DONE, Please reboot the HyperScan!");
				}
			}
		}
	}
		
	return nExitCode;
}
