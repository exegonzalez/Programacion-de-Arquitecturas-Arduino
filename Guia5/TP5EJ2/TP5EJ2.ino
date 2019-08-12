/* 2. Utilizando un reloj RTC, cree un datalog para mostrar por consola los datos de fecha, hora, 
 medida de distancia en cm y su correspondiente escala, utilizada en el ejercicio 7 de la guía 3.*/

#include <Wire.h>
#include "RTClib.h"

// RTC_DS1307 rtc;
RTC_DS3231 rtc;

String daysOfTheWeek[7] = { "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };
String monthsNames[12] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo",  "Junio", "Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre" };

void setup() {
   Serial.begin(9600);
   pinMode(6, INPUT); //echo
   pinMode(2, OUTPUT); //trig
   delay(1000); 
   // Comprobamos si tenemos el RTC conectado
   if (!rtc.begin()) {
      Serial.println(F("No hay un módulo RTC"));
      while (1);
   }
   // Si se ha perdido la corriente, fijar fecha y hora
   if (rtc.lostPower()) {
      // Fijar a fecha y hora de compilacion
      rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
      
      // Fijar a fecha y hora específica
      rtc.adjust(DateTime(2019, 6, 4, 17, 33, 0));
   }
}

void loop() {
   digitalWrite(2, LOW);
   delayMicroseconds(100);
   digitalWrite(2, HIGH);
   delayMicroseconds(200);
   digitalWrite(2, LOW);

   int duration = pulseIn(6, HIGH);
   int cm= duration*0.034/2;
  
   DateTime now = rtc.now();
   mostrarFecha(now);
   mostrarDistancia(cm);
   delay(3000);
}

void mostrarFecha(DateTime date){
   Serial.print(date.year(), DEC);
   Serial.print('/');
   Serial.print(date.month(), DEC);
   Serial.print('/');
   Serial.print(date.day(), DEC);
   Serial.print(" (");
   Serial.print(daysOfTheWeek[date.dayOfTheWeek()]);
   Serial.print(") ");
   Serial.print(date.hour(), DEC);
   Serial.print(':');
   Serial.print(date.minute(), DEC);
   Serial.print(':');
   Serial.print(date.second(), DEC);
}

void mostrarDistancia(int cm){
    if (cm<=5){
      Serial.print(", Distancia: ");
      Serial.print(cm);
      Serial.println("cm, Rango: Muy cerca");
    }
    else if((cm>5)&&(cm<=10)){
      Serial.print(", Distancia: ");
      Serial.print(cm);
      Serial.println("cm, Rango: Cerca");
    }
    else if ((cm>10)&&(cm<=25)){
      Serial.print(", Distancia: ");
      Serial.print(cm);
      Serial.println("cm, Rango: Proximo");
    }
    else{
      Serial.print(", Distancia: ");
      Serial.print(cm);
      Serial.println("cm");
    }
}
