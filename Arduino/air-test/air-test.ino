#include "airx.h"

airx key;

void setup(){
  Serial.begin(115200);
  key.init(5,1,"key");
  Serial.println(key.get());
  Serial.println(key.name);
}
void loop(){
  
}