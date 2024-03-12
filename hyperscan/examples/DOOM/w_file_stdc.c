//
// Copyright(C) 1993-1996 Id Software, Inc.
// Copyright(C) 2005-2014 Simon Howard
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// DESCRIPTION:
//	WAD I/O functions.
//

#include <stdio.h>
#include <stdlib.h>

#include "m_misc.h"
#include "w_file.h"
#include "z_zone.h"

#include "../../include/FatFS/ff.h"

/*
FATFS fs;

typedef struct {
    FIL file;
} FatFileStream;

FatFileStream* fatfs_fopen(const char* filename, const char* mode) {
	FRESULT res = f_mount(&fs, "0:", 1);
    if (res != FR_OK) {
        printf("Error mounting filesystem: %d\n", res);
        return 1;
    }

	if(res == FR_OK){
		printf("Opening %s\n", filename);
	}
	    
    FatFileStream* stream = malloc(sizeof(FatFileStream));
    if (stream == NULL) {
        return NULL;
    }

    res = f_open(&(stream->file), filename, FA_READ);
    if (res != FR_OK) {
        free(stream);
        return NULL;
    }

    return stream;
}

size_t fatfs_fread(void *ptr, size_t size, size_t nmemb, FatFileStream *stream) {
    UINT bytesRead;
    FRESULT res = f_read(&(stream->file), ptr, size * nmemb, &bytesRead);
    if (res != FR_OK) {
        return 0;
    }
    return bytesRead / size;
}

int fatfs_fclose(FatFileStream *stream) {
    f_close(&(stream->file));
    free(stream);
    FRESULT res = f_mount(NULL, "0:", 0);
    if (res != FR_OK) {
        printf("Error mounting filesystem: %d\n", res);
        return 1;
    }
    return 0;
}

int fatfs_fseek(FatFileStream *stream, long offset, int whence) {
    FRESULT res = f_lseek(&(stream->file), offset);
    if (res != FR_OK) {
        return -1;
    }
    return 0;
}

// Define fopen, fread, and fclose functions that use FatFs internally
FILE* ffopen(const char* filename, const char* mode) {
  	return (FILE*)fatfs_fopen(filename, mode);
}

size_t ffread(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    return fatfs_fread(ptr, size, nmemb, (FatFileStream*)stream);
}

int ffclose(FILE *stream) {
    return fatfs_fclose((FatFileStream*)stream);
}

int ffseek(FILE *stream, long offset, int whence) {
    return fatfs_fseek((FatFileStream*)stream, offset, whence);
}
*/
typedef struct
{
    wad_file_t wad;
    FILE *fstream;
} stdc_wad_file_t;

extern wad_file_class_t stdc_wad_file;

static wad_file_t *W_StdC_OpenFile(char *path)
{
    stdc_wad_file_t *result;
    FILE *fstream;

	printf("W_StdC_OpenFile\n");
	
    fstream = ffopen(path, "rb");

    if (fstream == NULL)
    {
        return NULL;
    }

    // Create a new stdc_wad_file_t to hold the file handle.

    result = Z_Malloc(sizeof(stdc_wad_file_t), PU_STATIC, 0);
    result->wad.file_class = &stdc_wad_file;
    result->wad.mapped = NULL;
    result->wad.length = M_FileLength(fstream);
    result->fstream = fstream;

    return &result->wad;

}

static void W_StdC_CloseFile(wad_file_t *wad)
{

    stdc_wad_file_t *stdc_wad;

    stdc_wad = (stdc_wad_file_t *) wad;

    ffclose(stdc_wad->fstream);
    Z_Free(stdc_wad);

}

// Read data from the specified position in the file into the 
// provided buffer.  Returns the number of bytes read.

size_t W_StdC_Read(wad_file_t *wad, unsigned int offset,
                   void *buffer, size_t buffer_len)
{
    stdc_wad_file_t *stdc_wad;
    size_t result;

    stdc_wad = (stdc_wad_file_t *) wad;

    // Jump to the specified position in the file.

    ffseek(stdc_wad->fstream, offset, SEEK_SET);

    // Read into the buffer.

    result = ffread(buffer, 1, buffer_len, stdc_wad->fstream);

    return result;
}


wad_file_class_t stdc_wad_file = 
{
    W_StdC_OpenFile,
    W_StdC_CloseFile,
    W_StdC_Read,
};


