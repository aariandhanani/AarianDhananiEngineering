/*
* Aarian Dhanani
* 2/22/2021
* Humidity Sensor
* https://github.com/adafruit/DHT-sensor-library/blob/master/examples/DHTtester/DHTtester.ino (Not exactly like the sensor)
* https://www.circuitbasics.com/how-to-set-up-the-dht11-humidity-sensor-on-an-arduino/ (Main source for this)
*/

#include <dht.h>

dht DHT;

#define DHT11_PIN 7

int controller = 0;
const int ledPin1 = 4;
const int ledPin2 = 5;
const int ledPin3 = 6;
const int fanPin = 12;

// Setup
void setup()
{ 
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT); // This is an output
  pinMode(ledPin2, OUTPUT); // This is an output
  pinMode(ledPin3, OUTPUT); // This is an output
  pinMode(fanPin, OUTPUT); // This is an output
}

void loop()
{
  int check = DHT.read11(DHT11_PIN);

  //temperature
  int temperatureVariable = (DHT.temperature * 1.8) + 32;
  Serial.print(temperatureVariable);
  Serial.println(" Degrees fahrenheit."); //https://www.rapidtables.com/convert/temperature/how-celsius-to-fahrenheit.html

  //humidity
  Serial.print(DHT.humidity);
  Serial.println(" is the humidity.");

  if (temperatureVariable >= 100)
  {
    controller = 3;
  }
  else if (temperatureVariable >= 32)
  {
    controller = 2;
  }
  else
  {
    controller = 1;
  }

  switch (controller)
  {
    case 1:
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      digitalWrite(fanPin, LOW);
      break;
    case 2:
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, LOW);
      digitalWrite(fanPin, HIGH);
      break;
    case 3:
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, HIGH);
      digitalWrite(fanPin, HIGH);
      break;
  }
  delay(500);
}
