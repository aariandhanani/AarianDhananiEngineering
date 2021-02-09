/*
* Aarian Dhanani
* 2/5/2021
* 
* Potentiometer
* 
* analogRead
* 
* Photoresistor
* 
* Map function
*/

const int potentiometerPin = A0;
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
  pinMode(potentiometerPin, INPUT);
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
  if (newPress == HIGH && oldPress == LOW)
  {
    //controller is a variable to see how many lights should be on
    controller ++;
  }

//  readValue = analogRead(potentiometerPin);
//  readValue = map(readValue, 0, 25, 0, 255);

  readValue = analogRead(photoPin);
  Serial.println(readValue); //For testing purposes
  analogWrite(ledPin1, readValue);
  analogWrite(ledPin2, readValue);
  analogWrite(ledPin3, readValue);
  delay(20);
}
