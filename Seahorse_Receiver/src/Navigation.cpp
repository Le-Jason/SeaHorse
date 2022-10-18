#include "Navigation.h"

Navigation::Navigation()
{
    myIMU.begin();
    temp = myIMU.getTemp();
    imu::Vector<3> accel = myIMU.getVector(Adafruit_BNO055::VECTOR_EULER);
    myIMU.setExtCrystalUse(true);
    samplingRate = 100;
    statevector.x = 0;
    statevector.y = 0;
    statevector.z = 0;
    vectorIMU.oldPhi = 0;
    vectorIMU.oldTheta = 0;
    vectorIMU.oldPsi = 0;
    vectorIMU.oldU = 0;
    vectorIMU.oldV = 0;
    vectorIMU.oldW = 0;
    vectorIMU.oldAx = accel.x();
    vectorIMU.oldAy = accel.y();
    vectorIMU.oldAz = accel.z();
    vectorIMU.oldTime = millis();
    calibration_BNO();

}

void Navigation::calibration_BNO()
{
    uint8_t system, gyro, accel, mg = 0;
    myIMU.getCalibration(&system, &gyro, &accel, &mg);
}

void Navigation::measurementIMU_BNO()
{
    imu::Quaternion quat=myIMU.getQuat();
    imu::Vector<3> accel = myIMU.getVector(Adafruit_BNO055::VECTOR_EULER);
    quater.q0 = quat.w();
    quater.q1 = quat.x();
    quater.q2 = quat.y();
    quater.q3 = quat.z();
    euler.roll = atan2(2*(quater.q0*quater.q1+quater.q2*quater.q3),1-2*(quater.q1*quater.q1+quater.q2*quater.q2));
    euler.pitch = asin(2*(quater.q0*quater.q2-quater.q3*quater.q1));
    euler.yaw = -atan2(2*(quater.q0*quater.q3+quater.q1*quater.q2),1-2*(quater.q2*quater.q2+quater.q3*quater.q3))-(pi/2);
    vectorIMU.newTime = millis();
    diffTime = vectorIMU.newTime - vectorIMU.oldTime;
    vectorIMU.oldPhi = vectorIMU.phi;
    vectorIMU.oldTheta = vectorIMU.theta;
    vectorIMU.oldPsi = vectorIMU.psi;
    

    vectorIMU.x = ((accel.x() - vectorIMU.oldAx) * diffTime * diffTime) + ((vectorIMU.u-vectorIMU.oldU)*diffTime) +  vectorIMU.x;
    vectorIMU.y = ((accel.y() - vectorIMU.oldAy) * diffTime * diffTime) + ((vectorIMU.v-vectorIMU.oldV)*diffTime) +  vectorIMU.y;
    vectorIMU.z = ((accel.z() - vectorIMU.oldAz) * diffTime * diffTime) + ((vectorIMU.w-vectorIMU.oldW)*diffTime) +  vectorIMU.z;;
    vectorIMU.phi = euler.roll;
    vectorIMU.theta = euler.pitch;
    vectorIMU.psi = euler.yaw;
    vectorIMU.u = ((accel.x() - vectorIMU.oldAx) * diffTime) + vectorIMU.u;
    vectorIMU.v = ((accel.y() - vectorIMU.oldAy) * diffTime) + vectorIMU.y;
    vectorIMU.w = ((accel.x() - vectorIMU.oldAz) * diffTime) + vectorIMU.z;
    vectorIMU.p = (vectorIMU.phi - vectorIMU.oldPhi)/diffTime;
    vectorIMU.q = (vectorIMU.theta - vectorIMU.oldTheta)/diffTime;
    vectorIMU.r = (vectorIMU.psi - vectorIMU.oldPsi)/diffTime;

    vectorIMU.oldU = vectorIMU.u;
    vectorIMU.oldV = vectorIMU.v;
    vectorIMU.oldW = vectorIMU.w;

}

void Navigation::filter()
{
    statevector.x = vectorIMU.x;
    statevector.y = vectorIMU.y;
    statevector.z = vectorIMU.z;
    statevector.phi = vectorIMU.phi;
    statevector.theta = vectorIMU.theta;
    statevector.psi = vectorIMU.psi;
    statevector.u = vectorIMU.u;
    statevector.v = vectorIMU.v;
    statevector.w = vectorIMU.w;
    statevector.p = vectorIMU.p;
    statevector.q = vectorIMU.q;
    statevector.r = vectorIMU.r;
}

stateVector Navigation::update()
{
    measurementIMU_BNO();
    filter();
    return statevector;
    delay(samplingRate);
}