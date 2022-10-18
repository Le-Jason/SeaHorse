#include "Telemetry.h"
#include "Controls_Quad.h"
#include "Navigation.h"


char MPin1 = 3; //Motor1
char MPin2 = 5; //Motor2
char MPin3 = 6; //Motor3
char MPin4 = 9; //Motor4

char radioCNSPin = 7; //nRF24L01 CNS Pin
char radioCEPin = 8; //nRF24L01 CE Pin
char ledModePin = 3; //LED Mode Pin Number
char ledBattPin = 4; //LED Battery Pin Number

//Object Setup
Telemetry uplink(radioCNSPin, radioCEPin, ledModePin, ledBattPin); //Radio Inialization
Navigation nav;
Controls_Quad controls(MPin1,MPin2,MPin3,MPin4);

Data_received data_received;
stateVector statevector;

void setup() {
  //Serial Inialization
  Serial.begin(9600);
  delay(5);
}

void loop() {
  while(uplink.available())
  {
    statevector = nav.update();
    data_received = uplink.read();
    controls.update(data_received.ch1, data_received.ch2, data_received.ch3, data_received.ch4);
  }
}