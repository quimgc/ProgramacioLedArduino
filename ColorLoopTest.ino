/**
   \par Copyright (C), 2012-2016, MakeBlock
   @file    ColorLoopTest.ino
   @author  Quim González Colat
   @version V1.0.0
   @date    2015/09/02
   @brief   Codi Programació Arduino

*/
#include "MeOrion.h"

//Per indicar a quin port està connectat la tira de led. En aquest cas al port 5.
MeRGBLed led(PORT_5);

/* Aquesta variable s'utilitza per la funció aleatori
 *  Per saber quan un numero és parell o imparell.
 *  S'utilitza per saber quan s'ha d'il·luminar.

*/

int num=0;


void setup() {
  
  //Crido la funció apagarLlums() per apagar tots els llums de la tira de led;
  apagarLlums();

  //Crido la funció inici() per recorrer 4 cops la matriu de led;
  inici();
}

void loop() {

 //crido la funció aleatori per fer l'efecte intermitent n vegades.
aleatori();


//apago els llums;
apagarLlums();

//faig una pausa de 5 minuts.
delay(300000);
}


/*El que es fa amb aquesta funció és un bucle que es repeteix cont vegades
 * i al seu interior hi ha dos bucles, un que va al incrementat i l'altre que va decrementant.
 * Amb això s'aconsegueix un efecte visual amb que la llum va de banda a banda. 
 * Quan cont = 4, es fa una pausa de 1 segon i s'apaguen els llums.

*/
void inici() {
  float color=0;
  
  //Serveix per contar quants cops s'ha d'executar.
  int cont=0;
  while (cont!=4) {

    for (int i=0; i < 15; i++) {
      color=color+16.5;
      led.setColorAt(i, 0, 0, color);
      led.show();
      delay(50);
    }
   

    for (int i = 15; i >=0; i--) {
      color=color-16.5;
      led.setColorAt(i, color, 0, 0);
      led.show();
      delay(50);
      
    }
    
   
cont++;
  }
  delay(1000);
  
}

// recorro un bucle per apagar tots els llums de la matriu.
void apagarLlums(){
 for (int i=0; i<15; i++){
  led.setColorAt(i,0,0,0);
  led.show();
 }
}


/* Amb aquesta funció s'agafa un número random entre 1 i 100
 *  i es repeteix el bucle random vegades.
 *  
 *  Amb aquest bucle el que s'aconsegueix és un efecte visual parpadejant amb colors aleatoris
 *  i fent un efecte amb que s'encen una si, una no. 
*/


void aleatori(){
int vegades= random(1,100);
while(vegades!=0){
 
  for (int i=0; i<15; i++){
    if(i%2==num){
    led.setColorAt(i, random(0,254), random(0,254), random(0,254));  
    }else{
      led.setColorAt(i,0,0,0);
    }
    led.show();
 }
 
  delay(100);

  //Amb aquesta condicio el que s'aconsegueix es que cada cop s'encengui una llum diferent.
  if(num==0){
    num=1;
  }else{
    num=0;
  } 

vegades--;}
  

}




