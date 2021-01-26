/*
* Maria Suarez
* My First Program
* We are going to lear how to use our Serial Monitor
* We are going to learn ho print
* and how to use variables
* 1/20/2021
* Version#1
*/
//variable is a container for values of specific type
//Whole numbers: byte, short, int, long
// real numbers: float, double
// letters char, string, String
// boolean
//declare a variable tyoe and a name
byte number; //global variable

void setup() { // this is a function
  /*the setup function only runs once
  when your turn on your arduino or you press the
  rest button
  We use it to initialize things
  */
  number =1; //initialize number to 3
  
  Serial.begin(9600);
  Serial.println("HEllo there");
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
}
