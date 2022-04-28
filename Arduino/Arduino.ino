#include "PedestrianButton.h"
#include "PedestrianLight.h"
#include "TrafficButton.h"
#include "TrafficLight.h"
#include "WarningLight.h"
#include "Protocol.h"


#define bitsPerSecond 9600


TrafficLight *tl[3];
WarningLight *wl[3];
PedestrianLight *pl[2];

TrafficButton *tb[3];
PedestrianButton *pb[2];

void setup() {
  // Setup serial
  Serial.begin(bitsPerSecond);

  // Initiate the breadBoard ligths 0
  tl[0] = new TrafficLight(0, 22, 23, 24);
  wl[0] = new WarningLight(0, 25);
  pl[0] = new PedestrianLight(0, 26, 27);

  // Initiate the breadBoard ligths 1
  tl[1] = new TrafficLight(1, 28, 29, 30);
  wl[1] = new WarningLight(1, 31);
  pl[1] = new PedestrianLight(1, 32, 33);
  
  // Initiate the breadBoard ligths 2
  wl[2] = new WarningLight(2, 34);
  tl[2] = new TrafficLight(2, 35, 36, 37);

  // Initiate the breadBoard button 0
  tb[0] = new TrafficButton(0, 13);
  pb[0] = new PedestrianButton(0, 12);
  
  // Initiate the breadBoard button 0
  tb[1] = new TrafficButton(1, 38);
  pb[1] = new PedestrianButton(1, 39);
  
  // Initiate the breadBoard button 0
  tb[2] = new TrafficButton(2, A0);
}

void loop() {  
  checkButtons();
}

void checkButtons()
{
  for( int i=0; i<3; i++ ) 
  {
    tb[i]->isPressed();
  }

  for( int i=1; i<2; i++) 
  {
    pb[i]->isPressed();
  }
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
