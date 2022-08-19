#include "ESP8266WiFi.h"
#include <Wire.h>
#include "Adafruit_SSD1306.h"
#include "Adafruit_GFX.h"

#define SCREEN_ADDRESS 0x3C

static String val = ""; 
const char *RemoteIp = "192.168.10.6"; // 设置远程主机Ip地址
const int RemotePort = 2000; // 设置远程主机端口号

WiFiClient client; // 创建Tcp客户端

Adafruit_SSD1306 display(128, 64, &Wire,-1);

void setup()
{
  Serial.begin(115200);
  Serial.println();
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.setTextColor(WHITE);
  display.clearDisplay();
  display.display();
  delay(2000); 
  
  display.setTextSize(1);
  display.setCursor(0, 5);
  display.println("Init.");
  display.display();
  delay(500);
  
  //WIFI连接
  WiFi.begin("CMCC-603", "h18017395008");  // 设置连接到的WiFi名称和密码
  display.setCursor(0,20);
  display.setTextSize(1);
  display.println("Connect to WIFI");
  display.display();
  Serial.println("Connect to WIFI");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }
  Serial.println();
  Serial.println(WiFi.localIP()); // 打印NodeMCU的IP地址
  display.setCursor(0,35);
  display.setTextSize(1);
  display.println(WiFi.localIP());
  display.display();
  delay(100);
   
  if (!client.connect(RemoteIp, RemotePort)) // 建立tcp连接
  { 
    
    Serial.println("Connected failed!");
    return;
  }
  
  client.print("5678");
  
  display.setTextSize(1);
  display.setCursor(0,50);
  display.println("Done.");
  display.display();
  delay(1000);
  display.clearDisplay();
  display.display();
}
void loop() {
  val="";
  if (client.available())
  {
    while (client.available() > 0) // 串口收到字符数大于零。
    {
    val += char(client.read());
    } 
    Serial.println(val);
    
    display.clearDisplay();
    display.display();
    display.setCursor(0, 0);
    display.setTextSize(2);
    display.println(val);
    display.display();
  }
}
