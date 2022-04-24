#include "PedestrianButton.h"
#include "PedestrianLight.h"
#include "TrafficButton.h"
#include "TrafficLight.h"
#include "WarningLight.h"
#include "Protocol.h"


#define bitsPerSecond 9600

PedestrianButton *pb[2];
PedestrianLight *pl[2];

TrafficButton *tb[3];
TrafficLight *tl[3];

WarningLight *wl[2];

void setup() {
  // Setup serial
  Serial.begin(bitsPerSecond);

  // Initiate the breadBoard 0
  tl[0] = new TrafficLight(0, 22, 23, 24);
  wl[0] = new WarningLight(0, 25);
  pl[0] = new PedestrianLight(0, 26, 27);
  tb[0] = new TrafficButton(0, A0);
  pb[0] = new PedestrianButton(0, A1);

}

void loop() {
  //tl[0]->testLight();
  //wl[0]->testLight();
  //pl[0]->testLight();
}

void serialEvent() {
  while ( ProtocolMessage::isMessageReady() )
  {
    ProtocolMessage *pm = new ProtocolMessage();

    int id = pm->getObjId();

    if ( pm->getMsgType() == 'C' )
    {
      if ( pm->getObjType() == 'P' )
      {
        switch (pm->getActionStatus())
        {
          case 'G':
            pl[id]->turnOnG();
            break;

          case 'R':
            pl[id]->turnOnR();
            break;

          default:
            pl[id]->turnOff();
            break;
        }
      }

      else if ( pm->getObjType() == 'T' )
      {
        switch (pm->getActionStatus())
        {
          case 'G':
            tl[id]->turnOnG();
            break;

          case 'Y':
            tl[id]->turnOnY();
            break;

          case 'R':
            tl[id]->turnOnR();
            break;

          default:
            tl[id]->turnOff();
            break;
        }
      }

      else if ( pm->getObjType() == 'W' )
      {
        switch (pm->getActionStatus())
        {
          case 'Y':
            wl[id]->turnOn();
            break;

          default:
            wl[id]->turnOff();
            break;
        }
      }
    }

    delete pm;
  }
}
