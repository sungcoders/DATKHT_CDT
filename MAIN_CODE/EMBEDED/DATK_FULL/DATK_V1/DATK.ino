#include <LiquidCrystal_I2C.h>
#define _dir      2
#define _step     3
#define EN        7
#define MSI1      6
#define MSI2      5
#define MSI3      4
#define mode1     1
#define mode2     5
#define mode3     9
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
int     mode = mode1;
int     HOME;
int     GO;
const int    pin[5] = {8,9,10,11};
typedef enum { button_up, button_down, button_mode, button_home }button;

void setup()
{
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  pinMode(_dir,OUTPUT);
  pinMode(_step,OUTPUT);
  pinMode(EN,OUTPUT);
  pinMode(13,OUTPUT);
  setpin();
  delay(TIME05S);
}

void loop()
{
  click_button();
}
