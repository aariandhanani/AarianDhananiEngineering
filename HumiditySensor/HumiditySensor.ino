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

// Setup
void setup()
{ 
  Serial.begin(9600);
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

  delay(500);
}
