#include <Adafruit_SSD1306.h>
#include <splash.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>

#define OLED_RESET     0
Adafruit_SSD1306 display( 128, 64, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, 16, 17);

  Wire.begin(/*SDA*/13,/*SCL*/14);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.print("GET:");
  display.display();
}

int n = 0;
String str = "";

void loop() {
  str = "";

  n = Serial2.available();
  if (n > 0) {
     while (Serial2.available() > 0)  
    {
        str += uint8_t(Serial2.read());
        delay(2);
    }
    //Serial.print("GET:");
    Serial.println(str);
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(2);
    display.setCursor(0, 0);
    display.print("GET:");
    display.setCursor(0, 25);
    display.print(str);
    display.display();
  }
}