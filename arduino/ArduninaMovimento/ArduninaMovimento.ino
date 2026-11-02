#include <Servo.h>

const int pinoPescoco = 11;

Servo pescoco;

void setup() {
  pescoco.attach(pinoPescoco);
  pescoco.write(90);
}

void loop() {
  pescoco.write(75);
  delay(650);
  pescoco.write(105);
  delay(650);
}
