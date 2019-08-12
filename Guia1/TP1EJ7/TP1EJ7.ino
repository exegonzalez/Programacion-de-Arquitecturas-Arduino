/* 7. Utilice un hc sr04 (sensor ultrasónico) para medir la distancia de los objetos que hay o pasan delante de estos.*/


long duration, cm;

void setup() {
 Serial.begin(9600);
 pinMode(9, OUTPUT);//trig
 pinMode(12, INPUT);//echo
}

void loop() {
  digitalWrite(9, LOW);
  delayMicroseconds(100);
  digitalWrite(9, HIGH);
  delayMicroseconds(200);
  digitalWrite(9, LOW);
 
  duration = pulseIn(12, HIGH);
 
  // Calculo de distancia
  cm= duration*0.034/2;
  Serial.print("La distancia es: ");
  Serial.print(cm);
  Serial.println(" cm");
}
