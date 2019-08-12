#include "Arduino.h"
#include "dados.h"
#include "LedControl.h"
#include "binary.h"

#define MAX 2       // Cuantas matrices se usarán

LedControl led=LedControl(12,11,10,MAX);  //LedControl(DIN,CLK,CS,Nro matrices) Creamos una instancia de LedControl

byte uno[8]={B00000000,B00000000,B00000000,B00011000,B00011000,B00000000,B00000000,B00000000};
byte dos[8]={B11000000,B11000000,B00000000,B00000000,B00000000,B00000000,B00000011,B00000011};
byte tres[8]={B11000000,B11000000,B00000000,B00011000,B00011000,B00000000,B00000011,B00000011};
byte cuatro[8]={B11000011,B11000011,B00000000,B00000000,B00000000,B00000000,B11000011,B11000011};
byte cinco[8]={B11000011,B11000011,B00000000,B00011000,B00011000,B00000000,B11000011,B11000011};
byte seis[8]={B11000011,B11000011,B00000000,B11000011,B11000011,B00000000,B11000011,B11000011};
byte espada[8]={B00000011,B00000111,B00001110,B01011100,B00111000,B00110000,B01001000,B10000000};
byte escudo[8]={B00000000,B01111110,B01111110,B01111110,B01111110,B01111110,B00111100,B00011000};
byte casco[8]={B11111111,B11111111,B10111101,B10011001,B10000001,B10000001,B01000010,B00000000};
byte mover[8]={B00001000,B00001100,B11111110,B11111111,B11111111,B11111110,B00001100,B00001000};
byte cancelar[8]={B11111111,B11000011,B10100101,B10011001,B10011001,B10100101,B11000011,B11111111};
byte activar[8]={B00111100,B01000010,B10000001,B10011001,B10011001,B10000001,B01000010,B00111100};

void iniciar(){
  for (int x=0; x< MAX ; x++)
        {
           led.shutdown(x,false);    // Activar las matrices
           led.setIntensity(x,8);    // Se ajusta el brillo de los LED´s como se desee (0-15)
           led.clearDisplay(x);      // Se borra todo
        }
}

int dado(int i){
  int x = random(1,6);
  switch (x){
    case 1:{
       led.setRow(i,0,uno[0]);
       led.setRow(i,1,uno[1]);
       led.setRow(i,2,uno[2]);
       led.setRow(i,3,uno[3]);
       led.setRow(i,4,uno[4]);
       led.setRow(i,5,uno[5]);
       led.setRow(i,6,uno[6]);
       led.setRow(i,7,uno[7]);
    break;}
    case 2:{
       led.setRow(i,0,dos[0]);
       led.setRow(i,1,dos[1]);
       led.setRow(i,2,dos[2]);
       led.setRow(i,3,dos[3]);
       led.setRow(i,4,dos[4]);
       led.setRow(i,5,dos[5]);
       led.setRow(i,6,dos[6]);
       led.setRow(i,7,dos[7]);
    break;}
    case 3:{
      Serial.println("aca");
       led.setRow(i,0,tres[0]);
       led.setRow(i,1,tres[1]);
       led.setRow(i,2,tres[2]);
       led.setRow(i,3,tres[3]);
       led.setRow(i,4,tres[4]);
       led.setRow(i,5,tres[5]);
       led.setRow(i,6,tres[6]);
       led.setRow(i,7,tres[7]);
    break;}
    case 4:{
       led.setRow(i,0,cuatro[0]);
       led.setRow(i,1,cuatro[1]);
       led.setRow(i,2,cuatro[2]);
       led.setRow(i,3,cuatro[3]);
       led.setRow(i,4,cuatro[4]);
       led.setRow(i,5,cuatro[5]);
       led.setRow(i,6,cuatro[6]);
       led.setRow(i,7,cuatro[7]);
    break;}
    case 5:{
       led.setRow(i,0,cinco[0]);
       led.setRow(i,1,cinco[1]);
       led.setRow(i,2,cinco[2]);
       led.setRow(i,3,cinco[3]);
       led.setRow(i,4,cinco[4]);
       led.setRow(i,5,cinco[5]);
       led.setRow(i,6,cinco[6]);
       led.setRow(i,7,cinco[7]);
    break;}
    case 6:{
       led.setRow(i,0,seis[0]);
       led.setRow(i,1,seis[1]);
       led.setRow(i,2,seis[2]);
       led.setRow(i,3,seis[3]);
       led.setRow(i,4,seis[4]);
       led.setRow(i,5,seis[5]);
       led.setRow(i,6,seis[6]);
       led.setRow(i,7,seis[7]);
    break;}
 }
 return x;
}

