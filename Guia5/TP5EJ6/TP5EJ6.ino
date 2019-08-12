/* 6. Ahora con mucho CUIDADO utilice duerma Arduino con el tiempo SLEEP_FOREVER para lo cual deberá despertarlo 
  con una interrupción, para mejorar el ejercicio 3 de la guía 4.
    attachInterrupt( 0, ServicioBoton, FALLING);
    LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
    detachInterrupt(0);*/

#include <Servo.h>
#include "LowPower.h"

#define pin_servo 9
const int reed = 2;
Servo servoMotor;

void abrir(){
   servoMotor.write(90);
   Serial.println("aca");
}

void setup(){
    Serial.begin(9600);
    servoMotor.attach(pin_servo);
    pinMode(reed, INPUT); 
}

void loop() {
    servoMotor.write(0);
    delay(250);
    attachInterrupt(0, abrir, FALLING);
    LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF); 
    detachInterrupt(0); 
    delay(3000);
}
