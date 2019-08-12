/* 6. Utilizando un buzzer y un ultrasónico hc-sr04, realizar un pequeño bip variando su de acuerdo a la distancia que se detecten los objetos:
a.  Si la distancia esta entre 20 cm y 30 cm el bip debe realizarse cada 1500 mseg
b.  Si la distancia esta entre 12 cm y 20 cm el bip debe realizarse cada 1 segundo
c.  Si la distancia esta entre 6 cm y 12 cm el bip debe realizarse cada 500 mseg
d.  Si la distancia esta entre 2 cm y 6 cm el bip debe realizarse cada 250 mseg
e.  Fuera de esos rango no debe emitir sonido*/


#define pin_buzzer 9
#define echo 6
#define trig 2

int duration, cm;
 
void setup() {
  Serial.begin(9600);
  pinMode(pin_buzzer, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
}
 
void loop(){
  digitalWrite(trig, LOW);
  delayMicroseconds(100);
  digitalWrite(trig, HIGH);
  delayMicroseconds(200);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  cm= duration*0.034/2;
  Serial.print("la distancia es: ");
  Serial.println(cm);
  medir(cm);
  delay(250);        
}

void medir(int cm){
  if ((cm>20)&&(cm<=30)){
    digitalWrite(pin_buzzer, HIGH);  
    delay(1500);             
    digitalWrite(pin_buzzer, LOW); 
  }   
  if ((cm>12)&&(cm<=20)){
    digitalWrite(pin_buzzer, HIGH);  
    delay(1000);             
    digitalWrite(pin_buzzer, LOW); 
  }
  if ((cm>6)&&(cm<=12)){
    digitalWrite(pin_buzzer, HIGH);  
    delay(500);             
    digitalWrite(pin_buzzer, LOW); 
  }
  if ((cm>=2)&&(cm<=6)){
    digitalWrite(pin_buzzer, HIGH);  
    delay(250);             
    digitalWrite(pin_buzzer, LOW); 
  }
  else{
    digitalWrite(pin_buzzer, LOW);
  }
}
