#ifndef __HS_CONTROLLER_H__
#define __HS_CONTROLLER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

/**************************************************************************
 *                           C O N S T A N T S                            *
 **************************************************************************/
#define hs_controller_1 0
#define hs_controller_2 1

typedef struct{
	bool b : 1;
	bool start : 1;
	bool select : 1;
	bool ls : 1;
	bool rs : 1;
	bool lt : 1;
	bool rt : 1;
	bool reserved : 5;
	bool y : 1;
	bool r : 1;
	bool g : 1;
	unsigned char joystick_y: 8;
	unsigned char joystick_x: 8;
} Bitfields;

typedef union{
	Bitfields input;
	unsigned char bytes[5];
} ControllerUnion;

ControllerUnion controller[1];

/**************************************************************************
 *               F U N C T I O N    D E C L A R A T I O N S               *
 **************************************************************************/
void HS_Controller_Init(void);
void HS_Controller_Read(void);

#ifdef __cplusplus
}
#endif

#endif
