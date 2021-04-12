/*
 * Aarian Dhanani
 * Joystick and Ultrasonic Sensor exploration
 * https://create.arduino.cc/projecthub/MisterBotBreak/how-to-use-a-joystick-with-serial-monitor-1f04f0
 * https://create.arduino.cc/projecthub/muhammad-aqib/arduino-rgb-led-tutorial-fc003e
 * https://create.arduino.cc/projecthub/abdularbi17/ultrasonic-sensor-hc-sr04-with-arduino-tutorial-327ff6
 */

const int VRXPin = A0;
const int VRYPin = A1;
const int SWPin = 2;
const int echoPin = 4;
const int trigPin = 3;
const int RPin = 9;
const int GPin = 10;
const int BPin = 11;

int x;
int y;
int button;

int ultrasonicValue;

int xValue;
int yValue;

long duration;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(VRXPin, INPUT);
  pinMode(VRYPin, INPUT);
  pinMode(SWPin, INPUT_PULLUP);
  pinMode(RPin, OUTPUT);
  pinMode(GPin, OUTPUT);
  pinMode(BPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  Serial.println(distance);
  
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
    xValue = map(x, 0, 1023, 0, 255);
    analogWrite(RPin, xValue);
    yValue = map(y, 0, 1023, 0, 255);
    analogWrite(BPin, yValue);
    if (distance < 300)
    {
      ultrasonicValue = map(distance, 300, 0, 0, 255);
    }
    analogWrite(GPin, ultrasonicValue);
  }

//  Serial.print(x);
//  Serial.print(" ");
//  Serial.print(y);
//  Serial.print(" ");
//  Serial.print(button);
//  Serial.println();

}
