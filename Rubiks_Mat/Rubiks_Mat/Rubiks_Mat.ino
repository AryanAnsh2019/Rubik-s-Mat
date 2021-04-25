#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() 
{
  lcd.init();
  lcd.backlight();
  Serial.begin(115200);
}
unsigned long touch=0,touch1,start,finished,elapsed,over;
float h,m,s,ms;
void loop() 
{
  int i=1;
  touch=touchRead(4);
  touch1=touchRead(15);
  //Serial.println(touch1);
  //Serial.println(touch); 
  if(touch<=30&&touch>=10)
  {
    i=1;
    //start=millis();
  }
  if(touch1<=20&&touch1>=0)
  {
    i=0;
    //finished=millis();
  }
  if(i==1)
  {
    start=millis();
  }
  if(i==2)
  {
    finished=millis();
  }
  elapsed=start-finished;
  //h=int(elapsed/360000);
  //over=elapsed%360000;
  m=int(elapsed/60000);
  over=elapsed%60000;
  s=int(over/1000);
  ms=over%1000;
  lcd.setCursor(0,0);
  lcd.print(m);
  //Serial.println(m);
  //lcd.setCursor(0,2);
  lcd.print(":");
  //lcd.setCursor(0,3);
  lcd.print(s);
  lcd.print(":");
  lcd.print(ms);
}
