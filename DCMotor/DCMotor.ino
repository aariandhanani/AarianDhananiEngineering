/*
 * Aarian Dhanani
 * 3/5/21
 * DC Motor
 */

const int pinDirection = 7;
const int pinOnOff = 8;
const int potentiometerPin = A0;
const int direction1 = 2;
const int direction2 = 3;
const int motor = 9;

boolean onOffValue;
boolean onOffOld;
boolean directionValue;
boolean directionOld;

boolean directionOn = false;
boolean onOff = false;

void setup() {
  Serial.begin(9600);
  pinMode(pinDirection, INPUT);
  pinMode(pinOnOff, INPUT);
  pinMode(potentiometerPin, INPUT);
  pinMode(direction1, OUTPUT);
  pinMode(direction2, OUTPUT);
  pinMode(motor, OUTPUT);

}

boolean reading (boolean last, int button)
{
  boolean current = digitalRead(button);
  delay(5);
  if (current != last)
  {
    current = digitalRead(button);
  }
  return current;
}

void loop() {
//    onOff = digitalRead(pinOnOff);
    onOffValue = reading(onOffOld, pinOnOff);
    if (onOffValue == HIGH && onOffOld == LOW)
    {
      onOff = !onOff;
    }



//    directionOn = digitalRead(pinDirection);
    directionValue = reading(directionOld, pinDirection);
    if (directionValue == HIGH && directionOld == LOW)
    {
      directionOn = !directionOn;
    }


    
//    Serial.println(digitalRead(pinDirection));
//    Serial.println(digitalRead(pinOnOff));
//    Serial.println(analogRead(potentiometerPin));

    if (onOff == true)
    {
      if (directionOn == true)
      {
        digitalWrite(direction1, HIGH);
        digitalWrite(direction2, LOW);
      }
      else
      {
        digitalWrite(direction1, LOW);
        digitalWrite(direction2, HIGH);
      }
      int value = analogRead(potentiometerPin);

      value = map(value, 0, 1023, 0, 255);
      analogWrite(motor, value);
    }
    else
    {
      analogWrite(motor, LOW);
    }

    onOffOld = onOffValue;
    directionOld = directionValue;
}
