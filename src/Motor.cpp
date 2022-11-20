#include <Arduino.h>

#include "Motor.h"

/**
 * Setup the Motor
 */
Motor::Motor(uint8_t iPin1, uint8_t iPin2, bool iReversed = false, int iMin = 0, int iMax = 1023)
{
    pin1 = iPin1;
    pin2 = iPin2;
    reversed = iReversed;
    min = iMin;
    max = iMax;
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
}

void Motor::forward(int speed)
{
  analogWrite(pin1, map(speed, min, max, 0, 255));
  digitalWrite(pin2, LOW);
}

void Motor::backward(int speed)
{
  digitalWrite(pin1, LOW);
  analogWrite(pin2, map(speed, min, max, 0, 255));
}

void Motor::stop()
{
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
}