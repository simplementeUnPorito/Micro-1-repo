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


extern u_int32_t fibonacciN_A(u_int16_t );



u_int32_t fibonacciN(u_int16_t N)
{
  if(N == 1 || N == 2)
    return 1;
    
  u_int32_t n1 = 1,n2 = 1,aux;
  for(u_int16_t i = 3; i<=N;i++)
  {
      aux = n1;
      n1 = n2;
      n2 = n2+aux;
  }
  return n2;
}

u_int16_t contVocal_A(char*);

u_int16_t contVocal(char *v)
{
    u_int16_t N = 0;
    char letter=*v++;
    while(letter!='\0')
    {
        switch(letter)
        {
            case 'a':case 'A':
            case 'e':case 'E':
            case 'i':case 'I':
            case 'o':case 'O':
            case 'u':case 'U':
                N++;
            default:
                break;
            
        }
        letter=*v++;
    }
    return N;
}

u_int32_t prime_A(u_int16_t N);

u_int32_t prime(u_int16_t N)
{
    if(N<=1) //verificamos caso trivial 1,0 y numeros negativos
        return 0;
    if(N == 2) //verificamos caso trivial 2
        return 1;
    else if(N%2 == 0) //verificamos si es impar, ya que 2 es el unico numero par primo
        return 0;
    u_int16_t limit = N>>1; //Un numero no puede ser multiplo de otro que sea mayor a su mitad
    for(u_int16_t i = 3;i<=limit;i+=2) //si no es multiplo de 2 no es de ningun numero par
        if(N%i == 0)
            return 0;
    return 1;
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
#define MAX 100
char buffer[MAX];


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    uint8_t n = 0,rc,ra;
 
    PC_Start();
    for(;;)
    {
        
        n = (uint8_t)getInt(buffer,MAX,"Ingrese el termino n de fibonacci que desea ver: ");
        
        rc =fibonacciN(n);
        ra = fibonacciN_A(n);
        snprintf(buffer,MAX,"Resultados:\n\r\ttC: %i\n\r\tA: %i\n\r",rc,ra);
        PC_PutString(buffer);
      
        
        n = (uint8_t)getInt(buffer,MAX,"Ingrese numero a verificar si es primo: ");
        rc =prime(n);
        ra = prime_A(n);
        snprintf(buffer,MAX,"Resultados:\n\r\ttC: %s\n\r\tA: %s\n\r",rc==1?"True":"False",ra==1?"True":"False");
        PC_PutString(buffer);
        
        
        
        PC_PutString("Ingrese cadena a contar las vocales: ");
        getLine(buffer,MAX,PC_GetChar,PC_PutChar);
        rc =contVocal(buffer);
        ra =contVocal_A(buffer);
        snprintf(buffer,MAX,"Resultados:\n\r\ttC: %i\n\r\tA: %i\n\r",rc,ra);
        PC_PutString(buffer);
        
        
        
        
    }
}

/* [] END OF FILE */
