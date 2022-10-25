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

class IMUstateVector{
    public:
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
        float oldTime;
        float newTime;
        float oldPhi;
        float oldTheta;
        float oldPsi;
        float oldU;
        float oldV;
        float oldW;
        float oldAx;
        float oldAy;
        float oldAz;

};

struct stateVector //struct of data to send over to reciever
{
    public:
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
        float diffTime;
        int8_t temp;
    public:
        Adafruit_BNO055 myIMU = Adafruit_BNO055();
        Euler euler;
        Quat quater;
        stateVector statevector;
        IMUstateVector vectorIMU;
        Navigation();
        virtual ~Navigation(){};
        stateVector update();
        void calibration_BNO();
        void measurementIMU_BNO();
        void filter();
};


#endif