#include <Servo.h>

/*
 * Aarian Dhanani
 * 3/3/21
 */

Servo servo1;

int const potentiometer = A0;

void setup()
{
  servo1.attach(9);
  servo1.write(0);
  pinMode(potentiometer, INPUT);
}

void servoFunction()
{
  for (int i = 0; i < 180; i++)
  {
    servo1.write(i);
    delay(5);
  }
  for (int i = 180; i > 180; i--)
  {
    servo1.write(i);
    delay(5);
  }
}
void loop()
{
  int value = analogRead(potentiometer);
  value = map(value, 0,1023, 0,180);
  servo1.write(value);
  //servoFunction();
}
