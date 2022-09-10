#include <Wire.h>
#include "Adafruit_SSD1306.h"
#include "Adafruit_GFX.h"

#define SCREEN_ADDRESS 0x3C

#define gun A0
#define xaxis A1
#define yaxis A2
#define left 11
#define right 12
#define key1 5
#define key2 6
#define key3 7
#define key4 8
#define key5 9
#define key6 10

Adafruit_SSD1306 display(128, 64, &Wire, -1);

int gun_v,x_v,y_v,l_v,r_v,k1_v,k2_v,k3_v,k4_v,k5_v,k6_v=0;

void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.begin("Hello,It's AirX!");

  pinMode(left, INPUT);
  pinMode(right, INPUT);
  pinMode(key1, INPUT);
  pinMode(key2, INPUT);
  pinMode(key3, INPUT);
  pinMode(key4, INPUT);
  pinMode(key5, INPUT);
  pinMode(key6, INPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.setTextColor(WHITE);
  display.clearDisplay();
  display.display();
  delay(500);
  display.setTextSize(2);
  display.setCursor(0, 5);
  display.println("Hello!");
  display.display();
  delay(1000);
  display.setTextSize(2);
  display.setCursor(0, 30);
  display.println("AirX!");
  display.display();
  delay(3000);
  display.clearDisplay();
  delay(500);

}

void loop() {
  gun_v=analogRead(gun);
  x_v=analogRead(xaxis);
  y_v=analogRead(yaxis);
  l_v=digitalRead(left);
  r_v=digitalRead(right);
  k1_v=digitalRead(key1);
  k2_v=digitalRead(key2);
  k3_v=digitalRead(key3);
  k4_v=digitalRead(key4);
  k5_v=digitalRead(key5);
  k6_v=digitalRead(key6);

  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 5);
  display.println("gun:");
  display.setCursor(0, 25);
  display.println("x-a:");
  display.setCursor(0, 45);
  display.println("y-a:");
  display.setCursor(40, 5);
  display.println(gun_v);
  display.setCursor(40, 25);
  display.println(x_v);
  display.setCursor(40, 45);
  display.println(y_v);
  display.display();
  delay(500);
  
  
}
