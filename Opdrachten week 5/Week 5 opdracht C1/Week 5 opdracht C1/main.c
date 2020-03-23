/* spi Serial Peripheral Interface
 *	 7 segments display
 *  Master
 *	WvdE
 * 24 febr 2011
 */
/*
 * Project name		: Demo5_5 : spi - 7 segments display
 * Author			: Avans-TI, WvdE, JW
 * Revision History	: 20110228: - initial release;
 * Description		: This program sends data to 1 4-digit display with spi
 * Test configuration:
     MCU:             ATmega128
     Dev.Board:       BIGAVR6
     Oscillator:      External Clock 08.0000 MHz
     Ext. Modules:    Serial 7-seg display
     SW:              AVR-GCC
 * NOTES			: Turn ON switch 15, PB1/PB2/PB3 to MISO/MOSI/SCK
*/
#include "4DigitDisplay.h"

int main()
{
	// inilialize
	DDRB=0x01;					  	// Set PB0 pin as output for display select
	spi_masterInit();              	// Initialize spi module
	displayDriverInit();            // Initialize display chip

	for (int i = -999; i < 10000; i++)
	{
		writeLedDisplay(i);
		wait(10);
	}
  	return (1);
}
