/* 10. Se podría mejorar el ejercicio anterior variando los colores de en esta secuencia rojo-anaranjado-amarillo. */


void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);//red
  pinMode(10, OUTPUT);//green
  pinMode(11, OUTPUT);//blue
  pinMode(6, INPUT);//echo
  pinMode(2, OUTPUT);//trig
}

void loop() {
  digitalWrite(2, LOW);
  delayMicroseconds(100);
  digitalWrite(2, HIGH);
  delayMicroseconds(200);
  digitalWrite(2, LOW);
  
  int duration = pulseIn(6, HIGH);
  int cm= duration*0.034/2;
  Serial.print("Distancia: ");
  Serial.print(cm);
  Serial.println(' ');
  encender(cm);
}

void encender(int cm){
    if (cm<=5){
      analogWrite(9, 255);
      analogWrite(10, 0);
      analogWrite(11, 0);
    }
    if ((cm>5) && (cm<=10)){
      analogWrite(9, 239);
      analogWrite(10, 127);
      analogWrite(11, 26);
    }
    if ((cm>10) && (cm<=25)){
      analogWrite(9, 255);
      analogWrite(10, 255);
      analogWrite(11, 0);
    }
    if (cm>25){
      analogWrite(9, 0);
      analogWrite(10, 0);
      analogWrite(11, 0);
   }
}
