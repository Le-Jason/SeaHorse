#ifndef Recieve_h
#define Recieve_h
#include <Arduino.h>

class Recieve
{
    #define ledBatt 1 //LED for Battery Pin
    #define LED_ON LED_BUILTIN
    #define ledMode 0 //LED for MODE Pin
    public:
        void InitializeReciever();
};

#endif