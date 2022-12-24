#include "airx.h"
#include <Wire.h>
#include "Adafruit_SSD1306.h"
#include "Adafruit_GFX.h"
#include <MsTimer2.h>

airx key;
int mode = 0;
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(128, 64, &Wire, -1);

void reset(){
  mode =0;
  MsTimer2::stop();
}

void setup(){
  Serial.begin(115200);
  key.init(5,1,"key");
  Serial.println(key.get());
  Serial.println(key.name);
  
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.setTextColor(WHITE);
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0,0);
  display.println("AirX");
  display.display();
  delay(2000);
  display.clearDisplay();
  display.display();
  delay(100);

}
void loop(){
  display.clearDisplay();
  if (key.get() ==1 ){
    display.setTextColor(WHITE);
    display.setTextSize(2);
    display.setCursor(0,0);
    display.println(key.name);
    display.setCursor(25,0);
    display.println(":ON");
    display.display();
  }
   if (key.get() ==0 ){
    display.setTextColor(WHITE);
    display.setTextSize(2);
    display.setCursor(0,0);
    display.println(key.name);
    display.setCursor(25,0);
    display.println(":OFF");
    display.display();
  }
}