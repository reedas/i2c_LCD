/*
* Project Name: LCD_16x02_I2C
* File: lcd.h 
* Description: HD44780-based character LCD 16x02 I2C library header file
* Author: Gavin Lyons.
* Complier: xc8 v2.00 compiler
* PIC: PIC16F1619 
* IDE:  MPLAB X v5.00
* Development board: Microchip Curiosity Board, PIC16F1619
* Created March 2019
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/pic_16F1619_projects
*/
/*
* Modified  and extended for mbed 6 by Andrew Reed
* Inspiration for extra functions from
* https://github.com/ARMmbed/TextLCD
*/

#ifndef LCD_H
#define LCD_H
#include "mbed.h"
/* ************* Data ********************/

#define SLAVE_ADDRESS_LCD 0x7e //I2C  address for PCF8574 I2C interface

/************** Command Byte Codes ******/
// See  http://www.dinceraydin.com/lcd/commands.html for HD44780 CMDs



#define LCD_LINE1 0x80
#define LCD_LINE2 0xC0
#define LCD_HOME  0x02
#define CLRSCR 0x01
#define DISPLAY_ON 0x0C
#define DISPLAY_OFF 0x08
#define CURSOR_ON 0x0A
#define CURSOR_OFF 0x08
#define CURSOR_BLINK 0x0F
#define CURSOR_INC 0x06
#define MODE_8BIT 0x38
#define MODE_4BIT 0x28
#define CURSORSHIFT 0x10
#define FUNCTIONSET 0x20
#define SETCGRAMADDR 0x40
#define SETDDRAMADDR 0x80
#define ENTRYMODESET 0x04
#define DISPLAYCONTROL 0x08


// flags for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// flags for display/cursor shift
#define DISPLAYMOVE 0x08
#define CURSORMOVE 0x00
#define MOVERIGHT 0x04
#define MOVELEFT 0x00

// flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00
#define LCD_BACKLIGHT 0x08
#define LCD_NOBACKLIGHT 0x00

// flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00


/**** Codes for I2C byte******/
// Byte = DATA-X-en-X-rs (en=enable rs = reg select)
#define DATA_BYTE_ON 0x05 //enable=1 and rs =1 1101  YYYY-X-en-X-rs
#define DATA_BYTE_OFF 0x01 // enable=0 and rs =1 1001 YYYY-X-en-X-rs
#define CMD_BYTE_ON 0x04  // enable=1 and rs =0 1100 YYYY-X-en-X-rs 
#define CMD_BYTE_OFF 0x00 // enable=0 and rs =0 1000 YYYY-X-en-X-rs 

/************* Function prototypes *******************/
void lcd_send_cmd (unsigned char data);
void lcd_send_data (unsigned char data);
void lcd_clear (void);
void lcd_init (void);
void lcd_begin(uint8_t cols = 16, uint8_t rows = 2);
void lcd_set_ncol_nrow(uint8_t, uint8_t);
void lcd_send_string (char *str);
void lcd_locate(uint8_t, uint8_t);
void lcd_noDisplay(void);
void lcd_display(void);
void lcd_noBlink(void);
void lcd_blink(void);
void lcd_noCursor(void);
void lcd_cursor(void);
void lcd_scrollDisplayLeft(void);
void lcd_scrollDisplayRight(void);
void lcd_printLeft(void);
void lcd_printRight(void);
void lcd_leftToRight(void);
void lcd_rightToLeft(void);
void lcd_shiftIncrement(void);
void lcd_shiftDecrement(void);
void lcd_noBacklight(void);
void lcd_backlight(void);
void lcd_autoscroll(void);
void lcd_noAutoscroll(void); 
void lcd_createChar(char, char *);

#endif