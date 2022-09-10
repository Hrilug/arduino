#define gun A0
#define xaxis A1
#define yaxis A2
#define left 11
#define right 12
#define key1 5
#define key2 6
#define key3 7
#define key4 8
#define key5 9
#define key6 10


int gun_v,x_v,y_v,l_v,r_v,k1_v,k2_v,k3_v,k4_v,k5_v,k6_v=0;

void setup() {
  Serial.begin(9600);
  Serial.println("Hello,It's AirX!");

  pinMode(left, INPUT);
  pinMode(right, INPUT);
  pinMode(key1, INPUT);
  pinMode(key2, INPUT);
  pinMode(key3, INPUT);
  pinMode(key4, INPUT);
  pinMode(key5, INPUT);
  pinMode(key6, INPUT);

}

int analyze(int n,int v){
  if (n != v){
    v=n;
  Serial.println(v);
  }
  return v;
}

void loop() {
  gun_v=analyze(analogRead(gun),gun_v);
  x_v=analyze(analogRead(xaxis),x_v);
  y_v=analyze(analogRead(yaxis),y_v);
  l_v=analyze(digitalRead(left),l_v);
  r_v=analyze(digitalRead(right),r_v);
  k1_v=analyze(digitalRead(key1),k1_v);
  k2_v=analyze(digitalRead(key2),k2_v);
  k3_v=analyze(digitalRead(key3),k3_v);
  k4_v=analyze(digitalRead(key4),k4_v);
  k5_v=analyze(digitalRead(key5),k5_v);
  k6_v=analyze(digitalRead(key6),k6_v);
  
}
