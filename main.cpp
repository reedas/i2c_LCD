#include "i2cLCD.h"
#include "mbed.h"


i2cLCD lcd(0x7e, 16, 2);
// main() runs in its own thread in the OS
int main() {
  printf("LCD Test\r\n\n");
  char count[16];
  lcd.begin();
  lcd.clear();
  lcd.locate(0, 0);
  lcd.printString((char *)"Hello World!");
  lcd.locate(0, 1);
  for (int i = 0; i < 16; i++) {
    lcd.printString((char *)"*");
    ThisThread::sleep_for(100ms);
  }
  printf("Cursor Positioning\n\r");
  lcd.clear();
  lcd.noBacklight();
  lcd.locate(0, 1);
  lcd.printString((char *)"Count = ");
  ThisThread::sleep_for(1s);
  lcd.backlight();
  for (int i = 0; i < 256; i++) {
    lcd.locate(10 - (i >= 100) - (i >= 10), 1);
    sprintf(count, "%3d", i);
    lcd.printString(count);
    ThisThread::sleep_for(100ms);
  }

  ThisThread::sleep_for(10s);
  lcd.clear();
  printf("Cursor Changing\n\r");
  lcd.locate(0, 0);
  lcd.noBlink();
  lcd.locate(0, 1);
  lcd.printString((char *)"No Blink");
  lcd.backlight();
  ThisThread::sleep_for(10s);
  lcd.locate(0, 0);
  lcd.blink();
  lcd.locate(0, 1);
  lcd.printString((char *)"Blinking");

  ThisThread::sleep_for(10s);
  lcd.noBlink();
  lcd.locate(0, 0);
  lcd.noCursor();
  lcd.locate(0, 1);
  lcd.printString((char *)"No Cursor");
  ThisThread::sleep_for(10s);
  lcd.locate(0, 0);
  lcd.cursor();
  lcd.locate(0, 1);
  lcd.printString((char *)"Show Cursor>");

  ThisThread::sleep_for(10s);
  lcd.clear();
  printf("Display Control\r\n");
  lcd.locate(0, 0);
  lcd.printString((char *)"No Display");
  ThisThread::sleep_for(1s);
  lcd.noDisplay();
  ThisThread::sleep_for(1s);
  lcd.display();
  lcd.locate(0, 0);
  lcd.noCursor();
  lcd.noBlink();
  lcd.printString((char *)"Display On!");
  ThisThread::sleep_for(10s);
  lcd.clear();
  printf("Custom Chars\r\n");
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
  lcd.createChar(0, backslash);
  lcd.clear();
  lcd.printString((char *) "Custom Chars");
  lcd.locate(0,1);
  lcd.printChar( 0 );
  lcd.printString((char *)" is not std");
  ThisThread::sleep_for(1s);
  printf("complete\r\n\n");
  fflush(stdout);
}
