/* 4. Utilizando las salidas PWM para conectar el led y un potenciómetro, varié la intensidad lumínica de uno de los led del ejercicio uno.*/


void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);//led
  pinMode(A1, INPUT);//potenciometro
}

void loop() {
  int value = analogRead(A1); 
  modular(value);
}

void modular(int value){
   int position = map(value, 0, 1023, 0, 255); 
   analogWrite(9, position);
   delay(1000);
}