void sumarpuntos(){
  int num1 =0;
  int num2 =0;
  int j1 =0;
  int j2 =0; 
  for (int x=0; x< 3 ; x++){
     num1 = dado(0);
     Serial.print(" Jugador 1, tirada ");
     Serial.println(x);
     num2 = dado(1);
     Serial.print(" Jugador 2, tirada ");
     Serial.println(x);
     j1=j1+num1;
     j2=j2+num2;
     delay(3000);
  }
  if (j1>j2){
    Serial.print(" El ganador es el jugador 1 con ");
    Serial.print(j1);
    Serial.println(" puntos");
  }
  else{
    if (j2>j1){
      Serial.print(" El ganador es el jugador 2 con ");
      Serial.print(j2);
      Serial.println(" puntos");
    }
    else{
      Serial.print(" Ambos jugadores empataron con ");
      Serial.print(j1);
      Serial.println(" puntos");
    }
    }
  }

void obtener3(){
  int num1 =0;
  int num2 =0; 
  while ((num1!=3)&&(num2!=3)){
     num1 = dado(0);
     Serial.print(" Jugador 1, obtuvo: ");
     Serial.println(num1);
     num2 = dado(1);
     Serial.print(" Jugador 2, obtuvo ");
     Serial.println(num2);
     delay(3000);
  }
  if (num1==3){
    Serial.println(" El ganador es el jugador 1");
  }
  else{
    Serial.println(" El ganador es el jugador 1");
  }
}

void dadoarcade(int i){
  int x = random(1,6);
  switch (x){
    case 1:{
       led.setRow(i,0,espada[0]);
       led.setRow(i,1,espada[1]);
       led.setRow(i,2,espada[2]);
       led.setRow(i,3,espada[3]);
       led.setRow(i,4,espada[4]);
       led.setRow(i,5,espada[5]);
       led.setRow(i,6,espada[6]);
       led.setRow(i,7,espada[7]);
    break;}
    case 2:{
       led.setRow(i,0,escudo[0]);
       led.setRow(i,1,escudo[1]);
       led.setRow(i,2,escudo[2]);
       led.setRow(i,3,escudo[3]);
       led.setRow(i,4,escudo[4]);
       led.setRow(i,5,escudo[5]);
       led.setRow(i,6,escudo[6]);
       led.setRow(i,7,escudo[7]);
    break;}
    case 3:{
       led.setRow(i,0,cancelar[0]);
       led.setRow(i,1,cancelar[1]);
       led.setRow(i,2,cancelar[2]);
       led.setRow(i,3,cancelar[3]);
       led.setRow(i,4,cancelar[4]);
       led.setRow(i,5,cancelar[5]);
       led.setRow(i,6,cancelar[6]);
       led.setRow(i,7,cancelar[7]);
    break;}
    case 4:{
       led.setRow(i,0,activar[0]);
       led.setRow(i,1,activar[1]);
       led.setRow(i,2,activar[2]);
       led.setRow(i,3,activar[3]);
       led.setRow(i,4,activar[4]);
       led.setRow(i,5,activar[5]);
       led.setRow(i,6,activar[6]);
       led.setRow(i,7,activar[7]);
    break;}
    case 5:{
       led.setRow(i,0,casco[0]);
       led.setRow(i,1,casco[1]);
       led.setRow(i,2,casco[2]);
       led.setRow(i,3,casco[3]);
       led.setRow(i,4,casco[4]);
       led.setRow(i,5,casco[5]);
       led.setRow(i,6,casco[6]);
       led.setRow(i,7,casco[7]);
    break;}
    case 6:{
       led.setRow(i,0,mover[0]);
       led.setRow(i,1,mover[1]);
       led.setRow(i,2,mover[2]);
       led.setRow(i,3,mover[3]);
       led.setRow(i,4,mover[4]);
       led.setRow(i,5,mover[5]);
       led.setRow(i,6,mover[6]);
       led.setRow(i,7,mover[7]);
    break;}
 }
}
