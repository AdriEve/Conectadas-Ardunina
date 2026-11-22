const int trig = 8;
const int echo = 12;
const int boca = 9;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(boca, OUTPUT);
}

void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long tempo = pulseIn(echo, HIGH);
  int distancia = tempo * 0.034 / 2;
  if (distancia < 15) {
    tone(boca, 880, 100);
  }
  delay(200);
}
