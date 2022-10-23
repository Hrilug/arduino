#include <WiFi.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


const char *id = "CMCC-603"; //定义两个字符串指针常量
const char *psw = "h18017395008";

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire);

void setup()
{
    Serial.begin(115200); // 设置串口波特率
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // 设置OLED的I2C地址

    display.clearDisplay();              // 清空屏幕
    display.setTextSize(1);              // 设置字体大小
    display.setTextColor(SSD1306_WHITE); // 设置字体颜色
    display.setCursor(0, 0);             // 设置开始显示文字的坐标
    display.println("Hello World!");     // 输出的字符
    display.display();                   // 使更改的显示生效
    delay(3000);
    display.clearDisplay();
    display.display();

    WiFi.begin(id, psw);
    while (WiFi.status() != WL_CONNECTED)
    { //未连接上
        delay(500);
        Serial.println("正在连接...");
        display.setTextSize(1);
        display.setCursor(0,10);             
        display.println("connecting");     
        display.display();                   

    }
    Serial.println("连接成功！");           
    Serial.println("正在连接...");

    display.clearDisplay();
    display.display();
    display.setTextSize(1);
    display.setCursor(0,10);             
    display.println("ip");     
    display.display();                   

}

void loop()
{
}
