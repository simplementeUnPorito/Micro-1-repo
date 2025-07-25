#include <SPI.h>
#include <Wire.h>
#include <SD.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // Ancho de la pantalla OLED en píxeles
#define SCREEN_HEIGHT 64 // Altura de la pantalla OLED en píxeles

#define OLED_RESET     -1 // Pin de reset de la OLED (-1 si no se usa)
#define SCREEN_ADDRESS 0x3C // Dirección I2C de la pantalla OLED
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define B0 2
#define B1 3
#define B2 4

#define PIN_H_PERILLA A0
#define PIN_C_PERILLA A1
#define PIN_M_PERILLA A2
#define PIN_P_PERILLA A3

#define PIN_H_SEGUIMIENDO PIN_H_PERILLA
#define PIN_C_SEGUIMIENDO PIN_C_PERILLA
#define PIN_M_SEGUIMIENDO PIN_M_PERILLA
#define PIN_P_SEGUIMIENDO PIN_P_PERILLA


#define CHIP_SELECT 10  // Pin para la tarjeta SD




void setup() {
  //Serial.begin(9600);

  // Inicializar la pantalla OLED
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
  
  display.clearDisplay();
  display.display();
  
  // Inicializar la tarjeta SD
  for(int i = 0;!SD.begin(CHIP_SELECT)&&i<10;i++);
  
  // Configurar los pines digitales con resistencias de pull-up
  pinMode(B0, INPUT_PULLUP);
  pinMode(B1, INPUT_PULLUP);
  pinMode(B2, INPUT_PULLUP);
  
  display.cp437(false);
  //Serial.println("inicializado");
}


// Leer el estado de los botones
int readBuffer() {
  //Serial.println(String(digitalRead(B2)) + ","+ String(digitalRead(B1)) + "," + String(digitalRead(B0)) );
  return (digitalRead(B2) << 2) | (digitalRead(B1) << 1) | digitalRead(B0);
}



// Mostrar el GIF correspondiente en la pantalla OLED

void showGifFromSD(unsigned int n,bool reset) {
  // Definir los archivos de imagen
  const char *gifFiles[8] PROGMEM  = {
    "start.bin", "error.bin","error.bin", "error.bin",
    "error.bin", "error.bin", "error.bin", "error.bin"
  };
  const unsigned int gifFramesCant[8] PROGMEM = {
    2,49,49,49,
    2,49,49,49
  };
  const unsigned int gifDelay[8] PROGMEM  = {
    500,20,20,20,
    20,20,20,20
  };
  static int i = 0;
  static File imageFile;
  unsigned char buffer[1024];  // Buffer para una línea de la imagen (128 píxeles)
  if(reset){
    i = 0;
    while(!(imageFile = SD.open(gifFiles[n],FILE_READ)));
  }
  display.clearDisplay();
  imageFile.seek(i*1024);
  imageFile.readBytes(buffer,1024);
  display.drawBitmap(0,0,buffer,128,64, 1);
  display.display();
  i++;
  if(i>=gifFramesCant[n])
    i = 0;
  delay(gifDelay[n]);
  
}
#define PERCENTAGE 1
#define BAR_MAX_WIDTH_PERCENTAGE 55
#define ANGLE 0
#define BAR_MAX_WIDTH_ANGLE 60 //valor maximo para la barra
#define MAX_POT_ANGLE 180
#define MIN_POT_VALUE 210 //quitandole valores iniciales no lineales
#define MAX_POT_VALUE 813 //quitandole valores finales no lineales

