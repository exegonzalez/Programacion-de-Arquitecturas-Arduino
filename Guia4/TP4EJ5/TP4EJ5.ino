/* 5. Un servo controla la llave del aspersor de agua para incendios de una habitación (dado que no hay presupuesto 
 para un aspersor eléctrico), programe las interrupciones necesarias para encender y apagar el aspersor, tenga en 
 cuenta que debe girar 97 grados el servo para mover la llave del aspersor.*/ 

#include "Servo.h"

#define pin_servo 9
#define sensorfuego 2

Servo servoMotor;
int valorSensor;

void setup() {
  Serial.begin(9600);
  pinMode(sensorfuego,INPUT);
  // Iniciamos el servo para que empiece a trabajar con el pin elegido
  servoMotor.attach(pin_servo);
  attachInterrupt(digitalPinToInterrupt(sensorfuego), encender, CHANGE);
  servoMotor.write(0);
}

void loop() {
}

void encender(){
  if (digitalRead(sensorfuego)==0){
    servoMotor.write(97);
    Serial.println("fuego");
  }
   else{
    servoMotor.write(0);
    Serial.println("no fuego");
   }
}
