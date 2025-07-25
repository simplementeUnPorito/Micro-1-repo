#include <rgb_lcd.h>

#include <SPI.h>
#include <Wire.h>
#include <SD.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define CHIP_SELECT 4

// Definición de comandos de estado
#define START 0
#define BIENVENIDA 1
#define MENU 2
#define MODO_LEER 3
#define MODO_GUARDAR_SELECCION 4
#define MODO_GUARDAR_EEPROM 5
#define MODO_LEER_SELECCION 6
#define ERROR 7

#define ANGLE_PERILLA 8
#define ANGLE_3D 9
#define PERCENTAGE_PERILLA 10
#define PERCENTAGE_3D 11

// Variables y constantes para mostrar GIFs
const char *gifFiles[8] = {
  "s", "b", "mn", "ml",
  "mgs", "ge", "mls", "e"
};
const unsigned int gifFramesCant[8] = { 2, 61, 60, 31, 101, 57, 57, 49 };
const unsigned int gifDelay[8] = { 478, 0, 0, 10, 0, 0, 0, 0 };

int previousGif = -1;  // Guardar el estado anterior
int frameCounter = 0;  // Contador de frames para el modo ERROR

void showGifFromSD(unsigned int n, bool reset) {
  static int i = 0;
  static File imageFile;
  static unsigned char buffer[1024];  // Buffer exacto para una imagen de 128x64 píxeles

  if (reset) {
    i = 0;
    if (imageFile) imageFile.close();  // Cerrar el archivo anterior si estaba abierto
    while (!(imageFile = SD.open(gifFiles[n], FILE_READ)));  // Intentar abrir el archivo
    frameCounter = 0;  // Reiniciar contador de frames
  }

  display.clearDisplay();

  unsigned long offset = i * 1024;
  if (offset < imageFile.size() && imageFile.seek(offset) && imageFile.read(buffer, 1024) == 1024) {
    display.drawBitmap(0, 0, buffer, 128, 64, 1);  // Dibujar la imagen desde el buffer
    display.display();
  }

  i++;
  if (i >= gifFramesCant[n]) {
    i = 0;  // Reiniciar el índice si se alcanza el último cuadro
    frameCounter++;  // Incrementar contador de frames en el modo ERROR
  }
  delay(gifDelay[n]);

  // Si estamos en modo ERROR y hemos completado un ciclo de frames, regresar al estado anterior
  if (n == ERROR && frameCounter >= gifFramesCant[ERROR]) {
    frameCounter = 0;  // Reiniciar el contador
    showGifFromSD(previousGif, true);  // Regresar al estado anterior
  }
}

#define PERCENTAGE 1
#define BAR_MAX_WIDTH_PERCENTAGE 55
#define ANGLE 0
#define BAR_MAX_WIDTH_ANGLE 60
#define MAX_POT_ANGLE 180
#define MIN_POT_VALUE 210
#define MAX_POT_VALUE 813
#define THRESHOLD_PERCENT 2  // Umbral de cambio de 3%

