#include "../../include/I2C/I2C.h"
#include "../../include/SPG290_Registers.h"
#include "../../include/SPG290_Constants.h"
#include "../../include/HS_Controller/HS_Controller.h"

/*
	These are the data ports used by the HyperScan controller. It
	seems like only 0~3 are really used, but responses seem to hang
	if you don't actually read all of the I2C data ports, so we do that
*/

//=============================================================
// void HS_Controller_Init(void);
//
// This initializes the Mattel HyperScan controller interface
//
// void return
//=============================================================
void HS_Controller_Init(void)
{
	I2C_Init();
	
	*P_TFT_GPIO_OUTPUTEN = 0x000FFFFF;
	*P_TFT_GPIO_PULLUP = 0x000FFFFF;
	*P_TFT_GPIO_PULLDOWN = 0x00000000;
	
	//	Flush initial controller inputs
	HS_Controller_Read();
}

//=============================================================
// void HS_Controller_Read(unsigned int controller_port);
//
// This reads the data from controller (controller_port) and returns
// the value
//
// void return, the controller data gets stored in the controller union/struct
// for the specific controller (hs_controller_1, or hs_controller_2)
//=============================================================
void HS_Controller_Read(void){
	/*
		The Mattel HyperScan controllers are selected by the
		TFT_GPIO port
	*/
	
	unsigned int read_count = 0;
	unsigned int controller_count = 0;
	
	//	HyperScan controller I2C device address
	*P_I2C_SLAVE_ADDR = 0x54;
	
	for(controller_count=0;controller_count<=1;controller_count++){
		//	Make controller active
		*P_TFT_GPIO_DATA |= (1 << controller_count);

		for(read_count=0;read_count<=4;read_count++){
			controller[controller_count].bytes[read_count] = I2C_Read8(read_count);
		}
		
		//	Disable controller
		*P_TFT_GPIO_DATA &= ~(1 << controller_count);
	}
	
	return;
}


