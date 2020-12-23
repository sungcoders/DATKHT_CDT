String sdata="";  // Initialised to nothing.
byte test,start;
 
void setup (void)
{
   Serial.begin(115200);
   Serial.println("Command Interpreter");
}
 
void loop(void ) {
  byte ch;
  String valStr;
  int val;
  while(Serial.available())
  {
    ch = Serial.read();
    sdata += (char)ch;
    if (ch=='\r')
    {
      sdata.trim();
      switch(sdata.charAt(0))
      {
       case 's':
          start = 1;
          Serial.println("Start Process");
          break;
       case 't':
          test = 1;
          Serial.println("Test");
          break;
       default: Serial.println(sdata);
      }
      if(sdata=="good")
      {
        Serial.println("dung roi");
      }
      else
      {
        Serial.println("no ok");
      }
      sdata = "";
    }
  } // end while
}
