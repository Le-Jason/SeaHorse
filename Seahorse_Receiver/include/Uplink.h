#ifndef Uplink_h
#define Uplink_h

#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const byte address[][6] = {"BE001","BE002"};

class Uplink
{
    #define radioCNS 7 //nRF24L01 CNS Pin
    #define radioCE 8 //nRF24L01 CE Pin
    #define ledMode 3 //LED Mode Pin Number
    #define ledBatt 4 //LED Battery Pin Number
    public:
  
        void InitializeUplink();
    
};
struct Data_received //struct of data to send over to reciever
{
    byte ch1;
    byte ch2;
    byte ch3;
    byte ch4;
};

#endif