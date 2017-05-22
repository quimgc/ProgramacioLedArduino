/**
   \par Copyright (C), 2012-2016, MakeBlock
   @file    ColorLoopTest.ino
   @author  MakeBlock
   @version V1.0.0
   @date    2015/09/02
   @brief   Description: this file is sample code for RGB LED, It used for random color change

   Function List:
   1. bool MeRGBLed::setColorAt(uint8_t index, uint8_t red, uint8_t green, uint8_t blue)
   2. void MeRGBLed::show()
   \par History:
   <pre>
   <Author>     <Time>        <Version>      <Descr>
   Mark Yan     2015/09/02    1.0.0          rebuild the old lib
   </pre>
*/
#include "MeOrion.h"

//Per indicar a quin port està connectat la tira de led. En aquest cas al port 5.
MeRGBLed led(PORT_5);

int cont=0;
int num=0;


void setup() {
  inici();
}

void loop() {
 
aleatori();

apagarLlums();

//faig una pausa de 5 minuts.
delay(300000);
}




void inici() {
  float color=0;
  //int compt=0;
  
  while (cont!=4) {

    for (int i=0; i < 15; i++) {
      color=color+16.5;
      led.setColorAt(i, 0, 0, color);
      led.show();
      delay(50);
    }
   

    for (int i = 15; i > 0; i--) {
      color=color-16.5;
      led.setColorAt(i, color, 0, 0);
      led.show();
      delay(50);
      
    }
    
   
cont++;
  }
  delay(1000);
  cont=0;
  apagarLlums();
  
}


void apagarLlums(){
 for (int i=0; i<15; i++){
  led.setColorAt(i,0,0,0);
  led.show();
 }
}

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
  if(num==0){
    num=1;
  }else{
    num=0;
  } 

vegades--;}
  

}




