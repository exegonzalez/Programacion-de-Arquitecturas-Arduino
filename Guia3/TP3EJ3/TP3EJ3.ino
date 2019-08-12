/* 3.  Modifique el ejercicio uno, para que luego de tres movimientos, lea la posición en la que quedo y la muestre por consola,  
y luego realice los siguiente movimientos 0, 180 y 90 grados y luego continúe.*/

#include "Servo.h"

#define pin_servo 9

Servo servoMotor;
int y = 0; 
void setup() {
  Serial.begin(9600);
  // Iniciamos el servo para que empiece a trabajar con el pin elegido
  servoMotor.attach(pin_servo);
}
 
void loop() {
  int x = random(0,180);
  
  if ( y < 3 ) {
    Serial.print("el angulo es: ");
    Serial.println(x);
    servoMotor.write(x);
    delay(250);
    y = y+1;
  }
  else {
    Serial.println("se encuentra en 0 grados !!");
    servoMotor.write(0);
    delay(1000);
    Serial.println("se encuentra en 180 grados !!");
    servoMotor.write(180);
    delay(1000);
    Serial.println("se encuentra en 90 grados !!");
    servoMotor.write(90);
    delay(1000);
    y = 0 ;
  }
}
