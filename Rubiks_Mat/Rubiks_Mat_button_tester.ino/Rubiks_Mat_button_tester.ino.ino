#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  pinMode(2, OUTPUT);
  //pinMode(15, INPUT);
  lcd.init();
  lcd.backlight();
  Serial.begin(115200);
}
unsigned long touch, start, finished, elapsed, over;
float h, m, s, ms;
boolean on = false;
void displayResult()
{
  lcd.init();
  lcd.backlight();
  elapsed = start - finished;
  //h=int(elapsed/360000);
  //over=elapsed%360000;
  m = int(elapsed / 60000);
  over = elapsed % 60000;
  s = int(over / 1000);
  ms = over % 1000;
  //lcd.setCursor(0,0);
  //lcd.print("0");
  lcd.print(m,0);
  //Serial.println(m);
  //lcd.setCursor(2,0);
  lcd.print(":");
  //lcd.setCursor(3,0);
  lcd.print(s,0);
  lcd.print(":");
  lcd.print(ms,0);
  //delay(500);
}
void loop()
{
  int i = 1;
  touch = touchRead(4);
  //Serial.println(touch1);
  //Serial.println(touch);
  if (touch <= 30 && touch >= 10)
  {
    if (on == true)
    {
      on = false;
    }
    else
    {
      on = true;
    }
    //start=millis();
  }
  if (on == true)
  {
    //Serial.println("a");
    digitalWrite(2, HIGH);
    //start = millis();
  }
  if (on == false)
  {
    digitalWrite(2, LOW);
    //finished = millis();
    //delay(200);
    //displayResult();
  }
delay(500);
}
