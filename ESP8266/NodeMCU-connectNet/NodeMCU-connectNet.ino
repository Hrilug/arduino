#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
  
LiquidCrystal_I2C lcd(0x27,16,2);  //配置LCD地址及行列

const char* ssid     = "ChinaNet-hrx";
const char* password = "hrx666666";
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "ntp1.aliyun.com", 60 * 60 * 8, 30 * 60 * 1000);

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to ");
  Serial.print(ssid); Serial.println(" ...");
  int i = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(i++); Serial.print(' ');
  }
  Serial.println("");
  Serial.println("Connection established!");
  Serial.print("IP address:    ");
  Serial.println(WiFi.localIP());
  timeClient.begin();
  lcd.init(); //初始化LCD
  lcd.backlight(); //打开背光 
}

void loop()
{

  timeClient.update();
  String time1 = timeClient.getFormattedTime();
  Serial.println(time1);
  
  lcd.setCursor(0,0);//设置显示位置
  lcd.print("Hello World!");//显示字符数据
  lcd.setCursor(0,1);//设置显示位置
  lcd.print(time1);//显示字符数据
  delay(1000);
}
