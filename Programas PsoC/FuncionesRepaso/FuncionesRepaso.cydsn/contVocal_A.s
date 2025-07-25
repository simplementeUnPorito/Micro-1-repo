
    .syntax unified
    .text

    .global contVocal_A
    .func contVocal_A, contVocal_A
    .thumb_func
contVocal_A:
    mov r1,#0 //N = 0 //N = 0
    
    contVocal_A_while:
    ldrb r2,[r0], #1   //letter = *v++
    cmp r2,#0
    beq contVocal_A_finwhile
        cmp r2,#65 //letter == A?
        beq contVocal_A_Sumar
        
        cmp r2,#97 //letter == a?
        beq contVocal_A_Sumar
        
        cmp r2,#69 //letter == E?
        beq contVocal_A_Sumar
        
        cmp r2,#101 //letter == e?
        beq contVocal_A_Sumar
        
        cmp r2,#73 //letter == I?
        beq contVocal_A_Sumar
        
        cmp r2,#105 //letter == i?
        beq contVocal_A_Sumar
        
        cmp r2,#79 //letter == O?
        beq contVocal_A_Sumar
    
        cmp r2,#111 //letter == o?
        beq contVocal_A_Sumar
        
        cmp r2,#85 //letter == U?
        beq contVocal_A_Sumar
        
        cmp r2,#117 //letter == u?
        beq contVocal_A_Sumar
    
        contVocal_A_no_Sumar:
            b contVocal_A_while
        contVocal_A_Sumar:
            add r1,#1
            b contVocal_A_while
    contVocal_A_finwhile:
    mov r0,r1
    bx lr
