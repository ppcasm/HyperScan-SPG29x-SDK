#ifndef __I2C_H__
#define __I2C_H__

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************
 *               F U N C T I O N    D E C L A R A T I O N S               *
 **************************************************************************/
void I2C_Init(void);
unsigned int I2C_Read8(int addr);
void I2C_Write8(int addr, unsigned int value);

#ifdef __cplusplus
}
#endif

#endif
