#include <arduino.h>

#define led 11
void setup(){
    pinMode(led,OUTPUT);
}
void lopp(){
    digitalWrite(led,HIGH);
    delay(1);
    digitalWrite(led,LOW);
    delay(1);
}