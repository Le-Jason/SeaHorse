#ifndef Transmit_h
#define Transmit_h
#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const byte address[][6] = {"BE001","BE002"};

class Transmit
{
    #define joy1X A2 //joystick left x-axis(Controls Thrust) Pin
    #define joy1Y A3 //joystick left y-axis(Controls Roll) Pin
    #define joy1S 4 //joystick left switch Pin
    #define joy2X A0 //joystick right x-axis(Controls Pitch) Pin
    #define joy2Y A1 //joystick right y-axis(Controls Yaw) Pin
    #define joy2S 7 //joystick right switch Pin
    #define button1 2 //button for Mode 1 Pin
    #define button2 3 //button for Mode 2 Pin
    #define radioCNS 9 //nRF24L01 CNS Pin
    #define radioCE 10 //nRF24L01 CE Pin
    
    public:
  
        void InitializeTransmitter();
    
};
struct Data_sent //struct of data to send over to reciever
{
    byte ch1;
    byte ch2;
    byte ch3;
    byte ch4;
};
#endif