/* 9. Se necesita controlar el sistema de riego de un invernadero el cual cuenta con dos válvulas eléctricas 
 controladas por un relé de dos canales y dos sensores de humedad de suelo programar las interrupciones 
 necesarias para encender y apagar las válvulas cuando sean necesario.*/

#define rele1 9
#define rele2 10
#define sensor1 2
#define sensor2 3

void setup(){
      Serial.begin(9600);
      pinMode(rele1, OUTPUT);
      pinMode(rele2, OUTPUT);
      pinMode(sensor1, INPUT);
      pinMode(sensor2, INPUT);
      attachInterrupt(digitalPinToInterrupt(sensor1), controlar1, CHANGE);
      attachInterrupt(digitalPinToInterrupt(sensor2), controlar2, CHANGE);
    }
    
void loop(){
  Serial.println(digitalRead(sensor1));
  
  Serial.println(digitalRead(sensor2));
  Serial.println("");
  delay(500);
}

void controlar1(){
    if (digitalRead(sensor1)==0){
      digitalWrite(rele1, LOW);
    }
    else{
      digitalWrite(rele1, HIGH);
    }
}

void controlar2(){
    if (digitalRead(sensor2)==0){
      digitalWrite(rele2, LOW);
    }
    else{
      digitalWrite(rele2, HIGH);
    }
}
