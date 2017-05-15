# WakeUpDarling!
Arduino + Coffee Machine Alarm

Prototype:

->![wakeup](https://cloud.githubusercontent.com/assets/22894897/22896151/3a740a36-f1dc-11e6-92b3-3020ded01b88.gif)<-

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

->![31caoriq80l _sy300_](https://cloud.githubusercontent.com/assets/22894897/20027208/738834a8-a2d3-11e6-9fa4-d4ee56378a8d.jpg)<-

Once I had everything, I wired the coffee machine as the light bulb in the simulator. 


-><img width="717" alt="screenshot 2017-02-13 10 51 39" src="https://cloud.githubusercontent.com/assets/22894897/22895685/a6b768c0-f1da-11e6-825c-6f4e9b76cdf5.png"><-

Schematics View:

<img width="736" alt="screenshot 2017-02-13 10 54 58" src="https://cloud.githubusercontent.com/assets/22894897/22895763/e223692c-f1da-11e6-817f-6fdb61156485.png">

The Real Time module was wired as following:

<img width="735" alt="screenshot 2017-02-13 10 59 11" src="https://cloud.githubusercontent.com/assets/22894897/22895935/79c6bd10-f1db-11e6-834a-51176f01b9c1.png">

Those Pins may vary on other Arduinos... just make sure you are wiring them to the SCL and SDA pins.

Code:

<pre>
<font color="#434f54">// WakeUpDarling!</font>
<font color="#434f54">// Dedicated to my wife and inspired by her.</font>
<font color="#434f54">// Made by Tania Molina</font>
<font color="#434f54">// License: MIT License</font>
<font color="#434f54">// Downloaded from: </font><u><font color="#434f54">https://circuits.io/circuits/3126865-wakeupdarling</font></u><font color="#434f54"></font>

<font color="#5e6d03">#include</font> <font color="#434f54">&lt;</font><b><font color="#d35400">DS3231</font></b><font color="#434f54">.</font><font color="#000000">h</font><font color="#434f54">&gt;</font> <font color="#434f54">//download if you don't have it yet.</font>
<font color="#5e6d03">#include</font> <font color="#434f54">&lt;</font><b><font color="#d35400">LiquidCrystal</font></b><font color="#434f54">.</font><font color="#000000">h</font><font color="#434f54">&gt;</font>

<b><font color="#d35400">DS3231</font></b> &nbsp;<font color="#000000">rtc</font><font color="#000000">(</font><font color="#00979c">SDA</font><font color="#434f54">,</font> <font color="#00979c">SCL</font><font color="#000000">)</font><font color="#000000">;</font>
<b><font color="#d35400">Time</font></b> <font color="#000000">t</font><font color="#000000">;</font>
<b><font color="#d35400">LiquidCrystal</font></b> <font color="#000000">lcd</font><font color="#000000">(</font><font color="#000000">7</font><font color="#434f54">,</font> <font color="#000000">6</font><font color="#434f54">,</font> <font color="#000000">5</font><font color="#434f54">,</font> <font color="#000000">4</font><font color="#434f54">,</font> <font color="#000000">3</font><font color="#434f54">,</font> <font color="#000000">2</font><font color="#000000">)</font><font color="#000000">;</font>


<font color="#00979c">void</font> <font color="#5e6d03">setup</font><font color="#000000">(</font><font color="#000000">)</font>
<font color="#000000">{</font>
 &nbsp;<font color="#434f54">// Setup Serial connection</font>
 &nbsp;<b><font color="#d35400">Serial</font></b><font color="#434f54">.</font><font color="#d35400">begin</font><font color="#000000">(</font><font color="#000000">115200</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#d35400">pinMode</font><font color="#000000">(</font><font color="#000000">9</font><font color="#434f54">,</font> <font color="#00979c">OUTPUT</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#d35400">digitalWrite</font><font color="#000000">(</font><font color="#000000">9</font><font color="#434f54">,</font> <font color="#00979c">LOW</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#000000">rtc</font><font color="#434f54">.</font><font color="#d35400">begin</font><font color="#000000">(</font><font color="#000000">)</font><font color="#000000">;</font>

 &nbsp;<font color="#000000">rtc</font><font color="#434f54">.</font><font color="#d35400">setTime</font><font color="#000000">(</font><font color="#000000">6</font><font color="#434f54">,</font> <font color="#000000">59</font><font color="#434f54">,</font> <font color="#000000">50</font><font color="#000000">)</font><font color="#000000">;</font> &nbsp;&nbsp;&nbsp;&nbsp;<font color="#434f54">// Set the real time for the module, uncomment to set time, comment once you set it and be sure the battery is new. </font>
 &nbsp;<font color="#434f54">//&lt;hour, minutes, seconds&gt; (24hr format)</font>
 &nbsp;<font color="#434f54">//rtc.setDate(1, 8, 2017); &nbsp;&nbsp;// Uncomment to set the date to January 1st, 2014 (optional)</font>
<font color="#000000">}</font>

<font color="#00979c">void</font> <font color="#5e6d03">loop</font><font color="#000000">(</font><font color="#000000">)</font>
<font color="#000000">{</font>
 &nbsp;<font color="#000000">t</font> <font color="#434f54">=</font> <font color="#000000">rtc</font><font color="#434f54">.</font><font color="#d35400">getTime</font><font color="#000000">(</font><font color="#000000">)</font><font color="#000000">;</font>
 
 &nbsp;<font color="#000000">lcd</font><font color="#434f54">.</font><font color="#d35400">begin</font><font color="#000000">(</font><font color="#000000">16</font><font color="#434f54">,</font> <font color="#000000">2</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#000000">lcd</font><font color="#434f54">.</font><font color="#d35400">clear</font><font color="#000000">(</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#434f54">// Send time</font>
 &nbsp;<font color="#000000">lcd</font><font color="#434f54">.</font><font color="#d35400">setCursor</font><font color="#000000">(</font><font color="#000000">1</font><font color="#434f54">,</font><font color="#000000">0</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#000000">lcd</font><font color="#434f54">.</font><font color="#d35400">print</font><font color="#000000">(</font><font color="#005c5f">"Wake up Darling"</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#000000">lcd</font><font color="#434f54">.</font><font color="#d35400">setCursor</font><font color="#000000">(</font><font color="#000000">0</font><font color="#434f54">,</font><font color="#000000">1</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#000000">lcd</font><font color="#434f54">.</font><font color="#d35400">print</font><font color="#000000">(</font><font color="#000000">t</font><font color="#434f54">.</font><font color="#d35400">hour</font><font color="#434f54">,</font> <font color="#00979c">DEC</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#000000">lcd</font><font color="#434f54">.</font><font color="#d35400">print</font><font color="#000000">(</font><font color="#005c5f">"hrs "</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#000000">lcd</font><font color="#434f54">.</font><font color="#d35400">print</font><font color="#000000">(</font><font color="#000000">t</font><font color="#434f54">.</font><font color="#d35400">min</font><font color="#434f54">,</font> <font color="#00979c">DEC</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#000000">lcd</font><font color="#434f54">.</font><font color="#d35400">print</font><font color="#000000">(</font><font color="#005c5f">"min "</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#000000">lcd</font><font color="#434f54">.</font><font color="#d35400">print</font><font color="#000000">(</font><font color="#000000">t</font><font color="#434f54">.</font><font color="#d35400">sec</font><font color="#434f54">,</font> <font color="#00979c">DEC</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#000000">lcd</font><font color="#434f54">.</font><font color="#d35400">print</font><font color="#000000">(</font><font color="#005c5f">"sec"</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#d35400">delay</font><font color="#000000">(</font><font color="#000000">1000</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;
 &nbsp;<font color="#434f54">//set alarm:</font>
 
 &nbsp;<font color="#5e6d03">if</font> <font color="#000000">(</font><font color="#000000">t</font><font color="#434f54">.</font><font color="#d35400">hour</font> <font color="#434f54">==</font> <font color="#000000">7</font> <font color="#434f54">&&</font> <font color="#000000">t</font><font color="#434f54">.</font><font color="#d35400">min</font> <font color="#434f54">==</font> <font color="#000000">0</font><font color="#000000">)</font> <font color="#434f54">//time to wake up</font>
 &nbsp;<font color="#000000">{</font>
 &nbsp;&nbsp;&nbsp;<font color="#d35400">digitalWrite</font> <font color="#000000">(</font><font color="#000000">9</font><font color="#434f54">,</font> <font color="#00979c">HIGH</font><font color="#000000">)</font><font color="#000000">;</font> <font color="#434f54">//turns on coffee machine</font>
 &nbsp;<font color="#000000">}</font>
 &nbsp;<font color="#5e6d03">if</font> <font color="#000000">(</font><font color="#000000">t</font><font color="#434f54">.</font><font color="#d35400">hour</font> <font color="#434f54">==</font> <font color="#000000">9</font> <font color="#434f54">&&</font> <font color="#000000">t</font><font color="#434f54">.</font><font color="#d35400">min</font> <font color="#434f54">==</font> <font color="#000000">0</font><font color="#000000">)</font> <font color="#434f54">//time to leave</font>
 &nbsp;<font color="#000000">{</font>
 &nbsp;&nbsp;&nbsp;<font color="#d35400">digitalWrite</font> <font color="#000000">(</font><font color="#000000">9</font><font color="#434f54">,</font> <font color="#00979c">LOW</font><font color="#000000">)</font><font color="#000000">;</font> <font color="#434f54">//turn off coffee machine</font>
 &nbsp;<font color="#000000">}</font>
 &nbsp;
<font color="#000000">}</font>

</pre>

To run the simulator, click here https://circuits.io/circuits/3145505-wakeupdarling

This is how it looks finished:

![ard](https://cloud.githubusercontent.com/assets/22894897/22409013/4d5550a8-e640-11e6-88ca-2ea34c908431.jpeg)

![ardu](https://cloud.githubusercontent.com/assets/22894897/22409431/ef554e34-e646-11e6-88f4-6e593f6a52df.jpeg)

I used an old box to put it inside so water/dust wouldn't damage it.

![arduino](https://cloud.githubusercontent.com/assets/22894897/22409587/25b8d340-e649-11e6-81ed-0803b6c6b85b.jpeg)

Good coffee helps this project to work better ;)
