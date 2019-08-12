/* 3. Utilizando un led rgb genere los 7 colores posible rojo, verde, azul, amarillo (rojo y verde), 
violeta (rojo y azul), celeste (azul y verde) y blanco (rojo, azul y verde) utilizando una función.*/


void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT);//red
  pinMode(4, OUTPUT);//green
  pinMode(3, OUTPUT);//blue
}

void loop() {
  int valor = Serial.readStringUntil('.').toInt();
  colores(valor);
}

void colores(int x){
  switch(x){
    case 1:
      digitalWrite(5, HIGH);
      delay(500);
    break;
    case 2:
      digitalWrite(3, HIGH);
      delay(500);
    break;
    case 3:
      digitalWrite(4, HIGH);
      delay(500);
    break;
    case 4:
      digitalWrite(5, HIGH);
      delay(500);
      digitalWrite(3, HIGH);
      delay(500);
    break;
    case 5:
      digitalWrite(5, HIGH);
      delay(500);
      digitalWrite(4, HIGH);
      delay(500);
    break;
    case 6:
      digitalWrite(4, HIGH);
      delay(500);
      digitalWrite(3, HIGH);
      delay(500);
    break;
    case 7:
      digitalWrite(5, HIGH);
      delay(500);
      digitalWrite(4, HIGH);
      delay(500);
      digitalWrite(3, HIGH);
      delay(500);
    break;
    case 8:
      digitalWrite(5, LOW);
      delay(500);
      digitalWrite(4, LOW);
      delay(500);
      digitalWrite(3, LOW);
      delay(500);
    break;
  }
}
