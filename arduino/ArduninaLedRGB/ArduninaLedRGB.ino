const int vermelho = 5;
const int verde = 6;
const int azul = 3;

void setup() {
}

void cor(int r, int g, int b) {
  analogWrite(vermelho, r);
  analogWrite(verde, g);
  analogWrite(azul, b);
}

void loop() {
  cor(255, 0, 0);   delay(1000);
  cor(0, 255, 0);   delay(1000);
  cor(0, 0, 255);   delay(1000);
  cor(255, 0, 255); delay(1000);
}
