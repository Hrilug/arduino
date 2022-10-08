#include <arduino.h>

void setup()
{
  Serial.begin(9600);
}
int analog(int pin)
{
  //Serial.println(analogRead(pin));
  int value = 220 - analogRead(pin);
  //将分贝分为八级
  if (value <= 50)
  {
    return 1;
  }
  else if (value <= 75)
  {
    return 2;
  }
  else if (value <= 100)
  {
    return 3;
  }
  else if (value <= 125)
  {
    return 4;
  }
  else if (value <= 150)
  {
    return 5;
  }
  else if (value <= 175)
  {
    return 6;
  }
  else if (value <= 220)
  {
    return 7;
  }
  else
  {
    return 8;
  }
}

void loop()
{
  delay(1);
  Serial.println(analog(4));
}
