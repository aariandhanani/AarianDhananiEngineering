/*
* Aarian Dhanani
* 2/22/2021
* Humidity Sensor
* https://github.com/adafruit/DHT-sensor-library/blob/master/examples/DHTtester/DHTtester.ino (Not exactly like the sensor)
* https://www.circuitbasics.com/how-to-set-up-the-dht11-humidity-sensor-on-an-arduino/ (Main source for this)
* https://create.arduino.cc/projecthub/muhammad-aqib/arduino-rgb-led-tutorial-fc003e
*/

#include <dht.h>

dht DHT;

#define DHT11_PIN 7

int controller = 0;
const int ledPin1 = 4;
const int ledPin2 = 5;
const int ledPin3 = 6;
const int RPin = 11;
const int GPin = 10;
const int BPin = 9;
int RValue = 255;
int BValue = 255;
int GValue = 255;


// Setup
void setup()
{ 
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT); // This is an output
  pinMode(ledPin2, OUTPUT); // This is an output
  pinMode(ledPin3, OUTPUT); // This is an output
  pinMode(RPin, OUTPUT); // This is an output
  pinMode(BPin, OUTPUT); // This is an output
  pinMode(GPin, OUTPUT); // This is an output
}

void RGB(int RValue1, int BValue1, int GValue1)
{
  analogWrite(RPin, RValue1);
  analogWrite(GPin, GValue1);
  analogWrite(BPin, BValue1);
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

  if (temperatureVariable >= 72)
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
      RValue = 0;
      BValue = 255;
      GValue = 0;
      RGB(RValue, BValue, GValue);
      break;
    case 2:
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, LOW);
      RValue = 255;
      BValue = 255;
      GValue = 255;
      RGB(RValue, BValue, GValue);
      break;
    case 3:
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, HIGH);
      RValue = 255;
      BValue = 0;
      GValue = 0;
      RGB(RValue, BValue, GValue);
      break;
  }
  delay(500);
}
