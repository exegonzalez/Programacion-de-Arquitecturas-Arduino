/* 6. Utilice el sensor fc-37, cree una escala de tres valores (llovizna, lluvia débil, lluvia fuerte) debe también representarla de manera cromática con un led variando su intensidad.*/

void setup ()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);//fc37
  pinMode(9, OUTPUT);//red
  pinMode(10, OUTPUT);//green
  pinMode(11, OUTPUT);//blue
}

void loop ()
{
  int nivel = analogRead (A0);
  Serial.print ( "Valor: " );
  Serial.print (nivel);
  Serial.print( " - ");
  rangolluvia(nivel);
  delay(1000);
}

void rangolluvia(int nivel){
  if (nivel> 200 && nivel < 300 )
  {
    Serial.println ("Llovizna");
    analogWrite(11, 0);
    analogWrite(10, 0);
    analogWrite(9, 255);
  }
  if (nivel> 100 && nivel < 200 )
  {
    Serial.println ("Lluvia debil");
    analogWrite(11, 0);
    analogWrite(10, 255);
    analogWrite(9, 0);
  }
  if (nivel> 0 && nivel < 100 )
  {
    Serial.println ("Lluvia fuerte");
    analogWrite(11, 255);
    analogWrite(10, 0);
    analogWrite(9, 0);
  }
}
