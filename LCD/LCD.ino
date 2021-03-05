/*
* Aarian Dhanani
* 2/25/2021
* LCD
* 
* https://www.arduino.cc/en/Tutorial/LibraryExamples/LiquidCrystalScroll
* 
*/

#include <LiquidCrystal.h>

LiquidCrystal myLCD = {2,3,4,5,6,7,};


// Setup
void setup()
{ 
  Serial.begin(9600);
  myLCD.begin(16,2);
  myLCD.print("Hi");
}

void loop()
{
  myLCD.setCursor(2,1);
  myLCD.print("Aarian");

  for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
    // https://www.arduino.cc/en/Tutorial/LibraryExamples/LiquidCrystalScroll
    // scroll one position right:
    myLCD.scrollDisplayRight();
    // wait a bit:
    delay(300);
  }

  myLCD.clear();

  myLCD.print("Ok");
  delay(2000);
  
  myLCD.clear();
  delay(1000);
}
