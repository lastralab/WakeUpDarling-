

//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// WakeUpDarling!
// 
// Made by Tania Molina
// License: CERN Open Hardware License
// Downloaded from: https://circuits.io/circuits/3126865-wakeupdarling

#include <LiquidCrystal.h>
#include <DS3231.h> //download it if is not in your library

DS3231 rtc(SDA, SCL);
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int starttime;
int activetime;
int prevoustime = 0;

int hours = 0;
int mins = 0;

void setup()
{
  lcd.begin(16, 2);
  lcd.clear();
  
  Serial.begin(115200);

  pinMode(11, INPUT);
  digitalWrite(11, LOW);
  pinMode(10, INPUT);
  digitalWrite(10, LOW); 
  pinMode(9, OUTPUT);
  digitalWrite(9, LOW);
  rtc.begin();
  rtc.setTime(19,30,00); //Real Time for the Module, example: (19:30:00)
  lcd.setCursor(1,0);
  lcd.print("Wake up Darling");
  lcd.setCursor(0,1);
  lcd.print(rtc.getTimeStr());
}

void loop()
{
  activetime = (millis() / 1000) - starttime;
      
   if (prevoustime < (activetime - 59))
      {
       mins++;
       prevoustime = activetime;
      }  
   if (mins > 59)
     {
      hours++;
      mins = 0;
     } 
    
   if(hours > 23)
     {
      hours = 0; 
     }
  
  lcd.setCursor(6,0);
  
  if(hours < 10)
  {
    lcd.print("0");
    lcd.print(hours);
  }
  else
  {
    lcd.print(hours);
  }
    
    lcd.print(":");
    
  if (mins < 10)
  {
    lcd.print("0");
      lcd.print(mins);
  }
  else
  {
      lcd.print(mins);
  }

if (hours == 6 && mins == 0)
{ 
  digitalWrite (9, HIGH);  
    } 
if (hours == 9 && mins == 0)
{
  digitalWrite (9, LOW);
}
  
}
