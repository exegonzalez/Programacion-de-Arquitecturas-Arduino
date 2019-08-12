/* 8. Varié la intensidad lumínica del rgb (en cualquier de su combinación de colores) de acuerdo a la variabilidad de luminosidad del ambiente.*/


void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);//red
  pinMode(10, OUTPUT);//green
  pinMode(11, OUTPUT);//blue
  pinMode(A1, INPUT);//LDR
}

void loop() {
  int v1 = analogRead(A1); 
  Serial.println(v1);
  encender(v1);
}

void encender(int v1){
   int position = map(v1, 0, 1023, 0, 255); 
   analogWrite(9, position);
   analogWrite(10, position);
   analogWrite(11, position);
   delay(1000);
}
