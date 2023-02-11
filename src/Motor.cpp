#include <Arduino.h>

#include "Motor.h"

/**
 * Setup the Motor
 */
Motor::Motor(uint8_t in1, uint8_t in2, uint8_t pwm, uint8_t offset, uint8_t standBy, int iFromMin = 0, int iFromMax = 255, int iToMin = 0, int iToMax = 255)
{
  motor = TB6612(in1, in2, pwm, offset, standBy);
  fromMin = iFromMin;
  fromMax = iFromMax;
  toMin = iToMin;
  toMax = iToMax;
}

void Motor::forward(int speed)
{
  motor.drive((map(speed, fromMin, fromMax, toMin, toMax)));
}

void Motor::forward(int speed, int duration)
{
  motor.drive((map(speed, fromMin, fromMax, toMin, toMax)), duration);
}

void Motor::backward(int speed)
{
  motor.drive(-(map(speed, fromMin, fromMax, toMin, toMax)));
}

void Motor::backward(int speed, int duration)
{
  motor.drive(-(map(speed, fromMin, fromMax, toMin, toMax)), duration);
}

void Motor::stop()
{
  motor.brake();
}