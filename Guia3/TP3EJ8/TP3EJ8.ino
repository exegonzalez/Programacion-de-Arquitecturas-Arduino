/* 8. Utilice una pantalla OLED para visualizar los datos del ejercicio 2 de la guía 2, deberá mostrar el valor su unidad de medida y su escala.*/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11   

DHT dht(DHTPIN, DHTTYPE);
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire);

void setup() {
  Serial.begin(9600);
  dht.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3C for 128x32
  
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  
  display.display();
  delay(1000);
  
  // Clear the buffer.
  display.clearDisplay();
  display.display();

  // text display tests
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.display(); // actually display all of the above
  delay(2000);
  display.clearDisplay();
  display.display();
}

void loop() {
  display.drawPixel(0, 0, WHITE);
  display.drawPixel(127, 0, WHITE);
  display.drawPixel(0, 31, WHITE);
  display.drawPixel(127, 31, WHITE);
  display.setCursor(0,0);
  display.display();
  delay(500);
  medir();
  display.display();
  delay(500);
}


void medir(){
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  display.clearDisplay();
  rangohumedad(h);
  rangotemperatura(t);
  delay(2000);
}

void rangohumedad(float h){
    if ((h>=0)&&(h<30)){
      display.print("La humedad es: ");
      display.print(h);
      display.println(" - Humedad baja");
    }
    if ((h>=30)&&(h<60)){
      display.print("La humedad es: ");
      display.print(h);
      display.println(" - Humedad media");
    }
    if ((h>=60)&&(h<90)){
      display.print("La humedad es: ");
      display.print(h);
      display.println(" - Humedad alta");
    }
    display.display();
}

void rangotemperatura(float t){
    if ((t>=0)&&(t<30)){
      display.print("La temperatura es: ");
      display.print(t);
      display.print("C°");
      display.println(" - Temperatura baja");
    }
    if ((t>=30)&&(t<60)){
      display.print("La temperatura es: ");
      display.print(t);
      display.print("C°");
      display.println(" - Temperatura media");
    }
    if ((t>=60)&&(t<90)){
      display.print("La temperatura es: ");
      display.print(t);
      display.print("C°");
      display.println(" - Temperatura alta");
    }
    display.display();
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
