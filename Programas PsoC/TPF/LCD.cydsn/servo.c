//Definiciones
#include "project.h"
#include <stdio.h>

uint8_t askUpdateServo;
uint8_t askGetNumber;
#define MAX_BUFFER 100
char8 bufferTX[MAX_BUFFER];


#define SERVO_SENSIBILITY 5e-6
#define SERVO_FRECUENCY 50
#define ANGLE_MIN 0u
#define ANGLE_MAX 180u

#define PULSE_MIN 199u
#define PULSE_MAX 399u

#define MAX_PERIOD SERVO_SENSIBILITY*SERVO_FRECUENCY
#define CLOCK_PWM MAX_PERIOD/SERVO_FRECUENCY




// Usamos floats para mejorar la precisión
#define SLOPE_ANGLE_TO_PULSE ((double)(PULSE_MAX - PULSE_MIN) / (ANGLE_MAX - ANGLE_MIN))
#define OFFSET_ANGLE_TO_PULSE ((double)PULSE_MIN - SLOPE_ANGLE_TO_PULSE * ANGLE_MIN)

uint8_t angleToPulse(uint8_t angle){
    if (ANGLE_MIN > angle)
        return PULSE_MIN;
    if (angle > ANGLE_MAX)
        return PULSE_MAX;
    return (uint16_t)(SLOPE_ANGLE_TO_PULSE * angle + OFFSET_ANGLE_TO_PULSE);
}

// Definir el tipo de puntero a función que retorna void y toma un uint16_t como argumento
typedef void (*PWM_Write)(uint16_t);
// Crear un array de punteros a las funciones
//#define MAX_SERVO 4
//PWM_Write writeServo[MAX_SERVO] = {PWM1_WriteCompare1, PWM1_WriteCompare2, PWM2_WriteCompare1, PWM2_WriteCompare2};
//
//void updateServos()
//{
//    
//    for(uint8_t i = 0;i<MAX_SERVO;i++)
//    {
//        writeServo(angleToPulse());
//    }
//}