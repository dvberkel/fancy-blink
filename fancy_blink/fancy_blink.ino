/*
 * Fancy Blink
 * Turns multiple LEDs on in a configurable manner.
 */

struct LedData {
  unsigned int pin;
  unsigned int duration;
  unsigned long last_time;
  unsigned int state;
};

void update_led_data(LedData &data, unsigned long t) {
  if ((t - data.last_time) > data.duration) {
    data.state = 255 - data.state;
    data.last_time = t; 
  }  
}

const unsigned int LED_COUNT = 3;
LedData leds[] = {
  { 8, 200, 0, 0 },
  { 9, 300, 0, 0 },
  { 10, 500, 0, 0 },
};

void setup() {
  unsigned long last_time = millis();
  for (int index = 0; index < LED_COUNT; index++) {
    pinMode(leds[index].pin, OUTPUT);
    leds[index].last_time = last_time;
  }
}

void loop() {
  unsigned long t = millis();
  for (int index = 0; index < LED_COUNT; index++) {
    update_led_data(leds[index], t);
    digitalWrite(leds[index].pin, leds[index].state);
  }
}
