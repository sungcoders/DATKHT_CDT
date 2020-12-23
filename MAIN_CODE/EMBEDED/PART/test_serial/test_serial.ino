String str,str1;
char str_c[50];
byte ch;
void setup()
{
  Serial.begin(9600);
  while (!Serial) {;}
}

void loop()
{
  while(Serial.available()>0)
  {
    str+=char(Serial.read());
    delay(10);
    Serial.print(".");
    if(Serial.available()==0)
    {
      delay(5);
      Serial.println("end");
      Serial.println(str);
        if(str=="on\r")
        {
          Serial.println("bat on");
          str="";
        }
        else if(str=="off\r")
        {
          Serial.println("tat off");
          str="";
        }
        else
        {
          Serial.println("khong xu li duoc: " + str);
          str="";
        }
    }
  }
}
