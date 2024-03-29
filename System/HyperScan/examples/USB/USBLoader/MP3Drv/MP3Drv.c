#include "../../../../../../SPG290/include/SPG290_Registers.h"
#include "../../../../../../SPG290/include/SPG290_Constants.h"
#include "../MP3Drv/MP3.h"

#define	 D_VolSel_0				  0									//single channel will be 1/32 of max volume
#define	 D_VolSel_1				  0x1<<6							//1/8
#define	 D_VolSel_2				  0x2<<6							//1/2
#define	 D_VolSel_3				  0x3<<6							//1

#define BITSTREAM_FILL_BATCH 512
//#define	TempPCM_Buffer_Size	2048	// unit is word
#define	TempPCM_Buffer_Size	4096
//#define	TempPCM_Buffer_Size	8192

//External definition
extern unsigned char *L_PCMFiles;

//Function definition
void FillSoftFIFO(void);
void EnableSoftCh(unsigned int Samplerate);
void read_bs(unsigned short *MP3_bs_buf, int temp_wp, int fill_size);
void read_bitstream(unsigned short *MP3_bs_buf, int *wp);
int get_bs_free_bytes(int wp);
void Play_MP3(unsigned int MP3_Addr, unsigned int Length);
void Stop_MP3(void);

//Variable definition
unsigned short	*PCMAddress;
unsigned short	*FIFOAddress;
unsigned short *TempAddress;
unsigned short *Address;
unsigned short *MP3_Start_Addr;

unsigned short	FIFOArray[4096];
unsigned short MP3_bs_buf[MP3_BITSTREAM_BUFFER_SIZE/2];
short	PCM_buf[1152*2];
unsigned char decoder_instance[MP3_DECODER_WORK_SPACE];
short 	TempPCM[TempPCM_Buffer_Size];
short	ADC_PCM_Buf_1[MP3_PCM_BUFFER_SIZE*2];
short	ADC_PCM_Buf_2[MP3_PCM_BUFFER_SIZE*2];
short	MP3_Encoded_Data_Buf_1[51200*3/2]={0};	// Initial as '0' to avoid non-zero value be viewed as MP3 data
short	MP3_Encoded_Data_Buf_2[51200*3/2]={0};
short	MP3_Encoded_Data_Buf_Spare[4096/2]={0};
unsigned int MP3_Encoded_Data_Buf_Index=0;
unsigned char *MP3_Encoded_Data_Ptr;

unsigned short	FIFOCounter=0, FIFO_Offset=0;
unsigned short	TempData=0;
unsigned samplerate, bitrate;
int wp, rp;
int error_msg;
int	space;
int pcm_cnt;
int pcm_wp, pcm_rp;
int temp_wp, temp_rp, TempPCM_ready, Need_PCM_Flag;
int Fill_count;
unsigned MP3_Status, MP3_Output_Type;
unsigned int MP3_Length;

