/*
* Aarian Dhanani
* 2/25/2021
* Humidity Sensor
* https://github.com/adafruit/DHT-sensor-library/blob/master/examples/DHTtester/DHTtester.ino (Not exactly like the sensor)
* https://www.circuitbasics.com/how-to-set-up-the-dht11-humidity-sensor-on-an-arduino/ (Main source for this)
* https://create.arduino.cc/projecthub/muhammad-aqib/arduino-rgb-led-tutorial-fc003e
*/

#include <dht.h>
#include <LiquidCrystal.h>

dht DHT;

#define DHT11_PIN 8

LiquidCrystal myLCD = {2,3,4,5,6,7,};


// Setup
void setup()
{ 
  Serial.begin(9600);
  myLCD.begin(16,2);
  myLCD.print("Ready");
}

void loop()
{
  int check = DHT.read11(DHT11_PIN);

  //temperature
  int temperatureVariable = (DHT.temperature * 1.8) + 32;
  Serial.print(temperatureVariable);
  Serial.println(" Degrees fahrenheit."); //https://www.rapidtables.com/convert/temperature/how-celsius-to-fahrenheit.html
  //humidity
  int humidityVariable = DHT.humidity;
  Serial.print(DHT.humidity);
  Serial.println(" is the humidity.");

  
  myLCD.print(temperatureVariable);
  myLCD.print(" Degrees F");

  myLCD.setCursor(0,1);

  myLCD.print(humidityVariable);
  myLCD.print(" Humidity");
  
  delay(100);
  myLCD.clear();
}
