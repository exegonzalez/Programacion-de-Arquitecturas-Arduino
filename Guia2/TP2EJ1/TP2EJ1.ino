                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           /* 1.  Utilice el sensor hc-sr04 para determinar la distancia de los objetos que pasan delante de este. Si un objeto 
se acerca o permanece a menos de 5 cm deberá encender un led rojo, el cual deberá apagar cuando este se aleje. */
   
void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);//red
  pinMode(6, INPUT); //echo
  pinMode(2, OUTPUT); //trig
}

void loop() {
  digitalWrite(2, LOW);
  delayMicroseconds(100);
  digitalWrite(2, HIGH);
  delayMicroseconds(200);
  digitalWrite(2, LOW);
 
  int duration = pulseIn(6, HIGH);
  int cm= duration*0.034/2;
  Serial.print(cm);
  Serial.println(' ');
  encender(cm);
  delay(250);
}

void encender(int cm){
    if (cm<=5){
      analogWrite(9, 255);
    }
    else{
      analogWrite(9,0);
    }
}
