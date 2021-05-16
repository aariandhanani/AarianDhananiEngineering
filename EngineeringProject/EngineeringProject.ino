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

//For Shift Register
const int RPin = 6;
const int GPin = 9;
const int BPin = 10;

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
const int buzzerPin = 12;

//For ball
int x = 15;
int y = 3;
bool up = true;
bool right = true;

//For P1 button
const int P1Button = 2;
boolean P1OldPress = false;
boolean P1NewPress = false;

//For P2 button
const int P2Button = 7;
boolean P2OldPress = false;
boolean P2NewPress = false;

//Set up
boolean P1Ready = false;
boolean P2Ready = false;
int P1Score = 0;
int P2Score = 0;
boolean gameOn = false;

//Set up
void setup() {
  Serial.begin(9600);
  pinMode(VRXPin, INPUT);
  pinMode(VRYPin, INPUT);
  pinMode(VRX2Pin, INPUT);
  pinMode(VRY2Pin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(P1Button, INPUT);
  pinMode(P2Button, INPUT);
  pinMode(RPin, OUTPUT); // This is an output
  pinMode(BPin, OUTPUT); // This is an output
  pinMode(GPin, OUTPUT); // This is an output
  analogWrite(RPin, 200);
  analogWrite(GPin, 200);
  analogWrite(BPin, 200);
  mx.begin();
}

//to print the score
void scorePrint()
{
  if (P1Score == 1)
  {
    mx.setPoint(1, 4, true);
    mx.setPoint(2, 4, true);
    mx.setPoint(3, 4, true);
    mx.setPoint(4, 4, true);
    mx.setPoint(5, 4, true);
    mx.setPoint(6, 4, true);
  }
  else if (P1Score == 2)
  {
    mx.setPoint(1, 4, true);
    mx.setPoint(2, 4, true);
    mx.setPoint(3, 4, true);
    mx.setPoint(4, 4, true);
    mx.setPoint(5, 4, true);
    mx.setPoint(6, 4, true);
    mx.setPoint(1, 7, true);
    mx.setPoint(2, 7, true);
    mx.setPoint(3, 7, true);
    mx.setPoint(4, 7, true);
    mx.setPoint(5, 7, true);
    mx.setPoint(6, 7, true);
  }
  if (P2Score == 1)
  {
    mx.setPoint(1, 27, true);
    mx.setPoint(2, 27, true);
    mx.setPoint(3, 27, true);
    mx.setPoint(4, 27, true);
    mx.setPoint(5, 27, true);
    mx.setPoint(6, 27, true);
  }
  else if (P2Score == 2)
  {
    mx.setPoint(1, 27, true);
    mx.setPoint(2, 27, true);
    mx.setPoint(3, 27, true);
    mx.setPoint(4, 27, true);
    mx.setPoint(5, 27, true);
    mx.setPoint(6, 27, true);
    mx.setPoint(1, 23, true);
    mx.setPoint(2, 23, true);
    mx.setPoint(3, 23, true);
    mx.setPoint(4, 23, true);
    mx.setPoint(5, 23, true);
    mx.setPoint(6, 23, true);
  }
}

//Player 1 paddle
void P1()
{
  yP1Joystick = analogRead(VRYPin);
  yP1 = map(yP1Joystick, 1023, 0, 6, -1);
//  Serial.println(yP1);
  mx.setPoint(yP1, 0, true);
  mx.setPoint(yP1 + 1, 0, true);
}

//Player 2 paddle
void P2()
{
  yP2Joystick = analogRead(VRY2Pin);
  //Serial.println(yP2Joystick);
  yP2 = map(yP2Joystick, 1023, 0, 6, -1);
//  Serial.println(yP2);
  mx.setPoint(yP2, 31, true);
  mx.setPoint(yP2 + 1, 31, true);
}

//Not used. This would be for an endless version of the game (player 1)
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

//Move the ball
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

//For player 1 button
boolean openReading (boolean last)
{
  boolean current = digitalRead(P1Button);
  delay(5);
  if (current != last)
  {
    current = digitalRead(P1Button);
  }
  return current;
}

//For player 2 button
boolean openReading2 (boolean last2)
{
  boolean current = digitalRead(P2Button);
  delay(5);
  if (current != last2)
  {
    current = digitalRead(P2Button);
  }
  return current;
}

//For testing
void P1ButtonFunction()
{
  Serial.println("Open button");
}

//Main loop
void loop() {
  mx.clear(); //Clear LED matrix
  //Run while the game is on
  while (gameOn == true) {
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
        P2Score = P2Score + 1;
        scorePrint();
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
        P1Score = P1Score + 1;
        scorePrint();
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

    //Check to see if a player has won the game yet
    if (P2Score == 2 or P1Score == 2)
    {
      P1Score = 0;
      P2Score = 0;
      gameOn = false;
      P1Ready = false;
      P2Ready = false;
    }
    delay(200);
  }

  //For buttons
  P1NewPress = openReading(P1OldPress);
  if (P1NewPress == HIGH && P1OldPress == LOW)
  {
    P1Ready = true;
    //P1ButtonFunction();
  }
  P2NewPress = openReading2(P2OldPress);
  if (P2NewPress == HIGH && P2OldPress == LOW)
  {
    P2Ready = true;
    //P1ButtonFunction();
  }
  //Serial.println(gameOn);

  //Start the game
  if (P1Ready == true and P2Ready == true)
  {
    gameOn = true;
  }

  //Draw if the player(s) are ready
  if (P1Ready == true)
  {
    mx.setPoint(3, 3, true);
    mx.setPoint(4, 3, true);
    mx.setPoint(3, 4, true);
    mx.setPoint(4, 4, true);
  }
  if (P2Ready == true)
  {
    mx.setPoint(3, 27, true);
    mx.setPoint(4, 27, true);
    mx.setPoint(3, 28, true);
    mx.setPoint(4, 28, true);
  }
  delay(100);
  P1OldPress = P1NewPress;
  P2OldPress = P2NewPress;
}
