

    .syntax unified
    .text

    .global prime_A
    .func prime_A, prime_A
    .thumb_func
prime_A:
    cmp r0,#1 //es N igual o menor a 1?
    bls prime_A_not
    cmp r0,#2 //es N igual a 2?
    beq prime_A_yes
    //ands r3,r0,#1 //es N par? 
    tst r0,#1 //TST hacia lo mismo hace un and sin guardar
    beq prime_A_not
    
    mov r1,r0
    lsr r1,#1 //r1 = N/2 = limit
    mov r2,#3 //i = 3
    prime_A_loop:
        
    
        udiv r3,r0,r2 //r3=N/i
        umull r3,r12,r3,r2 //r3=r3*r2 = (N/i)*i = N, descartamos R12
        cmp r0,r3 //Resto = r0-r3
        beq prime_A_not //si el resto es 0 es divisible
        add r2,#2 
        
        cmp r2, r1
        bls prime_A_loop //aun no llegamos a limit
        /*si no, terminamos el loop sin encontrar
        ningun multiplo, por lo qu es primo*/
    prime_A_yes:
        mov r0,#1
        b prime_A_fin
    prime_A_not:
        mov r0,#0
    prime_A_fin:
        BX lr
 
