/* 2. Girar el servo utilizando un potenciómetro.*/

#include "Servo.h"

#define pin_servo 9

Servo servoMotor;
 
void setup() {
  Serial.begin(9600); 
  pinMode(A0,INPUT);
  servoMotor.attach(pin_servo);
}
 
void loop() {
  int valor = analogRead(A0);
  int position = map(valor, 0, 1023, 0, 180); 
  Serial.print("El angulo es: ");
  Serial.println(position);
  servoMotor.write(position);
  delay(250);
}
