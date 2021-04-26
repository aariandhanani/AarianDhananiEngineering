//For LED Matrix
#include <MD_MAX72xx.h>
#include <SPI.h>
#define HARDWARE_TYPE MD_MAX72XX::DR1CR0RR0_HW
#define MAX_DEVICES 4
#define CLK_PIN   13  // or SCK
#define DATA_PIN  11  // or MOSI
#define CS_PIN    3  // or SS
MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);                      // SPI hardware interface
//MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES); // Arbitrary pins

//For player 1
const int VRXPin = A0;
const int VRYPin = A1;
int yP1 = 3;
int yP1Joystick;

//For player 2 joystick
const int VRX2Pin = A2;
const int VRY2Pin = A3;
int yP2 = 3;
int yP2Joystick;

//For buzzer
const int buzzerPin = 10;

//For ball
int x = 15;
int y = 3;
bool up = true;
bool right = true;

void setup() {
  Serial.begin(9600);
  pinMode(VRXPin, INPUT);
  pinMode(VRYPin, INPUT);
  pinMode(VRX2Pin, INPUT);
  pinMode(VRY2Pin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  mx.begin();

}

void P1()
{
  yP1Joystick = analogRead(VRYPin);
  yP1 = map(yP1Joystick, 1023, 0, 6, -1);
//  Serial.println(yP1);
  mx.setPoint(yP1, 0, true);
  mx.setPoint(yP1 + 1, 0, true);
}

void P2()
{
  yP2Joystick = analogRead(VRY2Pin);
  yP2 = map(yP2Joystick, 1023, 0, 6, -1);
//  Serial.println(yP2);
  mx.setPoint(yP2, 31, true);
  mx.setPoint(yP2 + 1, 31, true);
}

void AI()
{
  yP2 = y;
  if (yP2 == 7)
  {
    yP2 = 6;
  }
  mx.setPoint(yP2, 31, true);
  mx.setPoint(yP2 + 1, 31, true);
}

void ball()
{  
  if (y > 6)
  {
    up = false;
  }

  if (y < 1)
  {
    up = true;
  }
  
  if (x < 1)
  {
    right = true;
  }

  if (x > 29)
  {
    right = false;
  }
  
  if (up == true)
  {
    y = y + 1;
  }
  else
  {
    y = y - 1;
  }

  if (right == true)
  {
    x = x + 1;
  }
  else
  {
    x = x - 1;
  }
  mx.setPoint(y, x, true);
}

void loop() {
  noTone(buzzerPin);
  mx.clear();
  P1();
  P2();
  ball();

  //P1 loss check
  if (x == 1 and right == false)
  {
    if (y != yP1 and y != (yP1 + 1))
    {
      Serial.println("False");
      tone(buzzerPin, 500);
      delay(1000);
      noTone(buzzerPin);
      x = 15;
      y = 3;
    }
    else
    {
      Serial.println("True");
      right = true;
    }
  }
  //P2 loss check
  if (x == 30 and right == true)
  {
    if (y != yP2 and y != (yP2 + 1))
    {
      Serial.println("False");
      tone(buzzerPin, 500);
      delay(1000);
      noTone(buzzerPin);
      x = 15;
      y = 3;
    }
    else
    {
      Serial.println("True");
      right = false;
    }
  }
  delay(200);
}
