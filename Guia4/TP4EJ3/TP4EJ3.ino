/* 3. Necesitamos controlar el mecanismo para abrir una puerta, las tarjetas de identificación de los empleados 
 de una oficina son magnéticas, cuando un reed switch detecta una de estas tarjetas debe mover un servo en 90 grados 
 para destrabar la puerta (luego de unos segundo vuelva el servo a su posición original para simular que la puerta se cerró).*/

#include "Servo.h"

#define pin_servo 9
#define reed 2

Servo servoMotor;

void setup() {
   Serial.begin(9600);
   pinMode(reed, INPUT);//reed switch
   servoMotor.attach(pin_servo);
   attachInterrupt(digitalPinToInterrupt(reed), abrirpuerta, FALLING); 
}

void loop(){
   delay(3000);
   servoMotor.write(0);
   interrupts();
}

void abrirpuerta(){
  servoMotor.write(90);
  noInterrupts();
}
