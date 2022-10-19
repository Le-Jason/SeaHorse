#include "Telemetry.h"


Telemetry::Telemetry(char radioCNSPin, char radioCEPin, char ledModePin, char ledBattPin)
{
    //Radio Inialization
    RF24 radio(radioCNSPin,radioCEPin);
    radio.begin();
    radio.setAutoAck(false);
    radio.setDataRate(RF24_250KBPS);
    radio.openReadingPipe(1,address[0]);
    radio.setPALevel(RF24_PA_MIN);
    radio.startListening();
    data_received.ch1 = 127;
    data_received.ch2 = 127;
    data_received.ch3 = 127;
    data_received.ch4 = 127;
    //Pin Intialization
    pinMode(ledModePin,OUTPUT);
    pinMode(ledBattPin,OUTPUT);
}

char Telemetry::available()
{
    if (radio.available() == 1){
        return 1;
    }else{
        return 0;
    }

}

Data_received Telemetry::read()
{
    radio.read(&data_received,sizeof(Data_received));
    return data_received;
}

void Telemetry::write(Data_sent data_sent)
{
    radio.write(&data_sent,sizeof(Data_sent));
}