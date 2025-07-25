#include <SPI.h>
#include <Wire.h>
#include <SD.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // Ancho de la pantalla OLED en píxeles
#define SCREEN_HEIGHT 64  // Altura de la pantalla OLED en píxeles

#define OLED_RESET -1        // Pin de reset de la OLED (-1 si no se usa)
#define SCREEN_ADDRESS 0x3C  // Dirección I2C de la pantalla OLED
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define CHIP_SELECT 4  // Pin para la tarjeta SD

#define CHANGE_ANIMATION 5
#define START_LISTEN 0

#define PIN_H_PERILLA A0
#define PIN_C_PERILLA A1
#define PIN_M_PERILLA A2
#define PIN_P_PERILLA A3

#define PIN_H_SEGUIMIENDO PIN_H_PERILLA
#define PIN_C_SEGUIMIENDO PIN_C_PERILLA
#define PIN_M_SEGUIMIENDO PIN_M_PERILLA
#define PIN_P_SEGUIMIENDO PIN_P_PERILLA

// Variables y constantes para mostrar GIFs
const char *gifFiles[8] = {
  "s", "b", "mn", "ml",
  "mgs", "ge", "mls", "e"
};
const unsigned int gifFramesCant[8] = { 2, 61, 60, 31, 101, 57, 57, 49 };
const unsigned int gifDelay[8] = { 478, 0, 0, 10, 0, 0, 0, 0 };

void showGifFromSD(unsigned int n, bool reset) {
  static int i = 0;
  static File imageFile;
  static unsigned char buffer[1024];  // Buffer exacto para una imagen de 128x64 píxeles

  if (reset) {
    i = 0;
    if (imageFile)  imageFile.close();  // Cerrar el archivo anterior si estaba abierto
    while(!(imageFile = SD.open(gifFiles[n], FILE_READ)));//Serial.println("Error al abrir el archivo: ");
  }

  display.clearDisplay();

  // Leer la siguiente imagen en el buffer de 1024 bytes
  if (imageFile.seek(i * 1024) && imageFile.read(buffer, 1024) == 1024) {
    display.drawBitmap(0, 0, buffer, 128, 64, 1);  // Dibujar la imagen desde el buffer
    display.display();
  } //else Serial.println("Error leyendo el archivo de imagen");

  i++;
  if (i >= gifFramesCant[n]) {
    i = 0;  // Reiniciar el índice si se alcanza el último cuadro
  }
  delay(gifDelay[n]);
}

#define PIN_H_PERILLA A0
#define PIN_C_PERILLA A1
#define PIN_M_PERILLA A2
#define PIN_P_PERILLA A3

#define PIN_H_SEGUIMIENDO PIN_H_PERILLA
#define PIN_C_SEGUIMIENDO PIN_C_PERILLA
#define PIN_M_SEGUIMIENDO PIN_M_PERILLA
#define PIN_P_SEGUIMIENDO PIN_P_PERILLA
void setup() {
  // Inicializar la pantalla OLED
  Serial.begin(9600);
  Wire.setClock(400000);  // 400 kHz
  Serial.println("Iniciando...");
  while (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  Serial.println("No se pudo iniciar la pantalla OLED");
  display.clearDisplay();
  display.display();
  pinMode(LED_BUILTIN, OUTPUT);
  // Inicializar la tarjeta SD
  while (!SD.begin(CHIP_SELECT))
  Serial.println("No se pudo inicializar la tarjeta SD");


  display.cp437(false);
  //showGifFromSD(1, true);  // Cambia el índice según el GIF que quieras probar
 
}

// Función para mostrar valores de potenciómetros como ángulo o porcentaje
#define PERCENTAGE 1
#define BAR_MAX_WIDTH_PERCENTAGE 55
#define ANGLE 0
#define BAR_MAX_WIDTH_ANGLE 60
#define MAX_POT_ANGLE 180
#define MIN_POT_VALUE 210
#define MAX_POT_VALUE 813

int mapSaturado(int value, int value_min, int value_max, int result_min, int result_max) {
  int result = map(value, value_min, value_max, result_min, result_max);
  return max(result_min, min(result, result_max));
}

void showPot(int potValues[4], bool mode) {
  const int labels[4] = { 'H', 'C', 'M', 'P' };
  display.clearDisplay();

  int yPosition = 0;
  char buffer[5];
  int width;

  for (int i = 0; i < 4; i++) {
    display.setCursor(0, yPosition);
    display.drawChar(0, yPosition, labels[i], WHITE, BLACK, 2);
    if (mode == ANGLE) {
      width = mapSaturado(potValues[i], MIN_POT_VALUE, MAX_POT_VALUE, 0, BAR_MAX_WIDTH_ANGLE);
      display.fillRect(20, yPosition, width, 12, WHITE);

      display.setCursor(82, yPosition);
      display.setTextColor(WHITE);
      display.setTextSize(2);
      int angle = mapSaturado(potValues[i], MIN_POT_VALUE, MAX_POT_VALUE, 0, MAX_POT_ANGLE);
      snprintf(buffer, 5, "%3d", angle);
      display.print(buffer);
      display.drawChar(118, yPosition, 0xF7, WHITE, BLACK, 2);
    } else {
      width = mapSaturado(potValues[i], MIN_POT_VALUE, MAX_POT_VALUE, 0, BAR_MAX_WIDTH_PERCENTAGE);
      display.fillRect(20, yPosition, width, 12, WHITE);

      display.setCursor(78, yPosition);
      display.setTextColor(WHITE);
      display.setTextSize(2);
      int percentage = mapSaturado(potValues[i], 0, MAX_POT_VALUE, 0, 100);
      snprintf(buffer, 5, "%3d%%", percentage);
      display.print(buffer);
    }
    yPosition += 16;
  }

  display.display();
}


void loop() {/*
  static int gifActual = -1;
  int gifSolicitado = 0;

  // Verificar si hay datos disponibles en Serial
  if (Serial.available() > 0) {
    gifSolicitado = Serial.read() - '0';  // Leer el índice como un número

    // Verificar que gifSolicitado esté en el rango válido
    if (gifSolicitado >= 0 && gifSolicitado < 7) {
      if (gifSolicitado != gifActual) {
        showGifFromSD(gifSolicitado, true);  // Cambiar a la nueva animación
        gifActual = gifSolicitado;           // Actualizar el índice actual
      }
    }
  }

  // Continuar mostrando el GIF actual
  if (gifActual != -1) {
    showGifFromSD(gifActual, false);
  }
  */

  showGifFromSD(0,true);
  /*
      int potValue[4];
      potValue[0] = analogRead(PIN_H_SEGUIMIENDO);
      potValue[1] = analogRead(PIN_C_SEGUIMIENDO);
      potValue[2] = analogRead(PIN_M_SEGUIMIENDO);
      potValue[3] = analogRead(PIN_P_SEGUIMIENDO);
      showPot(potValue, PERCENTAGE);
      */
}
