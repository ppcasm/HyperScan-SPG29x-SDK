/*

This is part of the Mattel HyperScan SDK by ppcasm (ppcasm@gmail.com)

PLEASE READ: This is NOT a "normal" HyperScan application. It is made to be ran as part of a "loader chain" from a custom firmware.

This is an example of how you could load files from USB in early boot. PLEASE NOTE that this example has an entry address of 0xA00F5D00, and
does NOT have the normal structure that you would find in a Hyper.Exe file, and so it will not run as a HyperScan app. The reason is because 
this is made to be flashed to NOR flash, then copied to ram from the NOR flash on boot, and then ran. The reason this example is included is to showcase
part of the collection of tools that make up the "FlashCFW" suite. This would be patched/injected into the original firmware with the patcher.py 
script, either to be loaded live as a testing firmware, or to be flashed permanently into flash with the "FlashCFW" app. Please see patcher.py 
documentation to better understand what this is, and how to use it. 

DO NOT TRY TO RUN THIS AS A HYPER.EXE APP; IT WILL NOT WORK...
 
*/

#include <stdio.h>
#include <string.h>

#include "./FS/ff.h"
#include "./FS/diskio.h"

#include "../../include/SPG290_Registers.h"
#include "../../include/SPG290_Constants.h"

#define USB_LOAD() ((void (*)(void))0xA0091000)()

int main()
{
	HS_LEDS(0xFF);
	
	BYTE *ldrptr = (BYTE *)0xA00901FC;
	
	FATFS fs0;
	FIL fil;
	FRESULT fr;
	UINT br;
	
	f_mount(&fs0, "0:", 1);
	
	fr = f_open(&fil, "loadusb.bin", FA_READ);

	int sizes = f_size(&fil);
	
	fr = f_read(&fil, ldrptr, sizes, &br);
		
	f_close(&fil);

	HS_LEDS(0x00);
	
	USB_LOAD();	

return 0;		
}

