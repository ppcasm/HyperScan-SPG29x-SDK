/*

This is part of the Mattel HyperScan SDK by ppcasm (ppcasm@gmail.com)

Just a testing space for personal use.
 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Resource.h"
#include "../../../../../SPG290/scorelibs/include/SPG290_Registers.h"
#include "../../../../../SPG290/scorelibs/include/SPG290_Constants.h"

#define LOAD_ADDRESS 0xA0C001FC
#define ENTRY_ADDRESS 0xA0C01000

void Enable_Interrupts(){

	asm("li r4, 0x1");
	asm("mtcr r4, cr0");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
}

void Disable_Interrupts(){
	
	asm("li r4, 0x0");
	asm("mtcr r4, cr0");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
}

int main(){

	int i = 0;
	
	int nExitCode = 0;
	
	Enable_Interrupts();

    unsigned char *ldrptr = (unsigned char *)LOAD_ADDRESS;
	void (*entry_start)(void) = (void *)ENTRY_ADDRESS;

	unsigned char *usbldr = (unsigned char *)RES_CDUSBLDR_BIN;
	unsigned char *usbldr_end = (unsigned char *)RES_CDUSBLDR_BIN_END;
	
	int file_size = usbldr_end - usbldr;
	
	for(i=0;i<file_size;i++){
		ldrptr[i] = usbldr[i];
	}
	
	while(1){
		entry_start();
	}
	
	return nExitCode;
}

