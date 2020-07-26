const byte interruptPin = D1;
volatile int state = LOW;

void setup() {
  Serial.begin(115200);
  pinMode(interruptPin, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), handleInterrupt, RISING);
}

void loop() {
  digitalWrite(LED_BUILTIN, state);
}

void handleInterrupt() {
  delayMicroseconds(20);
  state = !state;
}
