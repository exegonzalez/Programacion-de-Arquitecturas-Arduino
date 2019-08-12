/* 6. Mida la intensidad lumínica utilizando un LDR.*/


void setup() {
 Serial.begin(9600);
 pinMode(A1, INPUT);//LDR
}

void loop() {
  int value = analogRead(A1);
  Serial.print("La luminosidad es: ");
  Serial.println(value); 
  delay(1000);
}
