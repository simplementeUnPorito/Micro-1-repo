#include "project.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define MAX_BUFF 100
#define MAX_DEGREE 255
char buffer[MAX_BUFF];
u_int8_t degree;
int8_t coeficiente[MAX_DEGREE];
int16_t x;
int64_t result;

//FUNCIONES GENERALES

/*
Función que lee una línea por el puerto serial.
Parámetros:
    buf -> dirección del buffer de caracteres recibidos
    tamBuf -> cantidad de posiciones disponible en el buffer
    getchar -> función que lee un caracter del puerto UART
    putchar -> función que escribe un caracter por el puerto UART
Retorno:
    Ninguno
*/
void getLine (char *buf, int tamBuf, uint8_t (*getcharl)(), void (*putcharl)(uint8_t)) {
    int i;
    uint8 c;
   
    for (i = 0; i < tamBuf -1; ) {
        if ((c = getcharl()) != 0){
            putcharl(c);
            if (c == '\r') break;   // salimos si recibimos un enter
            buf[i++] = c;
        }
    }
    buf[i] = '\0';
    putcharl('\n');
}

int16_t getInt(char *buf,u_int max_buf)
{
    u_int8_t salir = 0;
    int16_t result = 0;
    do
    {
        getLine(buf,max_buf,PC_GetChar,PC_PutChar);
        //u_int16_t aux = strtoul(buf,NULL,10);
        salir = sscanf(buf,"%hd",&result);
    }while(salir != 1);
    buf[0] = '\0';
    return result;
}



//FUNCIONES PARA EL PROGRAMA 
void getDegree()
{
    u_int8_t salir = 0;
    do
    {   PC_PutString("Grado del polinomio?");
        degree = (u_int8_t)getInt(buffer,MAX_BUFF-1);
        if (0<= degree && degree<=MAX_DEGREE-1) //creo que no es necesario pero bueno
            salir = 1;    
    }while (salir != 0);
    
}

void getCoef()
{
    u_int8_t aux = 0;
    for(u_int8_t i = degree;;)
    {
        snprintf(buffer,MAX_BUFF ,"Coeficiente de x^%i?",i);
        PC_PutString(buffer);
        aux = (u_int8_t)getInt(buffer,MAX_BUFF);
        if(0 <= aux && aux <= MAX_DEGREE)
        {
            coeficiente[i] = aux;
            if(i == 0) break;
            else i--;
        }
    }
}

void evalX()
{
    do
    {
        PC_PutString("Punto a evaluar?");
        x = getInt(buffer,MAX_BUFF);
        if(x == -999) break; //salir de eval
        
        result = 0;
        for(u_int8_t i = degree;; i--)
        {
            result += coeficiente[i]*pow(x,i);
            if(i == 0) break;
        }
        
        
    }while(x != -999);
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    PC_Start();
    for(;;)
    {
        getDegree();
        getCoef();
        evalX();
    }
}

/* [] END OF FILE */
