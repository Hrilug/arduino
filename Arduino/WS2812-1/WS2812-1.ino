#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN            6

#define NUMPIXELS      8

//这里的变量会和库里面的变量冲突，所以就随便取了
float  RDE1 = 0; //其实这里用不着float，随便了
float  GRE1 = 0;
float  BLE1 = 0;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second

void setup() {

#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif

  pixels.begin();
}

void loop() {
  GRE1 = 0; //这里再给初始化一下，以免出错，如果计算没有错的话，没有必要
  for (int o = 0; o < 255; o++) {
    RDE1 = 255;
    GRE1 = GRE1 + 1;
    BLE1 = 0;
    for (int l = 0; l < NUMPIXELS; l++) { //这个for循环是一个个去点亮，不懂怎么去一起点亮
      pixels.setPixelColor(l, pixels.Color(RDE1, GRE1, BLE1));
      pixels.show();
    }
    delay(20);//让渐变慢些
  }
  RDE1 = 255;
  for (int p = 0; p < 255; p++) {
    RDE1 = RDE1 - 1;
    GRE1 = 255;
    BLE1 = 0;
    for (int l = 0; l < NUMPIXELS; l++) {
      pixels.setPixelColor(l, pixels.Color(RDE1, GRE1, BLE1));
      pixels.show();
    }
    delay(20);
  }
  BLE1 = 0;
  for (int k = 0; k < 255; k++) {
    RDE1 = 0;
    GRE1 = 255;
    BLE1 = BLE1 + 1;
    for (int l = 0; l < NUMPIXELS; l++) {
      pixels.setPixelColor(l, pixels.Color(RDE1, GRE1, BLE1));
      pixels.show();
    }
    delay(20);
  }
  GRE1 = 255;
  for (int k = 0; k < 255; k++) {
    RDE1 = 0;
    GRE1 = GRE1 - 1;
    BLE1 = 255;
    for (int l = 0; l < NUMPIXELS; l++) {
      pixels.setPixelColor(l, pixels.Color(RDE1, GRE1, BLE1));
      pixels.show();
    }
    delay(20);
  }
  RDE1 = 0;
  for (int h = 0; h < 150; h++) {
    RDE1 = RDE1 + 1;
    GRE1 = 0;
    BLE1 = 255;
    for (int l = 0; l < NUMPIXELS; l++) {
      pixels.setPixelColor(l, pixels.Color(RDE1, GRE1, BLE1));
      pixels.show();
    }
    delay(20);
  }
}
