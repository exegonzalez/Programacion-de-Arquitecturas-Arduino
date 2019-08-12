/* 5. Utilice el sensor de humedad de suelo yl-69, cree una escala de cuatro valores (seco, húmedo, mojado, saturado) 
 debe también representarla de manera cromática con cuatro led. Para probarla utilice algún mate de la clase.*/
 
void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);//yl69
  pinMode(9, OUTPUT);//red
  pinMode(10, OUTPUT);//green
  pinMode(11, OUTPUT);//blue
}

void loop()
{
  int humedad = analogRead(A0);
  Serial.print(humedad); 
  Serial.print(" - ");
  rangosuelo(humedad);
  delay(1000);
}

void rangosuelo(int humedad){
  if(humedad >= 1000) {
   Serial.println("Suelo saturado");
   analogWrite(11, 255);
   analogWrite(10, 0);
   analogWrite(9, 0);
  }
  if(humedad < 1000 && humedad >= 600) { 
   Serial.println("Suelo mojado");
   analogWrite(10, 255);
   analogWrite(11, 0);
   analogWrite(9, 0);
  }
  if(humedad < 600 && humedad >= 370) {
   Serial.println("Suelo humedo");
   analogWrite(9, 255);
   analogWrite(10, 0);
   analogWrite(11, 0); 
  }
  if(humedad < 370) {
   Serial.println("Suelo seco");
   analogWrite(9, 255);
   analogWrite(10, 255);
   analogWrite(11, 0);
  }
}
