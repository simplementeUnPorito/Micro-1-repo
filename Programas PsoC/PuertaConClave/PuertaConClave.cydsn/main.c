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
#include <stdio.h>

//char delta_timer = 0;


#define MAX_PASS 4
#define PASSWORD "1247"
#define PERIOD_PUERTA_ABIERTA 10000u
#define MAX_BUFFER 100
char buffer[MAX_BUFFER];

;
uint8_t tiempoAbierto;
union {
    uint8_t state;
    struct {
    uint8_t puertaDesbloqueada:1;
    uint8_t puertaAbierta:1;
    uint8_t alarma:1;
    }bit;
} info;



uint16_t button = 0;
volatile uint16_t buttonMain = 0;
CY_ISR(intDebouncer)
{
    button  = debouncer(keyboard_out_Write,keyboard_in_Read);
    if(button)
        buttonMain = button;
}



void interpretarTeclado(uint16_t b)
{
    static char password[MAX_PASS];
    static uint8_t i = 0;
    //char entrada;
    switch(b)
    {
        case KEY_0:
            password[i++] = '0';
            PC_PutChar('0');
            break;
        case KEY_1:
            password[i++] = '1';
            PC_PutChar('1');
            break;
        case KEY_2:
            password[i++] = '2';
            PC_PutChar('2');
            break;
        case KEY_3:
            password[i++] = '3';
            PC_PutChar('3');
            break;
        case KEY_4:
            password[i++] = '4';
            PC_PutChar('4');
            break;
        case KEY_5:
            password[i++] = '5';
            PC_PutChar('5');
            break;
        case KEY_6:
            password[i++] = '6';
            PC_PutChar('6');
            break;
        case KEY_7:
            password[i++] = '7';
            PC_PutChar('7');
            break;
        case KEY_8:
            password[i++] = '8';
            PC_PutChar('8');
            break;
        case KEY_9:
            password[i++] = '9';
            PC_PutChar('9');
            break;
        case ESC_KEY:
            if(i>0){
                i--;
                PC_PutChar('\b');
                PC_PutChar(' ');
                PC_PutChar('\b');
                
            }
            break;
        case ENTER_KEY:
            
            if(strncmp(PASSWORD,password,4) == 0)
            {
                info.bit.puertaDesbloqueada = 1;
                info.bit.alarma = 0;
                //timer_puertaAbierta_Enable();
                PC_PutStringConst("\n\rOK\n\r");
            }
            else{
                info.bit.alarma = 1;
                PC_PutStringConst("\n\rERROR\n\r");
            }
            password[0] = '\0';
            break;
        default:
            break;
           
        
        
    }
    if(i >= MAX_PASS)
        i = 0;
}



void prenderLeds()
{
    //snprintf(buffer,MAX_BUFFER,"%i\n\r",info.state);
    //PC_PutString(buffer);
    Led_Write(info.state&7);
    //snprintf(buffer,MAX_BUFFER,"%i\n\r",aux);
    //PC_PutString(buffer);
}

CY_ISR(finTimerAlarmaPuerta)
{
    if(info.bit.puertaAbierta)
        info.bit.alarma = 1;
    if(info.bit.puertaDesbloqueada&&!info.bit.puertaAbierta)
        info.bit.puertaDesbloqueada = 0;
}


CY_ISR(intentoAbrir)
{
    if(info.bit.puertaDesbloqueada)
        info.bit.puertaAbierta = 1;
    else
        info.bit.alarma = 1;
}

CY_ISR(cerrar)
{
    if(info.state == 7 || info.state == 3)//estaba abierto, capaz cona alarm
        info.state = 0;
    
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    info.state = 0;
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    timer_debouncer_Start();
    //Timer_256ms_EnableTriggerMode;
    int_debouncer_StartEx(intDebouncer);
    
    timer_puertaAbierta_WritePeriod(PERIOD_PUERTA_ABIERTA);
    timer_puertaAbierta_Start();
    int_puertaAbierta_StartEx(finTimerAlarmaPuerta);
    int_puertaAbierta_Enable();
    PC_Start();
    
    int_sensorON_Start();
    int_sensorON_StartEx(intentoAbrir);
    int_sensorON_Enable();
    
    int_sensorOFF_Start();
    int_sensorOFF_StartEx(cerrar);
    int_sensorOFF_Enable();
    
    for(;;)
    {
        
        if(buttonMain)
        {
            interpretarTeclado(buttonMain);
            buttonMain = 0;
        }
        prenderLeds();
    }
}

/* [] END OF FILE */
