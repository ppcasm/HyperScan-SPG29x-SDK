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
#include <stdlib.h>

#include "./FS/ff.h"
#include "./FS/diskio.h"

#include "../../include/SPG290_Registers.h"
#include "../../include/SPG290_Constants.h"

#define MAX_LINE_LENGTH 64
#define MAX_KEY_LENGTH 24
#define MAX_VALUE_LENGTH 24
#define MAX_ENTRIES 4

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} ConfigEntry;

// This will parse some values from a config file in a "KEY=VALUE" format
int parseConfigFile(const char *filename, ConfigEntry *entries, int *num_entries) {
    FIL file;
    FRESULT res;
    char line[MAX_LINE_LENGTH];
    int count = 0;

    res = f_open(&file, filename, FA_READ);

    // Read lines from the file
    while (f_gets(line, sizeof(line), &file)) {
        // Ignore lines starting with '#' (comments) or empty lines
        if (line[0] == '#' || line[0] == '\n')
            continue;

        // Parse the line into key and value
        char *equal_sign = strchr(line, '=');
        if (equal_sign != NULL) {
        	// Replace '=' with null terminator to separate key and value
            *equal_sign = '\0'; 
            char *key = line;
            char *value = equal_sign + 1;
            
            // Remove leading/trailing spaces from key and value
            while (*key == ' ') key++;
            char *end = value + strlen(value) - 1;
            while (*end == ' ' || *end == '\n' || *end == '\r') *end-- = '\0';
            
            // Copy key and value into the new entry
            if (strlen(key) < MAX_KEY_LENGTH && strlen(value) < MAX_VALUE_LENGTH) {
                strncpy(entries[count].key, key, MAX_KEY_LENGTH - 1);
                strncpy(entries[count].value, value, MAX_VALUE_LENGTH - 1);
                count++;
                
                // Break if maximum number of entries reached
                if (count >= MAX_ENTRIES) break; 
            }
        }
    }

    *num_entries = count;
    
    f_close(&file);
    
    return 1;
}

int main()
{
	HS_LEDS(0xFF);
	
	// Set up some defaults, just in case there's no config file
	// we will attempt to load "usbload.bin" from the USB drive to the
	// normal Hyper.Exe address space
	BYTE *ldrptr = (BYTE *)0xA00901FC;

	void (*bin_start)(void) = (void *)0xA0091000;
	
	char *file_name[12];
	file_name[0] = "usbload.bin";
	
	FATFS fs0;
	FIL fil;
	FRESULT fr;
	UINT br;
	ConfigEntry entries[MAX_ENTRIES];
	int num_entries = 0;
	int file_size = 0;
	int i = 0;
	
	// Mount the USB drive with FatFS support
	f_mount(&fs0, "0:", 1);
	
	// Read config file so that we can set parameters for loading a binary from the USB drive
	if(parseConfigFile("usbload.ini", entries, &num_entries)){
		for(i=0;i<num_entries;++i){
			if(!strcmp(entries[i].key, "LOAD_ADDR")){
				ldrptr = (BYTE *)strtoul(entries[i].value, NULL, 16);
			}
			if(!strcmp(entries[i].key, "START_ADDR")){
				bin_start = (void *)strtoul(entries[i].value, NULL, 16);
			}
			if(!strcmp(entries[i].key, "LOAD_FILE")){
				if(strlen(entries[i].value) > sizeof(file_name)){
					file_name[0] = "usbload.bin";
				}
				else{
					*file_name = (char *)entries[i].value;
				}
			}
		}	
	}
	
	// Open the binary on the root of the USB drive by either the default name of "usbload.bin" if no
	// config.ini exists, or by the "LOAD_FILE" key=value if config.ini does exist
	fr = f_open(&fil, file_name[0], FA_READ);

	file_size = f_size(&fil);
	
	// Read binary file into either the default address space, or the one set up in the config.ini file
	// on the root of the USB drive
	fr = f_read(&fil, ldrptr, file_size, &br);
		
	f_close(&fil);
	
	// Unmount
    f_mount(NULL, "0:", 0);

	HS_LEDS(0x00);
	
	bin_start();	

return 0;		
}

