# WakeUpDarling-
Arduino based Coffee Machine Alarm

Video:

![simwud-2](https://cloud.githubusercontent.com/assets/22894897/20111199/a6c945e0-a5a4-11e6-84fa-bf9d606cb45e.gif)

Lab View:

<img width="792" alt="screen shot 2016-11-06 at 2 09 11 pm" src="https://cloud.githubusercontent.com/assets/22894897/20041727/a91ebbfc-a42a-11e6-9671-c52053b632ea.png">

Parts I used:

Arduino Uno

Pushbuttons (2)

LCD 16x2

Wires

Resistors (220Ω, 1kΩ)

Potentiometer

Coffee Machine (light bulb in the simulator)

Diode (1N4001)

Transistor NPN (2222A)

Relay SPDT 5V (coil) 120VAC

Soldering iron

Grounding Converters (2) like the one in the picture

![31caoriq80l _sy300_](https://cloud.githubusercontent.com/assets/22894897/20027208/738834a8-a2d3-11e6-9fa4-d4ee56378a8d.jpg)

Once I had everything, I wired the coffee machine as it was the light bulb.  

Schematics View:

<img width="863" alt="screen shot 2016-11-08 at 8 56 51 am" src="https://cloud.githubusercontent.com/assets/22894897/20106175/78fda4d4-a591-11e6-80ca-00de4065ab49.png">

Code:

//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// WakeUpDarling!
// 
// Made by Tania Melina
// License: CERN Open Hardware License
// Downloaded from: https://circuits.io/circuits/3145505-wakeupdarling


#include <LiquidCrystal.h>

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
  
  Serial.begin(9600);
  
  pinMode(11, INPUT);
  digitalWrite(11, HIGH);
  pinMode(10, INPUT);
  digitalWrite(10, HIGH); 
  pinMode(9, OUTPUT);
  digitalWrite(9, LOW);
  
  starttime = millis()/1000;
}
void loop()
{
  
  if(digitalRead(10) == LOW)
  
  {
    
    lcd.setCursor(0,1);
    lcd.print("Wake up Darling!");
    lcd.setCursor(0,0);
    hours++;
    delay(250);
  }
    
  else if (digitalRead(11) == LOW)
    {
     mins++;
     delay(250);
    } 
  
      activetime = (millis() / 1000) - starttime;
      if(prevoustime < (activetime - 59))
      {
       mins++;
       prevoustime = activetime;
      } 
      
      if(mins > 59)
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

The last part of the code is for you to select the alarm time.

Long Video:

![simwudlong](https://cloud.githubusercontent.com/assets/22894897/20111111/4b3acc94-a5a4-11e6-9b0f-a2b7fd9c4a49.gif)

To run the simulator, click here https://circuits.io/circuits/3145505-wakeupdarling

This is how it looks finished:

![whatsapp image 2016-11-08 at 15 05 07](https://cloud.githubusercontent.com/assets/22894897/20141226/a0661860-a64c-11e6-8023-d0a8f22379e6.jpeg)

![whatsapp image 2016-11-08 at 14 40 33](https://cloud.githubusercontent.com/assets/22894897/20141360/412e058c-a64d-11e6-8785-892cfd460142.jpeg)

