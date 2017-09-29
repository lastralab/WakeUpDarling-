// WakeUpDarling!
// *Dedicated to my wife.
// License: MIT License
// Copyright (c) 2017 Niam Moltta 
// Downloaded from: https://circuits.io/circuits/3126865-wakeupdarling

#include <DS3231.h> //download if you don't have it yet.
#include <LiquidCrystal.h>

DS3231  rtc(SDA, SCL);
Time t;
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);


void setup()
{
  // Setup Serial connection
  Serial.begin(115200);
  pinMode(9, OUTPUT);
  digitalWrite(9, LOW);
  rtc.begin();

  rtc.setTime(6, 59, 50);     // Set the real time for the module 
  //<hour, minutes, seconds> (24hr format)
  //rtc.setDate(1, 8, 2017);   // Uncomment to set the date to January 1st, 2014 (optional)
}

void loop()
{
  t = rtc.getTime();
 
  lcd.begin(16, 2);
  lcd.clear();
  // Send time
  lcd.setCursor(1,0);
  lcd.print("Wake up Darling");
  lcd.setCursor(0,1);
  lcd.print(t.hour, DEC);
  lcd.print("hrs ");
  lcd.print(t.min, DEC);
  lcd.print("min ");
  lcd.print(t.sec, DEC);
  lcd.print("sec");
  delay(1000);
  
  //set alarm:
 
  if (t.hour == 7 && t.min == 0) //time to wake up
  {
    digitalWrite (9, HIGH); //turns on coffee machine
  }
  if (t.hour == 9 && t.min == 0) //time to leave
  {
    digitalWrite (9, LOW); //turn off coffee machine
  }
  
}
