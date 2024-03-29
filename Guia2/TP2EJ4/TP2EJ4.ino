/* 4. Utilice el sensor bmp-180 para medir la presión ambiental, cree un a escala de dos valores (baja “verde” y alta “roja”), 
si la presión esta alta debe parpadear cada 1 segundo y si es baja cada 2,15 segundos.*/

#include <SFE_BMP180.h>

SFE_BMP180 bmp180;

char status;
double T,P;

void setup() {
 Serial.begin(9600);
 pinMode(9, OUTPUT);//red
 pinMode(10, OUTPUT);//green
 bmp180.begin();
}

void loop() {
status = bmp180.startTemperature();//Inicio de lectura de temperatura
  if (status != 0)
  {   
    delay(status); //Pausa para que finalice la lectura
    status = bmp180.getTemperature(T); //Obtener la temperatura
    if (status != 0)
    {
      status = bmp180.startPressure(3); //Inicio lectura de presión
      if (status != 0)
      {        
        delay(status);//Pausa para que finalice la lectura        
        status = bmp180.getPressure(P,T); //Obtenemos la presión
        if (status != 0)
        {                  
          rango(P);         
        }      
      }      
    }   
  } 
}


void rango(double x){
    if (x>=1010){
      Serial.print("Presion Alta :");
      Serial.print(x,2);
      Serial.println(" mb");
      analogWrite(9, 255);
      analogWrite(10, 0);
      delay(1000);
    }
    if (x<1010){
      Serial.print("Presion Baja :");
      Serial.print(x,2);
      Serial.println(" mb");
      analogWrite(10, 255);
      analogWrite(9, 0);
      delay(2150);
    } 
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
