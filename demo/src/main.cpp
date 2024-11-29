#include <Arduino.h>

#define INPUT_PIN 34

int value;

void setup()
{
  Serial.begin(9600);
  delay(200);
}

void loop()
{
  value = analogRead(INPUT_PIN);
  Serial.print("Value: ");
  Serial.println(value);
  delay(500);
}