int mapSaturado(int value, int value_min, int value_max, int result_min, int result_max) {
  int result = map(value, value_min, value_max, result_min, result_max);
  return max(result_min, min(result, result_max));
}
/*
version tratando de arreglar el ruido. no funco, ni idea de porqué xdnt
void showPot(int potValues[4], bool mode) {
  const int labels[4] = { 'B', 'C', 'M', 'P' };
  static int previous_values[4] = {0, 0, 0, 0};  // Almacena valores previos para el filtro
  display.clearDisplay();

  int yPosition = 0;
  char buffer[5];
  int width;

  for (int i = 0; i < 4; i++) {
    // Aplicar filtro de cambio mínimo del 3%
    int change = abs(potValues[i] - previous_values[i]);
    int threshold = (MAX_POT_VALUE - MIN_POT_VALUE) * THRESHOLD_PERCENT / 100;

    if (change > threshold) {
      previous_values[i] = potValues[i];  // Actualizar solo si el cambio es significativo
    }

    display.setCursor(0, yPosition);
    display.drawChar(0, yPosition, labels[i], WHITE, BLACK, 2);

    // Mostrar el valor como ángulo o porcentaje
    if (mode == ANGLE) {
      width = mapSaturado(previous_values[i], MIN_POT_VALUE, MAX_POT_VALUE, 0, BAR_MAX_WIDTH_ANGLE);
      display.fillRect(20, yPosition, width, 12, WHITE);

      display.setCursor(82, yPosition);
      display.setTextColor(WHITE);
      display.setTextSize(2);
      int angle = mapSaturado(previous_values[i], MIN_POT_VALUE, MAX_POT_VALUE, 0, MAX_POT_ANGLE);
      snprintf(buffer, 5, "%3d", angle);
      display.print(buffer);
      display.drawChar(118, yPosition, 0xF7, WHITE, BLACK, 2);  // ° symbol
    } else {
      width = mapSaturado(previous_values[i], MIN_POT_VALUE, MAX_POT_VALUE, 0, BAR_MAX_WIDTH_PERCENTAGE);
      display.fillRect(20, yPosition, width, 12, WHITE);

      display.setCursor(78, yPosition);
      display.setTextColor(WHITE);
      display.setTextSize(2);
      int percentage = mapSaturado(previous_values[i], 0, MAX_POT_VALUE, 0, 100);
      snprintf(buffer, 5, "%3d%%", percentage);
      display.print(buffer);
    }
    yPosition += 16;
  }

  display.display();
}*/

void showPot(int potValues[4], bool mode) {
  // Etiquetas para cada potenciómetro
  const int labels[4] = { 'B', 'C', 'M', 'P' };
  
  // Valores previos de los potenciómetros, inicializados como estáticos
  static int previous_values[4] = {0, 0, 0, 0};
  
  // Umbral estático calculado una sola vez
  static const int threshold = (MAX_POT_VALUE - MIN_POT_VALUE) * THRESHOLD_PERCENT / 100;

  display.clearDisplay();

  int yPosition = 0;
  char buffer[5];  // Buffer para almacenar los valores en texto
  int width;

  for (int i = 0; i < 4; i++) {
    // Calcular el cambio y verificar si es significativo
    int change = abs(potValues[i] - previous_values[i]);
    if (change > threshold) {
      previous_values[i] = potValues[i];  // Actualizar solo si el cambio es significativo
    }

    // Configurar la posición del cursor y mostrar la etiqueta
    display.setCursor(0, yPosition);
    display.drawChar(0, yPosition, labels[i], WHITE, BLACK, 2);

    // Mostrar el valor como ángulo o porcentaje
    if (mode == ANGLE) {
      width = mapSaturado(previous_values[i], MIN_POT_VALUE, MAX_POT_VALUE, 0, BAR_MAX_WIDTH_ANGLE);
      display.fillRect(20, yPosition, width, 12, WHITE);

      display.setCursor(82, yPosition);
      display.setTextColor(WHITE);
      display.setTextSize(2);
      int angle = mapSaturado(previous_values[i], MIN_POT_VALUE, MAX_POT_VALUE, 0, MAX_POT_ANGLE);
      snprintf(buffer, 5, "%3d", angle);
      display.print(buffer);
      display.drawChar(118, yPosition, 0xF7, WHITE, BLACK, 2);  // Símbolo de grados (°)
    } else {
      width = mapSaturado(previous_values[i], MIN_POT_VALUE, MAX_POT_VALUE, 0, BAR_MAX_WIDTH_PERCENTAGE);
      display.fillRect(20, yPosition, width, 12, WHITE);

      display.setCursor(78, yPosition);
      display.setTextColor(WHITE);
      display.setTextSize(2);
      int percentage = mapSaturado(previous_values[i], MIN_POT_VALUE, MAX_POT_VALUE, 0, 100);
      snprintf(buffer, 5, "%3d%%", percentage);
      display.print(buffer);
    }

    // Incrementar la posición vertical para el siguiente potenciómetro
    yPosition += 16;
  }

  // Actualizar la pantalla solo una vez al final
  display.display();
}


void setup() {
  Serial.begin(9600);
  Wire.setClock(400000);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    while (true);  // Detener si la OLED no se inicia correctamente
  }

  display.clearDisplay();
  display.display();
  pinMode(LED_BUILTIN, OUTPUT);

  if (!SD.begin(CHIP_SELECT)) {
    while (true);  // Detener si la tarjeta SD no se inicia correctamente
  }
  
  display.cp437(false);
}

