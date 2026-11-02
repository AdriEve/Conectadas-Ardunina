const int boca = 9;

void setup() {
  pinMode(boca, OUTPUT);
  randomSeed(analogRead(A0));
}

void loop() {
  int sons = random(3, 8);
  for (int i = 0; i < sons; i++) {
    int duracao = random(60, 180);
    tone(boca, random(400, 1400), duracao);
    delay(duracao + 30);
  }
  delay(random(800, 2000));
}
