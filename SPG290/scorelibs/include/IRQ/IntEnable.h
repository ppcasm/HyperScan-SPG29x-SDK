#ifndef __INTENABLE_H__
#define __INTENABLE_H__

#include "../../include/SPG290_Registers.h"
#include "../../include/SPG290_Constants.h"

//===================================================
// Unmask Ints
//===================================================
#define DAC_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_DAC_DIS)
#define MIC_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_MIC_DIS)
#define ADC_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_ADC_DIS)
#define TMB_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_TMB_DIS)
#define TIMER_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_TIMER_DIS)
#define LCDVS_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_LCDVS_DIS)
#define USB_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_USB_DIS)
#define SIO_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_SIO_DIS)
#define SPI_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_SPI_DIS)
#define UART_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_UART_DIS)
#define NAND_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_NAND_DIS)
#define SD_INT_UNMASK()				(*P_INT_MASK_CTRL1 &= ~C_INT_SD_DIS)
#define I2C_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_I2C_DIS)
#define I2S_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_I2S_DIS)
#define APBCH0_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_APBCH0_DIS)
#define APBCH1_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_APBCH1_DIS)
#define LDM_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_LDM_DIS)
#define BLN_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_BLN_DIS)
#define APBCH2_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_APBCH2_DIS)
#define APBCH3_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_APBCH3_DIS)

#define RTC_INT_UNMASK()			(*P_INT_MASK_CTRL2 &= ~C_INT_RTC_DIS)
#define MP4_INT_UNMASK()			(*P_INT_MASK_CTRL2 &= ~C_INT_MP4_DIS)
#define ECC_INT_UNMASK()			(*P_INT_MASK_CTRL2 &= ~C_INT_ECC_DIS)
#define EXT_INT_UNMASK()			(*P_INT_MASK_CTRL2 &= ~C_INT_GPIO_DIS)

#define INT_UNMASK_SETUP1(INT_DIS)	(*P_INT_MASK_CTRL1 &= ~INT_DIS)		
#define INT_UNMASK_SETUP2(INT_DIS)	(*P_INT_MASK_CTRL2 &= ~INT_DIS)

#endif
