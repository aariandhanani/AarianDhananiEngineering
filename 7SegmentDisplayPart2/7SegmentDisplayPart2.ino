 /*
 * 7 Segment Display
 * https://www.mathworks.com/help/supportpkg/arduinoio/ug/control-7-segment-display-with-74hc595-shift-register.html
 * https://timodenk.com/blog/shift-register-arduino-library/
 * 
 */

#include <ShiftRegister74HC595.h>
int numberOfShiftRegisters = 1; // number of shift registers attached in series
int serialDataPin = 6; // DS
int clockPin = 5; // SHCP
int latchPin = 10; // STCP

int controller = 0;
byte readValue;
boolean oldPress = false;
boolean newPress = false;
const int buttonPin = 9;
const int buttonPin2 = 10;


boolean upValue;
boolean upOld;
boolean downValue;
boolean downOld;

boolean up = false;
boolean down = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  Serial.begin(9600);
}

boolean reading (boolean last, int button)
{
  boolean current = digitalRead(button);
  delay(5);
  if (current != last)
  {
    current = digitalRead(button);
  }
  return current;
}

void loop() {
  uint8_t pinValues[] = { B00011000, B10101010 };
  sr.setAll(pinValues);
//  upValue = reading(upOld, buttonPin);
//  if (upValue == HIGH && upOld == LOW)
//  {
//    controller ++;
//    if (controller == 10)
//    {
//      controller = 0;
//    }
//    if (controller == -1)
//    {
//      controller == 9;
//    }
//    switch(controller)
//    {
//      case 0:
//        zero();
//        break;
//      case 1:
//        one();
//        break;
//      case 2:
//        two();
//        break;
//      case 3:
//        three();
//        break;
//      case 4:
//        four();
//        break;
//      case 5:
//        five();
//        break;
//      case 6:
//        six();
//        break;
//      case 7:
//        seven();
//        break;
//      case 8:
//        eight();
//        break;
//      case 9:
//        nine();
//        break;
//    }
//    up = !up;
//  }
//
//
//
//  downValue = reading(downOld, buttonPin2);
//  if (downValue == HIGH && downOld == LOW)
//  {
//    controller--;
//    if (controller == 10)
//    {
//      controller = 0;
//    }
//
//    if (controller < 0)
//    {
//      controller = 9;
//    }
//    switch(controller)
//    {
//      case 0:
//        zero();
//        break;
//      case 1:
//        one();
//        break;
//      case 2:
//        two();
//        break;
//      case 3:
//        three();
//        break;
//      case 4:
//        four();
//        break;
//      case 5:
//        five();
//        break;
//      case 6:
//        six();
//        break;
//      case 7:
//        seven();
//        break;
//      case 8:
//        eight();
//        break;
//      case 9:
//        nine();
//        break;
//    }
//    down = !down;
//  }
//  Serial.println(controller); //For testing purposes
//  upOld = upValue;
//  downOld = downValue;
}
