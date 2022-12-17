#include <Arduino.h>

#include "Motor.h"

/**
 * Setup the Motor
 */
Motor::Motor(uint8_t in1, uint8_t in2, uint8_t pwm, uint8_t offset, uint8_t standBy, int iMin = 0, int iMax = 255)
{
  motor = TB6612(in1, in2, pwm, offset, standBy);
  min = iMin;
  max = iMax;
}

void Motor::forward(int speed)
{
  motor.drive((map(speed, min, max, 0, 255)));
}

void Motor::forward(int speed, int duration)
{
  motor.drive((map(speed, min, max, 0, 255)), duration);
}

void Motor::backward(int speed)
{
  motor.drive(-(map(speed, min, max, 0, 255)));
}

void Motor::backward(int speed, int duration)
{
  motor.drive(-(map(speed, min, max, 0, 255)), duration);
}

void Motor::stop()
{
  motor.brake();
}