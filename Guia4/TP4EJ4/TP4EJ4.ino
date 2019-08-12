/* 4. Programe dos interrupciones que envíen un mensaje por consola, una que 
 indique cuando empezó a llover y otra que indique cuando ya no llueve.*/

#define sensor 2

void setup (){
  Serial.begin(9600);
  pinMode(sensor, INPUT);//fc37
  attachInterrupt(digitalPinToInterrupt(sensor), mojado, CHANGE);
  }

void loop (){
}

void mojado(){
   if (digitalRead(2)==1){
   Serial.println("Esta lloviendo");
   
   }
   else{
    Serial.println("No esta lloviendo");
   }
}
