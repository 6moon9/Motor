#include <Arduino.h>

#define DEFAULTSPEED 255

class TB6612
{
    public:
        TB6612(int In1pin, int In2pin, int PWMpin, int offset, int STBYpin);
        void drive(int speed);
        void drive(int speed, int duration);
        void brake();
        void standby();
    private:
        int In1, In2, PWM, Offset, Standby;
        void fwd(int speed);
        void rev(int speed);
};