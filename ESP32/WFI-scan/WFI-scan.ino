#include <Arduino.h>
#include "WiFi.h"
#include "Ticker.h"
 
String ssid = "";
String password = "";
Ticker t1;
 
void aysncScanHandler()
{
  if (!WiFi.isConnected())
  {
    int wifiScanStatus = WiFi.scanComplete();
    switch (wifiScanStatus)
    {
    case -1:
      Serial.println("扫描中...");
      break;
    case -2:
      Serial.println("未进行扫描...");
      break;
    default:
      Serial.println("扫描完成");
      for (size_t i = 0; i < wifiScanStatus; i++)
      {
        Serial.print("WiFi的名称(SSID):");
        Serial.println(WiFi.SSID(i));
        Serial.print("WiFi的信号强度(RSSI):");
        Serial.println(WiFi.RSSI(i));
        Serial.print("WiFi加密与否:");
        Serial.println(WiFi.encryptionType(i) == WIFI_AUTH_OPEN ? "未加密" : "加密");
 
        // if (WiFi.SSID(i) == "anny")
        // {
        //   ssid = WiFi.SSID(i);
        //   password = "20141208";
        // };
      }
      WiFi.scanDelete();
      t1.detach();
      break;
    }
  }
}
 
void connectAnny()
{
  WiFi.begin();
  while (!WiFi.isConnected())
  {
    Serial.print(".");
  }
  Serial.println("连接成功");
}
 
void setup()
{
  Serial.begin(115200);
  WiFi.mode(WIFI_MODE_STA);
  WiFi.disconnect(); //断开可能的连接
  delay(100);
  Serial.println("开始扫描WIFI:");
  WiFi.scanNetworks(true);
  t1.attach(0.5, aysncScanHandler);
}
void loop()
{
  if (!WiFi.isConnected())
  {
    if (ssid == "anny")
    {
      Serial.println(ssid);
      connectAnny();
    }
  }
}