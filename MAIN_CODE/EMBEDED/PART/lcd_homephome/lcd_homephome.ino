#include  <glcd_spi.h>

#define   PIN_GLCD_CS         10           //LOAD
#define   PIN_GLCD_SDA        11           //DIN
#define   PIN_GLCD_AO         12           //AO
#define   PIN_GLCD_SCK        13           //CLK

#define   GRAPHIC_MODE        1
#define   TEXT_MODE           0

int num_count = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  delay(1000);
  
  /*Init GLCD*/
  InitLcd(PIN_GLCD_CS, PIN_GLCD_SCK, PIN_GLCD_SDA, PIN_GLCD_AO, TEXT_MODE);  

  /*Run test function*/
  digitalWrite(LED_BUILTIN, HIGH);
  TestLcd();
  delay(2000);  
  ClearLcd();
  PrintLcd(0, 0, "VBLUno Hello World");
  PrintIntLcd(1, 0, 123);
  PrintFloatLcd(2, 0, 35.6791);
  PrintLcd(3, 0, "-----------");
}

// the loop function runs over and over again forever
void loop() {  
  delay(1000);
  PrintIntLcd(5, 0, num_count);
  if(num_count++ > 10000){
    num_count = 0;
  }
}
