#include "Arduino.h"
#include "airx.h"

void airx::init(char pin_, int model_,char name_[])
{
  pin = pin_;
  model = model_;
  char name[] = name_[];
  pinMode(pin, INPUT);
  airx::get();
}

int airx::get()
{
  if (model == 0) {
    int key_ = digitalRead(pin);
    key = key_;
  }
  else if (model ==1) {
    int key_ = analogRead(pin);
    key = key_;
  }

  return key;
}
