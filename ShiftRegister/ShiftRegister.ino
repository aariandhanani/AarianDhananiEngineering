 /*
  * Shift Register
  * Aarian Dhanani
  */

const int SER = 8;
const int LATCH = 9;
const int CLCK = 12;

void setup() {
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLCK, OUTPUT);
}

void loop() {
  digitalWrite(LATCH, LOW);
  shiftOut(SER, CLCK, MSBFIRST, B11110000);
  digitalWrite(LATCH, HIGH);
}
