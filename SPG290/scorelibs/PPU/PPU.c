// include header
#include "../../scorelibs/include/PPU/PPU.h"

volatile UV32* getSpritePaletteAddr(unsigned int bank)
{
	return P_SPRITE_ATTRIBUTE_BASE + (8 * bank);
}
