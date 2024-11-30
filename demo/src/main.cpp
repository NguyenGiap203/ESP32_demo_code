#include <Arduino.h>

#define PIR_SENSOR 27
#define LED 26
#define TIME_OUT 5

unsigned long now_time = millis();
unsigned long last_time = 0;
boolean startTime = false;
boolean motion_detect = false;

void IRAM_ATTR detectCallback()
{
  digitalWrite(LED, HIGH);
  startTime = true;
  last_time = millis();
}

void setup()
{
  Serial.begin(9600);
  pinMode(PIR_SENSOR, INPUT_PULLUP); // khi co chuyen dong, PIR_SENSOR tra ve 0, nen can dung dien tro keo len pull up
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW); // Led off khi bat dau

  attachInterrupt(digitalPinToInterrupt(PIR_SENSOR), detectCallback, RISING);
}

void loop()
{
  now_time = millis(); // update current time each loop

  // check move
  if (digitalRead(PIR_SENSOR) == HIGH && (motion_detect == false))
  {
    Serial.println("Motion detected!");
    digitalWrite(LED, HIGH); // bật LED
    motion_detect = true; // đánh dấu đã phát hiện chuyển động
  }

  //
  if (startTime && (now_time - last_time) > TIME_OUT * 1000)
  {
    Serial.println("Motion Stop..........");
    digitalWrite(LED, LOW);
    startTime = false;
    motion_detect = false; // tắt đánh dấu chuyển động
  }
}