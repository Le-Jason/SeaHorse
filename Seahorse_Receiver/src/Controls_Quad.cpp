#include "Controls_Quad.h"

Controls_Quad::Controls_Quad(char Motor1Pin,char Motor2Pin,char Motor3Pin,char Motor4Pin)
{
    OffSets.Motor1Offset = 0;
    OffSets.Motor2Offset = 0;
    OffSets.Motor3Offset = 0;
    OffSets.Motor4Offset = 0;

    //Servo Intialization
    Motor1ESC.attach(Motor1Pin);
    Motor2ESC.attach(Motor2Pin);
    Motor3ESC.attach(Motor3Pin);
    Motor4ESC.attach(Motor4Pin);
}

void Controls_Quad::update(int Motor1Val,int Motor2Val,int Motor3Val,int Motor4Val)
{
    Motor1ESC.write(Values.Motor1Val);
    Motor2ESC.write(Values.Motor2Val);
    Motor3ESC.write(Values.Motor3Val);
    Motor4ESC.write(Values.Motor4Val);
}