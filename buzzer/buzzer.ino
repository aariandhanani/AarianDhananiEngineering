/*
 * Using a buzzer
 * 
 * 4/7/21
 * 
 * Aarian Dhanani
 */

#include "notes.h"

int song[] = {NOTE_B0, NOTE_C1, NOTE_C8, NOTE_D5};
int duration[] = {10, 5, 8 , 15};

const int buzzerPin = 10;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 4; i++)
  {
    int noteDur = 1000/duration[i];
    tone(buzzerPin, song[i], noteDur);
    delay(noteDur*1.30);
    noTone(buzzerPin);
  }
//  tone(buzzerPin, 300);
//  delay(1000);
//  noTone(buzzerPin);
//  delay(1000);
}
