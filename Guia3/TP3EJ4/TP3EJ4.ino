/* 4. Mover un dc utilizando un potenciómetro variando su velocidad.*/

#include <Servo.h>

Servo servo;

#define potenciometro A0
#define pin_servo 9
int val; 

void setup() {
  Serial.begin(9600);
  servo.attach(pin_servo);
}

void loop() {
  val = analogRead(potenciometro); 
  val = map(val, 0, 1023, 0, 180);
  servo.write(val);     
  //delay(100); 
}
