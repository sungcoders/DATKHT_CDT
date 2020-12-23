
void read_serial()
{
  if(Serial.available())
  {
    byte c = Serial.read();
    switch((char)c)
    {
      case 'm':
        {
          mode=mode+4;
          if(mode>13) { mode=1; }
          switch(mode)
          {
            case 1: { Serial.print('a');  lcd16((float)GO/200); steps_go = 200; Serial.print((float)GO/200); }   break;
            case 5: { Serial.print('b');  lcd16((float)GO/200); steps_go = 200; Serial.print((float)GO/200); }   break;
            case 9: { Serial.print('c');  lcd16((float)GO/200); steps_go = 200; Serial.print((float)GO/200); }   break;
            case 13:{ Serial.print('d');  lcd16((float)GO/200); steps_go = 2;   Serial.print((float)GO/200); }    break;
          }
        }
        break;
      case 'u': { _steps(dir_up, steps_go, mode); }  break;
      case 'd': { _steps(dir_down, steps_go, mode); }  break;
      case 'h': { lcd.setCursor(14,0); lcd.print("OK"); HOME=0; GO=0; Serial.write('q'); lcd16((float)GO/200);}  break;
    }
  }
}

void click_button()
{
  switch (read_button())
  {
    case button_up: { delay(500); _steps(dir_up,steps_go,mode); } break;
    case button_down: { delay(500); _steps(dir_down,steps_go,mode); } break;
    case button_mode:
    {
      while(digitalRead(pin[2])==0)
      {
        mode=mode+4;
        delay(500);
        if(mode>13) { mode=1; }
        switch(mode)
        {
          case 1: { Serial.write('a'); lcd16((float)GO/200); Serial.print((float)GO/200); steps_go = 200;}   break;
          case 5: { Serial.write('b'); lcd16((float)GO/200); Serial.print((float)GO/200); steps_go = 200;}   break;
          case 9: { Serial.write('c'); lcd16((float)GO/200); Serial.print((float)GO/200); steps_go = 200;}   break;
          case 13:{ Serial.write('d'); lcd16((float)GO/200); Serial.print((float)GO/200); steps_go = 2;}    break;
        }
      }
    }
    break;
    case button_home:
    {
      delay(200);
      Serial.write('q');
      HOME=0;
      GO=0;
      lcd.setCursor(14,0);
      lcd.print("OK");
      lcd16((float)GO/200);
    }
    break;
  }
}
