/*
 * _4DigitDisplay.h
 *
 * Created: 23-Mar-20 11:41:11
 *  Author: Jaspe
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define BIT(x)		( 1<<x )
#define DDR_SPI		DDRB					// spi Data direction register
#define PORT_SPI	PORTB					// spi Output register
#define SPI_SCK		1						// PB1: spi Pin System Clock
#define SPI_MOSI	2						// PB2: spi Pin MOSI
#define SPI_MISO	3						// PB3: spi Pin MISO
#define SPI_SS		0						// PB0: spi Pin Slave Select

// wait(): busy waiting for 'ms' millisecond
// used library: util/delay.h
void wait(int ms);
void spi_masterInit(void);
void spi_write( unsigned char data );
char spi_writeRead( unsigned char data );
void spi_slaveSelect(unsigned char chipNumber);
void spi_slaveDeSelect(unsigned char chipNumber);
void displayDriverInit();
void displayOn();
void displayOff();
void writeLedDisplay( int data );