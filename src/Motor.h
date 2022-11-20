#include <Arduino.h>

class Motor
{
    public:
        Motor(uint8_t iPin1, uint8_t iPin2, bool iReversed = false, int iMin = 0, int iMax = 1023);
        void forward(int speed);
        void backward(int speed);
        void stop();
        uint8_t pin1;
        uint8_t pin2;
        int min = 0;
        int max = 1023;
        bool reversed = false;
};
