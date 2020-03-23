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

 	// clear display (all zero's)
	for (char i =1; i<=4; i++)
	{
      	spi_slaveSelect(0); 		// Select display chip
      	spi_write(i);  				// 	digit adress: (digit place)
      	spi_write(0);				// 	digit value: 0 
  	  	spi_slaveDeSelect(0);		// Deselect display chip
	}    
	wait(1000);

/*
	// write 4-digit data  
 	for (char i =1; i<=4; i++)
  	{
		spi_slaveSelect(0);         // Select display chip
		spi_write(i);         		// 	digit adress: (digit place)
		spi_write(i);  		// 	digit value: i (= digit place)
		spi_slaveDeSelect(0); 		// Deselect display chip
	
		wait(1000);
  	}
	wait(1000);
*/


	writeLedDisplay(1024);

  	return (1);
}
