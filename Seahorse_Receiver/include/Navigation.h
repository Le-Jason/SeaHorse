#ifndef Navigation_h
#define Navigation_h

#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <math.h>

class Quat{
    public:
        float q0;
        float q1;
        float q2;
        float q3;
};

class Euler{
    public:
        float roll;
        float pitch;
        float yaw;
};

struct stateVector //struct of data to send over to reciever
{
    float x;
    float y;
    float z;
    float phi;
    float theta;
    float psi;
    float u;
    float v;
    float w;
    float p;
    float q;
    float r;
};

class Navigation
{   
    protected:
        float pi = 3.14159265359;
        char samplingRate;
        float deg2rad = pi/180;
        float rad2deg = 180/pi;

    public:
        Adafruit_BNO055 myIMU = Adafruit_BNO055();
        Euler euler;
        Quat quater;
        stateVector statevector;
        Navigation();
        virtual ~Navigation(){};
        stateVector update();
};


#endif