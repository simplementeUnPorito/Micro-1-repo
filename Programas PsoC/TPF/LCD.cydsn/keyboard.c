#include <stdio.h>
#include "keyboard.h"



//KeyPosition decoderReadKeyboard(uint8_t code) {
//    KeyPosition activeKey;
//    uint8_t rowCode = code & MASK_ROW_KB, columnCode = code >> MAX_COLUMN_KB;
//
//    // Encontrar la posición de la fila activa
//    activeKey.row = 0;
//    while (rowCode >>= 1) activeKey.row++;
//
//    // Encontrar la posición de la columna activa
//    activeKey.column = 0;
//    while (columnCode >>= 1) activeKey.column++;
//    
//    return activeKey;
//}
uint16_t readKeyboard(void (*write)(uint8_t), uint8_t (*read)(void)) {
    uint8_t column, row;
    uint16_t result = 0;

    // Recorre todas las columnas (activas)
    for (column = (1 << (MAX_COLUMN_KB)); column > 0; column >>= 1) {
        write(column);  // Envía la señal activa (columna)

        // Si es necesario un delay para que el teclado se estabilice hay que ver
        // Cydelay(ALGO)???;

        row = read();  // Lee las filas pasivas
        if (row != 0) {  // Si alguna fila está activa (se detecta una tecla presionada)
            result = (column << (MAX_ROW_KB-1)) | row;  // Combina los bits de columna y fila
            break;  // Sale del ciclo si se detecta una pulsación
        }
    }

    return result;
}

uint16_t debouncer(void (*write)(uint8_t), uint8_t (*read)(void)){
    // Definir el enum
    enum myState {noInput, firstTime, secondTime, firstTimeOut};
    // Declarar una variable del tipo enum state
    static enum myState state = noInput;
    uint16_t filtredInput = 0, currentInputDetected;
    static uint16_t lastInputDetected;
    currentInputDetected = readKeyboard(write, read);
    switch(state)
    {
        case noInput:
            if(currentInputDetected){
                lastInputDetected = currentInputDetected;
                state = firstTime;
            }
            break;
        case firstTime:
            //falso positivo, fue solo ruido
            if(currentInputDetected == 0) 
                state = noInput;
            //señal constante, por lo tanto valida
            else if(currentInputDetected == lastInputDetected)
            {
                state = secondTime;
                filtredInput = lastInputDetected;
            }
            //2 botones pulsados seguidos, consideramos solo el ultimo
            else
                lastInputDetected = currentInputDetected;
                
            break;
        case secondTime:
            //boton dejo de pulsarse, pasamos a firstTimeOut
            if(currentInputDetected == 0){
                state = firstTimeOut;
            }
            //instantaneamente despues de la otra señal, pulsamos otro boton
            else if(lastInputDetected != currentInputDetected)
            {
                lastInputDetected = currentInputDetected;
                state = firstTime;
            }
            //si no hacemos nada, es que el boton aun no ha sido soltado
            break;
        case firstTimeOut:
            //boton dejo de pulsarse por 2 periodos, por lo que reiniciamos la maquina
            if(currentInputDetected == 0){
                state = noInput;
                lastInputDetected = 0;
            }
            //instantaneamente despues de la otra señal, pulsamos otro boton
            else if(lastInputDetected != currentInputDetected)
            {
                //filtredInput = lastInputDetected;
                lastInputDetected = currentInputDetected;
                state = firstTime;
            }
            //si es igual a lastInputDetected, fue un falso positivo de que se haya soltado
            //por lo que volvemos a secondTime
            else 
                state = secondTime;
            
            break;
        default:
            state = noInput;
    }
    return filtredInput;
}


