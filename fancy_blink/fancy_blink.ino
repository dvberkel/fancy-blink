/*
 * Fancy Blink
 * Turns a multiple LEDs on in a configurable manner.
 */

struct LedData {
  unsigned int pin;
  unsigned int duration;
  unsigned long last_time;
  unsigned int state;
};

const unsigned int LED_COUNT = 1;
LedData LEDS[] = {
  { 13, 500, 0, 0 }
};

void setup() {
  unsigned long last_time = millis();
  for (int index = 0; index < LED_COUNT; index++) {
    pinMode(LEDS[index].pin, OUTPUT);
    LEDS[index].last_time = last_time;
  }
}

void loop() {
  unsigned long t = millis();
  for (int index = 0; index < LED_COUNT; index++) {
    if ((t - LEDS[index].last_time) > LEDS[index].duration) {
      LEDS[index].state = 255 - LEDS[index].state;
      LEDS[index].last_time = t; 
    }
    digitalWrite(LEDS[index].pin, LEDS[index].state);
  }
}
