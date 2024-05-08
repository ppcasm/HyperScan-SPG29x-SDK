#ifndef __UART_H__
#define __UART_H__

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************
 *                           C O N S T A N T S                            *
 **************************************************************************/

//UART Baud Rate defines (For SPG290 27MHz use only)
#define  BAUD_RATE_1200        0x57E4
#define  BAUD_RATE_2400        0x2BF2
#define  BAUD_RATE_4800        0x15F9
#define  BAUD_RATE_9600        0x0AFC
#define  BAUD_RATE_19200       0x057E
#define  BAUD_RATE_38400       0x02BF
#define  BAUD_RATE_57600       0x01D4
#define  BAUD_RATE_115200      0x00EA


/**************************************************************************
 *               F U N C T I O N    D E C L A R A T I O N S               *
 **************************************************************************/
void UART_Initial(int BaudRate);
void UART_SendChar(char Data);
char UART_GetChar();

#ifdef __cplusplus
}
#endif

#endif
