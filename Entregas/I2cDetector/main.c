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
#include <stdio.h>

int detectarEsclavosI2C(uint8 (*sendStart)(uint8,uint8),uint8 (*sendStop)(void),uint8_t *slaves,uint8 xfer,uint8 noError)
{  
    int result = 0;
    for(uint8_t address = 0;address<=127;address++)
    {
        if(sendStart(address,xfer) ==noError){
            slaves[address] = 1;
            result = 1;
        }
            
        else
            slaves[address] = 0;
        sendStop();
    }
    return result;
}
char buffer[100];
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    I2C_Start();
    PC_Start();
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    uint8_t esclavosDetectados[127];
    for(;;)
    {
        uint8_t  result =detectarEsclavosI2C(I2C_MasterSendStart,I2C_MasterSendStop,esclavosDetectados,I2C_WRITE_XFER_MODE,I2C_MSTR_NO_ERROR);
        if(result){
        PC_PutStringConst("Esclavo(s) detectado(s):");
            for(uint8_t i = 0;i<=127;i++){ 
                if(esclavosDetectados[i] == 1){
                    snprintf(buffer,100,"%x,",i);
                    PC_PutString(buffer);
                }
            }
            PC_PutStringConst("\b \n\r");
            /*
            PC_PutChar('\b');
            PC_PutChar(' ');
            PC_PutChar('\n');
            PC_PutChar('\r');
            */
        }
   
        
    }
}

/* [] END OF FILE */
