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
unsigned long timer;
int minimum = 10000;
int maximum = 0;

// Setup
void setup()
{ 
  Serial.begin(9600);
  pinMode(photoPin, INPUT);
  pinMode(ledPin1, OUTPUT); // This is an output
  pinMode(ledPin2, OUTPUT); // This is an output
  pinMode(ledPin3, OUTPUT); // This is an output
  calibrate();
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

void calibrate()
{
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  
  //millis() is a function.

  timer = millis();
  Serial.println("Ok");
  while ((millis() - timer) < 5000)
  {
    readValue = analogRead(photoPin);
    if (readValue < minimum)
    {
      minimum = readValue;
    }
    if (readValue > maximum)
    {
      maximum = readValue;
    }
    Serial.println(readValue);
  }
}

void loop()
{
  newPress = reading(oldPress);

  if (newPress == HIGH && oldPress == LOW)
  {
    calibrate();
  }

  readValue = analogRead(photoPin);

  readValue = map(readValue, minimum, maximum, 255, 0);
  readValue = constrain(readValue, 0, 255);
  
  Serial.println(readValue); //For testing purposes
  analogWrite(ledPin1, readValue);
  analogWrite(ledPin2, readValue);
  analogWrite(ledPin3, readValue);
}
