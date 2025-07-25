#include "project.h"
#include <stdio.h>
#include <stdlib.h>


#define MAX_BUFF 100
#define MAX_DEGREE 255
char buffer[MAX_BUFF];
char question[MAX_BUFF];
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

int16_t getInt(char *buf,u_int max_buf,char *msg)
{
    u_int8_t salir = 0;
    int16_t result = 0;
    do
    {
        PC_PutString(msg);
        getLine(buf,max_buf,PC_GetChar,PC_PutChar);
        //u_int16_t aux = strtoul(buf,NULL,10);
        (salir = sscanf(buf,"%hd",&result))?:PC_PutString("Error, valor ingresado no entero\r\n");
    }while(salir != 1);
    buf[0] = '\0';
    return result;
}
int64_t power (int16_t x,uint8_t n) {     //Funcion que calcula la potencia
    
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return x;
    }
    int64_t result = x;
    for(uint8_t i=1; i<n; i++){
        result*= x;
    }
    return result;
}


//FUNCIONES PARA EL PROGRAMA 
void getDegree()
{
    u_int8_t salir = 0;
    do
    {   
        degree = (u_int8_t)getInt(buffer,MAX_BUFF-1,"Grado del polinomio?\r\nGrado = ");
        if (0<= degree && degree<=MAX_DEGREE-1) //creo que no es necesario pero bueno
            salir = 1;
        else
            PC_PutString("Error, valor ingresado no valido");
    }while (salir != 1);
    
}

void getCoef()
{
    u_int8_t aux = 0;
    for(u_int8_t i = degree;;)
    {
        snprintf(question,MAX_BUFF ,"Coeficiente de x^%i?\r\nC_%i = ",i,i);
        aux = (u_int8_t)getInt(buffer,MAX_BUFF,question);
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
        x = getInt(buffer,MAX_BUFF,"Punto a evaluar?\r\nx = ");
        if(x == -999) break; //salir de eval
        
        result = 0;
        for(u_int8_t i = degree;; i--)
        {
            result += coeficiente[i]*power(x,i);
            if(i == 0) break;
        }
        snprintf(buffer,MAX_BUFF ,"f(%i) = %i\r\n",x,(int)result);
        PC_PutString(buffer);
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
