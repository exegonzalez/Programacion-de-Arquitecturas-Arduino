/* 9. Utilice una matriz led para simular la tirada de un dado clásico (del 1 al 6), luego conecte dos matrices y resuelva las siguientes actividades:
a. Simule que dos jugadores tiran un dado 3 veces cada uno (rotando sus turnos) y suman los puntos determinar quién gano (es decir quien sumo mas).
b. Simule ahora que dos jugadores tirar un dado un turno cada uno hasta que uno obtenga un tres, el que lo consiga primero gana el juego.
c. Modifique el diseño de su dado y cree un dado arcade donde los símbolos serán espada, escudo, casco, mover, perder turno, activar poder; 
deberá usar su creatividad para determinar los diseños que representen dichas actividades.*/


/* (Guia 5) Ej 1. Cree una librería para Arduino que le permita migrar todo el código utilizado para resolver el ejercicio 9 de la guía 3 (el de los dados), 
 *  de manera que en sketch principal solo importe la librería y queden las llamadas a las funciones.*/

#include "dados.h"

void setup(){
  Serial.begin(9600);
      iniciar();
   }

void loop(){ 
        //sumarpuntos();
        //randomSeed(analogRead(A0));
        //obtener3();
        dado(0);
        //dadoarcade(0);
        delay(500);  //se espera 1 segundo
        //led.clearDisplay(0);
  }
