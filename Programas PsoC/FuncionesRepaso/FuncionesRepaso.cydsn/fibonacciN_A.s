

    .syntax unified
    .text


    .global fibonacciN_A
    .func fibonacciN_A, fibonacciN_A
    .thumb_func
fibonacciN_A:
    cmp R0, #2 //N comp 2
    bhi fibonacciN_A_Not_1
    //fibonacciN_A_return_1:
        mov R0, #1
        b fibonacciN_A_fin
    fibonacciN_A_Not_1:
        mov r1, #1 //n1 = 1
        mov r2, #1 //n2 = 1
        mov r3, #3 //i = 3
        fibonacciN_A_loop:
            cmp r3,r0 //i<=N -->i>N
            bgt fibonacciN_A_r2
            mov r12,r1 //aux = n1
            mov r1,r2  //n1 = n2
            add r2,r12 //n2 = r2
            add r3,#1
            b fibonacciN_A_loop
    fibonacciN_A_r2:
        mov r0,r2
    fibonacciN_A_fin:
        BX lr
