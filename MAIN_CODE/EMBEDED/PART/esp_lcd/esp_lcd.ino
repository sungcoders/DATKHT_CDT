#include "ST7565_homephone_esp8266.h"//a
ST7565 lcd(0,1, 2,3);//b
 
 
void setup()   {  
  lcd.ON();//c
  lcd.SET(22,0,0,0,4);   //d
  
}
void loop(){
  lcd.Tri(60,10,30,40,90,40,BLACK);
  lcd.Display();
}  
