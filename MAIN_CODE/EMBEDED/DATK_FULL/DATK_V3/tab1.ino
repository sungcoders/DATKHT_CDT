

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
    (dir==1)?GO+=1:GO-=1;
    read_serial();
    click_button();
  }
  delay(50);
  EEPROM.write(0, GO);
  delay(50);
  lcd16((float)GO/200);
  Serial.print((float)GO/200);
  (GO<0)?lcd.setCursor(1,0),lcd.print("under over"):((GO/200>ERROR)?lcd.setCursor(1,0),lcd.print("under over"):lcd.print(""));
  digitalWrite(EN, HIGH);
}

void setpin() {for(int i=0; i<5; i++) {pinMode(pin[i],INPUT);}}

int read_button()
{
  if(digitalRead(pin[0])==0) {return (button_up);  }
  if(digitalRead(pin[1])==0) {return (button_down);}
  if(digitalRead(pin[2])==0) {return (button_mode);}
  if(digitalRead(pin[3])==0) {return (button_home);}
  return ERROR;
}

float math_step()
{
  float mili_step = GO/200;
  return (mili_step);
}

void LED(int num)
{
  for(int i=0; i<num; i++)
  {
    digitalWrite(13,HIGH);
    delay(500);
    digitalWrite(13,LOW);
    delay(500);
  }
}

void lcd16(float num)

{
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("MODE: ");
  lcd.setCursor(7,0);
  (mode==1)?(lcd.print("Quick")):((mode==5)?lcd.print("medium"):(mode==9)?lcd.print("slow"):lcd.print("one_step"));
  lcd.setCursor(1,1);
  lcd.print("Cycles: ");
  lcd.setCursor(9,1);
  lcd.print(num);
}

char *str_char(float num)
{
 String str = (String)num;
 str.toCharArray(cv, str.length()+1);
 return (cv);
}

void startup_init()
{
  lcd.begin();
  lcd.backlight();
  lcd.print("    Bat dau!  ");
  pinMode(_dir,OUTPUT);
  pinMode(_step,OUTPUT);
  pinMode(EN,OUTPUT);
  pinMode(13,OUTPUT);
  digitalWrite(EN,HIGH);
}
