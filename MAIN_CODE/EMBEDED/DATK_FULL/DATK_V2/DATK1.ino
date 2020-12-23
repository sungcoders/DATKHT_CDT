#include <EEPROM.h>
#include <avr/pgmspace.h>
#include <LiquidCrystal_I2C.h>
#define _dir      2
#define _step     3
#define EN        7
#define MSI1      6
#define MSI2      5
#define MSI3      4
#define en_up     1
#define en_down   0
#define dir_up    1
#define dir_down  0
#define low       0
#define high      1

#define TIME01S   1000
#define TIME05S   5000

LiquidCrystal_I2C lcd(0x27,16,2);

String  str = "";
int     ERROR = 9999;
int     mode = 1;
int     HOME;
int     GO;
int     steps_go;
int     limit_up;
const int     save_step PROGMEM = GO;
unsigned int     addr0=0, addr1=1, addr2=2 ,addr3=3 ,addr4=4;
const int    pin[5] = {8,9,10,11};
static char cv[20];
typedef enum { button_up, button_down, button_mode, button_home }button;

void setup()
{
  Serial.begin(9600);
  delay(TIME01S);
  startup_init();
  setpin();
  GO = EEPROM.read(0);
  lcd16((float)GO/200);
  Serial.print((float)GO/200);
  Serial.print('a');
}

void loop()
{
  click_button();
  read_serial();
}
