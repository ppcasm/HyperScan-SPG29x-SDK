#ifndef __NORFLASH_H__
#define __NORFLASH_H__

#ifdef __cplusplus
extern "C" {
#endif

#define C_Flash_BaseAddr	0x9e000000

#define C_CMD1_Addr			(volatile unsigned int *)0x9e055550
#define C_CMD2_Addr			(volatile unsigned int *)0x9e02aaa0
#define C_CMD3_Addr			(volatile unsigned int *)0x9e055550
#define C_CMD4_Addr			(volatile unsigned int *)0x9e055550
#define C_CMD5_Addr			(volatile unsigned int *)0x9e02aaa0
#define C_CMD6_Addr			(volatile unsigned int *)0x9e055550

#define C_CMD_Data1			0xaa
#define C_CMD_Data2			0x55
#define C_CMD_Data3			0x80
#define C_CMD_Data4			0xaa
#define C_CMD_Data5			0x55

#define C_WORD_WRITE		0xa0
#define C_SECTOR_ERASE		0x30
#define C_BLOCK_ERASE		0x50
#define C_CHIP_ERASE		0x10

#define C_WRITE_DELAY_TIME	1000
#define C_SECTOR_ERASE_TIME	500000
#define C_BLOCK_ERASE_TIME	500000
#define C_CHIP_ERASE_TIME	500000
/**************************************************************************
 *                           C O N S T A N T S                            *
 **************************************************************************/
#define 	C_SECTOR_SIZE	2048		// 2048 words/sector, 1 word = 16 bits
#define 	C_BLOCK_SIZE 	32768		// 32768 words/block, 16 sector/block

/**************************************************************************
 *               F U N C T I O N    D E C L A R A T I O N S               *
 **************************************************************************/
void NorFlash_Init(void);
void NorFlash_Delay(unsigned int clk);
void NorFlash_WordWrite(unsigned int addr, unsigned data);
unsigned int NorFlash_SetAddress(unsigned int addr);
extern void NorFlash_ChipErase(void);
extern void NorFlash_BlockErase(unsigned int addr);
extern void NorFlash_SectorErase(unsigned int addr);
extern void NorFlash_Write32(unsigned int addr, unsigned int data);

#ifdef __cplusplus
}
#endif

#endif
