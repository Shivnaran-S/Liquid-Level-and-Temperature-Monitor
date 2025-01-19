###Liquid Level and Temperature Monitor

The thermal and level identifier of liquid can be used in the manufacturer sector. As it is automated it reduces the manpower and improves the production. It doesn’t produce any fault in it, thus wastage of loss is neglected.

As a liquid tank is being filled once the liquid level reaches the maximum limit the distance calculator made of ultrasonic sensor detects that the expected liquid level is reached and gives a buzzer sound with light glowing beside .
Also LCD displays the distance between the increasing liquid level and sensor . ( Here once the distance between liquid level and sensor is 2 cm the buzzer gives a buzzing sound ) . So the incoming liquid stops and now the liquid proof temperature sensor measures the temperature of the liquid , if the temperature is found to be above a particular temperature ( here 32 degree Celsius ) the fan starts  running and cools down the liquid temperature . Once the liquid is cooled , the fan stops running .

This project can be extended with auto filling of the tank once the liquid level goes down a particular level and auto stopping of liquid pouring inside the tank when the maximum limit is reached . Also the temperature can be maintained at a particular level by using a fan and a heater in large scale applications .

This project can satisfy various demands from simple home needs to industry needs when advanced and made on a large scale . 

Tools Required are :  Ultrasonic Sensor HC-SR04, Waterproof Temperature Sensor, Fan, LED, LCD Display, Transistor, 4.7H ohm resistors, jumper wires, breadboard and Arduino UNO and its software application.
Connections made : 

ultrasonic sensor —-->  Arduino
Vcc               —-->  5V
GND               —-->  GND
Trig              —-->  Digital I/O pin 9
Echo              --->  Digital I/O pin 10

Buzzer : 
Positive long leg   → Digital I/O pin 11
Negative short leg  → Ground of Arduino

LED           —-->     Arduino
Long leg (+ve)   →     One leg of 4.7K ohm Resistor
Short leg (-ve)  →     Ground

RESISTOR ( 4.7K ohm Resistor )   →  Arduino
One leg     			                  →  Long leg (+ve) of LED
Another leg                      →  Digital pin 13
      
Water Proof TemperatureSensor    →  Arduino
( + ve )   - Red                 →  5 Volt
( - ve )   - Black               →  GND
Data pin   - Yellow              →  Digital pin 2
Connect Red and Yellow wire with a 4.7K ohm resistor
      
FAN  : 
Connect fan’s black wire to 5 volt of arduino
Connect fan’s white wire to transistor’s third pin
      
LCD		→ Arduino
Vcc  → +5 Volt
GND		→ GND
SDA		→ A4
SCL		→ A5

Transistor : 
Connect middle pin to one leg of a 4.7K ohm resistor and connect that resistor’s another leg to the digital I/O pin 6 of arduino
Connect one end pin to black wire of fan
Another end pin to arduino’s 5 volt

Code implementation: using C++
Software | Arduino https://www.arduino.cc/en/software

NEW LEARNINGS:
We got to gain a deeper understanding of how a computer's hardware components interact with software to execute instructions. We have likely gained several new insights, skills and a valuable learning experience.Mainly we got to know about electronic components like arduino and rest all the sensors.
