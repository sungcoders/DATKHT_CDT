#include "LCDSPI_SCDT.h"
#include <EEPROM.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>

byte a=250;
uint16_t dem=0;
float home0;

typedef enum { btn_u, btn_d, btn_e, btn_m }btn;
typedef enum { mn_main, mn_setting, mn_limitup, mn_limitdown, mn_stepup, mn_stepdow }mn;
int mn_position = mn_main;
byte pointer=1, sethome, up, down, mode;

void menu_home(byte mode, float cycle)
{
//  lcd_clear();
  lcd_print(0,0,"HOME");
  lcd_print(0,1,"Mode:");
  lcd_int(5,1,mode);
  lcd_print(9,1,"Cycle:");
  lcd_number(15,1,cycle);
  switch(btn_click())
  {
    case btn_u:
      break;
    case btn_d:
      break;
    case btn_m:
    {
      lcd_print(3,6,"SET HOME AT HERE ?");
      lcd_print(3,7,"click again to accept");
      switch(btn_click())
      {
        case btn_m:
        {
          lcd_print(6,6,"Home is Setted");
          break;
        }
      }
      break; 
    }
    case btn_e:
      break;
  }
}

void menu_setting()
{
//  lcd_clear();
  lcd_print(0,0,"HOME/SETTING");
  lcd_print(1,1,"Select Your Setting");
  lcd_print(3,2,"Mode Config");
  lcd_print(3,3,"Step Up");
  lcd_print(3,4,"Step Down");
  switch(btn_click())
  {
    case btn_u:
    {
      pointer=(pointer<1)? 5 :pointer--;
      break;
    }
    case btn_d:
    {
      pointer=(pointer>5)? 1 :pointer++;
      break;      
    }
  }
}

void HOME()
{
  switch(mn_position)
  {
    case mn_main:
    {
      menu_home(2,345.67);
      break;
    }
    case mn_setting:
    {
     break;
    }
  }
}
byte point()
{
  switch(pointer)
  {
    case 1:
    {
      lcd_print(0,2,">");
      return 1;
      break;
    }
    case 2:
    {
      lcd_print(0,3,">");
      return 2;
      break;
    }
    case 3:
    {
      lcd_print(0,4,">");
      return 3;
      break;
    }
    case 4:
    {
      lcd_print(0,5,">");
      return 4;
      break;
    }
    case 5:
    {
      lcd_print(0,6,">");
      return 5;
      break;
    }
    default:
    {
      return 0;
      break;      
    }
  } 
}

byte btn_click()
{
  byte btn_up = digitalRead(2);
  byte btn_down = digitalRead(3);
  byte btn_enter = digitalRead(4);
  byte btn_move = digitalRead(5); 
  if(btn_up==0)
  {
    return btn_u;
  }
  else if(btn_down==0)
  {
    return btn_d;
  }
  else if(btn_enter==0)
  {
    return btn_e;   
  }
  else if(btn_move==0)
  {
    return btn_m;
  }
}
