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
  Serial.begin(115200);
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
  display.println("AirX");
  display.display();
  delay(3000);
  display.clearDisplay();
  display.display();
  delay(500);
}

int analyze(int n,int v){
  if n != v{
    v=n;
  display.setTextSize(2);
  display.setCursor(0,0);
  display.println(b);
  display.display();
  }
  return v;
}

void loop() {
  gun_v=analyze(analogRead(gun),gun_v);
  x_v=analyze(analogRead(xaxis),x_v);
  y_v=analyze(analogRead(yaxis),y_v);
  l_v=analyze(digitalWrite(left),l_v);
  r_v=analyze(digitalWrite(right),r_v);
  k1_v=analyze(digitalWrite(key1),k1_v);
  k2_v=analyze(digitalWrite(key2),k2_v);
  k3_v=analyze(digitalWrite(key3),k3_v);
  k4_v=analyze(digitalWrite(key4),k4_v);
  k5_v=analyze(digitalWrite(key5),k5_v);
  k6_v=analyze(digitalWrite(key6),k6_v);
  
}
