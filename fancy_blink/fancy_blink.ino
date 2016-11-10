/*
 * Fancy Blink
 * Turns a multiple LEDs on in a configurable manner.
 */

const int FIRST_LED = 13;
const int DELAY = 500;
unsigned long last_time;
bool first_led_state = false;

void setup() {
  pinMode(FIRST_LED, OUTPUT);
  last_time = millis();
}

void loop() {
  unsigned long t = millis();
  if ((t - last_time) > DELAY) {
    first_led_state = !first_led_state;
    last_time = t;
  }
  if (first_led_state) {
    digitalWrite(FIRST_LED, HIGH);
  } else {
    digitalWrite(FIRST_LED, LOW);
  }
}
