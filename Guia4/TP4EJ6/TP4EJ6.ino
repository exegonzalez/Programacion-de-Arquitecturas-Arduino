/* 6. Utilice un sensor PIR hc-sr501 para detectar la presencia de personas en una habitación, cuando se detecte dicha presencia 
 se deberá dispara alterar el estado de una variable para que se pueda activar una función que haga parpadear un diodo led rojo 
 y cuando no se detecte presencia se deberá cambiar el estado para que la función se detenga.*/

#define sensor 2
#define led 9
bool parpadeo=false;

void setup(){  
    Serial.begin(9600);
    pinMode(led, OUTPUT);
    pinMode(sensor, INPUT);
    attachInterrupt(digitalPinToInterrupt(sensor), encender, CHANGE);
 }

void loop(){
  if (parpadeo==true){
    digitalWrite(led, HIGH);
    }
  else{
    digitalWrite(led, LOW);
   }
}

void encender(){
  if (digitalRead(sensor)==1){
    parpadeo=true;
    }
  else{
    parpadeo=false;
   }
}
