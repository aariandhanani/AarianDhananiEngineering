/*
* Aarian Dhanani
* 2/9/2021
* Photoresistor and Button
* 
*/

const int photoPin = A1;
const int buttonPin = 10;
const int ledPin1 = 9;
const int ledPin2 = 6;
const int ledPin3 = 5;
int readValue;
boolean oldPress = false;
boolean newPress = false;

// Setup
void setup()
{ 
  Serial.begin(9600);
  pinMode(photoPin, INPUT);
  pinMode(ledPin1, OUTPUT); // This is an output
  pinMode(ledPin2, OUTPUT); // This is an output
  pinMode(ledPin3, OUTPUT); // This is an output
}

boolean reading (boolean last)
{
  boolean current = digitalRead(buttonPin);
  delay(5);
  if (current != last)
  {
    current = digitalRead(buttonPin);
  }
  return current;
}

void loop()
{
  newPress = reading(oldPress);

  readValue = analogRead(photoPin);
  
  Serial.println(readValue); //For testing purposes
  analogWrite(ledPin1, readValue);
  analogWrite(ledPin2, readValue);
  analogWrite(ledPin3, readValue);
  delay(20);
}
