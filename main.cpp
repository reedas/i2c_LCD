#include "i2cLCD.h"
#include "mbed.h"


// main() runs in its own thread in the OS
int main() {
  printf("LCD Test\r\n\n");
  char count[16];
  lcd_begin();
  lcd_clear();
  lcd_send_cmd(LCD_LINE1);
  lcd_send_string((char *)"Hello World!");
  lcd_send_cmd(LCD_LINE2);
  for (int i = 0; i < 16; i++) {
    lcd_send_string((char *)"*");
    ThisThread::sleep_for(100ms);
  }
  printf("Cursor Positioning\n\r");
  lcd_clear();
  lcd_noBacklight();
  lcd_locate(0, 1);
  lcd_send_string((char *)"Count = ");
  ThisThread::sleep_for(1s);
  lcd_backlight();
  for (int i = 0; i < 256; i++) {
    lcd_locate(10 - (i >= 100) - (i >= 10), 1);
    sprintf(count, "%3d", i);
    lcd_send_string(count);
    ThisThread::sleep_for(100ms);
  }

  ThisThread::sleep_for(10s);
  lcd_clear();
  printf("Cursor Changing\n\r");
  lcd_locate(0, 0);
  lcd_noBlink();
  lcd_locate(0, 1);
  lcd_send_string((char *)"No Blink");
  lcd_backlight();
  ThisThread::sleep_for(10s);
  lcd_locate(0, 0);
  lcd_blink();
  lcd_locate(0, 1);
  lcd_send_string((char *)"Blinking");

  ThisThread::sleep_for(10s);
  lcd_noBlink();
  lcd_locate(0, 0);
  lcd_noCursor();
  lcd_locate(0, 1);
  lcd_send_string((char *)"No Cursor");
  ThisThread::sleep_for(10s);
  lcd_locate(0, 0);
  lcd_cursor();
  lcd_locate(0, 1);
  lcd_send_string((char *)"Show Cursor>");

  ThisThread::sleep_for(10s);
  lcd_clear();
  printf("Display Control\r\n");
  lcd_locate(0, 0);
  lcd_send_string((char *)"No Display");
  ThisThread::sleep_for(1s);
  lcd_noDisplay();
  ThisThread::sleep_for(1s);
  lcd_display();
  lcd_locate(0, 0);
  lcd_noCursor();
  lcd_noBlink();
  lcd_send_string((char *)"Display On!");
  ThisThread::sleep_for(10s);
  lcd_clear();
  printf("Custom Chars");
  char backslash[8] = {
      // \ backslash is not a standard character for lcd
      0b00000, 
      0b10000, 
      0b01000, 
      0b00100, 
      0b00010, 
      0b00001, 
      0b00000,
  };
  lcd_createChar(0, backslash);
  lcd_clear();
    lcd_send_string((char *) "Custom Chars");
    lcd_locate(0,1);
    lcd_send_data( 0 );
    sprintf(count, " is not std");
  lcd_send_string(count);

}
