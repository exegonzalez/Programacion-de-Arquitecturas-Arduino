/* 7. Utilice una pantalla LCD RGB para mostrar los datos del ejercicio 1 de la guía 2, en la primera línea 
 *  de la pantalla deberá mostrar “distancia: valor cm” y en la segunda línea muestre la distancia de los objetos 
 *  de acuerdo al siguiente criterio si está a menos de 5 cm muy cerca, a menos de 10 cerca, a menos de 25 próximo 
 *  y más de 25 no mostrar nada; Además la pantalla deberá variar su color con los siguientes valor 
 rojo, amarillo, azul, verde respectivamente.*/

#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 0;
const int colorG = 0;
const int colorB = 0;

void setup() {
    Serial.begin(9600);
    pinMode(6, INPUT); //echo
    pinMode(2, OUTPUT); //trig
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    lcd.setRGB(colorR, colorG, colorB);
    // Print a message to the LCD.
    delay(1000);
}

void loop() {
  digitalWrite(2, LOW);
  delayMicroseconds(100);
  digitalWrite(2, HIGH);
  delayMicroseconds(200);
  digitalWrite(2, LOW);
 
  int duration = pulseIn(6, HIGH);
  int cm= duration*0.034/2;
  Serial.print(cm);
  Serial.println(' ');
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0)
    // print the number of seconds since reset:
    //lcd.print(millis()/1000);
    lcd.clear();
    mostrar(cm);
    delay(100);
}

void mostrar(int cm){
    if (cm<=5){
      lcd.setRGB(255, 0, 0);
      lcd.setCursor(0, 0);
      lcd.print("Distancia: ");
      lcd.print(cm);
      lcd.print("cm");
      lcd.setCursor(0, 1);
      lcd.print("Muy cerca");
    }
    else if((cm>5)&&(cm<=10)){
      lcd.setRGB(255, 255, 0);
      lcd.setCursor(0, 0);
      lcd.print("Distancia: ");
      lcd.print(cm);
      lcd.print("cm");
      lcd.setCursor(0, 1);
      lcd.print("Cerca");
    }
    else if ((cm>10)&&(cm<=25)){
      lcd.setRGB(0, 0, 255);
      lcd.setCursor(0, 0);
      lcd.print("Distancia: ");
      lcd.print(cm);
      lcd.print("cm");
      lcd.setCursor(0, 1);
      lcd.print("Proximo");
    }
    else{
      lcd.setRGB(0, 255, 0);
      lcd.setCursor(0, 0);
      lcd.print("Distancia: ");
      lcd.print(cm);
      lcd.print("cm");
    }
}
