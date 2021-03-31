 /*
  * Shift Register
  * Aarian Dhanani
  */

const int SER = 8;
const int LATCH = 9;
const int CLCK = 12;

int seq[] = {1,2,4,8,16,32,64,128};

void setup() {
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLCK, OUTPUT);
//  digitalWrite(LATCH, LOW);
//  shiftOut(SER, CLCK, MSBFIRST, B11110000);
//  digitalWrite(LATCH, HIGH);
}

void loop() {
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(LATCH, LOW);
    shiftOut(SER, CLCK, MSBFIRST, seq[i]);
    digitalWrite(LATCH, HIGH);
    delay(500);
  }
}
