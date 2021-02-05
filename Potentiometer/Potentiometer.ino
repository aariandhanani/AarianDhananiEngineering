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
const int ledPin1 = 9;
const int ledPin2 = 6;
const int ledPin3 = 5;
int readValue;

// Setup
void setup()
{ 
  Serial.begin(9600);
  pinMode(potentiometerPin, INPUT);
  pinMode(ledPin1, OUTPUT); // This is an output
  pinMode(ledPin2, OUTPUT); // This is an output
  pinMode(ledPin3, OUTPUT); // This is an output
}

void loop()
{
  readValue = analogRead(potentiometerPin);
  readValue = map(readValue, 0, 1023, 0, 255);
  
//  Serial.println(readValue); //For testing purposes
  analogWrite(ledPin1, readValue);
  analogWrite(ledPin2, readValue);
  analogWrite(ledPin3, readValue);
  delay(20);
}
