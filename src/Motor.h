#include <Arduino.h>

#include "TB6612.h"

class Motor
{
    public:
        Motor(uint8_t in1, uint8_t in2, uint8_t pwm, uint8_t offset, uint8_t standBy, int iFromMin = 0, int iFromMax = 255, int iToMin = 0, int iToMax = 255);
        void forward(int speed);
        void forward(int speed, int duration);
        void backward(int speed);
        void backward(int speed, int duration);
        void stop();
        int fromMin = 0;
        int fromMax = 255;
        int toMin = 0;
        int toMax = 255;
        TB6612 motor = TB6612(0, 0, 0, 0, 0);
};
