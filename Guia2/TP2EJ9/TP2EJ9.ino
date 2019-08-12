/*9.  Utilice un pulsador para prender y apagar un led rgb, el color debe elegirse aleatoriamente.*/

bool control = false;
void setup() {
    pinMode(2, INPUT_PULLUP);//pulsador
    pinMode(9, OUTPUT);//red
    pinMode(10, OUTPUT);//green
    pinMode(11, OUTPUT);//blue
    Serial.begin(9600);
}
 
void loop() {
  int valorPulsador = digitalRead(2);// Leemos el valor del pin2
  if (valorPulsador == LOW) {
      control = !control;
      if (control){
        colores(random(1,7));
        delay(100);
      }
      else{
        colores(8);
        delay(100);
      }
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
