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

#include "config.h"

#include "doomtype.h"
#include "m_argv.h"

#include "w_file.h"

#include "../../include/FatFS/ff.h"

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
	    
    FatFileStream* stream = malloc(sizeof(FatFileStream));
    if (stream == NULL) {
    	printf("Could not allocate\n");
        return NULL;
    }

    res = f_open(&(stream->file), filename, FA_READ);
    if (res != FR_OK) {
        free(stream);
        return NULL;
    }

	printf("Opened: %x\n", stream);
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
    printf("close\n");
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

extern wad_file_class_t stdc_wad_file;

/*
#ifdef _WIN32
extern wad_file_class_t win32_wad_file;
#endif
*/

#ifdef HAVE_MMAP
extern wad_file_class_t posix_wad_file;
#endif 

static wad_file_class_t *wad_file_classes[] = 
{
/*
#ifdef _WIN32
    &win32_wad_file,
#endif
*/
#ifdef HAVE_MMAP
    &posix_wad_file,
#endif
    &stdc_wad_file,
};

wad_file_t *W_OpenFile(char *path)
{
    wad_file_t *result;
    int i;

    //!
    // Use the OS's virtual memory subsystem to map WAD files
    // directly into memory.
    //

    if (!M_CheckParm("-mmap"))
    {
    	printf("Opening\n");
        return ffopen(path, "r"); //stdc_wad_file.OpenFile(path);
    }

    // Try all classes in order until we find one that works

    result = NULL;

    for (i = 0; i < arrlen(wad_file_classes); ++i)
    {
        result = wad_file_classes[i]->OpenFile(path);

        if (result != NULL)
        {
            break;
        }
    }

    return result;
}

void W_CloseFile(wad_file_t *wad)
{
    wad->file_class->CloseFile(wad);
}

size_t W_Read(wad_file_t *wad, unsigned int offset,
              void *buffer, size_t buffer_len)
{
	printf("READ\n");
    return wad->file_class->Read(wad, offset, buffer, buffer_len);
}

