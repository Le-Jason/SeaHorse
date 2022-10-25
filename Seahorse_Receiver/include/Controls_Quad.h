#ifndef Controls_Quad_h
#define Controls_Quad_h

#include <Servo.h>
#include <Arduino.h>

class offSets{
    public:
        int Motor1Offset;
        int Motor2Offset;
        int Motor3Offset;
        int Motor4Offset;
};

class control_pins{
    public:
        char Motor1Pin;
        char Motor2Pin;
        char Motor3Pin;
        char Motor4Pin;
};

class values{
    public:
        int Motor1Val;
        int Motor2Val;
        int Motor3Val;
        int Motor4Val;
};

class Controls_Quad
{
    protected:
        Servo Motor1ESC; //Top Right Servo Object
        Servo Motor2ESC; //Bottom Right Servo Object
        Servo Motor3ESC; //Bottom Left Servo Object
        Servo Motor4ESC; //Top Left Servo Object
    public:
        offSets OffSets;
        control_pins Pins;
        values Values;

        Controls_Quad(char Motor1Pin,char Motor2Pin,char Motor3Pin,char Motor4Pin);
        virtual ~Controls_Quad() {};
        // void initialize();
        void update(int Motor1Val,int Motor2Val,int Motor3Val,int Motor4Val);
};


#endif