/*
 * Aarian Dhanani
 * 3/5/21
 * DC Motor
 */

const int pinDirection = 7;
const int pinOnOff = 8;
const int potentiometerPin = A0;
const int direction1 = 2; //?
const int direction2 = 5; //?
const int motor = 9;

void setup() {
  Serial.begin(9600);
  pinMode(pinDirection, INPUT);
  pinMode(pinOnOff, INPUT);
  pinMode(potentiometerPin, INPUT);
  pinMode(direction1, OUTPUT);
  pinMode(direction2, OUTPUT);
  pinMode(motor, OUTPUT);

}

void loop() {
//  Serial.println(digitalRead(pinDirection));
//  Serial.println(digitalRead(pinDirection));
    Serial.println(analogRead(potentiometerPin));

    int value = analogRead(potentiometerPin);

    value = map(value, 0, 1023, 0, 255);
    digitalWrite(direction1, HIGH);
    digitalWrite(direction2, LOW);
    analogWrite(motor, value);
}
