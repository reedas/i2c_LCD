#include "mbed.h"
#include "i2cLCD.h"

// Function Prototypes
void writeCommand(uint8_t command);
void writeData(uint8_t data) ;
void writeLowNibble( uint8_t highNibble) ;
void writeHighNibble( uint8_t lowNibble) ;
void pulseEnable( void ) ;
void writeStr( char * textStr) ;
void cls( void ) ;
void locate( uint8_t row, uint8_t column ) ;
void init( void ) ;

//

I2C i2c(I2C_SDA, I2C_SCL);

// Functions

void writeCommand(uint8_t command) {
    writeLowNibble(command & 0x0f);
    writeHighNibble((command >> 4) & 0x0f);
}
void writeData(uint8_t data) {
    writeLowNibble(data&0x0f);
    writeHighNibble((data >> 4) & 0x0f);
}
void writeLowNibble( uint8_t highNibble) {

}
void writeHighNibble( uint8_t lowNibble) {

}
void pulseEnable( void ) {

}
void writeStr( char * textStr) {

}
void cls( void ) {

}
void locate( uint8_t row, uint8_t column ) {

}
void init( void ) {

}
// main() runs in its own thread in the OS
int main()
{
    while (true) {
        i2c.
    }
}

