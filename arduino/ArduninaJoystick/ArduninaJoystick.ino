#include <Servo.h>

const int eixoX = A1;
const int pinoPescoco = 11;

Servo pescoco;

void setup() {
  pescoco.attach(pinoPescoco);
}

void loop() {
  int x = analogRead(eixoX);
  int angulo = map(x, 0, 1023, 0, 180);
  pescoco.write(angulo);
  delay(15);
}
