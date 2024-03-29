/*2.  Utilice uno de los sensores de la familia de los dht para medir la temperatura y humedad. Crear una escala de tres valores para cada uno alta, media y baja. 
 Mostrar la variabilidad de al menos una de estas. Luego pruebe con los otros sensores de la familia ¿qué diferencia encuentra?*/

#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11   

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  rangohumedad(h);
  rangotemperatura(t);
  delay(2000);
}

void rangohumedad(float h){
    if ((h>=0)&&(h<30)){
      Serial.print("La humedad es: ");
      Serial.print(h);
      Serial.println(" - Humedad baja");
    }
    if ((h>=30)&&(h<60)){
      Serial.print("La humedad es: ");
      Serial.print(h);
      Serial.println(" - Humedad media");
    }
    if ((h>=60)&&(h<90)){
      Serial.print("La humedad es: ");
      Serial.print(h);
      Serial.println(" - Humedad alta");
    }
}

void rangotemperatura(float t){
    if ((t>=0)&&(t<30)){
      Serial.print("La temperatura es: ");
      Serial.print(t);
      Serial.print("C°");
      Serial.println(" - Temperatura baja");
    }
    if ((t>=30)&&(t<60)){
      Serial.print("La temperatura es: ");
      Serial.print(t);
      Serial.print("C°");
      Serial.println(" - Temperatura media");
    }
    if ((t>=60)&&(t<90)){
      Serial.print("La temperatura es: ");
      Serial.print(t);
      Serial.print("C°");
      Serial.println(" - Temperatura alta");
    }
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
