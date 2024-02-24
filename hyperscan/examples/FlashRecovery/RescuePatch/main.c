/*

This is part of the Mattel HyperScan SDK by ppcasm (ppcasm@gmail.com)

This example is part of the FlashRescue project. It's the logic for the recovery mode, please see the FlashRescue example to
better understand what this is.   
 
*/

#include "../../../include/SPG290_Registers.h"

// Macro for controlling the HyperScan LEDs
#define HS_LEDS(value) (*P_CSI_GPIO_SETUP = (0x1FFE0000+(value<<5)))

#define UPLOAD_ADDRESS 0x800001FC
#define ENTRY_ADDRESS 0xA0001000

#define BIT(n)	(1 << n)

#define SW_UART_UART	BIT(24)

#define UART_BUSY	BIT(3)
#define UART_TRANSMIT_EMPTY	BIT(7)
#define UART_TRANSMIT_FULL	BIT(5)
#define UART_RECEIVE_EMPTY	BIT(4)
#define UART_RECEIVE_FULL	BIT(6)

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef volatile u32 vu32;

typedef enum {
	false = 0, true = 1
} bool;

static void uart_enable_interface() {
	*P_UART_INTERFACE_SEL |= SW_UART_UART;
}

static void uart_wait_nonbusy() {
	u32 status = *P_UART_TXRX_STATUS;
	while (status & UART_BUSY || status & UART_TRANSMIT_FULL || !(status & UART_TRANSMIT_EMPTY)) {
		status = *P_UART_TXRX_STATUS;
	}
}

static void uart_write_byte(u32 c) {
	*P_UART_TXRX_DATA = c;
	uart_wait_nonbusy();
}

static void print_string(const char *str) {
	while (*str) {
		uart_write_byte(*str++);
	}
}

static u8 uart_read_byte() {
	while (*P_UART_TXRX_STATUS & UART_RECEIVE_EMPTY);
	return *P_UART_TXRX_DATA;
}

static void print_nibble(unsigned char n) {
	uart_write_byte("0123456789abcdef"[n & 0xF]);
}

static void print_byte(unsigned char b) {
	print_nibble(b >> 4);
	print_nibble(b >> 0);
}

int main()
{
	// Turn all LEDs ON
	HS_LEDS(0xFF);
	
	// Setup IOB port for correct port direction to get the CD door status
	*P_IOB_GPIO_SETUP = 0x3F3F3302;
	
	// Read CD door status
	if(*P_IOB_GPIO_INPUT&(1<<9)){
		// If the CD door is closed on boot, boot as normal
		asm("la r8, 0xA0001000");
		asm("br! r8");
		asm("nop!");
	}
	else{
		
		// Do this stuff if the CD door is closed on boot
		
		// Setup SDRAM for copying
		*P_MIU_SDRAM_SETUP1 = (*P_MIU_SDRAM_SETUP1 & 0xFFFF0000) | 0x4834; 
		
		// Enable UART
		uart_enable_interface();

		// invalidate D-Cache
		asm("cache 0x18, [r15, 0]");
		asm("nop");
		asm("nop!");
		asm("nop!");
		asm("nop!");
		asm("nop!");
		asm("nop");
		
		//	invalidate I-Cache
		asm("cache 0x10, [r15, 0]");
		asm("nop");
		asm("nop!");
		asm("nop!");
		asm("nop!");
		asm("nop!");
		asm("nop");

		// Drain write buffer
		asm("cache 0x1A, [r15, 0]");
		asm("nop");
		asm("nop!");
		asm("nop!");
		asm("nop!");
		asm("nop!");
		asm("nop");
				
		// Flush UART
		while (!(*P_UART_TXRX_STATUS & UART_RECEIVE_EMPTY)) {
			print_byte(*P_UART_TXRX_DATA);
		}

		// Print "Ready! " over UART
		print_string("Ready! ");

		// Get and pack the size bytes of the binary about to be uploaded (comes from the python send script)
		u32 size = 0;
		size |= uart_read_byte() << 0;
		size |= uart_read_byte() << 8;
		size |= uart_read_byte() << 16;
		size |= uart_read_byte() << 24;

		// Print "...GO!" to let us know we did receive the 4 size bytes 
		print_string("...GO!\n");
		
		// Set the destination and ending address we intend to upload to in SDRAM
		u8 *dest = (u8 *)UPLOAD_ADDRESS;
		u8 *end = (u8 *)UPLOAD_ADDRESS + size;
		
		// Define the LEDs value, and a count that we will use later
		u8 leds = 0;
		u32 counts = 0;
		
		// Download the binary data over UART, and "roll" the LEDs by 
		// having a count that ticks the LEDs forward by 1 for every 500
		// bytes received over UART
		while (dest < end) {
			counts++;
			HS_LEDS(1<<leds);
			*dest++ = uart_read_byte();
			if(counts % 500 == 0) leds++;
			if(leds>=8) leds = 0;
		}

		*P_MIU_SDRAM_SETUP1 = (*P_MIU_SDRAM_SETUP1 & 0xFFFF0000) | 0x4B04;
		
		// Function pointer to our entry address
		void (*entry_point)(void) = (void *)ENTRY_ADDRESS;
		
		// Turn off LEDs to let us know everything actually did complete
		// just in case something doesn't run, you'll have an indicator that 
		// at least let's you know everything ran proper
		HS_LEDS(0x00);

		// Start executing from defined entry point
		entry_point();
	}

return 0;		
}

