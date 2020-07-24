#include "mbed.h"
#include "i2cLCD.h"

// main() runs in its own thread in the OS
int main()
{
    char count[16];
    lcd_begin();
    lcd_clear();
    lcd_send_cmd(LCD_LINE1);
    lcd_send_string((char *)"Hello World!");
    lcd_send_cmd(LCD_LINE2);
    for(int i = 0; i < 16; i++) {
        lcd_send_string((char *)"*");
        ThisThread::sleep_for(100ms);
    }
    lcd_noBacklight();
    lcd_locate(0,1);
    lcd_send_string((char *)"Count = ");
    for(int i = 0; i < 256; i++) {
        lcd_locate(10,1);
        sprintf(count, "%3d", i);
        lcd_send_string(count);
    }
    lcd_backlight();
    ThisThread::sleep_for(10s);
    lcd_locate(0,0);
    lcd_noBlink();
    lcd_locate(0,1);
    lcd_send_string((char *)"No Blink");
    lcd_backlight();
    ThisThread::sleep_for(10s);
    lcd_locate(0,0);
    lcd_blink();
    lcd_locate(0,1);
    lcd_send_string((char *)"Blink");

    ThisThread::sleep_for(10s);
    lcd_locate(0,0);
    lcd_noCursor();
    lcd_locate(0,1);
    lcd_send_string((char *)"No Cursor");
    ThisThread::sleep_for(10s);
    lcd_locate(0,0);
    lcd_cursor();
    lcd_locate(0,1);
    lcd_send_string((char *)"Cursor  ");

    ThisThread::sleep_for(10s);
    lcd_locate(0,0);
    lcd_noDisplay();
    lcd_locate(0,1);
    lcd_send_string((char *)"No Display");
    ThisThread::sleep_for(10s);

    lcd_display();
    lcd_locate(0,0);
    lcd_cursor();
    lcd_noBlink();
    lcd_locate(0,1);
    lcd_send_string((char *)"Display On!");
    ThisThread::sleep_for(10s);




}

