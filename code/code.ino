#include <LiquidCrystal.h>
int potPin = A0;
int controlPin = 10;

void setup() {
  // set frequency of 31372.55 Hz
  TCCR1B = TCCR1B & 0b11111000 | 0x01;
  
  pinMode(potPin, INPUT);
  pinMode(controlPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  analogWrite(controlPin, map(analogRead(potPin), 0, 1023, 0, 255));

  Serial.println(map(analogRead(potPin), 0, 1023, 0, 255));
  
  delay(1000);
}
