/* 4. Utilice un módulo bluetooth HC-06 para poder enviar los datos del ejercicio 12 de la guía 3 a una aplicación en Android, 
 para poder monitorear lo que pasa. Y además permita enviar un mensaje de encender o pagar las válvulas desde el dispositivo móvil.*/

#include <SoftwareSerial.h> 
SoftwareSerial blue(2,3); //10 TX, 11 RX.
#define rele 9

void setup(){
  pinMode(rele, HIGH);
  blue.begin(9600);
  Serial.begin(9600);
}
 
void loop(){
  if(blue.available()>0){
      String datos= blue.readStringUntil('.');
      Serial.println(datos); 
      if(datos == "encender" ){
        digitalWrite(rele, HIGH);
        Serial.println("Rele encendido");
        blue.write("recibido. Encendiendo."); 
      }
      else if(datos == "apagar" ){
        digitalWrite(rele, LOW);
        Serial.println("Rele apagado");
        blue.write("recibido. Apagando."); 
      }
    }
   delay(500);
}
