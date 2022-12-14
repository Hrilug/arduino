#define NTC0 -1
#define NTC1 262
#define NTC2 294
#define NTC3 330
#define NTC4 350
#define NTC5 393
#define NTC6 441
#define NTC7 495
#define NTCL5 196
#define NTCL6 221
#define NTCL7 248   
#define NTCH1 525
//音符
int tune[]=                 
{
  NTC3,NTC2,NTC3,NTC6,NTC3,NTC2,NTC3,NTC7,
  NTC3,NTC2,NTC3,NTCH1,NTC7,NTC5,
  NTC3,NTC2,NTC3,NTC6,NTC3,NTC2,NTC3,NTC7,
  NTC5,NTC2,NTCL7,
  NTC3,NTC2,NTC3,NTC6,NTC3,NTC2,NTC3,NTC7,
  NTC3,NTC2,NTC3,NTCH1,NTC7,NTC5,
  NTC2,NTC3,NTCL6,NTC2,NTC3,NTCL6,NTCL5,
  NTCL6,NTC1,NTCL7,
  
  NTCL6,NTC1,NTC1,NTC2,NTC2,NTC3,NTC3,NTC5,NTC6,
  NTC5,NTC3,NTC2,
  NTCL6,NTC1,NTC1,NTC2,NTC2,NTC3,NTC3,NTCL6,NTCL5,
  NTCL6,NTC1,NTC1,NTC2,NTC2,NTC3,NTC3,NTC5,NTC6,
  NTC5,NTC3,NTC2,
  NTC2,NTC3,NTCL6,NTC2,NTC3,NTCL6,NTCL5,NTCL6,
 
  NTCL6,NTC1,NTC2,NTC1,NTCL6,
  NTCL6,NTC1,NTC2,NTC1,NTC3,
  NTC3,NTC5,NTC6,NTC6,NTC5,NTC3,NTC2,NTC1,NTC2,NTC3,
  NTCL6,NTC1,NTC2,NTC1,NTCL6,
  NTCL6,NTC1,NTC2,NTC1,NTC3,
  NTC2,NTC3,NTCL6,NTC2,NTC3,NTCL6,NTCL5,NTCL6,
  
  NTC3,NTC5,NTCH1,NTC7,NTC3,
  NTC3,NTC2,NTC1,NTC1,NTC2,NTC3,
  NTC3,NTC2,NTC1,NTC6,NTCH1,NTC7,NTC6,NTC5,NTC2,NTC3,
  NTC3,NTC5,NTCH1,NTC7,NTC3,
  NTC3,NTC2,NTC1,NTC1,NTC2,NTC3,
  NTC2,NTC3,NTCL6,NTC2,NTC3,NTCL6,NTCL5,NTCL6,
};
//节拍
int durt[]=                   
{
250,250,250,250,250,250,250,250,
250,250,250,250,500,500,
250,250,250,250,250,250,250,250,
500,500,1000,
250,250,250,250,250,250,250,250,
250,250,250,250,500,500,
250,250,500,250,250,250,250,500,500,1000,
 
250,250,250,250,250,250,250,125,125,
750,250,1000,
250,250,250,250,250,250,500,500,1500,
250,250,250,250,250,250,250,125,125,
750,250,1000,
250,250,500,250,250,250,250,1500,

250,250,750,250,500,250,250,
750,250,500,250,250,500,250,250,250,250,500,500,1000,
250,250,875,125,500,250,250,500,500,1000,
250,250,500,250,250,250,250,1500,

250,250,750,250,500,250,250,
500,250,250,500,250,250,500,250,250,250,250,250,250,1500,
250,250,750,250,500,250,250,
500,250,250,1000,250,250,500,250,250,250,250,2000,
 
};
int length;
int tonepin=6;   

void setup()
{
  pinMode(tonepin,OUTPUT);
  length=sizeof(tune)/sizeof(tune[0]);   
}

void loop()
{
  for(int x=0;x<length;x++)
  {
    tone(tonepin,tune[x]);
    delay(durt[x]);   
    noTone(tonepin);
  }
  delay(2000);
}
