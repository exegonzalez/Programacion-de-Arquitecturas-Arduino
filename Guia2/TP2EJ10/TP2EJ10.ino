/* 10. Utilice un reed switch y led, cuando el sensor detecte un campo magnético y se cierre genere un parpadeo de led rojo y cuando el campo magnético se aleje y se abra verde.*/

void setup() {
   Serial.begin(9600);
   pinMode(12, INPUT);//reed switch
   pinMode(10,OUTPUT);//green
   pinMode(9,OUTPUT);//red  
}

void loop(){
   int estado = digitalRead(12);
   Serial.println(digitalRead(12));
   if (estado == HIGH) {     
       Serial.println("Cerrado");
       digitalWrite(9,HIGH);
       digitalWrite(10,LOW);
       delay(1000);
       apagar(); 
   } 
   else {
       Serial.println("Abierto");
       digitalWrite(10,HIGH);
       digitalWrite(9,LOW);
       delay(1000);
       apagar();
   }
}

void apagar(){
  digitalWrite(10,LOW);
  digitalWrite(9,LOW);
  delay(1000);
}
