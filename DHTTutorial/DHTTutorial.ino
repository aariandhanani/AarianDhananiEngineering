

#include <dht.h>
#include <LiquidCrystal.h>


const int RPin = 11;
const int GPin = 10;
const int BPin = 9;
int RValue = 255;
int BValue = 255;
int GValue = 255;


dht DHT;

LiquidCrystal myLCD = {2,3,4,5,6,7,};

#define DHT11_PIN 8

void setup()
{
  Serial.begin(9600);
  myLCD.begin(16,2);
  myLCD.print("Ready");

  pinMode(RPin, OUTPUT);
  pinMode(BPin, OUTPUT);
  pinMode(GPin, OUTPUT);
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

  int temperatureVariable = (DHT.temperature * 1.8) + 32;

  Serial.println(temperatureVariable);


  int humidityVariable = DHT.humidity;
  Serial.println(humidityVariable);



  myLCD.print(temperatureVariable);
  myLCD.print(" Degrees F");

  myLCD.setCursor(0,1);

  myLCD.print(humidityVariable);
  myLCD.print(" Humidity");
  
  delay(100);
  myLCD.clear();

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
      RValue = 0;
      BValue = 255;
      GValue = 0;
      RGB(RValue, BValue, GValue);
      break;
    case 2:
      RValue = 255;
      BValue = 255;
      GValue = 255;
      RGB(RValue, BValue, GValue);
      break;
    case 3:
      RValue = 255;
      BValue = 0;
      GValue = 0;
      RGB(RValue, BValue, GValue);
      break;
  }

  delay(500);
}
