#include <SPI.h> // 加载SPI库
#include <Wire.h> // 加载Wire库
#include <Adafruit_GFX.h> // 加载Adafruit_GFX库
#include <Adafruit_SSD1306.h> // 加载Adafruit_SSD1306库

// 定义 OLED屏幕的分辨率
Adafruit_SSD1306 display(128, 64, &Wire,-1);

void setup() {
  Serial.begin(9600); // 设置串口波特率

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // 设置OLED的I2C地址
  display.clearDisplay(); // 清空屏幕
  display.setTextSize(1); // 设置字体大小
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0); // 设置开始显示文字的坐标
  display.println("你好"); // 输出的字符
  display.display(); // 使更改的显示生效
}

void loop() {
   Serial.println("OLED FeatherWing test");
}
