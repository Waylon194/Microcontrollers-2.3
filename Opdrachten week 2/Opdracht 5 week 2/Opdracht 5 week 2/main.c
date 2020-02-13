#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include "lcd.h"

#define false 0
#define true 1

int main(void)
{
	// Init I/O
	DDRD = 0xFF; // PORTD(7) output, PORTD(6:0) input

	// Init LCD
	init_4bits_mode();

	while (1)
	{
		lcd_clear();
		lcd_write_text("Yedi you are", 1, false);
		lcd_write_text("Yedi you are", 2, true);
		//Call to trigger error message on LCD screen.
		//lcd_write_text("Yedi you are", 3, true);
	}
}