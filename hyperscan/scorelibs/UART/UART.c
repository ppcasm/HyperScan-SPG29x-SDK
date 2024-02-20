#include "../../include/SPG290_Registers.h"
#include "../../include/SPG290_Constants.h"
#include "../../include/UART/UART.h"

//=============================================================
//	void UART_Init(int BaudRate)
//
//
//	void return
//=============================================================
void UART_Init(int BaudRate){
/*	
	For now I'll leave this blank, as UART is already set up
	by the firmware on the Mattel HyperScan, but having the 
	option to change configs for other SPG29x systems would be useful.
*/
}

//=============================================================
//	void UART_SendChar(char cData)
//
//
//	void return
//=============================================================
void UART_SendChar(char cData){
    while(*P_UART_TXRX_STATUS & C_UART_TXFIFO_FULL);
    *P_UART_TXRX_DATA = cData;
	while(*P_UART_TXRX_STATUS & C_UART_BUSY_FLAG);  
}

//=============================================================
//	char UART_GetChar();
//
//
//	char return (the character send to the device)
//=============================================================
char UART_GetChar(){
    char cData = 0;
    int i=0;
    
    while(*P_UART_TXRX_STATUS & C_UART_RXFIFO_EMPTY){
    	i++;
    	if(i==10000)break;
    }
    
    if(i==10000) cData = 0xFF; else cData = *P_UART_TXRX_DATA;
    
    return cData;
}



