/*
 * Fancy Blink
 * Turns a multiple LEDs on in a configurable manner.
 */

const unsigned int LED_COUNT = 1;
const unsigned int LEDS[] = {13};
const unsigned int DELAY[] = {500};

unsigned long last_times[] = {0};
unsigned int led_states[] = {0};

void setup() {
  unsigned long last_time = millis();
  for (int index = 0; index < LED_COUNT; index++) {
    pinMode(LEDS[index], OUTPUT);
    last_times[index] = last_time;
  }
}

void loop() {
  unsigned long t = millis();
  for (int index = 0; index < LED_COUNT; index++) {
    if ((t - last_times[index]) > DELAY[index]) {
      led_states[index] = 255 - led_states[index];
      last_times[index] = t; 
    }
    digitalWrite(LEDS[index], led_states[index]);
  }
}
