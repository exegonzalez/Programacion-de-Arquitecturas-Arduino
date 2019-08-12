/* 12. Utilice un relé para prender y apagar una lámpara, ingresando un comando a través de la consola. */

#define rele 8

void setup() {
  // put your setup code here, to run once:
  pinMode(rele, HIGH);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0){
    String letra = Serial.readStringUntil('.');
    if(letra == "E" ){
      digitalWrite(rele, HIGH);
      Serial.println("Encender luz");
      }
    else if(letra == "A" ){
      digitalWrite(rele, LOW);
      Serial.println("Apagar luz");
      }
    }
}
