#define up    5
#define down  6
#define enter 7
#define back  8
// khai bao pin
const int stepPin = 3; 
const int dirPin = 2; 

struct sinhvien
{
  int mssv;
  char ten[20];
};

typedef enum {
  BUT_LEFT=1,
  BUT_DOWN,
  BUT_CONFIRM,
  BUT_RIGHT,
  BUT_UP
} ButtonState;

void setup()
{
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
}
void loop()
{
  digitalWrite(dirPin,LOW);
  digitalWrite(7,HIGH);
  for(int x = 0; x < 200; x++)
  {
    digitalWrite(stepPin,HIGH); 
    delay(5); 
    digitalWrite(stepPin,LOW); 
    delay(5); 
  }
  digitalWrite(7,LOW);
  delay(10000);
  
  digitalWrite(dirPin,HIGH);
  digitalWrite(7,HIGH);
  for(int x = 0; x < 200; x++)
  {
    digitalWrite(stepPin,HIGH); 
    delay(5); 
    digitalWrite(stepPin,LOW); 
    delay(5); 
  }
  digitalWrite(7,LOW);
  delay(10000);
  
}
