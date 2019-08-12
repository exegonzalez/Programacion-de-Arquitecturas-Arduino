/* 2. Utilizando los leds del ejercicio anterior genere un numero randomico entre 0 y 10,y dependiendo de dicho valor encienda por dos 
 segundos el led que corresponda según el siguiente criterio (si num 1, 3, 7 rojo, 0, 2, 8 verde 4, 5, 9 amarillo y 10 todos apagados).*/

 
void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT);//led red
  pinMode(4, OUTPUT);//led green
  pinMode(3, OUTPUT);//led yellow
}

void loop() {
  if (Serial.available()>0){
   int valor = random(0,11);
   Serial.println(valor);
   if((valor == 1)||(valor == 3)||(valor == 7)){  
    digitalWrite(5, HIGH);
    delay(500);
    digitalWrite(5, LOW);
    delay(500);
   } 
   if((valor == 0)||(valor == 2)||(valor == 8)){    
      digitalWrite(4, HIGH);
      delay(500);
      digitalWrite(4, LOW);
      delay(500);
   }      
   if((valor == 4)||(valor == 5)||(valor == 9)){
      digitalWrite(3, HIGH);
      delay(500);
      digitalWrite(3, LOW);
      delay(500);
   }
   if(valor == 10){
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
   }  
 }
}
