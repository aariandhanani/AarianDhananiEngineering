 /*
  * Shift Register
  * Aarian Dhanani
  */

#include <IRremote.h>

//create the object

const int IRpin = 7;
IRrecv rec(IRpin);
decode_results values;

const int SER = 8;
const int LATCH = 9;
const int CLCK = 12;

void setup() {
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLCK, OUTPUT);
  Serial.begin(9600);
  rec.enableIRIn();
  rec.blink13(true);
  
//  digitalWrite(LATCH, LOW);
//  shiftOut(SER, CLCK, MSBFIRST, B11110000);
//  digitalWrite(LATCH, HIGH);
}

void loop()
{
  if (rec.decode(&values))
  {
    
    Serial.println(values.value, HEX);
    rec.resume();
  }

  switch(values.value)
  {
    case 0XFF6897:
      digitalWrite(LATCH, LOW);
      shiftOut(SER, CLCK, MSBFIRST, B00000000);
      digitalWrite(LATCH, HIGH);
      break;
    case 0XFF30CF:
      digitalWrite(LATCH, LOW);
      shiftOut(SER, CLCK, MSBFIRST, B00000001);
      digitalWrite(LATCH, HIGH);
      break;
    case 0XFF18E7:
      digitalWrite(LATCH, LOW);
      shiftOut(SER, CLCK, MSBFIRST, B00000010);
      digitalWrite(LATCH, HIGH);
      break;
    case 0XFF7A85:
      digitalWrite(LATCH, LOW);
      shiftOut(SER, CLCK, MSBFIRST, B00000100);
      digitalWrite(LATCH, HIGH);
      break;
    case 0XFF10EF:
      digitalWrite(LATCH, LOW);
      shiftOut(SER, CLCK, MSBFIRST, B00001000);
      digitalWrite(LATCH, HIGH);
      break;
    case 0XFF38C7:
      digitalWrite(LATCH, LOW);
      shiftOut(SER, CLCK, MSBFIRST, B00010000);
      digitalWrite(LATCH, HIGH);
      break;
    case 0XFF5AA5:
      digitalWrite(LATCH, LOW);
      shiftOut(SER, CLCK, MSBFIRST, B00100000);
      digitalWrite(LATCH, HIGH);
      break;
    case 0XFF42BD:
      digitalWrite(LATCH, LOW);
      shiftOut(SER, CLCK, MSBFIRST, B01000000);
      digitalWrite(LATCH, HIGH);
      break;
    case 0XFF4AB5:
      digitalWrite(LATCH, LOW);
      shiftOut(SER, CLCK, MSBFIRST, B10000000);
      digitalWrite(LATCH, HIGH);
      break;
  }
}
