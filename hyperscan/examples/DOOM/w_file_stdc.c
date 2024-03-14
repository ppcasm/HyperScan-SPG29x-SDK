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

FatFileStream* fopen_fatfs(const char* filename, const char* mode) {
    FatFileStream* stream = malloc(sizeof(FatFileStream));
    if (stream == NULL) {
        return NULL;
    }

    UINT fmode;
    if (strcmp(mode, "r") == 0) {
        fmode = FA_READ;
    } else if (strcmp(mode, "w") == 0) {
        fmode = FA_WRITE | FA_CREATE_ALWAYS;
    } else if (strcmp(mode, "a") == 0) {
        fmode = FA_WRITE | FA_OPEN_ALWAYS | FA_OPEN_APPEND;
    } else if (strcmp(mode, "r+") == 0) {
        fmode = FA_READ | FA_WRITE;
    } else if (strcmp(mode, "w+") == 0) {
        fmode = FA_READ | FA_WRITE | FA_CREATE_ALWAYS;
    } else if (strcmp(mode, "a+") == 0) {
        fmode = FA_READ | FA_WRITE | FA_OPEN_ALWAYS | FA_OPEN_APPEND;
    } else {
        free(stream);
        return NULL; // Unsupported mode
    }

    FRESULT res = f_open(&(stream->file), filename, fmode);
    if (res != FR_OK) {
        free(stream);
        return NULL;
    }

    return stream;
}

size_t fread_fatfs(void *ptr, size_t size, size_t nmemb, FatFileStream *stream) {
    UINT bytesRead;
    FRESULT res = f_read(&(stream->file), ptr, size * nmemb, &bytesRead);
    if (res != FR_OK) {
        return 0;
    }
    return bytesRead / size;
}

size_t fwrite_fatfs(const void *ptr, size_t size, size_t nmemb, FatFileStream *stream) {
    UINT bytesWritten;
    FRESULT res = f_write(&(stream->file), ptr, size * nmemb, &bytesWritten);
    if (res != FR_OK) {
        return 0;
    }
    return bytesWritten / size;
}

int fseek_fatfs(FatFileStream *stream, long offset, int whence) {
    FRESULT res = f_lseek(&(stream->file), offset);
    if (res != FR_OK) {
        return -1;
    }
    return 0;
}

int fclose_fatfs(FatFileStream *stream) {
    f_close(&(stream->file));
    free(stream);
    return 0;
}

typedef struct
{
    wad_file_t wad;
    FILE *fstream;
} stdc_wad_file_t;

extern wad_file_class_t stdc_wad_file;

static wad_file_t *W_StdC_OpenFile(char *path)
{
    stdc_wad_file_t *result;
    
    FIL fp;
    FRESULT res;
    res = f_open(&fp, path, FA_READ);
    
    if (res == NULL)
    {
        return NULL;
    }

    // Create a new stdc_wad_file_t to hold the file handle.

    result = Z_Malloc(sizeof(stdc_wad_file_t), PU_STATIC, 0);
    result->wad.file_class = &stdc_wad_file;
    result->wad.mapped = NULL;
    result->wad.length = f_size(&fp); //M_FileLength(fstream);
    printf("SIZE: %x\n", f_size(&fp));
    result->fstream = 0; //fstream;

    return &result->wad;
}

static void W_StdC_CloseFile(wad_file_t *wad)
{
    stdc_wad_file_t *stdc_wad;

    stdc_wad = (stdc_wad_file_t *) wad;

    fclose_fatfs(stdc_wad->fstream);
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

    fseek_fatfs(stdc_wad->fstream, offset, SEEK_SET);

    // Read into the buffer.

    result = fread_fatfs(buffer, 1, buffer_len, stdc_wad->fstream);

    return result;
}


wad_file_class_t stdc_wad_file = 
{
    W_StdC_OpenFile,
    W_StdC_CloseFile,
    W_StdC_Read,
};


