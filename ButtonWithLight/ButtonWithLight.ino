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

// Setup
void setup()
{ 
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT); // This is an output
  pinMode (buttonPin, INPUT); // This is an input
}

void loop()
{
  readValue = digitalRead(buttonPin);
  if (readValue == 1)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW); 
  }
}
