#include "Uplink.h"
#include "Controls.h"


Uplink uplink;
Controls controls(3,5,6,9,10);

//Object Setup
RF24 radio(radioCNS,radioCE); //Radio Object

Data_received data_received;

void setup() {
  //Pin Intialization
  uplink.InitializeUplink();

  //Radio Inialization
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

  //Serial Inialization
  Serial.begin(9600);
  
  delay(5);
}

void loop() {
  while(radio.available())
  {
    radio.read(&data_received,sizeof(Data_received));
    controls.update(data_received.ch1, data_received.ch2, data_received.ch3, data_received.ch4);
  }
}