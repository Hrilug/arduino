int leftMotor1 = 2;
int leftMotor2 = 3;
int rightMotor1 = 4;
int rightMotor2 = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //usart read
  if(Serial.available()>0)
  {
    char cmd = Serial.read();//读取蓝牙模块发送到串口的数据
  
    Serial.print(cmd);
    motorRun(cmd);
      
  }  
}
void motorRun(int cmd)
{
  switch(cmd){
    case '1':
      digitalWrite(leftMotor1, HIGH);
      digitalWrite(leftMotor2, LOW);
      digitalWrite(rightMotor1, HIGH);
      digitalWrite(rightMotor2, LOW);
      break;
     case '2':
      digitalWrite(leftMotor1, LOW);
      digitalWrite(leftMotor2, HIGH);
      digitalWrite(rightMotor1, LOW);
      digitalWrite(rightMotor2, HIGH);
      break;
     case '3':
      digitalWrite(leftMotor1, LOW);
      digitalWrite(leftMotor2, HIGH);
      digitalWrite(rightMotor1, HIGH);
      digitalWrite(rightMotor2, LOW);
      break;
     case '4':
      digitalWrite(leftMotor1, HIGH);
      digitalWrite(leftMotor2, LOW);
      digitalWrite(rightMotor1, LOW);
      digitalWrite(rightMotor2, HIGH);
      break;
     default:
      digitalWrite(leftMotor1, LOW);
      digitalWrite(leftMotor2, LOW);
      digitalWrite(rightMotor1, LOW);
      digitalWrite(rightMotor2, LOW);
  }
}
