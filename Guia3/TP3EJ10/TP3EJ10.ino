/* 10. Utilice un sensor ultrasónico sobre un servo, (simulando ser un radar como se observa en la figura) 
que monitoree en un rango de 30 cm contemplando lo siguiente:
a. De monitorear en un rango de 180 grados como si fuera un radar.
b. Si detecta algo debe detenerse y encender un láser que apunte a la posición donde se detectó el objeto.
c. Cuando el objeto salga de adelante deberá continuar monitoreando.*/


#include "Servo.h"

#define pin_servo 10
#define trigPin  9
#define echoPin  8
#define laser 3

Servo servoMotor;
long duration, cm, inches;
int x=1;
 
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(laser, OUTPUT);
  pinMode(echoPin, INPUT);
  servoMotor.attach(pin_servo);
}
 
void loop(){
  monitorear();
  delay(250);
}

void monitorear(){
  for (int i=0;i<175;i++){
    servoMotor.write(i);
    medir();
    delay(50);
  }
  for (int i=175;i>0;i--){
    servoMotor.write(i);
    medir();
    delay(50);
  }
}

void medir(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  cm= duration*0.034/2;
 
  while (cm<=30){
    digitalWrite(laser,HIGH);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    duration = pulseIn(echoPin, HIGH);
    cm= duration*0.034/2;
  }
  digitalWrite(laser,LOW);
}
