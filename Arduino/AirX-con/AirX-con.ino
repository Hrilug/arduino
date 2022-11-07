#include <Wire.h>
#include "Adafruit_SSD1306.h"
#include "Adafruit_GFX.h"
#include "airx.h"

#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(128, 64, &Wire, -1);

airx gun, xa, ya, key1, key2, key3, key4, key5, key6;
airx mem[6] = { key1, key2, key3, key4, key5, key6 };
int data[6];
int mode = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("Hello,It's AirX!");
  gun.init(A0, 2, 'gun');
  xa.init(A1, 2, 'xa');
  ya.init(A2, 2, 'ya');
  key1.init(5, 1, 'key1');
  key2.init(6, 1, 'key2');
  key3.init(7, 1, 'key3');
  key4.init(8, 1, 'key4');
  key5.init(9, 1, 'key5');
  key6.init(10, 1, 'key6');

  pinMode(11,INPUT_PULLUP);
  pinMode(12,INPUT_PULLUP);

  data[0] = key1.get();
  data[1] = key2.get();
  data[2] = key3.get();
  data[3] = key4.get();
  data[4] = key5.get();
  data[5] = key6.get();

  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.setTextColor(WHITE);
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(40, 30);
  display.println("AirX");
  display.display();
  delay(2000);
  display.clearDisplay();
  delay(500);
}

void loop() {
  //Serial.print(gun.get());
  //Serial.print(xa.get());
  //Serial.println(ya.get());

  if (digitalRead(11) == 0) {
    mode = 0;
    display.clearDisplay();
  } else if (digitalRead(12) == 0) {
    mode = 1;
    display.clearDisplay();
  }

  if (mode == 0) {
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
  } else if (mode == 1) {
    int ldata[6] = { key1.get(), key2.get(), key3.get(), key4.get(), key5.get(), key6.get() };
    for (int con = 5; con <= 0; con--) {
      Serial.println(ldata[con]);
    }

    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(0, 5);
    for (int con = 5; con <= 0; con--) {
      display.println(ldata[con]);
    }
    display.display();
    for (int con = 5; con <= 0; con--) {
      data[con] = ldata[con];
    }
  }
}