#define PIN_H_PERILLA A0
#define PIN_C_PERILLA A3 //A1
#define PIN_M_PERILLA A1 //A2
#define PIN_P_PERILLA A2

#define PIN_H_SEGUIMIENDO PIN_H_PERILLA
#define PIN_C_SEGUIMIENDO PIN_C_PERILLA
#define PIN_M_SEGUIMIENDO PIN_M_PERILLA
#define PIN_P_SEGUIMIENDO PIN_P_PERILLA

#define CHANGE_ANIMATION 77
#define START_LISTEN 0

#define enRango(entrada) 0 <= entrada && entrada <= 11
int readBuffer(int entradaAnterior) {
  
  //Serial.println(String(digitalRead(B2)) + ","+ String(digitalRead(B1)) + "," + String(digitalRead(B0)) );
  Serial.write(START_LISTEN);
  for (int i = 0; i < 10 && !Serial.available(); i++)
    delay(10);
  int entrada = Serial.read();
  Serial.write(entrada);
  return enRango(entrada)?entrada:entradaAnterior;
  

  //Serial.flush();
}

void loop() {
    static int gifAnterior = -1;
    static int gifSolicitado = 0;
    static int contadorError = 0;
    static int preError;
    
    /*
    if (Serial.available() > 0) {
      if (Serial.read() == CHANGE_ANIMATION) {  // Verificar inicio de cambio
        gifSolicitado = readBuffer(gifAnterior);  // Leer la nueva animación
        digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));  // Alternar LED
      }
    }*/
    if(Serial.available()>0){
      int datoRecibido = Serial.read();
      Serial.write(datoRecibido);
      gifSolicitado = enRango(datoRecibido)?datoRecibido:gifSolicitado;
    }
    //gifSolicitado = 7;
    //Serial.println(gifSolicitado);
    int potValue[4];
    if(gifSolicitado == ERROR && contadorError == 49)
      gifSolicitado = preError;
    // Si cambia el botón presionado, mostrar la nueva imagen
    if (0 <= gifSolicitado && gifSolicitado <= 7){
      if (gifSolicitado != gifAnterior){
        showGifFromSD(gifSolicitado, true);
        if(gifSolicitado == ERROR)
          preError = gifAnterior;
          contadorError = 0;
      }
      else
        showGifFromSD(gifSolicitado, false);
      
    }
    else if (gifSolicitado == 8) {
      potValue[0] = analogRead(PIN_H_PERILLA);
      potValue[1] = analogRead(PIN_C_PERILLA);
      potValue[2] = analogRead(PIN_M_PERILLA);
      potValue[3] = analogRead(PIN_P_PERILLA);
      showPot(potValue, ANGLE);
    } else if (gifSolicitado == 9) {
      potValue[0] = analogRead(PIN_H_SEGUIMIENDO);
      potValue[1] = analogRead(PIN_C_SEGUIMIENDO);
      potValue[2] = analogRead(PIN_M_SEGUIMIENDO);
      potValue[3] = analogRead(PIN_P_SEGUIMIENDO);
      showPot(potValue, ANGLE);
    } else if (gifSolicitado == 10) {
      potValue[0] = analogRead(PIN_H_PERILLA);
      potValue[1] = analogRead(PIN_C_PERILLA);
      potValue[2] = analogRead(PIN_M_PERILLA);
      potValue[3] = analogRead(PIN_P_PERILLA);
      showPot(potValue, PERCENTAGE);
    } else if (gifSolicitado == 11) {
      potValue[0] = analogRead(PIN_H_SEGUIMIENDO);
      potValue[1] = analogRead(PIN_C_SEGUIMIENDO);
      potValue[2] = analogRead(PIN_M_SEGUIMIENDO);
      potValue[3] = analogRead(PIN_P_SEGUIMIENDO);
      showPot(potValue, PERCENTAGE);
    } else
      gifSolicitado = ERROR;
    gifAnterior = gifSolicitado;
    if(gifSolicitado == ERROR)
      contadorError++;
}
