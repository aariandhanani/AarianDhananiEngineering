/*
* Aarian Dhanani
* 2/3/2021
* 
* Controlling 3 LEDs with a button.
* Read from negative, write to positive.
*/

const int ledPin1 = 7;
const int ledPin2 = 6;
const int ledPin3 = 5;
const int buttonPin = 4;
int controller = 0;
byte readValue;

// Setup
void setup()
{ 
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT); // This is an output
  pinMode(ledPin2, OUTPUT); // This is an output
  pinMode(ledPin3, OUTPUT); // This is an output
  pinMode (buttonPin, INPUT); // This is an input
}

void loop()
{
  readValue = digitalRead(buttonPin);
  if (readValue == 1)
  {
    //controller is a variable to see how many lights should be on
    controller ++;
  }

  //turns on a light depending on the controller variable
  switch (controller)
  {
    case 1:
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      break;
    case 2:
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, LOW);
      break;
    case 3:
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, HIGH);
      break;
     default:
      controller = 0; //Because there aren't more than 3 lights on the breadboard for this project
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      break;
  }
  Serial.println(controller); //For testing purposes
  delay(200); //A delay so too many button inputs aren't read (kind of)
}
