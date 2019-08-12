/* 5. Utilice las funciones Arduino sleep, para poder ahorra el consumo de la placa Arduino durante el tiempo que no se requiera 
 y alargar la vida útil de la batería. Para este caso utilizaremos el siguiente comando LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF); 
 esto dormirá el Arduino por ocho segundo una vez que despierte deberá realizar la medición de luminosidad ambiente y mostrarla por consola.*/

#include "LowPower.h"
#define luz A0
int sensorValue;

void setup(){  
    Serial.begin(9600); 
}  
   
void loop(){
  LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
  sensorValue = analogRead(luz);        
  Serial.print("Luminosidad ambiente: ");              
  Serial.println(sensorValue);
  delay(250);
}  
