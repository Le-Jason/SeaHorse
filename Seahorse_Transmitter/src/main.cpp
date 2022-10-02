#include "Transmit.h"
#include "Recieve.h"
//Global Variables
Transmit t;
Recieve r;

//Object Setup
RF24 radio(radioCNS,radioCE); //setup radio object

Data_sent data_collection; //setup for data struct
void modeChange(){
};
//Setup Function
void setup() {
  //Pin Intialization
  t.InitializeTransmitter();
  r.InitializeReciever();
  attachInterrupt(digitalPinToInterrupt(button1),modeChange,FALLING);
  

  //Radio Intialization
  radio.begin();
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.openWritingPipe(address[0]);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  data_collection.ch1 = 127;
  data_collection.ch2 = 127;
  data_collection.ch3 = 127;
  data_collection.ch4 = 127;

  //Serial Moniter Intialization
  Serial.begin(9600);
  
  delay(5);
}

void loop() {
  int pitchVal;
  int rollVal;
  int yawVal;
  int thrustVal;
  yawVal = map(analogRead(joy2Y),0,1024,0,255);
  pitchVal = map(analogRead(joy2X),0,1024,0,255);
  thrustVal = map(analogRead(joy1X),0,1024,0,255);
  rollVal = map(analogRead(joy1Y),0,1024,0,255);
  data_collection.ch1 = pitchVal;
  data_collection.ch2 = rollVal;
  data_collection.ch3 = yawVal;
  data_collection.ch4 = thrustVal;
  radio.write(&data_collection,sizeof(Data_sent));
  Serial.println(pitchVal);
}

