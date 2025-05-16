// include header
#include "../../scorelibs/include/PPU/PPU.h"

volatile UV32* getSpritePaletteAddr(unsigned int bank)
{
	return P_SPRITE_ATTRIBUTE_BASE + (8 * bank);
}

volatile SV32* getSpriteXPos(unsigned int id)
{
	return (volatile SV32*)(P_SPRITE_X_BASE + (8 * id));
}

volatile SV32* getSpriteYPos(unsigned int id)
{
    return (volatile SV32*)(P_SPRITE_Y_BASE + (8 * id));
}
