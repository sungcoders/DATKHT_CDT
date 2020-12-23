/*
  SCROUCE: Form TTPCTU DESIGN by SCDT K$@
  TRY YOUR BEST.
 */

void setup()
{
  start_lcd();
  lcd_clear();
  delay(100);
}

void loop()
{
//  HOME();
    lcd_print(0,5,"Internet:           ");
//    lcd_print(10,5,"success");
    lcd_print(52,5,"again_");
    lcd_print(18,5,"10");
    lcd_print(0,6,"MQTT:");
    lcd_int(5,6,12);
   lcd_print(0,7,"YHDC:     A        W");
   delay(5000);
   lcd_clear();
}
