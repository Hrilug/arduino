#include<ESP8266WiFi.h>

const char* ssid = "CMCC-603";
const char* password = "h18017395008";

WiFiServer server(80);//服务端口
String data = "";

 void setup() {
  
  //开启串口监视器
  Serial.begin(115200);
  
  //开启wifi:用户名+密码
  WiFi.begin(ssid,password);

  //尝试连接wifi
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.println('.');
    }
  Serial.println("连接成功");
  Serial.println(WiFi.localIP());

  //开启服务
  server.begin();
  Serial.println("Server started"); 
}

void loop() {
 //确定是否连线
 WiFiClient client = server.available();
 Serial.println("客户端与服务器没有连接上");
 //判断客户端是否与服务器连上,若没有连接上,则执行if
 if(!client){
  return;
  }

  Serial.println("客户端与服务器连接上");
  //客户端是否与服务器连上
  while(client){
     if(!client.available()){
      if(data != "")
        Serial.println(data);
        data = "";
      }
    else if (client.available()) {
      //如果有一句话过来,则每执行一个while循环就往data添加字符（有信息过来会连续执行else if语句）
      data += char(client.read());
      }
    }
}
