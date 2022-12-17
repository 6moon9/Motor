#include "TB6612.h"
#include <Arduino.h>

TB6612::TB6612(int In1pin, int In2pin, int PWMpin, int offset, int STBYpin)
{
    In1 = In1pin;
    In2 = In2pin;
    PWM = PWMpin;
    Standby = STBYpin;
    Offset = offset;

    pinMode(In1, OUTPUT);
    pinMode(In2, OUTPUT);
    pinMode(PWM, OUTPUT);
    pinMode(Standby, OUTPUT);
}

void TB6612::drive(int speed)
{
    digitalWrite(Standby, HIGH);
    speed = speed * Offset;
    if (speed >= 0)
        fwd(speed);
    else
        rev(-speed);
}
void TB6612::drive(int speed, int duration)
{
    drive(speed);
    delay(duration);
}

void TB6612::fwd(int speed)
{
    digitalWrite(In1, HIGH);
    digitalWrite(In2, LOW);
    analogWrite(PWM, speed);
}

void TB6612::rev(int speed)
{
    digitalWrite(In1, LOW);
    digitalWrite(In2, HIGH);
    analogWrite(PWM, speed);
}

void TB6612::brake()
{
    digitalWrite(In1, HIGH);
    digitalWrite(In2, HIGH);
    analogWrite(PWM, 0);
}

void TB6612::standby()
{
    digitalWrite(Standby, LOW);
}