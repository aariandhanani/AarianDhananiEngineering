/*
* Aarian Dhanani
* 1/26/2021
* 
* Setting up pins as input/output
* using pinMode
* use a delay in milliseconds
*/

const int ledPin = 12;

void setup() { // this is a function
  /*the setup function only runs once
  when your turn on your arduino or you press the
  rest button
  We use it to initialize things
  */
  pinMode(ledPin, OUTPUT)

  digitalWrite 
  Serial.begin(9600);
}
//another function that will repeat until you
//turn off the arduino
void loop() {
  if(number >255)
  {
     number = 1; // between this to brackets is true
  }
  else
  {
    int result = 2*number+3;
    Serial.println(result);//equation * mult + add / div - subs % modulus
    number= number +1;
    delay(100); //delay 100 milliseconds
  }

  for (int count = 0; count < 10; count++)
  {
    Serial.print("*");
  }
  Serial.println();
}
