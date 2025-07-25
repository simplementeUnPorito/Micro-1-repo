//Definiciones
#include "project.h"
#include <stdio.h>

uint8_t askUpdateServo;
uint8_t askGetNumber;
#define MAX_BUFFER 100
char8 bufferTX[MAX_BUFFER];


#define SERVO_SENSIBILITY 5e-6
#define SERVO_FRCUENCY 50
#define ANGLE_MIN 0u
#define ANGLE_MAX 180u

#define PULSE_MIN 199u
#define PULSE_MAX 399u

#define MAX_PERIOD SERVO_SENSIBILITY*SERVO_FRECUENCY
#define CLOCK_PWM MAX_PERIOD/SERVO_FRECUENCY




// Usamos floats para mejorar la precisión
#define SLOPE_ANGLE_TO_PULSE ((double)(PULSE_MAX - PULSE_MIN) / (ANGLE_MAX - ANGLE_MIN))
#define OFFSET_ANGLE_TO_PULSE ((double)PULSE_MIN - SLOPE_ANGLE_TO_PULSE * ANGLE_MIN)




uint16_t angleToPulse(uint8_t angle);
uint16 potBitsToPulse(uint16 bits);