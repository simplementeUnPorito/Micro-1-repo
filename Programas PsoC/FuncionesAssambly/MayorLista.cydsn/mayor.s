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


    .syntax unified
    .text
/*
    Determina la dirección del mayor elemnto de un vector del tipo
    int32_t
    
    Parametros:
        R0->Dirección de inicio del vector
        R1->Cantidad de elementos del vector
    Return:
        R0->Dirección del elemento mayor
int32_t *mayor(int32_t v, uint16_t tam)
{
    int32_t* pm = v;
    for(int16_t i = 1, v++;i<tam;i++)
    {
        if(*v>*pm)
            pm = v;
        v++;
    }
    return pm;
}
*/

    .global mayor
    .func mayor, mayor
    .thumb_func
  
mayor:
    push {R4,R5}
    mov R2,#1 //la variable i
    mov R3,R0 //la variable pm
    add R0,#4 //apuntamos al segundo elemento de v
    mayor_mientras: cmp R2, R1 
    bhs mayor_fin_mientras //comparamos i con tam
        ldr R4, [R3] //*pm
        ldr R5, [R0] //*v
        cmp R5, R4   //*v comp *pm
        blt mayor_fin_si 
            mov R3, R0
        mayor_fin_si:
        add R0, #4
        add R2, #1
    b  mayor_mientras
    mayor_fin_mientras:
    pop {R4,R5}
    mov r0,r3 //guardamos el valor de retorno
    bx lr
    
    .endfunc
*/

    .end


/* [] END OF FILE */
