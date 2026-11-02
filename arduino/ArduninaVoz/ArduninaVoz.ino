const int boca = 9;

void setup() {
  pinMode(boca, OUTPUT);
}

void loop() {
  tone(boca, 880, 180);
  delay(1000);
}
