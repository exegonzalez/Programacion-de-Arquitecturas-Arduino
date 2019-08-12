/* 3. Utilice un control remoto inalámbrico para realizar las siguientes actividades:
a. Teclas del 0 al 9 deberá mover un servo de manera aleatoria entre en número de la tecla apretada y 160.
b. Teclas arriba y abajo deberá encender un led rojo y verde respectivamente.
c. Teclas izquierda y derecha emitir un beep de 2 segundos.
d. Tecla Ok deberá reproducir la marcha imperial del ejercicio 8 de la guía 3.*/

#include "IRremote.h"
#include "Servo.h"

//Control
const long KEY_UP = 0xFF18E7;
const long KEY_LEFT =0xFF10EF; 
const long KEY_OK = 0xFF38C7;
const long KEY_RIGHT = 0xFF5AA5;
const long KEY_DOWN = 0xFF4AB5;
const long KEY_1 =0xFFA25D;
const long KEY_2 = 0xFF629D;
const long KEY_3 = 0xFFE21D;
const long KEY_4 = 0xFF22DD;
const long KEY_5 = 0xFF02FD;
const long KEY_6 = 0xFFC23D;
const long KEY_7 = 0xFFE01F;
const long KEY_8 = 0xFFA857;
const long KEY_9 = 0xFF906F;
const long KEY_0 = 0xFF9867;
const long KEY_ASTERISK = 0xFF6897;
const long KEY_POUND = 0xFFB04F;

const int RECV_PIN = 9;
int x;

#define pin_servo 10
#define ledverde 4
#define ledrojo 5
#define buzzer 11

Servo servoMotor;
IRrecv irrecv(RECV_PIN);
decode_results results;
 
void setup(){
   pinMode(ledverde, OUTPUT);
   pinMode(ledrojo, OUTPUT);
   pinMode(buzzer, OUTPUT);
   Serial.begin(9600);
   irrecv.enableIRIn();
   servoMotor.attach(pin_servo);
}
 
void loop(){
   if (irrecv.decode(&results)){ 
      switch (results.value)
      {
      case KEY_UP:
         if (digitalRead(ledverde)==LOW){
          digitalWrite(ledverde,HIGH);
         }
         else{
          digitalWrite(ledverde,LOW);
         }
         break;
      case KEY_LEFT:
         beep();
         break;
      case KEY_OK:
         Serial.println("Suena la marcha imperial"); //Incompatibilidad de librerias 
         break;
      case KEY_RIGHT:
         beep();
         break;
      case KEY_DOWN:
         if (digitalRead(ledrojo)==LOW){
          digitalWrite(ledrojo,HIGH);
         }
         else{
          digitalWrite(ledrojo,LOW);
         }break;
      case KEY_1:
         x = random(1,160);
         servoMotor.write(x);
         break;
      case KEY_2:
         x = random(2,160);
         servoMotor.write(x);
         break;
      case KEY_3:
         x = random(3,160);
         servoMotor.write(x);
         break;
      case KEY_4:
         x = random(4,160);
         servoMotor.write(x);
         break;
      case KEY_5:
         x = random(5,160);
         servoMotor.write(x);
         break;
      case KEY_6:
         x = random(6,160);
         servoMotor.write(x);
         break;
      case KEY_7:
         x = random(7,160);
         servoMotor.write(x);
         break;
      case KEY_8:
         x = random(8,160);
         servoMotor.write(x);
         break;
      case KEY_9:
         x = random(9,160);
         servoMotor.write(x);
         break;
      case KEY_0:
         Serial.println("KEY_0");
         break;
      case KEY_ASTERISK:
         Serial.println("KEY_ASTERISK");
         break;
      case KEY_POUND:
         Serial.println("KEY_POUND");
         break;
      }
      irrecv.resume();
   }
}

void beep(){
    analogWrite(buzzer, 20);
    delay(500);                 // Espera
    analogWrite(buzzer, 0);            // Apaga
    delay(500);                 // Espera
}
