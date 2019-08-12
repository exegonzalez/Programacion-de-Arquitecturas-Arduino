/* 5. Ahora varié la intensidad de los tres valores del led RGB (utilizando la misma técnica que en el punto anterior) para generar distintos colores.*/


void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);//red
  pinMode(10, OUTPUT);//green
  pinMode(11, OUTPUT);//blue
  pinMode(A1, INPUT);//potenciometro
}

void loop() {
  int v1 = analogRead(A1); 
  modular(v1);
}

void modular(int v1){
   int position = map(v1, 0, 1023, 0, 255); 
   analogWrite(9, position);
   analogWrite(10, position);
   analogWrite(11, position);
}
