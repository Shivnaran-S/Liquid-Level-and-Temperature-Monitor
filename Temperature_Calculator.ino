//YouTube|Tech at Home

#include <OneWire.h>
#include <DallasTemperature.h>

//Arduino Code - 2N2222
int Button = 6; //GPIO 2 --- Digital Input coming from button
#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

float Celsius = 0;
float Fahrenheit = 0;

void setup() {
  sensors.begin();
  Serial.begin(9600);
  // put your setup code here, to run once:
pinMode(Button, OUTPUT); //Step pin as input

}

void loop() {
  sensors.requestTemperatures();

  Celsius = sensors.getTempCByIndex(0);
  Fahrenheit = sensors.toFahrenheit(Celsius);
  if(Celsius > 30){
  digitalWrite(Button, HIGH);
  delay(5000);
  }
  else{
  digitalWrite(Button, LOW);
  }
  delay(1000);
  Serial.print(Celsius);
  Serial.print(" C  ");
  Serial.print(Fahrenheit);
  Serial.println(" F");
  delay(1000);
}
//const int lm35_pin = A1;      /* LM35 O/P pin */


