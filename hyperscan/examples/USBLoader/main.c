/*

This is part of the Mattel HyperScan SDK by ppcasm (ppcasm@gmail.com)

Just a testing space for personal use.
 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "MP3Drv/MP3.h"
#include "MP3Drv/MP3Drv.h"

#include "../../include/TV/TV.h"
#include "../../include/SPG290_Registers.h"
#include "../../include/SPG290_Constants.h"
#include "../../include/HS_Controller/HS_Controller.h"
#include "../../include/FatFS/ff.h"

void DAC_Init(){
	
	// Patch the excvec 
	unsigned int *excvec_old = (unsigned int *)0xA00902FC;	
	unsigned int *excvec_new = (unsigned int *)0xA00002FC;
	
	asm("li r4, 0x0");
	asm("mtcr r4, cr0");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	
	*excvec_new = *excvec_old;	
	
	asm("li r4, 0x1");
	asm("mtcr r4, cr0");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	
	// Then intialize the DAC interrupts
	*P_INT_MASK_CTRL1 = ~0x00000001;
	*P_DAC_CLK_CONF = 0x00000003;
	*P_DAC_MODE_CTRL1 = ~0x00000003;
}

int main(){
	
	DAC_Init();

	FATFS fs0;
	FIL fil;
	FRESULT fr;
	UINT br;
	
	int nExitCode = 0;
	
	int file_size = 0;
	
	// Stupid Framebuffer
	unsigned short *fb = (unsigned short *) 0xA0400000;
	
	char *header = "HyperScan USB Loader";

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

	// Mount the USB drive with FatFS support
	f_mount(&fs0, "0:", 1);
	
	// Open background music MP3
	fr = f_open(&fil, "bg.mp3", FA_READ);

	// Get size of background music MP3
	file_size = f_size(&fil);

	// Create a buffer for storing the background music MP3
	unsigned char *mp3ptr = (unsigned char *)malloc(file_size+4);
	
	// Read the background music MP3 into buffer
	fr = f_read(&fil, mp3ptr, file_size, &br);
	
	// Close file
	f_close(&fil);
	
	// Unmount
    f_mount(NULL, "0:", 0);
    
    // Address points to mp3 buffer
	Address = (unsigned short*)mp3ptr; 

	// Play mp3
	Play_MP3((unsigned int)Address,file_size);
	
	// Repeat
	Repeat_ON_MP3();
	
	while(1){
		// Handle the MP3 stream
		MP3_Service_Loop();
	}
	
	return nExitCode;
}
