/* 1. Programe dos interrupción que utilice un pulsador cada una para controlar 5 leds (una para encender y otra para apagar), 
 cada vez que se presiona el pulsador de encender se debe encender un led (es decir si se presiona una vez se prende un led, 
 dos veces dos leds…) lo mismo con el de apagar cada vez que se presiona el botón se apaga uno); tenga cuidado con los valores 
 extremos 1 y 5 de no excederlos para que el código se mantenga funcionando correctamente. */

#define pin1 9
#define pin2 10
#define pin3 11
#define pulsador1 2
#define pulsador2 3
int cont;

bool control = false;
void setup() {
    pinMode(pulsador1, INPUT_PULLUP);//pulsador
    pinMode(pulsador2, INPUT_PULLUP);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    attachInterrupt(digitalPinToInterrupt(pulsador1), prender, FALLING);
    attachInterrupt(digitalPinToInterrupt(pulsador2), apagar, FALLING);
    Serial.begin(9600);
}
 
void loop() {
}

void prender(){
  switch(cont){
    case 0:{
      digitalWrite(pin1,HIGH);
      cont=cont+1;
      break;}
    case 1:{
      digitalWrite(pin2,HIGH);
      cont=cont+1;
      break;}
    case 2:{
      digitalWrite(pin3,HIGH);
      cont=cont+1;
      break;}  
  }
}

void apagar(){
  switch(cont){
    case 1:{
      digitalWrite(pin1,LOW);
      cont=cont-1;
      break;}
    case 2:{
      digitalWrite(pin2,LOW);
      cont=cont-1;
      break;}
    case 3:{
      digitalWrite(pin3,LOW);
      cont=cont-1;
      break;}
  }
}