void FillSoftFIFO(void)
{
	unsigned short TempValue;
	unsigned short TempCounter;
	
	if(MP3_Output_Type == Stereo)
	{		
		for(TempCounter=0;TempCounter<2048;TempCounter++)
		{
			TempValue = TempPCM[temp_rp];
			TempValue ^= 0x8000;
			FIFOArray[TempCounter+FIFO_Offset] = TempValue;
			temp_rp++;
			if(temp_rp == TempPCM_Buffer_Size)
				temp_rp = 0;
			if( (MP3_Status&0x50) == 0x50)
			{
				if(temp_rp == temp_wp)
					MP3_Status |= D_MP3_PCM_Empty;
			}
		}
	}
	else if(MP3_Output_Type == Left_Only)
	{
		for(TempCounter=0;TempCounter<1024;TempCounter++)	// for stereo
		{
			TempValue = TempPCM[temp_rp];
			TempValue ^= 0x8000;
			FIFOArray[TempCounter*2+FIFO_Offset] = TempValue;
			FIFOArray[TempCounter*2+1+FIFO_Offset] = TempValue;
			temp_rp += 2;
			if(temp_rp == TempPCM_Buffer_Size)
				temp_rp = 0;
			if( (MP3_Status&0x50) == 0x50)
			{
				if((temp_rp == temp_wp) || (temp_rp-temp_wp == 1) || (temp_wp-temp_rp == TempPCM_Buffer_Size-1))
					MP3_Status |= D_MP3_PCM_Empty;
			}
		}
	}
	else if(MP3_Output_Type == Right_Only)
	{
		for(TempCounter=0;TempCounter<1024;TempCounter++)	// for stereo
		{
			TempValue = TempPCM[temp_rp+1];
			TempValue ^= 0x8000;
			FIFOArray[TempCounter*2+FIFO_Offset] = TempValue;
			FIFOArray[TempCounter*2+1+FIFO_Offset] = TempValue;
			temp_rp += 2;
			if(temp_rp == TempPCM_Buffer_Size)
				temp_rp = 0;
			if( (MP3_Status&0x50) == 0x50)
			{
				if((temp_rp == temp_wp) || (temp_rp-temp_wp == 1) || (temp_wp-temp_rp == TempPCM_Buffer_Size-1))
					MP3_Status |= D_MP3_PCM_Empty;
			}
		}
	}

	if(FIFOCounter != 0)
	{
		FIFO_Offset = 0;
		FIFOCounter = 0;
	}
	else
	{
		FIFO_Offset += 2048;
		FIFOCounter = 1;
	}
}

void MP3_Service_Loop_ISR(void)
{
	if( (MP3_Status&0xd0) == 0xd0)
	{
		if((MP3_Status&D_MP3_Repeat) != 0)
			Play_MP3((unsigned int)MP3_Start_Addr,MP3_Length);
		else
			Stop_MP3();
		return;
	}
	if( ((MP3_Status&D_MP3_Play) != 0) && ((MP3_Status&D_MP3_Pause) == 0) )
	{
		FillSoftFIFO();
		Need_PCM_Flag = 1;		// Set flag to start MP3 decoder
		*P_DAC_INT_STATUS = 0xC000 | 0x0004 | 0x0003;	// for stereo, 8KBytes
	}
}

void EnableSoftCh(unsigned int Samplerate)
{
	unsigned int TempValue;

	*P_DAC_BUFFER_SA = 0;
	*P_DAC_FIFOBA_LOW = ((unsigned int)FIFOArray);				// Set start address of buffer for SPU soft channel
	*P_DAC_FIFOBA_HIGH = ((unsigned int)FIFOArray) >> 16;

	if((MP3_Status&D_MP3_Speed) == 0)
	{
		TempValue = 27000000/Samplerate - 1;					// Set sampling rate of current PCM file
		*P_DAC_SAMPLE_CLK = TempValue;
	}
	*P_DAC_INT_STATUS = 0x4000 | 0x0004 | 0x0003;				// Enable software channel as stereo, 8Kbytes buffer
	*P_DAC_MODE_CTRL2  = (0x0608 | D_VolSel_1 | 0x1003);		// for both channel
}

void Init_MP3(void)
{
	*P_DAC_INT_STATUS = 0;			//Stop SPU software channel
	*P_DAC_MODE_CTRL2  = 0;
	MP3_Status = 0;
	Address = 0;
	MP3_Start_Addr = 0;
}

