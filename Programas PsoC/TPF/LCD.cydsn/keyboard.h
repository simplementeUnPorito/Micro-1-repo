#include "project.h"
#include <stdio.h>

#define MAX_ROW_KB 5
#define MASK_ROW_KB 0x1F //b0001 1111
#define MAX_COLUMN_KB 4

// Definiciones para las teclas, según fila y columna
#define F1_KEY      0x11  
#define F2_KEY      0x12  
#define HASH_KEY    0x14  
#define STAR_KEY    0x18  
#define KEY_1       0x21
#define KEY_2       0x22
#define KEY_3       0x24
#define UP_ARROW    0x28
#define KEY_4       0x41
#define KEY_5       0x42
#define KEY_6       0x44
#define DOWN_ARROW  0x48
#define KEY_7       0x81
#define KEY_8       0x82
#define KEY_9       0x84
#define ESC_KEY     0x88
#define LEFT_ARROW  0x101
#define KEY_0       0x102
#define RIGHT_ARROW 0x104
#define ENTER_KEY   0x108

//typedef struct {
//    uint8_t row;    // Fila pasiva porque hay más
//    uint8_t column; // Columna pasiva porque hay menos
//} KeyPosition;
//
//KeyPosition decoderReadKeyboard(uint8_t code);
uint16_t readKeyboard(void (*write)(uint8_t), uint8_t (*read)(void));
uint16_t debouncer(void (*write)(uint8_t), uint8_t (*read)(void));
void echoButton(uint16_t b,char8* bufferTX, uint8 max, void (*putString)(const char8*));