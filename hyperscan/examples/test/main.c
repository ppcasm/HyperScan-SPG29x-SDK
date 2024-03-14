/*

This is part of the Mattel HyperScan SDK by ppcasm (ppcasm@gmail.com)

Just a testing space for personal use.
 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../../include/TV/TV.h"
#include "../../include/SPG290_Registers.h"
#include "../../include/SPG290_Constants.h"
#include "../../include/HS_Controller/HS_Controller.h"
#include "../../include/FatFS/ff.h"

struct HyperHomebrew {
	char name[12];
	char icon_file[12];
};

int main()
{
	// Stupid Framebuffer
	unsigned short *fb = (unsigned short *) 0xA0400000;

	char *header = "HyperScan USB Loader";

	struct HyperHomebrew hyperbrew[4];
	
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

	TV_Print(fb, (((640/8)-strlen(header))/2), 4, header);
/*	
	FATFS fs;
	FIL fp;
	
	f_mount(&fs, "", 1);
	
	f_open(&fp,"config.ini", FA_READ);
	f_close(&fp);	
*/
	while(1){
		TV_PrintHex(fb, 35, 8, *(volatile unsigned int *)0x881C006C);
	}
	
	return nExitCode;
}
