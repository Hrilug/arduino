#include <Wire.h>
#include "Adafruit_SSD1306.h"
#include "Adafruit_GFX.h"
#include "airx.h"

#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(128, 64, &Wire, -1);

airx gun;
airx xa;
airx ya;

void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.begin("Hello,It's AirX!");


  gun.init(A0, 1);
  xa.init(A1, 1);
  ya.init(A2, 1);
  //  left.init(11, 0);
  //  right.init(12, 0);
  //  key1.init(5, 0);
  //  key2.init(6, 0);
  //  key3.init( 7, 0);
  //  key4.init(8, 0);
  //  key5.init(9, 0);
  //  key6.init(10, 0);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.setTextColor(WHITE);
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 30);
  display.println("AirX!");
  display.display();
  delay(3000);
  display.clearDisplay();
  delay(500);

}

void loop() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 5);
  display.println("gun:");
  display.setCursor(0, 25);
  display.println("x-a:");
  display.setCursor(0, 45);
  display.println("y-a:");
  display.setCursor(50, 5);
  display.println(gun.get());
  display.setCursor(50, 25);
  display.println(xa.get());
  display.setCursor(50, 45);
  display.println(ya.get());
  display.display();
  delay(50);
}