/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "keyboard.h"
//#include "servo.h"

//Definiciones Logicas
#define TRUE  1
#define FALSE 0

#define POT_MAX 1

#define MAX_BUFFER 100
char buffer[MAX_BUFFER];
CY_ISR_PROTO(readPot);

#if defined (__GNUC__)
    asm(".global _printf_float");
#endif

uint16_t button = 0;
uint8_t conversionIsStarted = FALSE;
uint8_t conversionIsEnded = FALSE;

uint16 potBits[POT_MAX];
void myStart()
{
    PC_Start();
    PWM1_Start();
    PWM2_Start();
    I2C_LCD_Start();
    POT_Start();
    
    
    conversionIsStarted = FALSE;
    button = 0;
}

#define PULSE_MIN 99u
#define PULSE_MAX 399u
#define BITS_MIN (uint16_t)819
#define BITS_MAX (uint16_t)3276
// Asegúrate de que la división ocurra como doble precisión
#define SLOPE_BITS_TO_PULSE ((double)(PULSE_MAX - PULSE_MIN) / (double)(BITS_MAX - BITS_MIN))
// Corregir paréntesis de cierre y usar la constante correcta
#define OFFSET_BITS_TO_PULSE ((double)(PULSE_MIN - SLOPE_BITS_TO_PULSE * BITS_MIN))

uint16_t potBitsToPulse(uint16_t bits){
    if(BITS_MIN > bits)
        return PULSE_MIN;
    if(bits > BITS_MAX)
        return PULSE_MAX;
    return (uint16_t)(SLOPE_BITS_TO_PULSE * bits + OFFSET_BITS_TO_PULSE);
}

uint16_t bits_pot_value;
uint8_t testPot()
{
    uint8_t result = FALSE;
    if(!conversionIsStarted)
    {
       conversionIsStarted = TRUE;
       POT_StartConvert();
    }else if(POT_IsEndConversion(POT_RETURN_STATUS))
    {
        
//        for(uint8_t i = 0;i<POT_MAX;i++)
//            potBits[i] = POT_GetResult16(i);
        //PC_PutString("Leyendo potenciometro...\n\r");
        bits_pot_value = POT_GetResult16();
        //snprintf(buffer, MAX_BUFFER, "Valor bruto: %d\n\r", raw_value);
        //PC_PutString(buffer);
        //snprintf(buffer,MAX_BUFFER,"Valor = %i\n\r",potBits[0]);
        //PC_PutString(buffer);
        result = TRUE;
        conversionIsStarted = FALSE;
        
    }
    return result;
}


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    myStart();
    
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    for(;;)
    {
        //PC_PutString("XD");
        //button = debouncer(keyboard_out_Write,keyboard_in_Read);
        //echoButton(button,buffer, MAX_BUFFER, PC_PutString);
        if(testPot()){
            uint16_t aux = potBitsToPulse(bits_pot_value);
            PWM1_WriteCompare1(aux);
            snprintf(buffer,MAX_BUFFER,"%i\n\r",aux);
            PC_PutString(buffer);
        }
        
        CyDelay(20);
        
        
    }
}