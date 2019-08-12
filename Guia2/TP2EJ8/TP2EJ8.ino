/*8.  Utilice un sensor tilt para detectar vibraciones, genere n parpadeos del led de 500 milisegundo, los n parpadeos iniciaran en uno y 
 se irán incrementando en cada vibración detectada hasta un máximo de 10 (luego se debe reiniciar).*/

int n = 1;
void setup(){ 
  Serial.begin(9600);
  pinMode(2, INPUT);
  digitalWrite(2 , HIGH);
  pinMode(13, OUTPUT);
 }

void loop(){
  if (digitalRead(2)){
    parpadeo(n);
  }  
  else{
    digitalWrite(13, LOW);
  }
}

void parpadeo(int n){
  if (n<=10){
    digitalWrite(13, HIGH);
    n+1;
  }
  else{
    n=1;
    digitalWrite(13,HIGH);
  }
 delay(500); 
}
