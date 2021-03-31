 /*
 * 7 Segment Display
 */

const int g = 8;
const int f = 12;
const int a = 7;
const int b = 6;
const int e = 5;
const int d = 4;
const int c = 2;
int controller = 0;
byte readValue;
boolean oldPress = false;
boolean newPress = false;
const int buttonPin = 9;
const int buttonPin2 = 10;


boolean upValue;
boolean upOld;
boolean downValue;
boolean downOld;

boolean up = false;
boolean down = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  Serial.begin(9600);

  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(g, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(a, HIGH);
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

void zero()
{
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(g, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(a, HIGH);
}

void one()
{
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(g, LOW);
  digitalWrite(f, LOW);
  digitalWrite(e, LOW);
  digitalWrite(d, LOW);
  digitalWrite(a, LOW);
}

void two()
{
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(g, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(a, HIGH);
}

void three()
{
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(e, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(a, HIGH);
}

void four()
{
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(d, LOW);
  digitalWrite(a, LOW);
}

void five()
{
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(a, HIGH);
}

void six()
{
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(a, HIGH);
}

void seven()
{
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(g, LOW);
  digitalWrite(f, LOW);
  digitalWrite(e, LOW);
  digitalWrite(d, LOW);
  digitalWrite(a, HIGH);
}

void eight()
{
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(a, HIGH);
}

void nine()
{
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(d, LOW);
  digitalWrite(a, HIGH);
}

void loop() {
  upValue = reading(upOld, buttonPin);
  if (upValue == HIGH && upOld == LOW)
  {
    controller ++;
    if (controller == 10)
    {
      controller = 0;
    }
    if (controller == -1)
    {
      controller == 9;
    }
    switch(controller)
    {
      case 0:
        zero();
        break;
      case 1:
        one();
        break;
      case 2:
        two();
        break;
      case 3:
        three();
        break;
      case 4:
        four();
        break;
      case 5:
        five();
        break;
      case 6:
        six();
        break;
      case 7:
        seven();
        break;
      case 8:
        eight();
        break;
      case 9:
        nine();
        break;
    }
    up = !up;
  }



  downValue = reading(downOld, buttonPin2);
  if (downValue == HIGH && downOld == LOW)
  {
    controller--;
    if (controller == 10)
    {
      controller = 0;
    }

    if (controller < 0)
    {
      controller = 9;
    }
    switch(controller)
    {
      case 0:
        zero();
        break;
      case 1:
        one();
        break;
      case 2:
        two();
        break;
      case 3:
        three();
        break;
      case 4:
        four();
        break;
      case 5:
        five();
        break;
      case 6:
        six();
        break;
      case 7:
        seven();
        break;
      case 8:
        eight();
        break;
      case 9:
        nine();
        break;
    }
    down = !down;
  }
  Serial.println(controller); //For testing purposes
  upOld = upValue;
  downOld = downValue;
}
