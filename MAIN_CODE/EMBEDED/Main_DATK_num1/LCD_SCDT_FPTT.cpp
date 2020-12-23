#include "LCD_SCDT_FPTT.h"
ST7565 l(3,4,5,6,7);

void l_init()
{
  l.ON();
  l.SET(23,0,0,0,4); 
}
void ldb(String &str)
{
  char str_c[20];
  str.toCharArray(str_c,str.length()+1);
  Serial.println(str_c);
  unsigned char b PROGMEM = str_c;
  l.Asc_String(10,15,b, BLACK);
  l.Display();
}
void l_bd() // phu
{
  const static unsigned char text[] PROGMEM ="gooo dkkkkkkkkkkkkkkkkkkkkd";
  l.Asc_String(10,15,text,BLACK);
  l.Display();
}
void bm()
{
  l.Bitmap( 0,0,128,64,logo16_glcd_bmp,BLACK); 
  l.Bitmap( 0,0,128,64,image_glcd_bmp,BLACK); 
  l.Display();
}
void line()
{
  l.DrawLine(0,0,60,30,BLACK);
  l.Display();
}
void string_nonePSTR()
{
  unsigned char db="";
  unsigned char b PROGMEM = db;
  l.Asc_String(10,15,b, BLACK);
  l.Display();
}
//void oled_main()
//{
//  
//}
//void pointer()
//{
//  
//}
//void btn_read()
//{
//  
//}
