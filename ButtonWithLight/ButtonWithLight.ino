/*
* Aarian Dhanani
* 1/28/2021
* 
* Controlling an LED with a button.
* Read from negative, write to positive.
*/

const int ledPin = 6;
const int buttonPin = 5;
byte readValue;

void setup()
{ 
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT); // This is an output
  pinMode (buttonPin, INPUT); // This is an input
  digitalWrite(ledPin, HIGH);
}
//another function that will repeat until you
//turn off the arduino
void loop()
{
  digitalWrite(ledPin, HIGH);
  delay(400);
  digitalWrite(ledPin, LOW);
  delay(400);
}
