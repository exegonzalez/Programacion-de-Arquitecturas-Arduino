/* 9. Varié la intensidad lumínica del rgb (en su color rojo) de acuerdo a la distancia de los objetos que están delante del hc sr04 de acuerdo 
 al siguiente criterio si está a menos de 5 cm rojo intenso, a menos de 10 rojo medio, a menos de 25 rojo tenue y más de 25 apagado. */


void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);//red
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
    }
    if ((cm>5) && (cm<=10)){
      analogWrite(9, 127);
    }
    if ((cm>10) && (cm<=25)){
      analogWrite(9, 63);
    }
    if (cm>25){
      analogWrite(9, 0);
   }
}
