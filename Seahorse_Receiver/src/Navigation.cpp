#include "Navigation.h"

Navigation::Navigation()
{
    myIMU.begin();
    int8_t temp=myIMU.getTemp();
    myIMU.setExtCrystalUse(true);
    samplingRate = 100;
    statevector.x = 0;
    statevector.y = 0;
    statevector.z = 0;
}


stateVector Navigation::update()
{
    uint8_t system, gyro, accel, mg = 0;
    myIMU.getCalibration(&system, &gyro, &accel, &mg);

    imu::Quaternion quat=myIMU.getQuat();
    quater.q0 = quat.w();
    quater.q1 = quat.x();
    quater.q2 = quat.y();
    quater.q3 = quat.z();

    euler.roll = atan2(2*(quater.q0*quater.q1+quater.q2*quater.q3),1-2*(quater.q1*quater.q1+quater.q2*quater.q2));
    euler.pitch=asin(2*(quater.q0*quater.q2-quater.q3*quater.q1));
    euler.yaw=-atan2(2*(quater.q0*quater.q3+quater.q1*quater.q2),1-2*(quater.q2*quater.q2+quater.q3*quater.q3))-(pi/2);

    return statevector;
    delay(samplingRate);
}