void Play_MP3(unsigned int MP3_Addr, unsigned int Length)
{	
	*P_DAC_INT_STATUS = 0;			//Stop SPU software channel
	*P_DAC_MODE_CTRL2  = 0;
	MP3_Status &= ~(D_MP3_Play | D_MP3_Pause | D_MP3_Data_End | D_MP3_Buf_Empty | D_MP3_PCM_Empty);	//Reset MP3 status
	
	mp3_decoder_init(decoder_instance, (unsigned char *)MP3_bs_buf, 1);	
	Address = (unsigned short *)MP3_Addr;
	MP3_Start_Addr = (unsigned short *)MP3_Addr;
	MP3_Length = Length;
	
	FIFOCounter=0;
	FIFO_Offset=0;
	wp = 0;
	pcm_rp=0;
	pcm_wp=0;
	temp_wp=0;
	temp_rp=0;
	TempPCM_ready=0;
	
	// Fill buffer for playing. Data must be enough at first time.
	read_bs(MP3_bs_buf, wp, MP3_BITSTREAM_BUFFER_SIZE/2-256);
	wp = (MP3_BITSTREAM_BUFFER_SIZE/2 - 256) *2;
	
	Fill_count = 0;
	Need_PCM_Flag = 1;
	MP3_Status |= D_MP3_Play;
	MP3_Output_Type = Stereo;
}

unsigned int Get_MP3_Status(void)
{
	return(MP3_Status);
}

void Stop_MP3(void)
{
	*P_DAC_INT_STATUS = 0;
	*P_DAC_MODE_CTRL2  = 0;
	MP3_Status = 0;
}

void Pause_MP3(void)
{
	*P_DAC_INT_STATUS = 0;
	*P_DAC_MODE_CTRL2  = 0;
	MP3_Status |= D_MP3_Pause;
}

void Resume_MP3(void)
{
	Fill_count = 0;
	Need_PCM_Flag = 1;
	MP3_Status &= ~D_MP3_Pause;
	MP3_Status |= D_MP3_Play;
}

void Repeat_ON_MP3(void)
{
	MP3_Status |= D_MP3_Repeat;
}

void Repeat_OFF_MP3(void)
{
	MP3_Status &= ~D_MP3_Repeat;
}

void MP3_Output_Stereo(void)
{
	MP3_Output_Type = Stereo;
}

void MP3_Output_Left_Only(void)
{
	MP3_Output_Type = Left_Only;
}

void MP3_Output_Right_Only(void)
{
	MP3_Output_Type = Right_Only;
}

