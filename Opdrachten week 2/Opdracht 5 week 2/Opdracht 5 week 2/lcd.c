/*
 * lcd.c
 *
 * Created: 6-2-2020 13:05:48
 *  Author: Waylon
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

#define LCD_E 	3
#define LCD_RS	2

void lcd_strobe_lcd_e(void)
{
	PORTC |= (1<<LCD_E); // E high
	_delay_ms(1); // nodig
	PORTC &= ~(1<<LCD_E); // E low
	_delay_ms(1); // nodig?
}

void init_4bits_mode(void)
{
	// PORTC output mode and all low (also E and RS pin)
	DDRC = 0xFF;
	PORTC = 0x00;

	// Step 2 (table 12)
	PORTC = 0x20; // function set
	lcd_strobe_lcd_e();

	// Step 3 (table 12)
	PORTC = 0x20; // function set
	lcd_strobe_lcd_e();
	PORTC = 0x80;
	lcd_strobe_lcd_e();

	// Step 4 (table 12)
	PORTC = 0x00; // Display on/off control
	lcd_strobe_lcd_e();
	PORTC = 0xF0;
	lcd_strobe_lcd_e();

	// Step 4 (table 12)
	PORTC = 0x00; // Entry mode set
	lcd_strobe_lcd_e();
	PORTC = 0x60;
	lcd_strobe_lcd_e();
}

void lcd_write_data(unsigned char byte)
{
	// First nibble.
	PORTC = byte;
	PORTC |= (1<<LCD_RS);
	lcd_strobe_lcd_e();

	// Second nibble.
	PORTC = (byte<<4);
	PORTC |= (1<<LCD_RS);
	lcd_strobe_lcd_e();
}

void lcd_write_command(unsigned char byte)
{
	// First nibble.
	PORTC = byte;
	PORTC &= ~(1<<LCD_RS);
	lcd_strobe_lcd_e();

	// Second nibble.
	PORTC = (byte<<4);
	PORTC &= ~(1<<LCD_RS);
	lcd_strobe_lcd_e();
}

void lcd_clear(void)
{
	lcd_write_command(0x01);
	_delay_ms(250);
}

void set_cursor(int position){
	//TODO: Finish method.
	//lcd_write_command();
}

void lcd_write_text(char *str, int line, _Bool slowmode){
	if (line == 1){
		lcd_write_command(0x80);

	}
	else if (line == 2){
		lcd_write_command(0xC0);
	}
	else {
		char errorMessage[5] = "Error";
		lcd_clear();
		for (int i = 0; i <= 5; i++){
			lcd_write_data(errorMessage[i]);
		}
		//TODO: Find a way to stop/exit at this line, so that the text is NOT printed beyond this point.
	}
	
	for(;*str; str++){
		lcd_write_data(*str);
		if (slowmode){
			_delay_ms(100);
		}
	}
}