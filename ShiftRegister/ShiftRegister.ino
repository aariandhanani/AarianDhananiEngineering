 /*
  * Shift Register
  * Aarian Dhanani
  */

const int SER = 8;
const int LATCH = 9;
const int CLCK = 12;

int seq[] = {1,2,4,8,16,32,64,128};
int seq2[] = {3, 12, 48, 192};
int seq3[] = {15, 240};

int seq4[] = {1,3,7,15,31,63,127,255,127,63,31,15,7,3,1};

void setup() {
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLCK, OUTPUT);
//  digitalWrite(LATCH, LOW);
//  shiftOut(SER, CLCK, MSBFIRST, B11110000);
//  digitalWrite(LATCH, HIGH);
}

void sequence1() 
{
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(LATCH, LOW);
    shiftOut(SER, CLCK, MSBFIRST, seq[i]);
    digitalWrite(LATCH, HIGH);
    delay(500);
  }
}

void sequence2() 
{
  for (int i = 0; i < 4; i++)
  {
    digitalWrite(LATCH, LOW);
    shiftOut(SER, CLCK, MSBFIRST, seq2[i]);
    digitalWrite(LATCH, HIGH);
    delay(500);
  }
}

void sequence3() 
{
  for (int i = 0; i < 2; i++)
  {
    digitalWrite(LATCH, LOW);
    shiftOut(SER, CLCK, MSBFIRST, seq3[i]);
    digitalWrite(LATCH, HIGH);
    delay(500);
  }
}

void sequence4() 
{
  for (int i = 0; i < 15; i++)
  {
    digitalWrite(LATCH, LOW);
    shiftOut(SER, CLCK, MSBFIRST, seq4[i]);
    digitalWrite(LATCH, HIGH);
    delay(500);
  }
}

void loop()
{
//  sequence1();
//  sequence2();
//  sequence3();
  sequence4();
}