int mapSaturado(int value,int value_min, int value_max,int result_min,int result_max){
  int result = map(value,value_min,value_max,result_min,result_max);
  Serial.println(result);
  if(result <result_min)
    return result_min;
  if(result_max<result)
    return result_max;
  return result;
}
void showPot(int potValues[4],bool mode) {
  const int labels[4] PROGMEM = {0x48, 0x43, 0x4d, 0x50};
  display.clearDisplay();

  int yPosition = 0;
  char buffer[5];
  //obtener el porcentaje de barra que esta llena
  
  int width;
  for (int i = 0; i < 4; i++) {
    display.setCursor(0, yPosition);
    display.drawChar(0,yPosition,labels[i],WHITE,BLACK,2);
    if(mode == ANGLE){
    
  
      // dibujar barra
      width = mapSaturado(potValues[i],MIN_POT_VALUE,MAX_POT_VALUE,0,BAR_MAX_WIDTH_ANGLE);
      display.fillRect(20, yPosition,width, 12, WHITE);

      // saltar a posicion arbitaria e imprimir angulo
      display.setCursor(82, yPosition);
      display.setTextColor(WHITE);
      display.setTextSize(2);
      //obtener el angulo desplazado
      int angle = mapSaturado(potValues[i],MIN_POT_VALUE,MAX_POT_VALUE,0,MAX_POT_ANGLE);
      snprintf(buffer,5,"%3d",angle);
      display.print(buffer);
      display.drawChar(118,yPosition,0xF7,WHITE,BLACK,2);
    }
    else
    {
      width = mapSaturado(potValues[i],MIN_POT_VALUE,MAX_POT_VALUE,0,BAR_MAX_WIDTH_PERCENTAGE);
      display.fillRect(20, yPosition,width, 12, WHITE);

      // saltar a posicion arbitaria e imprimir porcentaje
      display.setCursor(78, yPosition);
      display.setTextColor(WHITE);
      display.setTextSize(2);
      int percentage = mapSaturado(potValues[i], 0, MAX_POT_VALUE, 0, 100);
      snprintf(buffer,5,"%3d",percentage);
      buffer[3] = '%';
      buffer[4] = '\0';
      display.print(buffer);
      
    }

    // saltamos 16 columnas
    yPosition += 16;
  }

  display.display();
}

void loop() {
  
  // Leer el estado de los pines y determinar qué imagen mostrar
  static int gifAnterior = -1;
  int gifSolicitado;
  gifSolicitado = readBuffer();
  //gifSolicitado = 7;
  //Serial.println(gifSolicitado);
  int potValue[4];
  // Si cambia el botón presionado, mostrar la nueva imagen
  if(0<=gifSolicitado && gifSolicitado<=2)
    if (gifSolicitado != gifAnterior) 
      showGifFromSD(gifSolicitado,true);
    else
      showGifFromSD(gifSolicitado,false);
  else if(gifSolicitado == 4){
    potValue[0] = analogRead(PIN_H_SEGUIMIENDO);
    potValue[1] = analogRead(PIN_C_SEGUIMIENDO);
    potValue[2] = analogRead(PIN_M_SEGUIMIENDO);
    potValue[3] = analogRead(PIN_P_SEGUIMIENDO);
    showPot(potValue,ANGLE);
  }
  else if(gifSolicitado == 5)
  {
    potValue[0] = analogRead(PIN_H_SEGUIMIENDO);
    potValue[1] = analogRead(PIN_C_SEGUIMIENDO);
    potValue[2] = analogRead(PIN_M_SEGUIMIENDO);
    potValue[3] = analogRead(PIN_P_SEGUIMIENDO);
    showPot(potValue,PERCENTAGE);
  }
  else if(gifSolicitado == 6){
    potValue[0] = analogRead(PIN_H_PERILLA);
    potValue[1] = analogRead(PIN_C_PERILLA);
    potValue[2] = analogRead(PIN_M_PERILLA);
    potValue[3] = analogRead(PIN_P_PERILLA);
    showPot(potValue,ANGLE);
  }
  else if(gifSolicitado == 7)
  {
    potValue[0] = analogRead(PIN_H_PERILLA);
    potValue[1] = analogRead(PIN_C_PERILLA);
    potValue[2] = analogRead(PIN_M_PERILLA);
    potValue[3] = analogRead(PIN_P_PERILLA);
    showPot(potValue,PERCENTAGE);
  }
  gifAnterior = gifSolicitado;
  
}
