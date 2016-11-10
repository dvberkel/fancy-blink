/*
 * Fancy Blink
 * Turns a multiple LEDs on in a configurable manner.
 */

const int FIRST_LED = 13;
const int DELAY = 500;
unsigned long last_time;
int first_led_state = 0;

void setup() {
  pinMode(FIRST_LED, OUTPUT);
  last_time = millis();
}

void loop() {
  unsigned long t = millis();
  if ((t - last_time) > DELAY) {
    first_led_state = 255 - first_led_state;
    last_time = t;
  }
  digitalWrite(FIRST_LED, first_led_state);
}