void echoButton(uint16_t b,char8* bufferTX, uint8 max, void (*putString)(const char8*))
{
    
    switch(b)
    {
        case F1_KEY:
            snprintf(bufferTX,max,"F1 [COD:%x]\n\r",b);
            putString(bufferTX);
            break;
        case F2_KEY:
            //PC_PutString("F2\n\r");
            snprintf(bufferTX,max,"F2 [COD:%x]\n\r",b);
            putString(bufferTX);
            break;
        case HASH_KEY:
            snprintf(bufferTX,max,"# [COD:%x]\n\r",b);
            putString(bufferTX);
            //PC_PutString("#\n\r");
            break;
        case STAR_KEY:
            snprintf(bufferTX,max,"* [COD:%x]\n\r",b);
            putString(bufferTX);
            //PC_PutString("*\n\r");
            break;
        case KEY_0:
            snprintf(bufferTX,max,"0 [COD:%x]\n\r",b);
            putString(bufferTX);
            //PC_PutString("0\n\r");
            break;
        case KEY_1:
            snprintf(bufferTX,max,"1 [COD:%x]\n\r",b);
            putString(bufferTX);
            //PC_PutString("1\n\r");
            break;
        case KEY_2:
            snprintf(bufferTX,max,"2 [COD:%x]\n\r",b);
            PC_PutString(bufferTX);
            //PC_PutString("2\n\r");
            break;
        case KEY_3:
            snprintf(bufferTX,max,"3 [COD:%x]\n\r",b);
            putString(bufferTX);
            //PC_PutString("3\n\r");
            break;
        case KEY_4:
            snprintf(bufferTX,max,"4 [COD:%x]\n\r",b);
            putString(bufferTX);
            //PC_PutString("4\n\r");
            break;
        case KEY_5:
            snprintf(bufferTX,max,"5 [COD:%x]\n\r",b);
            putString(bufferTX);
            //PC_PutString("5\n\r");
            break;
        case KEY_6:
            snprintf(bufferTX,max,"6 [COD:%x]\n\r",b);
            putString(bufferTX);
            //PC_PutString("6\n\r");
            break;
        case KEY_7:
            snprintf(bufferTX,max,"7 [COD:%x]\n\r",b);
            putString(bufferTX);
            //PC_PutString("7\n\r");
            break;
        case KEY_8:
            snprintf(bufferTX,max,"8 [COD:%x]\n\r",b);
            putString(bufferTX);
            //PC_PutString("8\n\r");
            break;
        case KEY_9:
            snprintf(bufferTX,max,"9 [COD:%x]\n\r",b);
            putString(bufferTX);
            //PC_PutString("9\n\r");
            break;
        case UP_ARROW:
            snprintf(bufferTX,max,"Up [COD:%x]\n\r",b);
            putString(bufferTX);
            //PC_PutString("Up\n\r");
            break;
        case DOWN_ARROW:
            snprintf(bufferTX,max,"Down [COD:%x]\n\r",b);
            putString(bufferTX);
            //PC_PutString("Down\n\r");
            break;
        case RIGHT_ARROW:
            snprintf(bufferTX,max,"Right [COD:%x]\n\r",b);
            putString(bufferTX);
            //PC_PutString("Right\n\r");
            break;
        case LEFT_ARROW:
            snprintf(bufferTX,max,"Left [COD:%x]\n\r",b);
            putString(bufferTX);
            //PC_PutString("Left\n\r");
            break;
        case ESC_KEY:
            snprintf(bufferTX,max,"Esc [COD:%x]\n\r",b);
            putString(bufferTX);
            //PC_PutString("Esc\n\r");
            break;
        case ENTER_KEY:
            snprintf(bufferTX,max,"Enter [COD:%x]\n\r",b);
            putString(bufferTX);
            //PC_PutString("Enter\n\r");
            break;
        case 0:
            //PC_PutString("PitoPitoDorodito\n\r");
            break;
        default:
            snprintf(bufferTX,max,"ERROR [COD:%x]\n\r",b);
            putString(bufferTX);
            //PC_PutString("ERROR\n\r");
            break;
         
        
    }
}