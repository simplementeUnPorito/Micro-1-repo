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

#define TAM 10
int32_t* mayor(int32_t *,uint16_t);

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    int32_t vec[TAM] = {-1,2,-3,4,-5,4,3,2,1,0};
    int32_t *may;
    for(;;)
    {
        /* Place your application code here. */
        may = mayor(vec,TAM);
    }
}

/* [] END OF FILE */
