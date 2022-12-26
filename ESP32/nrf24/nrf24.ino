#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "nRF24L01.h"
#include "RF24.h"
#include <Adafruit_SSD1306.h>

#define OLED_RESET     0
Adafruit_SSD1306 display( 128, 64, &Wire, OLED_RESET);

RF24 radio(22,21);
const byte address[5] = {0x00,0x00,0x00,0x00,0x01};
 
void setup() {
  Serial.begin(115200);
  Serial.println("HelloWrold!");

  Wire.begin(/*SDA*/13,/*SCL*/14);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.print("GET:");
  display.display();

  radio.begin();
  radio.openReadingPipe(0,address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();  
}

void loop() {
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));

    Serial.println(text);

    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(2);
    display.setCursor(0, 0);
    display.print("GET:");
    display.setCursor(0, 30);
    display.print(text);
    display.display();
  }
}
