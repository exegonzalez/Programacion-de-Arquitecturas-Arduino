/*3.  Utilice un ldr para medir la intensidad lumínica del ambiente, genere una escala con 5 valores (cuando exceda el tercer valor de la escala se deberán 
 apagar el o los led y se encenderán cuando vuelva descienda al tercer valor). El o los led deberá parpadear cada 733 milisegundos.*/
 
void setup() {
 Serial.begin(9600);
 pinMode(A1, INPUT);//ldr
 pinMode(9, OUTPUT);//red
}

void loop() {
  int value = analogRead(A1);
  rango(value); 
}

void rango(int value){
    if ((value>=0)&&(value<200)){
      Serial.println("Luminosidad: 1");
      analogWrite(9, 255);
      delay(733);
    }
    if ((value>=200)&&(value<400)){
      Serial.println("Luminosidad: 2");
      analogWrite(9, 255);
      delay(733);
    }
    if ((value>=400)&&(value<600)){
      Serial.println("Luminosidad: 3");
      analogWrite(9, 255);
      delay(733);
    }
    if ((value>=600)&&(value<800)){
      Serial.println("Luminosidad: 4");
      analogWrite(9, 0);
      delay(733);
    }
    if ((value>=800)&&(value<=1000)){
      Serial.println("Luminosidad: 5");
      analogWrite(9, 0);
      delay(733);
    } 
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
