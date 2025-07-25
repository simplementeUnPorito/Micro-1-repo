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
#include <project.h>
#include "LiquidCrystal_I2C.h"

uint32_t Addr = 0x3F;

int main()
{
    I2C_Start();
    LiquidCrystal_I2C_init(Addr,20,4,0);
    begin();
    
    LCD_print("PSoC 4 Pioneer");
    setCursor(0,1);
    LCD_print("Primera fila");
    setCursor(0,2);
    LCD_print("Segunda fila");
    setCursor(0,3);
    LCD_print("Ultima Fila");
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
