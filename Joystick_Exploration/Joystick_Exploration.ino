/*
 * Aarian Dhanani
 * Joystick exploration
 * https://create.arduino.cc/projecthub/MisterBotBreak/how-to-use-a-joystick-with-serial-monitor-1f04f0
 * https://create.arduino.cc/projecthub/muhammad-aqib/arduino-rgb-led-tutorial-fc003e
 */

const int VRXPin = A0;
const int VRYPin = A1;
const int SWPin = 2;
const int RPin = 9;
const int GPin = 10;
const int BPin = 11;

int x;
int y;
int button;

int xValue;
int yValue;

void setup() {
  Serial.begin(9600);
  pinMode(VRXPin, INPUT);
  pinMode(VRYPin, INPUT);
  pinMode(SWPin, INPUT_PULLUP);
  pinMode(RPin, OUTPUT);
  pinMode(GPin, OUTPUT);
  pinMode(BPin, OUTPUT);
}

void loop() {
  x = analogRead(VRXPin);
  y = analogRead(VRYPin);
  button = digitalRead(SWPin);

  if (button == 0)
  {
    analogWrite(RPin, 0);
    analogWrite(BPin, 0);
    analogWrite(GPin, 0);
  }
  else
  {
    xValue = map(x, 0, 1023, 0, 256);
    analogWrite(RPin, xValue);
    yValue = map(y, 0, 1023, 0, 256);
    analogWrite(BPin, yValue);
  }

  Serial.print(x);
  Serial.print(" ");
  Serial.print(y);
  Serial.print(" ");
  Serial.print(button);
  Serial.println();

}
