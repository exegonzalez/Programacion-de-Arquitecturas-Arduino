/* 1.  Mover un servo motor de manera aleatoria utilizando la librería random.*/

#include "Servo.h"

#define pin_servo 9

Servo servoMotor;
 
void setup() {
  Serial.begin(9600);
  // Iniciamos el servo para que empiece a trabajar con el pin elegido
  servoMotor.attach(pin_servo);
}
 
void loop() {
  int x = random(0,180);
  Serial.print("el angulo es: ");
  Serial.println(x);
  servoMotor.write(x);
  delay(250);
}
