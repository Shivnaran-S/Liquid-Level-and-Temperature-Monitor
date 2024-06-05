#include <OneWire.h>
#include <DallasTemperature.h>

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define ONE_WIRE_BUS 2

//Arduino Code - 2N2222
int Button = 6; //GPIO 2 --- Digital Input coming from button

// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledPin = 13;

// defines variables
long duration;
int distance;
int safetyDistance;

float Celsius = 0;
float Fahrenheit = 0;

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
sensors.begin(); // Beginning the waterproof temperature sensor
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
pinMode(Button, OUTPUT); //Step pin as input
Serial.begin(9600); // Starts the serial communication
// initialize the LCD
	lcd.begin();
// Turn on the blacklight and print a message.
	lcd.backlight();
}


void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance = (duration / 2) * 0.0344;

lcd.setCursor(0,0);
lcd.println("Distance: ");
lcd.println(distance);

safetyDistance = distance;
if (safetyDistance <=2){
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
}
else{
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
}

// Prints the distance on the Serial Monitor


sensors.requestTemperatures();

  Celsius = sensors.getTempCByIndex(0);
  Fahrenheit = sensors.toFahrenheit(Celsius);
  if(Celsius >=32 ){
  digitalWrite(Button, HIGH);
  delay(500);//5000
  }
  else{
  digitalWrite(Button, LOW);
  }
  delay(100);//100
  Serial.print(Celsius);
  Serial.print(" C  ");
  Serial.print(Fahrenheit);
  Serial.println(" F");
  delay(100);//100
}
