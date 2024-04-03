/*

This is part of the Mattel HyperScan SDK by ppcasm (ppcasm@gmail.com)

Just a testing space for personal use.
 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../../hslibs/include/FatFS/ff.h"
#include "../../../../../../SPG290/scorelibs/include/TV/TV.h"
#include "../../../../../../SPG290/scorelibs/include/SPG290_Registers.h"
#include "../../../../../../SPG290/scorelibs/include/SPG290_Constants.h"
#include "../../../../hslibs/include/HS_Controller/HS_Controller.h"

#define FRAMEBUFFER_ADDRESS 0xA0400000
#define FRAMEBUFFER_WIDTH   640
#define FRAMEBUFFER_HEIGHT  480

#define LOAD_ADDRESS 0xA00901FC
#define ENTRY_ADDRESS 0xA0091000

void draw_pixel(unsigned short* framebuffer, int x, int y, unsigned short color) {
    if (x >= 0 && x < FRAMEBUFFER_WIDTH && y >= 0 && y < FRAMEBUFFER_HEIGHT) {
        framebuffer[y * FRAMEBUFFER_WIDTH + x] = color;
    }
}

void box(unsigned short* framebuffer, int x, int y, int width, int height, int radius, unsigned short color) {

	int i = 0;
	int dx = 0;
	int dy = 0;
    int x0 = x;
    int y0 = y;
    int x1 = x + width - 1;
    int y1 = y + height - 1;

    // Draw top and bottom lines
    for (i = x0 + radius; i <= x1 - radius; i++) {
        draw_pixel(framebuffer, i, y0, color);
        draw_pixel(framebuffer, i, y1, color);
    }

    // Draw left and right lines
    for (i = y0 + radius; i <= y1 - radius; i++) {
        draw_pixel(framebuffer, x0, i, color);
        draw_pixel(framebuffer, x1, i, color);
    }

    // Draw rounded corners
    for (dy = -radius; dy <= radius; dy++) {
        for (dx = -radius; dx <= radius; dx++) {
            if (dx*dx + dy*dy <= radius*radius) {
                draw_pixel(framebuffer, x0 + radius + dx, y0 + radius + dy, color);
                draw_pixel(framebuffer, x1 - radius + dx, y0 + radius + dy, color);
                draw_pixel(framebuffer, x0 + radius + dx, y1 - radius + dy, color);
                draw_pixel(framebuffer, x1 - radius + dx, y1 - radius + dy, color);
            }
        }
    }
}

void Menu_Border(unsigned short* framebuffer, int x, int y, int width, int height, int radius, int thickness, unsigned short color) {
	int t = 0;
    for (t = 0; t < thickness; t++) {
        box(framebuffer, x + t, y + t, width - t * 2, height - t * 2, radius, color);
    }
}

int Get_Dir_List_Size(){
	
	int dir_count = 0;
	
	FATFS fs0; // FatFS mountpoint
    FRESULT res; // FatFs result variable
    DIR dir; // Directory object
    FILINFO fno; // File information object

    // Mount the file system
    res = f_mount(&fs0, "", 1);
    
    if (res != FR_OK) {
        printf("Failed to mount the file system. Error code: %d\n", res);
        while(1);
    }

    // Open the root directory
    res = f_opendir(&dir, "/apps");
    if (res != FR_OK) {
        printf("Failed to open the root directory. Error code: %d\n", res);
        while(1);
    }

    for (;;) {
    	// Read a directory item
        res = f_readdir(&dir, &fno);

		// Break on error or end of directory
        if (res != FR_OK || fno.fname[0] == 0) break;

		// Check if it's a directory
        if (fno.fattrib & AM_DIR) {
			dir_count++;
        }
    }

    // Close the directory
    f_closedir(&dir);

    // Unmount the file system
    f_mount(NULL, "", 0);

    return dir_count;
}

int Load_Directory_List(char **dir_buf){
	
	int dir_count = 0;
	
	FATFS fs0; // FatFS mountpoint
    FRESULT res; // FatFs result variable
    DIR dir; // Directory object
    FILINFO fno; // File information object

    // Mount the file system
    res = f_mount(&fs0, "", 1);
    
    if (res != FR_OK) {
        printf("Failed to mount the file system. Error code: %d\n", res);
        while(1);
    }

    // Open the root directory
    res = f_opendir(&dir, "/apps");
    if (res != FR_OK) {
        printf("Failed to open the root directory. Error code: %d\n", res);
        while(1);
    }

    for (;;) {
    	// Read a directory item
        res = f_readdir(&dir, &fno);

		// Break on error or end of directory
        if (res != FR_OK || fno.fname[0] == 0) break;

		// Check if it's a directory
        if (fno.fattrib & AM_DIR) {
			dir_buf[dir_count] = (char *)malloc(strlen(fno.fname) + 1);
			sprintf(dir_buf[dir_count], "%s", fno.fname);
			dir_count++;
        }
    }

    // Close the directory
    f_closedir(&dir);

    // Unmount the file system
    f_mount(NULL, "", 0);

    return 0;
}

static int Show_Selection(char **dir_buf, int dir_count, int index, int selection){
	int i = 0;

	if(dir_count >= 16) dir_count = 16;
	
	if(selection < 0) selection = 0;
	if(selection > 16) selection = 16;
	if(selection > dir_count - 1) selection = dir_count - 1;

	for(i=index;i<dir_count-index;i++){
		
		if(i == selection){
			TV_Print((unsigned short *)FRAMEBUFFER_ADDRESS, 34, 8+i, "-->");
			TV_PrintColor((unsigned short *)FRAMEBUFFER_ADDRESS, 37, 8+i, dir_buf[i], 0x7E0);
		}
		else{
			TV_Print((unsigned short *)FRAMEBUFFER_ADDRESS, 34, 8+i, "   ");
			TV_Print((unsigned short *)FRAMEBUFFER_ADDRESS, 37, 8+i, dir_buf[i]);
		}
	}
	
	return selection;
}

void execute_binary(char *dir_buf){

	int file_size = 0;
	
	unsigned int *ldrptr = (unsigned int *)LOAD_ADDRESS;
	void (*entry_start)(void) = (void *)ENTRY_ADDRESS;
	
	FATFS fs0; // FatFS mountpoint
	FIL fil;
    FRESULT res; // FatFs result variable
	UINT br;
	
    // Mount the file system
    res = f_mount(&fs0, "", 1);
    
    if (res != FR_OK) {
        printf("Failed to mount the file system. Error code: %d\n", res);
        while(1);
    }

    // Open the file
	char *filepath = (char *)malloc(strlen("/apps/")+strlen(dir_buf)+strlen("hyper.exe"));
	sprintf(filepath, "/apps/%s/hyper.exe", dir_buf);
	
    res = f_open(&fil, filepath, FA_READ);

	file_size = f_size(&fil);
	
	res = f_read(&fil, ldrptr, file_size, &br);

    // Close the directory
    f_close(&fil);

    // Unmount the file system
    f_mount(NULL, "", 0);
	
	entry_start();
}

void DAC_Init(){

	asm("li r4, 0x0");
	asm("mtcr r4, cr0");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");

	//volatile unsigned int *cd_stuff = (volatile unsigned int *)0x8820004C;
	//*cd_stuff = 0;
	
	//volatile unsigned int *cd_clk_conf = (volatile unsigned int *)0x88210044;
	//*cd_clk_conf = 0;	
	
	asm("li r4, 0x1");
	asm("mtcr r4, cr0");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	
}
int main(){

	DAC_Init();
	
	// Stupid Framebuffer
	unsigned short *fb = (unsigned short *)FRAMEBUFFER_ADDRESS;
	
	int dir_count = 0;
	int nExitCode = 0;
	int selection = 0;
	
	char *loading = "- NOW LOADING -";
	char *header1 = "--- HyperScan USB Loader (CD Version) ---";
	char *header2 = "--- ppcasm (ppcasm@gmail.com) ---";
	char *header3 = "Join the Discord: https://discord.gg/rHh2nW9sue";

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
	TV_Init(RESOLUTION_640_480, COLOR_RGB565, FRAMEBUFFER_ADDRESS, FRAMEBUFFER_ADDRESS, FRAMEBUFFER_ADDRESS);

	TV_Print(fb, (((640/8)-strlen(header1))/2), 2, header1);
	TV_Print(fb, (((640/8)-strlen(header2))/2), 3, header2);
	TV_Print(fb, (((640/8)-strlen(header3))/2), 4, header3);

    Menu_Border(fb, (FRAMEBUFFER_WIDTH - 250) / 2, 20 + (FRAMEBUFFER_HEIGHT - 320) / 2, 250, 320, 1, 6, 0xFFFF); 

	dir_count = Get_Dir_List_Size();

	char *dir_buf[dir_count];
	
	Load_Directory_List(dir_buf);
	
	Show_Selection(dir_buf, dir_count, 0, selection);

	while(1){
		
		// If right trigger is pressed, move menu select down
		HS_Controller_Read();
		if(controller[hs_controller_1].input.rt){
			selection++;
			selection = Show_Selection(dir_buf, dir_count, 0, selection);
		}
		
		// If left trigger is pressed, move menu select up
		HS_Controller_Read();
		if(controller[hs_controller_1].input.lt){
			selection--;
			selection = Show_Selection(dir_buf, dir_count, 0, selection);
		}
		
		// If start is pressed, load and execute Hyper.Exe
		HS_Controller_Read();
		if(controller[hs_controller_1].input.start){
			TV_Print((unsigned short *)FRAMEBUFFER_ADDRESS, 20, 28, "                    ");
			TV_Print((unsigned short *)FRAMEBUFFER_ADDRESS, 40-(strlen(loading)/2), 27, loading);
			TV_Print((unsigned short *)FRAMEBUFFER_ADDRESS, 40-(strlen(dir_buf[selection])/2), 28, dir_buf[selection]);
			execute_binary(dir_buf[selection]);
		}		
	}
	
	return nExitCode;
}

