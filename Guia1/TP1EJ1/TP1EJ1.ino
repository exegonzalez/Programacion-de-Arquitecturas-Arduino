/* 1. Conectar 3 leds (rojo, verde y amarillo) y hacer que se prendan 2 segundos cada uno secuencialmente, mientras uno esta encendido los demás deberán estar apagados.*/


void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT);//led red
  pinMode(4, OUTPUT);//led green
  pinMode(3, OUTPUT);//led yellow
}

void loop() {
  if (Serial.available()>0){
    String valor = Serial.readStringUntil('.');
    if(valor == "E"){  
      digitalWrite(5, HIGH);
      delay(500);
      digitalWrite(5, LOW);
      delay(500); 
      digitalWrite(4, HIGH);
      delay(500);
      digitalWrite(4, LOW);
      delay(500);
      digitalWrite(3, HIGH);
      delay(500);
      digitalWrite(3, LOW);
      delay(500);
    }
  }  
}
