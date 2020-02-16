/*
 * lcd.h
 *
 * Created: 6-2-2020 13:05:31
 * Edited: 16-2-2020
 *  Authors: Waylon, Jasper
 */

void init_4bits_mode(void);
void lcd_write_text(char *str, int line, _Bool slowmode);
void lcd_clear(void);
void lcd_strobe_lcd_e(void);
void lcd_write_data(unsigned char byte);
void lcd_write_command(unsigned char byte);
void set_cursor(int position);
void lcd_charToRight();