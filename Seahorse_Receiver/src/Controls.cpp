#include "Controls.h"

Controls::Controls(char YawPin,char RollPinR,char RollPinL,char PitchPin,char ThottlePin)
{
    OffSets.pitchOffset = 95;
    OffSets.rollOffset = 100;
    OffSets.yawOffset = 90;

    //Servo Intialization
    pitchServo.attach(PitchPin);
    rollRServo.attach(RollPinR);
    rollLServo.attach(RollPinL);
    yawServo.attach(YawPin);
}

void Controls::update(int pitchVal,int rollRVal,int yawVal,int thrustVal)
{
    Values.pitchVal = map(Values.pitchVal,0,255,OffSets.pitchOffset-45,OffSets.pitchOffset+45);
    Values.rollRVal = map(Values.rollRVal,0,255,OffSets.rollOffset-45,OffSets.rollOffset+45);
    if((Values.rollRVal-OffSets.rollOffset)>0){
      Values.rollLVal = OffSets.rollOffset - (Values.rollRVal-OffSets.rollOffset);
    }
    yawVal = map(Values.yawVal,0,255,OffSets.yawOffset-45,OffSets.yawOffset+45);
    thrustVal = map(Values.thrustVal,127,255,1000,1500); //might change
    pitchServo.write(Values.pitchVal);
    rollRServo.write(Values.rollRVal);
    rollLServo.write(Values.rollLVal);
    yawServo.write(Values.yawVal);
    throttleESC.writeMicroseconds(Values.thrustVal);
}