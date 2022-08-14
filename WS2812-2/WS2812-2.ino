#include <FastLED.h>

#define LED_PIN     6

#define NUM_LEDS    8

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  
  
  leds[0] = CRGB(0, 0, 0);
  FastLED.show();
  delay(500);
}
