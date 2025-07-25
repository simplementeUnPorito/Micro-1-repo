#include "project.h"
#include <stdio.h>
#include <string.h>  // Para usar strlen
#include "rgb_lcd.h"

// Definición del carácter personalizado (carita sonriente)
uint8_t smiley[8] = {
    0b00000,  // Línea 1
    0b01010,  // Línea 2
    0b01010,  // Línea 3
    0b00000,  // Línea 4
    0b10001,  // Línea 5
    0b01110,  // Línea 6
    0b00000,  // Línea 7
    0b00000   // Línea 8
};

int main(void) {
    CyGlobalIntEnable;  // Habilitar interrupciones globales

    // Inicializar el componente I2C
    I2C_LCD_Start();

    // Inicializar el LCD (16 columnas, 2 filas)
    LCD_begin(16, 2, LCD_5x8DOTS);

    // Limpiar la pantalla LCD antes de imprimir
    LCD_clear();

    // Crear el carácter personalizado en la ubicación 0 de CGRAM
    LCD_createChar(0, smiley);

    for(;;) {
        // 1. Desactivar autoscroll antes de escribir
        LCD_noAutoscroll();

        // 2. Mostrar un mensaje en la primera línea
        LCD_setCursor(0, 0);  // Asegurarse de que el cursor esté al principio
        char msg[] = "Hello, PSoC!";
        LCD_print(msg, strlen(msg));

        // 3. Mostrar el carácter personalizado en la segunda línea
        LCD_setCursor(0, 1);
        LCD_print("Smiley: ", 8);
        LCD_write(0);  // Mostrar la carita sonriente

        // 4. Esperar un poco antes de activar el autoscroll
        CyDelay(2000);  // Esperar 2 segundos

        // 5. Activar el autoscroll y mostrar un mensaje largo
        char scrollMsg[] = "Scroll --> My journey has come to an end.";
        
        LCD_autoscroll();
        
        // 6. Simular el autoscroll desplazando el mensaje largo
        for(uint8_t i = 0; i < 10; i++) {
            LCD_scrollDisplayLeft();  // Desplazar a la izquierda
            CyDelay(100);  // Esperar entre cada desplazamiento
        }
        for(uint8_t i = 0; i < 10; i++) {
            LCD_scrollDisplayRight();  // Desplazar a la izquierda
            CyDelay(100);  // Esperar entre cada desplazamiento
        }

        
         // 7. Activar y desactivar el parpadeo del cursor
        LCD_cursor();  // Mostrar el cursor
        CyDelay(1000);  // Esperar 1 segundo
        LCD_noCursor();  // Ocultar el cursor
        CyDelay(1000);  // Esperar 1 segundo

        // 8. Activar y desactivar el parpadeo del cursor
        LCD_blink();  // Activar el parpadeo del cursor
        CyDelay(1000);  // Esperar 1 segundo
        LCD_noBlink();  // Desactivar el parpadeo del cursor
        CyDelay(1000);  // Esperar 1 segundo

        // 8. Activar y desactivar el parpadeo del LED de la retroiluminación
        LCD_blinkLED();  // Activar el parpadeo del LED
        CyDelay(1000);  // Esperar 1 segundo
        LCD_noBlinkLED();  // Desactivar el parpadeo del LED
        CyDelay(1000);  // Esperar 1 segundo
        
        // 10. Desactivar el autoscroll y limpiar la pantalla para evitar sobreescribir
        LCD_noAutoscroll();
        LCD_clear();

        // 8. Cambiar el color del backlight en un ciclo
        LCD_setRGB(255, 0, 0);  // Cambiar el color a rojo
        CyDelay(100);          // Esperar 1 segundo

        LCD_setRGB(0, 255, 0);  // Cambiar el color a verde
        CyDelay(100);          // Esperar 1 segundo

        LCD_setRGB(0, 0, 255);  // Cambiar el color a azul
        CyDelay(100);          // Esperar 1 segundo

        LCD_setRGB(255, 255, 255);  // Cambiar el color a blanco
        CyDelay(100);              // Esperar 1 segundo
    }
}
