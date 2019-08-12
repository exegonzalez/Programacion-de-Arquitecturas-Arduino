/* 7. Utilice interrupciones para mejorar el conteo de las vibraciones del ejercicio 8 de la guía 2.*/

int n = 1;
#define led 13
#define sensor 2

void setup(){ 
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  digitalWrite(sensor , HIGH);
  pinMode(led, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(sensor), contar, RISING);
 }

void loop(){
}

void contar(){
    if (n<10){
      n=n+1;
    }
    else{
      n=1;
    } 
    parpadear();
}

void parpadear(){
  digitalWrite(led,HIGH);
  delay(500);
  digitalWrite(led,LOW);
  Serial.print("Vibracion nro: ");
  Serial.println(n);
}
