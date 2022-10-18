#ifndef Telemetry_h
#define Telemetry_h

#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const byte address[][6] = {"BE001","BE002"};

struct Data_received //struct of data to send over to reciever
{
    byte ch1;
    byte ch2;
    byte ch3;
    byte ch4;
};

class tele_pins{
    public:
        char radioCNSPin;
        char radioCEPin;
        char ledModePin;
        char ledBattPin;
};
class Telemetry
{
    public:
        tele_pins Pins;
        RF24 radio;
        Data_received data_received;
        Telemetry(char radioCNSPin, char radioCEPin, char ledModePin, char ledBattPin);
        virtual ~Telemetry() {};
        char available();
        Data_received read();
};


#endif