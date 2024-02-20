#include "../../include/SPG290_Constants.h"
#include "../../include/SPG290_Registers.h"
#include "../../include/TV/TV.h"
#include "../../include/TV/Font_8x16.h"

// =============================================================
//	void TV_ClearScreen(unsigned short *fb)
//
//	This clears the TV screen. This needs to be fixed at some point
//	so as not to assume 640x480 resolution
// 
// 
//	void return
// =============================================================
void TV_ClearScreen(unsigned short *fb){
	int i = 0;
	for(i=0;i<=640*480;i++){
		fb[i] = 0x0000;
	}
}

// =============================================================
//	void TV_Init(unsigned int Mode, unsigned int ColorModeIN,
//	unsigned int FB1_Addr, unsigned int FB2_Addr, unsigned int FB3_Addr);
//
//	This initializes basic TV output, then sets up some initial framebuffer
//	addresses (3), and sets color scheme, then selects FB1_Addr as the 
//	default framebuffer.
// 
//
//	void return
// =============================================================
void TV_Init(unsigned int Resolution, unsigned int ColorMode, unsigned int FB1_Addr, unsigned int FB2_Addr, unsigned int FB3_Addr){
	*P_TV_CLK_CONF = C_TV_CLK_EN | C_TV_RST_DIS; 	
	*P_TV_VIDEODAC_CTRL = C_TV_VIDEODAC_EN; 
	*P_TV_MODE_CTRL = C_TV_CTRL_EN 			
					| C_TV_NTSC_MODE 				
					| C_TV_INTERLACE_MODE 
					| C_TV_NTSC_TYPE 		
					| C_TV_LITTLE_ENDIAN; 	

	if(Resolution == RESOLUTION_640_480){
		*P_TV_MODE_CTRL |= C_TV_VGA_MODE;
	}
	
	if(ColorMode == COLOR_RGB565){
		*P_TV_MODE_CTRL	|= 	C_TV_RGB_MODE 				
							| C_TV_RGB565_MODE;
	}

	TV_Buffer_Set(FB1_Addr, FB2_Addr, FB3_Addr);
	TV_ClearScreen((unsigned short *)FB1_Addr);
	TV_Buffer_Sel(0);
}

// =============================================================
// 	void TV_Buffer_Set(unsigned int FB1_Addr, unsigned int FB2_Addr,
// 	unsigned int FB3_Addr)
//
//	This sets the current framebuffer pointers (3)
//	
//
//	void return
// =============================================================
void TV_Buffer_Set(unsigned int FB1_Addr, unsigned int FB2_Addr, unsigned int FB3_Addr){
	
	*P_TV_BUFFER_SA1 = FB1_Addr;
	*P_TV_BUFFER_SA2 = FB2_Addr;
	*P_TV_BUFFER_SA3 = FB3_Addr;
}

// =============================================================
//	void TV_Buffer_Sel(unsigned int sel)
// 
//	This selects the current framebuffer
//
//	void return
// =============================================================
void TV_Buffer_Sel(unsigned int sel){
	
	*P_TV_BUFFER_SEL = sel;
}

// =============================================================
//	void TV_Saturation(unsigned int satu)
// 
//	This sets TV saturation
//
//	void return
// =============================================================
void TV_Saturation(unsigned int satu){
	
	*P_TV_SATURATION_SETUP = satu & 0x000000ff;
}

// =============================================================
//	void TV_Hue(unsigned int hue)
// 
//	This sets TV hue
// 
//	void return
// =============================================================
void TV_Hue(unsigned int hue){
	
	*P_TV_HUE_SETUP = hue & 0x000000ff;
}

// =============================================================
//	void TV_Fade(unsigned int fade)
// 
//	This sets TV fade
// 
//	void return
// =============================================================
void TV_Fade(unsigned int fade){
	
	*P_TV_FADE_SETUP = fade & 0x000000ff;
}

// =============================================================
//	void TV_Print(unsigned int x, unsigned int y, unsigned char *text)
// 
//	Print to TV screen via low level framebuffer access
// 
//	void return
// =============================================================
void TV_Print(unsigned short *fb, unsigned int x, unsigned int y, char *text){
	
    short xx, yy;
    unsigned short colorz;
    while (*text) 
    {
        for (yy = 0; yy < 16; yy++) 
        {
	      for (xx = 0; xx < 8; xx++)
	      {
            if(font[(*text)*16+yy] & (1<<(8-xx))) colorz = 0xFFFF; else colorz = 0x0000; //fb[(y*16+yy)*640+(x*8+xx)];
	        fb[(y*16+yy)*640+(x*8+xx)] = colorz;
	      }
	}
	x++;
	text++;
    }
    
  return;
}

// =============================================================
// void TV_Print(unsigned int x, unsigned int y, unsigned char *text)
// 
// Print to TV screen via low level framebuffer access
// 
// void return
// =============================================================
void TV_PrintHex(unsigned short *fb, unsigned int x, unsigned int y, unsigned long value){
	
	unsigned long i;
	unsigned long digit;
	char s[9];
	for(i=0;i<8;i++)
	{
		digit=value>>28;
	    value<<=4;
	    s[i] = digit+'0'+(digit<10?0:'a'-10-'0');
	}
	
	s[8]=0x00;
	TV_Print(fb, x, y, "0x");
	x++;
	x++;
	TV_Print(fb, x, y, s);
}

//==============================================================
//	void TV_FadeOut(void)
//
//	This will perform a predefined fade-out using the "TV_Fade" primative
//
//	void return
//==============================================================
void TV_FadeOut(void)    
{
	unsigned int i, j;
	for(i=0; i<256; i++)
	{
		TV_Fade(i);
		for(j=0; j<1024*6; j++);
	}
}

//==============================================================
//	void TV_FadeIn(void)
//
//	This will perform a predefined fade-in using the "TV_Fade" primative
//
//	void return
//==============================================================
void TV_FadeIn(void)     
{
	unsigned int i, j;
	for(i=0; i<256; i++)
	{
		TV_Fade(255-i);
		for(j=0; j<1024*8; j++);
	}
}
