#ifndef RGB_LCD_H
#define RGB_LCD_H

#include "project.h"

// Device I2C Address
#define I2C_RGB_ADDR  0xC4  // Dirección del controlador RGB
#define I2C_LCD_ADDR  0x7C  // Dirección del LCD

// Control del cursor y desplazamiento
#define LCD_DISPLAYMOVE 0x08
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// Color define
#define WHITE 0
#define RED 1
#define GREEN 2
#define BLUE 3

// Registro de control para el controlador RGB
#define REG_RED 0x04
#define REG_GREEN 0x03
#define REG_BLUE 0x02

#define REG_MODE1 0x00
#define REG_MODE2 0x01
#define REG_OUTPUT 0x08

// Commands for LCD
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// Flags for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// Flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// Flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

#define RGB_ADDRESS 0xC4
#define RGB_ADDRESS_V5 0x30

// Variables globales necesarias para el manejo del RGB
extern uint8_t rgb_chip_addr;

    
void LCD_begin(uint8_t cols, uint8_t rows, uint8_t charsize);
void LCD_write(uint8_t value);
void i2c_send_byteS(uint8_t* data, uint8_t length);
void LCD_setCursor(uint8_t col, uint8_t row);
void LCD_print(char* data, uint8_t size);
void LCD_display(void);
void LCD_noDisplay();
void LCD_clear(void);
void LCD_setRGB(unsigned char r, unsigned char g, unsigned char b);
void LCD_command(uint8_t value);
void LCD_setReg(unsigned char reg, unsigned char dat);
void LCD_noCursor(void);
void LCD_cursor(void);
void LCD_noBlink(void);
void LCD_blink(void);
void LCD_scrollDisplayLeft(void);
void LCD_scrollDisplayRight(void);
void LCD_leftToRight(void);
void LCD_rightToLeft(void);
void LCD_autoscroll(void);
void LCD_noAutoscroll(void);
void LCD_createChar(uint8_t location, uint8_t charmap[]) ;
void LCD_createCharFromProgmem(uint8_t location, const uint8_t *charmap);
void LCD_blinkLED(void);
void LCD_noBlinkLED(void);
void LCD_setPWM(unsigned char color, unsigned char pwm);
void LCD_setColor(unsigned char color);
#endif // RGB_LCD_H
