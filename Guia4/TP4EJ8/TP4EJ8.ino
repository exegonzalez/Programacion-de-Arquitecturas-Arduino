/* 8. Modifique el ejercicio 9 de la guía 2 para que funcione con interrupciones.*/

#define rojo 9 
#define verde 10
#define azul 11
#define pulsador 2

void setup() {
    pinMode(pulsador, INPUT_PULLUP);
    pinMode(rojo, OUTPUT);
    pinMode(verde, OUTPUT);
    pinMode(azul, OUTPUT);
    Serial.begin(9600);
    attachInterrupt(digitalPinToInterrupt(pulsador), prender, CHANGE);
}
 
void loop() {
}

void prender(){
  if (digitalRead(pulsador)==0){
    colores(random(1,7));
  }
  else{
    colores(8);
  }
}

void colores(int x){
  switch(x){
    case 1:
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
    break;
    case 2:
      digitalWrite(11, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(9, LOW);
    break;
    case 3:
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(9, LOW);
    break;
    case 4:
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
    break;
    case 5:
      digitalWrite(9, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(10, HIGH);
    break;
    case 6:
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
    break;
    case 7:
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
    break;
    case 8:
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
    break;
  }
}  
