# WakeUpDarling!
Arduino + Coffee Machine Alarm

Prototype:

![wakeup](https://cloud.githubusercontent.com/assets/22894897/22896151/3a740a36-f1dc-11e6-92b3-3020ded01b88.gif)

The light bulb represents the Coffee Machine and the RTC module will send the time to the LCD display, then you can set the alarm.

PARTS I USED:

Arduino Uno

Real Time Module for Arduino

LCD 16x2

Wires

Resistors (220Ω, 1kΩ)

Potentiometer

Coffee Machine (light bulb in the simulator)

Diode (1N4001)

Transistor NPN (2222A)

Relay SPDT 5VDC 

Soldering iron

Grounding Converters (2) like the one in the picture

![31caoriq80l _sy300_](https://cloud.githubusercontent.com/assets/22894897/20027208/738834a8-a2d3-11e6-9fa4-d4ee56378a8d.jpg)

Once I had everything, I wired the coffee machine as the light bulb in the simulator. 


<img width="717" alt="screenshot 2017-02-13 10 51 39" src="https://cloud.githubusercontent.com/assets/22894897/22895685/a6b768c0-f1da-11e6-825c-6f4e9b76cdf5.png">

Schematics View:

<img width="736" alt="screenshot 2017-02-13 10 54 58" src="https://cloud.githubusercontent.com/assets/22894897/22895763/e223692c-f1da-11e6-817f-6fdb61156485.png">

The Real Time module was wired as following:

<img width="735" alt="screenshot 2017-02-13 10 59 11" src="https://cloud.githubusercontent.com/assets/22894897/22895935/79c6bd10-f1db-11e6-834a-51176f01b9c1.png">

Those Pins may vary on other Arduinos... just make sure you are wiring them to the SCL and SDA pins.

Code:

```C++
// WakeUpDarling!
// Dedicated to my wife.
// Created by Tania Molina
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

  //rtc.setTime(6, 59, 50);     // Uncomment this line to set the real time for the module, then comment it again after uploading.
  //<hour, minutes, seconds> (24hr format)
  //rtc.setDate(1, 1, 2017);   // Uncomment to set the date to January 1st, 2017 (optional)
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
  if (t.hour == 9 && t.min == 0) //you left before this time and forgot to turn it off... an accident can happen!...
  {
    digitalWrite (9, LOW); //turns off the coffee machine and saves the world.
  }
  
}
```

To run the simulator, click here https://circuits.io/circuits/3145505-wakeupdarling

This is how it looks finished:
<p style="text-align: center;"><img src="https://cloud.githubusercontent.com/assets/22894897/26328068/fcf839e6-3f17-11e7-8404-03b5bd97d8cb.JPG" width="50%" height="50%"><img src="https://cloud.githubusercontent.com/assets/22894897/22409431/ef554e34-e646-11e6-88f4-6e593f6a52df.jpeg" width="50%" height="50%">

I used an old box to put it inside so water/dust wouldn't damage it.

<img src="https://cloud.githubusercontent.com/assets/22894897/22409013/4d5550a8-e640-11e6-88ca-2ea34c908431.jpeg" width="50%" height="50%"><img src="https://cloud.githubusercontent.com/assets/22894897/22409587/25b8d340-e649-11e6-81ed-0803b6c6b85b.jpeg" width="50%" height="50%">

Good coffee helps this project to work better ;) </p>
