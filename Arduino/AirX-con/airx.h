#ifndef AIRCON_H_
#define AIRCON_H_

#include <Arduino.h>

class airx
{
  public:
    char pin;
    int key;
    int model;
    char name[];

    void init(char pin_,int model_,char name_[]);
    int get();
};

#endif
