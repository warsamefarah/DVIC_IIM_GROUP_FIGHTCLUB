#include <Arduino.h>
#include <Servo.h>

Servo myservo;
Servo myservo2;

int pos = 0;
// int val;

void setup() {
  pinMode(9, INPUT);
  myservo.attach(3);

  pinMode(10, INPUT);
  myservo2.attach(11);

  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (digitalRead(9)) {
    for (pos = 0; pos <= 90; pos += 1) {
      myservo.write(pos);
      delay(2);
    }

    for (pos = 90; pos >= 0; pos -= 1) {
      myservo.write(pos);
      delay(2);
    }
  }

  if (digitalRead(10)) {
    for (pos = 0; pos <= 100; pos += 1) {
      myservo2.write(pos);
      delay(2);
    }

    for (pos = 100; pos >= 0; pos -= 1) {
      myservo2.write(pos);
      delay(2);
    }
  }

  if (digitalRead(10) && digitalRead(9)) {
    for (pos = 0; pos <= 90; pos += 1) {
      myservo.write(pos);
      myservo2.write(pos);
      delay(2);
    }

    for (pos = 90; pos >= 0; pos -= 1) {
      myservo.write(pos);
      myservo2.write(pos);
      delay(2);
    }
  }

  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
}