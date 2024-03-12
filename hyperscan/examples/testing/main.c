/*

This is part of the Mattel HyperScan SDK by ppcasm (ppcasm@gmail.com)

This is a basic canvas to start your HyperScan project. Check around for documentation and example code.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/TV/TV.h"
#include "../../include/FatFS/ff.h"
#include "../../include/SPG290_Registers.h"
#include "../../include/SPG290_Constants.h"
#include "../../include/HS_Controller/HS_Controller.h"

#define DrvUSBH_Initial() ((int (*)(void))0xA001E5D4)()
#define DrvUSBH_LUNInitial(LUN) ((int(*)(int))0xA001E9E4)(LUN)
#define DrvUSBH_ReadSector(block, blocknum, inaddr, ukn1) ((int (*) (LBA_t, UINT, BYTE *, int))0xA001EEE8)(block, blocknum, inaddr, ukn1)
#define DrvUSBH_WriteSector(block, blocknum, outaddr, ukn1) ((int (*) (LBA_t, UINT, BYTE *, int))0xA001EFCC)(block, blocknum, outaddr, ukn1) 

int main(){
	
	HS_LEDS(0xFF);
	
	// Stupid framebuffer for now
	unsigned short *fb = (unsigned short *) 0xA0400000;

	int nExitCode = 0;
	
	/************************************************************************/
	/*   TODO: add your code here                                           */
	/************************************************************************/

	/* Initalize Mattel HyperScan controller interface */
	HS_Controller_Init();
	
	/*
	 Set TV output up with RGB565 color scheme and make set all framebuffers
	 to stupid framebuffer address, TV_Init will select the first framebuffer
	 as default.
	*/
	TV_Init(RESOLUTION_640_480, COLOR_RGB565, 0xA0400000, 0xA0400000, 0xA0400000);
	/*
	f_mount(&fs0, "0:", 1);
	
	fr = f_open(&fil, "loadusb.bin", FA_READ);

	int sizes = f_size(&fil);
		
	f_close(&fil);
	*/
	while(1){
		TV_PrintHex(fb, 35, 3, 0x41424344);
	}
		
	return nExitCode;
}
