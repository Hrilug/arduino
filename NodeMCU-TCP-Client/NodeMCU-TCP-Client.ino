#include <BMA220.h>
#include "ESP8266WiFi.h"

const char *RemoteIp = "192.168.10.2"; // 设置远程主机Ip地址
const int RemotePort = 1234; // 设置远程主机端口号

WiFiClient client; // 创建Tcp客户端
BMA220 bma;

void setup()
{
  Serial.begin(115200);
  Serial.println();

  //WIFI连接
  WiFi.begin("CMCC-603", "h18017395008");  // 设置连接到的WiFi名称和密码
  Serial.print("Connecting...");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println(WiFi.localIP()); // 打印NodeMCU的IP地址


  if (!client.connect(RemoteIp, RemotePort)) // 建立tcp连接
  {
    Serial.println("Connected failed!");
    return;
  }
  client.print("hrilugclient");
  
  if (!bma.begin()) {
        Serial.println(F("No valid BMA220 sensor found, check wiring"));
        while (true){}  // stop here, no reason to go on...
}
}
void loop() {
  if (client.available())
  {
    int x=bma.readAcceleration(XAXIS);
    int y=bma.readAcceleration(YAXIS);
    int z=bma.readAcceleration(ZAXIS);
    Serial.print("x-axis: ");
    Serial.println(x);
    Serial.print("y-axis: ");
    Serial.println(y);
    Serial.print("z-axis: ");
    Serial.println(z);

    client.print("x");
    client.print(x);
    delay(1000);
  }
}
