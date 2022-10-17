#ifndef Controls_h
#define Controls_h

#include <Servo.h>
#include <Arduino.h>

class offSets{
    public:
        int pitchOffset;
        int rollOffset;
        int yawOffset;
};

class pins{
    public:
        char YawPin;
        char RollPinR;
        char RollPinL;
        char PitchPin;
        char ThottlePin;
};

class values{
public:
    int pitchVal;
    int rollRVal;
    int rollLVal;
    int yawVal;
    int thrustVal;
};

class Controls
{
protected:
    Servo pitchServo; //Pitch Servo Object
    Servo rollRServo; //RollR Servo Object
    Servo rollLServo; //RollL Servo Object
    Servo yawServo; //Yaw Servo Object
    Servo throttleESC; //trottleESC Servo Object
public:
    offSets OffSets;
    pins Pins;
    values Values;

    Controls(char YawPin,char RollPinR,char RollPinL,char PitchPin,char ThottlePin);
    virtual ~Controls() {};
    // void initialize();
    void update(int pitchVal,int rollRVal,int yawVal,int thrustVal);
};


#endif