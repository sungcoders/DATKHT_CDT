
void click_button()
{
  switch (read_button())
  {
    case button_up:
    {
      Serial.println("up");
      _steps(dir_up,1,mode);
    }
    break;
    case button_down:
    {
      Serial.println("down");
      _steps(dir_down,1,mode);
    }
    break;
    case button_mode:
    {
      Serial.println("mode");
      mode=mode+4;
      if(mode>9)
      {
        mode=1;
      }
    }
    break;
    case button_home:
    {
      Serial.println("home");
      lcd.print("sethome at here");
    }
    break;
    default: {Serial.print("");}
  }
}

void multi_step(int msi1, int msi2, int msi3)
{
  pinMode(MSI1,OUTPUT);
  pinMode(MSI2,OUTPUT);
  pinMode(MSI3,OUTPUT);
  digitalWrite(MSI1,msi1);
  digitalWrite(MSI2,msi2);
  digitalWrite(MSI3,msi3);
}

void _steps(boolean dir, int steps,int mode)
{  
  digitalWrite(EN, LOW);
  digitalWrite(_dir, dir);
  for (int i = 0; i < steps; i++)
  {
    digitalWrite(_step, HIGH);
    delay(mode);
    digitalWrite(_step, LOW);
    delay(mode);
    GO+=i;
    lcd.print(math_step());
  }
  digitalWrite(EN, HIGH);
}

void setpin() {for(int i=0; i<5; i++) {pinMode(pin[i],INPUT);}}

int read_button()
{
  if(digitalRead(pin[0])==0) {return (button_up);}
  if(digitalRead(pin[1])==0) {return (button_down);}
  if(digitalRead(pin[2])==0) {return (button_mode);}
  if(digitalRead(pin[3])==0) {return (button_home);}
  return ERROR;
}

void read_serial()
{
  while(Serial.available())
  {
    byte c = Serial.read();
    str+=(char)c;
    delay(10);
    if (c=='\r')
    {
      str.trim();
      Serial.println(str);
      str = "";
      switch((char)c)
      {
        case 'u':
          digitalWrite(13,HIGH);
          break;
      }
    }
  }
}

void check_mode()
{
  switch(mode)
  {
    case mode1:
      break;
    case mode2:
      break;
    case mode3:
      break;
  }
}

float math_step()
{
  float mili_step = GO/200;
  return (mili_step);
}
