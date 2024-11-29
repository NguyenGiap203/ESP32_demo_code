#include <Arduino.h>

#define LED 16

const int freq = 60;
const int resolution = 10; // 0-16 bit
const int channel = 0;
/*CHANNEL: each channel has 6 GPIO port
0: 16-17-18-19-21-22
1: 0-4-5-12-13-14
2: 2-12-13-14-15-16
3: ...*/

void setup()
{
  ledcSetup(channel, freq, resolution);
  ledcAttachPin(LED, channel);
}

void loop()
{
  for (int i = 0; i <= 255; i++)
  {
    ledcWrite(channel, i);
    delay(20);
  }

  for (int i = 255; i >= 0; i--)
  {
    ledcWrite(channel, i);
    delay(20);
  }
}