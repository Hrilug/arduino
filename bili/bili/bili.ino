#define firstsign_pin 2     //第一次触发引脚
#define secondsign_pin 3    //第二次触发引脚
#define gunswitch 4            //扳机开关
#define mos_pin 5              //二级线圈开关
#define signs_distance 5.0    //两个触发器之间的距离,单位cm,有一位小数保证语法正确
#define sign_to_coil_distance 2.0 //第二个触发器到线圈中心距离，单位cm,有一位小数保证语法正确

int speed(){
  float speed = 0;
  int timedelay = 0;
  int firstsign = 1;
  int secondsign = 1;
  while(firstsign){
     firstsign =1- digitalRead(firstsign_pin);  //firstsign=0时跳出while循环
  }
  int Time1 = millis();   //stmega328p时间戳，单位ms
   while(secondsign){
     secondsign =1- digitalRead(secondsign_pin);  //secondsign=0时跳出while循环
  }
  int Time2 = millis();
  speed = signs_distance*10.0 / (float(Time2 -Time1)); // m/s = (cm/ms)*10 
  timedelay = int(sign_to_coil_distance*10 /speed); //ms = cm*10 / (m/s)
  char buff[20];
  char speed_str[8];
  dtostrf(speed,5,2,speed_str);
  sprintf(buff,"speed:%s m/s,timedelay:%d ms",speed_str,timedelay);
  Serial.println(buff);

  return timedelay;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(firstsign_pin,INPUT);
  pinMode(secondsign_pin,INPUT);
  pinMode(gunswitch,INPUT);
  pinMode(mos_pin,OUTPUT);

  Serial.begin(9600);  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(mos_pin,LOW);
  if(digitalRead(gunswitch) ==1 ) {
    delayMicroseconds(speed());
    digitalWrite(mos_pin,HIGH);
  }
}

