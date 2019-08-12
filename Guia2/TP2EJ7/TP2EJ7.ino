/*7.  Utilice un sensor flex y dos led en los cuales a cada uno le deberá variar la intensidad dependiendo del valor obtenido del sensor, 
 uno indicara la fuerza que está ejerciendo sobre el sensor y el otro la resistencia del sensor.*/

void setup() {
    Serial.begin(9600);
    pinMode(A0, INPUT);//flex
    pinMode(9, OUTPUT);//red
    pinMode(7, OUTPUT);//led
}

void loop() {
    int valor = analogRead(A0);
    Serial.println(valor);
    int value = map(valor, 500, 1023, 0, 255); 
    intensidad(value);       
}

void intensidad(int x){
    analogWrite(9, x);
    int aux = (255-x);
    analogWrite(7, aux);
    delay(500);
}
