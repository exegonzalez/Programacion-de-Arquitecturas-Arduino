/* 2. Utilizando interrupciones y un sensor de humedad de suelo digital, realice un monitoreo en tiempo real 
 de la cantidad de mates cebados, además cada vez que se ceba o toma el mate deberá indicarlo, toda la 
 información deberá ser mostrada en una pantalla oled.*/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire);
int n = 0;
String m1;
#define sensor1 2

void setup(){
      Serial.begin(9600);
      display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3C for 128x32
      
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
      pinMode(sensor1, INPUT);
      attachInterrupt(digitalPinToInterrupt(sensor1), controlar, CHANGE);
    }
    
void loop() {
    display.clearDisplay ();
    display.drawPixel(0, 0, WHITE);
    display.drawPixel(127, 0, WHITE);
    display.drawPixel(0, 31, WHITE);
    display.drawPixel(127, 31, WHITE);
    display.setCursor(0,10);
    display.println(m1);
    display.display();
    display.print("Mates cebados: ");
    display.println(n);
    display.display();
}

void controlar(){
    if (digitalRead(sensor1)==LOW){
      m1= "Mate cebado";
      Serial.println ("m1");
    }
    else{
      m1= "Mate tomado";
      Serial.println ("m1");
      n++;
    }
    Serial.print("Mates cebados: ");
    Serial.println(n);
}
