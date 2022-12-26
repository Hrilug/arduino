#include <Wire.h>
#include "Adafruit_SSD1306.h"
#include "Adafruit_GFX.h"
#include "airx.h"
//#include <MsTimer2.h>

#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(128, 64, &Wire, -1);

airx gun, xa, ya, key1, key2, key3, key4, key5, key6;
airx mem[6] = { key1, key2, key3, key4, key5, key6 };
int data[6];
int mode = 0;

// void reset() {
//   mode = 0;
//   MsTimer2::stop();
// }

void setup() {
  Serial.begin(115200);
  Serial.println("Hello,It's AirX!");
  gun.init(A0, 2, "gun");
  xa.init(A1, 2, "xa");
  ya.init(A2, 2, "ya");
  key1.init(5, 1, "key1");
  key2.init(6, 1, "key2");
  key3.init(7, 1, "key3");
  key4.init(8, 1, "key4");
  key5.init(9, 1, "key5");
  key6.init(10, 1, "key6");

  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);

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
  delay(100);
}

void loop() {
  // int ldata[6] = { key1.get(), key2.get(), key3.get(), key4.get(), key5.get(), key6.get() };
  // for (int con = 0; con <= 5; con++) {
  //   if (data[con] != ldata[con]) {
  //     if (mode == 0) {
  //       mode = 1;
  //       MsTimer2::set(1000, reset);
  //       MsTimer2::start();
  //     } else if (mode == 1) {
  //       MsTimer2::stop();
  //       MsTimer2::set(1000, reset);
  //       MsTimer2::start();
  //     }
  //     display.clearDisplay();
  //     display.setTextSize(2);
  //     display.setCursor(0, 5);
  //     display.println(mem[con].name);
  //     if (ldata[con] == 0) {
  //       display.println(":on");
  //     } else if (ldata[con] == 1) {
  //       display.println(":off");
  //     }
  //     data[con] = ldata[con];
  //   }
  // }

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
  }
}