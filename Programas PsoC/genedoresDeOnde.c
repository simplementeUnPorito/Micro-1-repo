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

#include <stdint.h>
#include <math.h>


void generateSquareWave(uint8_t f, uint8_t D){
    DAC_SetValue(255);
    CyDelay(1000*D/(100*f));
    DAC_SetValue(0);
    CyDelay(1000*(100-D)/(100*f));
}

uint8_t generateTriangleWave(uint8_t f){
    static uint8_t point = 0;
    static uint8_t flag = 1;
    if(flag)
        point++;
    else
        point--;
    if(point == 255 || point == 0)
        flag = !flag;
    CyDelay(1000/(255*f));
    
    
    return point;
}


uint8_t generateSawToothWave(uint8_t f){
    static uint8_t point = 255;
    point++;
    
    CyDelay(1000/(255*f));
    
    
    return point;
}


uint8_t generateSineWave(uint8_t f){
    static uint8_t t = 0;
    
    uint8_t point = 255/2*(1+sin(2*M_PI*t/255));
    t++;
    CyDelay(1000/(255*f));
    
    
    return point;
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    DAC_Start();
    for(;;)
    {
        //generateSquareWave(100,50);
        DAC_SetValue(generateSineWave(100));
    }
}

/* [] END OF FILE */
