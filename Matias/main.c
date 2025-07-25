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


char buff[20];  //Buffer de entrada.
int8 n;         //Grado mayor del polinomio. Para este trabajo, el maximo grado podra ser 9.
int32 coef[10]; //Vector de coeficientes del polinomio. Para este trabajo solo se tendra un maximo de 10 coeficientes.
int32 x, tot=0, term=0;     //x = punto a evaluar en el polinomio. tot = total. term = termino del polinomio.


void leeLinea (char *buf, int tamBuf) {     //Funcion que lee un linea por puerto serial.
    int i;
    uint8 c;
   
    for (i = 0; i < tamBuf -1; ) {
        if ((c = UART_PC_GetChar()) != 0){
            UART_PC_PutChar(c);
            if (c == '\r') break;   // salimos si recibimos un enter
            buf[i++] = c;
        }
    }
    buf[i] = '\0';
    UART_PC_PutChar('\n');
}



int32 potencia (int8 pot) {     //Funcion que calcula la potencia
    int8 i;
    int32 m;
    
    m = x;
    if(pot == 0){
        m = 1;
        return m;
    }
    if(pot == 1){
        return m;
    }
    for(i=1; i<pot; i++){
        m = m*x;
    }
    return m;
}


int main(void) {
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    int8 i;
    char linea[30];
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    UART_PC_Start();
    
    
    for(;;) {

        /* Place your application code here. */
        UART_PC_PutString("Grado del polinomio?\n\r");
        leeLinea(buff, 20);
        sscanf(buff, "%d", &n);
        while(n>10 || n<0){
            UART_PC_PutString("\nValor no valido para esta prueba, intente de nuevo: \n\r");
            leeLinea(buff, 20);
            sscanf(buff, "%d", &n);
        }
        
        for(i=n; i>-1; i--){
            sprintf(linea, "Coeficiente de x^%d?\n\r", i);
            UART_PC_PutString(linea);
            leeLinea(buff, 20);
            sscanf(buff, "%d", &coef[i]);
        }
        
        UART_PC_PutString("Punto a evaluar?\n\r");
        leeLinea(buff, 20);
        sscanf(buff, "%d", &x);
        while(x != -999){
            tot = 0;
            for(i=n; i>-1; i--){
                term = potencia(i);
                term = term * coef[i];
                tot = tot + term;
            }
            sprintf(linea, "p(%d) = %d\n\n\r", x, tot);
            UART_PC_PutString(linea);
            UART_PC_PutString("Punto a evaluar?\n\r");
            leeLinea(buff, 20);
            sscanf(buff, "%d", &x);
        }
        UART_PC_PutString("FIN\n\n\r");   
        
    }
    
}

/* [] END OF FILE */
