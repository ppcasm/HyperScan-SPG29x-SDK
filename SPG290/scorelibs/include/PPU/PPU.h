#ifndef __PPU_H__
#define __PPU_H__

#include "../../include/SPG290_Registers.h"

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************
 *               C O N S T A N T     D E C L A R A T I O N S              *
 **************************************************************************/
#define FLIP_HORIZ				  0x01
#define FLIP_VERT				  0x02

/**************************************************************************
 *               F U N C T I O N    D E C L A R A T I O N S               *
 **************************************************************************/
volatile UV32* getSpritePaletteAddr(unsigned int bank);

#ifdef __cplusplus
}
#endif

#endif