void MP3_Service_Loop(void)
{	
	if( ((MP3_Status&D_MP3_Play) != 0) && ((MP3_Status&D_MP3_Pause) == 0) )
	{
		if( (MP3_Status&0x70) == 0x70)
			MP3_Status &= ~D_MP3_Play;
	
		if(Need_PCM_Flag == 1)			//Check whether first or last half of FIFO need data
		{
			//*P_GPIO_TFT_PORT |= 0x02;	// test performance
			if(pcm_wp == pcm_rp)		//Check whether PCM buffer is empty. If yes, decode next frame.
			{
				//*P_GPIO_TFT_PORT |= 0x04;	// test performance
				pcm_cnt = mp3_decoder_run(decoder_instance, wp, PCM_buf+pcm_wp);	//Decode 1 frame and put data from pcm_rp.
				//*P_GPIO_TFT_PORT &= ~0x04;	// test performance
 				if(pcm_cnt == 0)
				{
					if((MP3_Status&D_MP3_Data_End) != 0)
					{
						MP3_Status |= D_MP3_Buf_Empty;
						return;
					}
				} 
				pcm_wp += pcm_cnt*2;
				if(pcm_wp >= 1152*2)
					pcm_wp -= 1152*2;
			}
			
			if(pcm_cnt != 0)
			{
				do
				{
					TempPCM[temp_wp] = PCM_buf[pcm_rp];
					pcm_rp ++;
					if(pcm_rp >= 1152*2)
						pcm_rp -= 1152*2;
					temp_wp ++;	// unit is words	//Write pointer of TempPCM buffer, which spares data for SPU FIFO
					if( (temp_rp - temp_wp == 1) || (temp_wp - temp_rp == (TempPCM_Buffer_Size-1)) )
					{
						TempPCM_ready = 1;
						break;
					}
					if( (temp_wp%2048) == 0 && Fill_count<3)
					{
						if(temp_wp == TempPCM_Buffer_Size)
							temp_wp = 0;
						TempPCM_ready = 1;
						Fill_count++;
						break;						//Stop filling TempPCM buffer when it is full 
					}
	 				else if( (temp_wp%2048) == 0 )
					{
						if(temp_wp == TempPCM_Buffer_Size)
							temp_wp = 0;
						//break;						//Stop filling TempPCM buffer when it is full 
					} 
				}while(pcm_rp != pcm_wp);			//or data in PCM buffer is empty.
			}
			error_msg = mp3_errno(decoder_instance);
			//if(error_msg != 0)
			if(error_msg == -2)
			{
				*P_DAC_INT_STATUS = 0;			//Stop SPU software channel
				*P_DAC_MODE_CTRL2  = 0;
				MP3_Status = 0;					//Stop playin MP3
				return;
			}
			
			space = get_bs_free_bytes(wp);
			if( (space > BITSTREAM_FILL_BATCH) && ((MP3_Status&D_MP3_Data_End) == 0) )	//Check whether no. of data in MP3 buffer is lower than threshold
				read_bitstream(MP3_bs_buf, &wp);//If yes, fill new data.
			
			if(TempPCM_ready == 1)			//Check whether data in TempPCM buffer is enough to load to SPU FIFO
			{
				TempPCM_ready = 0;
				if(Fill_count < 3)
					MP3_Service_Loop_ISR();	//Fill data in SPU in the beginning. Spare 4K bytes data for 1st SPU IRQ.
				else	
					Need_PCM_Flag = 0;
				if(Fill_count == 3)
				{
					bitrate = mp3_get_bitrate(decoder_instance);
					samplerate = mp3_get_sampling_rate(decoder_instance);
					EnableSoftCh(samplerate);	// Start playing on SPU software channel
					Need_PCM_Flag = 0;
					Fill_count++;
					
				}
			}
			//*P_GPIO_TFT_PORT &= ~0x02;	// test performance
		}
	}
}


int bs_byte_size(int wp)
{
	int size;
	int rp = mp3_decoder_read_index(decoder_instance);
	size = wp - rp;
	if(size < 0)
		size += MP3_BITSTREAM_BUFFER_SIZE;
	return(size);
}

int get_bs_free_bytes(int wp)
{
	int space;
	int rp = mp3_decoder_read_index(decoder_instance);
	space = rp - wp;
	if(space < 0)
		space += MP3_BITSTREAM_BUFFER_SIZE;
	return(space);
}

void read_bs(unsigned short *MP3_bs_buf, int temp_wp, int fill_size)
{
	int count;
	for(count=0;count<fill_size;count++)
	{
		TempData = *Address;
		Address += 1;
		if( (count+temp_wp) >= (MP3_BITSTREAM_BUFFER_SIZE/2) )
			MP3_bs_buf[count+temp_wp-MP3_BITSTREAM_BUFFER_SIZE/2] = TempData;
		else
			MP3_bs_buf[count+temp_wp] = TempData;
		
		if(Address >= (MP3_Start_Addr+MP3_Length))
			MP3_Status |= D_MP3_Data_End;
	}
}


void read_bitstream(unsigned short *MP3_bs_buf, int *wp)
{
	int space;
	int temp_wp;
	temp_wp = *wp;
	space = get_bs_free_bytes(temp_wp);
	while(space > BITSTREAM_FILL_BATCH)
	{
		read_bs(MP3_bs_buf, temp_wp/2, BITSTREAM_FILL_BATCH/2);	//fill data in MP3_bs_buf
		space -= BITSTREAM_FILL_BATCH;
		temp_wp += BITSTREAM_FILL_BATCH;
		if(temp_wp >= MP3_BITSTREAM_BUFFER_SIZE)
			temp_wp -= MP3_BITSTREAM_BUFFER_SIZE;
	}
	*wp = temp_wp;
}



