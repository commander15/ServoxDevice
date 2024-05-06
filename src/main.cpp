#include <Arduino.h>
#include <Servo.h>

#define SERVO_PIN 2
#define IR_PIN    A5

Servo Motor;

void moveMotor(int pos);

void setup() {
  Serial.begin(9600);
  Serial.println(0);

  Motor.attach(SERVO_PIN);
  Motor.write(0);
}

void loop() {
  if (Serial.available() >= 5) {
    String packet = Serial.readStringUntil('#');
    packet.remove(0, 1);

    int pos = packet.toInt();
    moveMotor(pos);
  } else
    delay(500);
}

void moveMotor(int pos)
{
    Motor.write(pos);

    Serial.print('*');

    if (pos < 10)
      Serial.print("00");
    else if (pos < 100)
      Serial.print('0');
    Serial.print(pos);

    Serial.print('#');

    delay(15);
}
