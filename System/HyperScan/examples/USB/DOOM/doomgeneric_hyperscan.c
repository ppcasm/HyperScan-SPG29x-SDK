//doomgeneric for Mattel HyperScan

#include "doomkeys.h"
#include "m_argv.h"
#include "doomgeneric.h"

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "../../../../../SPG290/include/TV/TV.h"
#include "../../../../../SPG290/include/SPG290_Registers.h"
#include "../../../../../SPG290/include/SPG290_Constants.h"
#include "../../../hslibs/include/HS_Controller/HS_Controller.h"
#include "../../../hslibs/include/FatFS/ff.h"

static int FrameBufferFd = -1;
static int* FrameBuffer = 0;

static int KeyboardFd = -1;

#define KEYQUEUE_SIZE 16

static unsigned short s_KeyQueue[KEYQUEUE_SIZE];
static unsigned int s_KeyQueueWriteIndex = 0;
static unsigned int s_KeyQueueReadIndex = 0;

static unsigned int s_PositionX = 0;
static unsigned int s_PositionY = 0;

static unsigned int s_ScreenWidth = 0;
static unsigned int s_ScreenHeight = 0;

enum EnFrameBuferIoctl
{
    FB_GET_WIDTH,
    FB_GET_HEIGHT,
    FB_GET_BITSPERPIXEL
};

void _unlink_r(){
	printf("_unlink_r called\n");
}

void _link_r(){
	printf("_link_r called\n");
}

static unsigned char convertToDoomKey(unsigned char scancode)
{
    unsigned char key = 0;

    switch (scancode)
    {
    case 0x9C:
    case 0x1C:
        key = KEY_ENTER;
        break;
    case 0x01:
        key = KEY_ESCAPE;
        break;
    case 0xCB:
    case 0x4B:
        key = KEY_LEFTARROW;
        break;
    case 0xCD:
    case 0x4D:
        key = KEY_RIGHTARROW;
        break;
    case 0xC8:
    case 0x48:
        key = KEY_UPARROW;
        break;
    case 0xD0:
    case 0x50:
        key = KEY_DOWNARROW;
        break;
    case 0x1D:
        key = KEY_FIRE;
        break;
    case 0x39:
        key = KEY_USE;
        break;
    case 0x2A:
    case 0x36:
        key = KEY_RSHIFT;
        break;
    case 0x15:
        key = 'y';
        break;
    default:
        break;
    }

    return key;
}

static void addKeyToQueue(int pressed, unsigned char keyCode)
{
	//printf("key hex %x decimal %d\n", keyCode, keyCode);

        unsigned char key = convertToDoomKey(keyCode);

        unsigned short keyData = (pressed << 8) | key;

        s_KeyQueue[s_KeyQueueWriteIndex] = keyData;
        s_KeyQueueWriteIndex++;
        s_KeyQueueWriteIndex %= KEYQUEUE_SIZE;
}

void DG_Init()
{

	/*
	Set TV output up with RGB565 color scheme and make set all framebuffers
	to stupid framebuffer address, TV_Init will select the first framebuffer
	as default.
	*/
	TV_Init(RESOLUTION_320_240, COLOR_RGB565, 0xA0500000, 0xA0500000, 0xA0500000);

	printf("Getting screen width...");
	s_ScreenWidth = 320;
	printf("%d\n", s_ScreenWidth);

	printf("Getting screen height...");
	s_ScreenHeight = 240;
    printf("%d\n", s_ScreenHeight);

    if (0 == s_ScreenWidth || 0 == s_ScreenHeight)
    {
        printf("Unable to obtain screen info!");
        exit(1);
    }

    int argPosX = 0;
    int argPosY = 0;

    argPosX = M_CheckParmWithArgs("-posx", 1);
    if (argPosX > 0)
    {
        sscanf(myargv[argPosX + 1], "%d", &s_PositionX);
    }

    argPosY = M_CheckParmWithArgs("-posy", 1);
    if (argPosY > 0)
    {
        sscanf(myargv[argPosY + 1], "%d", &s_PositionY);
    }
}

static void handleKeyInput()
{
    if (KeyboardFd < 0)
    {
        return;
    }

    unsigned char scancode = 0;

    if (read(KeyboardFd, &scancode, 1) > 0)
    {
        unsigned char keyRelease = (0x80 & scancode);

        scancode = (0x7F & scancode);

        //printf("scancode:%x pressed:%d\n", scancode, 0 == keyRelease);

        if (0 == keyRelease)
        {
            addKeyToQueue(1, scancode);
        }
        else
        {
            addKeyToQueue(0, scancode);
        }
    }
}

void DG_DrawFrame()
{
	TV_Buffer_Set(&DG_ScreenBuffer, &DG_ScreenBuffer, &DG_ScreenBuffer);
    //handleKeyInput();
}

void DG_SleepMs(uint32_t ms)
{
}

uint32_t ticks = 0;

uint32_t DG_GetTicksMs()
{
    return ticks++; //get_uptime_ms();
}

int DG_GetKey(int* pressed, unsigned char* doomKey)
{
    if (s_KeyQueueReadIndex == s_KeyQueueWriteIndex)
    {
        //key queue is empty

        return 0;
    }
    else
    {
        unsigned short keyData = s_KeyQueue[s_KeyQueueReadIndex];
        s_KeyQueueReadIndex++;
        s_KeyQueueReadIndex %= KEYQUEUE_SIZE;

        *pressed = keyData >> 8;
        *doomKey = keyData & 0xFF;

        return 1;
    }
}

void DG_SetWindowTitle(const char * title)
{
}

int main(int argc, char **argv)
{
	int i = 0;
	FATFS fs0;
	f_mount(&fs0, "0:", 1);
	
	char *fake_argv[] = {"HYPER.EXE", "-iwad", "doom1.wad", "-nosound", "-scaling", "1", NULL};
	
	int fake_argc = sizeof(fake_argv) / sizeof(fake_argv[0]) - 1;
	
	doomgeneric_Create(fake_argc, fake_argv);

    for (i = 0; ; i++)
    {
        doomgeneric_Tick();
    }
    
    return 0;
}

