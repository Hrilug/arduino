#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET     0
Adafruit_SSD1306 display(OLED_RESET);

void setup() {
  Serial.begin(9600);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //or 0x3C
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("HelloWorld");
  display.display();
  delay(1000);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("GET:");
  display.display();
}

int n = 0;
String str = "";

void loop() {
  str = "";

  n = Serial.available();
  if (n > 0) {
     while (Serial.available() > 0)  
    {
        str += char(Serial.read());
        delay(2);
    }
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.print("GET:");
    display.setCursor(0, 10);
    display.print(str);
    display.display();
  }
}
