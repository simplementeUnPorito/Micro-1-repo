#include "rgb_lcd.h"
#include "project.h"

uint8_t _displayfunction;
uint8_t _displaycontrol;
uint8_t _displaymode;
uint8_t _numlines;
uint8_t _currline;

uint8_t rgb_chip_addr; // Declaración global de rgb_chip_addr

// Inicialización del LCD
void LCD_begin(uint8_t cols, uint8_t rows, uint8_t charsize) {
    if (rows > 1) {
        _displayfunction |= LCD_2LINE;
    }
    _numlines = rows;
    _currline = 0;

    I2C_LCD_Start();

    CyDelay(50);

    LCD_command(LCD_FUNCTIONSET | _displayfunction);
    CyDelay(5);
    LCD_command(LCD_FUNCTIONSET | _displayfunction);
    CyDelay(1);
    LCD_command(LCD_FUNCTIONSET | _displayfunction);

    _displaycontrol = LCD_DISPLAYON | LCD_CURSOROFF | LCD_BLINKOFF;
    LCD_display();

    LCD_clear();
    _displaymode = LCD_ENTRYLEFT | LCD_ENTRYSHIFTDECREMENT;
    LCD_command(LCD_ENTRYMODESET | _displaymode);

    LCD_setReg(0x00, 0x00);
    LCD_setReg(0x01, 0x00);
    LCD_setReg(0x08, 0xAA);
}

// Enviar comando al LCD
void LCD_command(uint8_t value) {
    uint8_t data[2] = {0x80, value};
    i2c_send_byteS(data, 2);
}

// Escribir un valor en el LCD
void LCD_write(uint8_t value) {
    uint8_t data[2] = {0x40, value};
    i2c_send_byteS(data, 2);
}

// Limpiar la pantalla del LCD
void LCD_clear() {
    LCD_command(LCD_CLEARDISPLAY);
    CyDelay(2);
}

// Configurar el cursor
void LCD_setCursor(uint8_t col, uint8_t row) {
    col = (row == 0 ? col | 0x80 : col | 0xc0);
    uint8_t data[2] = {0x80, col};
    i2c_send_byteS(data, 2);
}

// Activar el display
void LCD_display() {
    _displaycontrol |= LCD_DISPLAYON;
    LCD_command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// Apagar el display
void LCD_noDisplay() {
    _displaycontrol &= ~LCD_DISPLAYON;
    LCD_command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// Imprimir texto en el LCD
void LCD_print(char* data, uint8_t size) {
    for (uint8_t i = 0; i < size; i++) {
        LCD_write(data[i]);
    }
}

// Controlar el color del backlight RGB
void LCD_setRGB(unsigned char r, unsigned char g, unsigned char b) {
    LCD_setReg(REG_RED, r);
    LCD_setReg(REG_GREEN, g);
    LCD_setReg(REG_BLUE, b);
}

// Enviar datos al backlight
void LCD_setReg(unsigned char addr, unsigned char dta) {
    uint8_t buffer[2] = {addr, dta};
    I2C_LCD_MasterWriteBuf(I2C_RGB_ADDR >> 1, buffer, 2, I2C_LCD_MODE_COMPLETE_XFER);
    while (I2C_LCD_MasterStatus() & I2C_LCD_MSTAT_XFER_INP);
}

// Enviar datos a través de I2C
void i2c_send_byteS(unsigned char* dta, unsigned char len) {
    I2C_LCD_MasterWriteBuf(I2C_LCD_ADDR >> 1, dta, len, I2C_LCD_MODE_COMPLETE_XFER);
    while (I2C_LCD_MasterStatus() & I2C_LCD_MSTAT_XFER_INP);
}

void LCD_createChar(uint8_t location, uint8_t charmap[]) {
    location &= 0x7; // Solo tenemos 8 ubicaciones 0-7 en CGRAM
    LCD_command(LCD_SETCGRAMADDR | (location << 3));

    uint8_t data[9];
    data[0] = 0x40;  // Definir la dirección para los datos
    for (int i = 0; i < 8; i++) {
        data[i + 1] = charmap[i];
    }
    i2c_send_byteS(data, 9);
}

// Habilitar el autodesplazamiento (justificar a la derecha)
void LCD_autoscroll(void) {
    _displaymode |= LCD_ENTRYSHIFTINCREMENT;
    LCD_command(LCD_ENTRYMODESET | _displaymode);
}

// Deshabilitar el autodesplazamiento (justificar a la izquierda)
void LCD_noAutoscroll(void) {
    _displaymode &= ~LCD_ENTRYSHIFTINCREMENT;
    LCD_command(LCD_ENTRYMODESET | _displaymode);
}


// Desplazar el contenido de la pantalla a la izquierda sin cambiar la RAM
void LCD_scrollDisplayLeft(void) {
    LCD_command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVELEFT);
}

// Desplazar el contenido de la pantalla a la derecha sin cambiar la RAM
void LCD_scrollDisplayRight(void) {
    LCD_command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVERIGHT);
}

// Configurar la dirección del texto de izquierda a derecha
void LCD_leftToRight(void) {
    _displaymode |= LCD_ENTRYLEFT;
    LCD_command(LCD_ENTRYMODESET | _displaymode);
}

// Configurar la dirección del texto de derecha a izquierda
void LCD_rightToLeft(void) {
    _displaymode &= ~LCD_ENTRYLEFT;
    LCD_command(LCD_ENTRYMODESET | _displaymode);
}

void LCD_blinkLED(void) {
    if (rgb_chip_addr == RGB_ADDRESS_V5) {
        // Adjuntar todos los LED a pwm1
        // El período de parpadeo en segundos = (<reg 1> + 2) * 0.128s
        // Relación encendido/apagado del pwm1 = <reg 2> / 256
        LCD_setReg(0x04, 0x2a);  // 0010 1010
        LCD_setReg(0x01, 0x06);  // parpadeo cada segundo
        LCD_setReg(0x02, 0x7f);  // encendido la mitad del tiempo, apagado la otra mitad
    } else {
        // El período de parpadeo en segundos = (<reg 7> + 1) / 24
        // Relación encendido/apagado = <reg 6> / 256
        LCD_setReg(0x07, 0x17);  // parpadeo cada segundo
        LCD_setReg(0x06, 0x7f);  // encendido la mitad del tiempo, apagado la otra mitad
    }
}

// Desactivar el parpadeo del LED de la retroiluminación
void LCD_noBlinkLED(void) {
    if (rgb_chip_addr == RGB_ADDRESS_V5) {
        LCD_setReg(0x04, 0x15);  // 0001 0101
    } else {
        LCD_setReg(0x07, 0x00);  // Desactivar el parpadeo
        LCD_setReg(0x06, 0xff);  // Encendido total
    }
}
// Ocultar el cursor
void LCD_noCursor(void) {
    _displaycontrol &= ~LCD_CURSORON;
    LCD_command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// Mostrar el cursor
void LCD_cursor(void) {
    _displaycontrol |= LCD_CURSORON;
    LCD_command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// Apagar el parpadeo del cursor
void LCD_noBlink(void) {
    _displaycontrol &= ~LCD_BLINKON;
    LCD_command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// Encender el parpadeo del cursor
void LCD_blink(void) {
    _displaycontrol |= LCD_BLINKON;
    LCD_command(LCD_DISPLAYCONTROL | _displaycontrol);
}