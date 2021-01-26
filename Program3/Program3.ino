/*
* Aarian Dhanani
* 1/26/2021
* 
* Setting up pins as input/output
* using pinMode
* use a delay in milliseconds
*/

const int ledPin = 12;

void setup()
{ 
  /*the setup function only runs once
  when your turn on your arduino or you press the
  rest button
  We use it to initialize things
  */
  
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  Serial.begin(9600);
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
