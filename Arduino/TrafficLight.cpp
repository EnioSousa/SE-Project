#include "TrafficLight.h"

TrafficLight::TrafficLight(int id, int g, int y, int r)
{
  _portG = g;
  pinMode(g, OUTPUT);
  _portY = y;
  pinMode(y, OUTPUT);
  _portR = r;
  pinMode(r, OUTPUT);

  _id = id;
  
  this->statusUpdate('O');
}

int TrafficLight::getId() 
{
  return _id;
}

void TrafficLight::turnOnG()
{
  digitalWrite(_portG, HIGH);
  digitalWrite(_portY, LOW);
  digitalWrite(_portR, LOW);

  this->statusUpdate('G');
}

void TrafficLight::turnOnY()
{
  digitalWrite(_portG, LOW);
  digitalWrite(_portY, HIGH);
  digitalWrite(_portR, LOW);

  this->statusUpdate('Y');
}

void TrafficLight::turnOnR()
{
  digitalWrite(_portG, LOW);
  digitalWrite(_portY, LOW);
  digitalWrite(_portR, HIGH);

  this->statusUpdate('R');
}

void TrafficLight::turnOff()
{
  digitalWrite(_portG, LOW);
  digitalWrite(_portY, LOW);
  digitalWrite(_portR, LOW);
  
  this->statusUpdate('O');
}  

void TrafficLight::testLight()
{
  this->turnOnG();
  delay(250);
  
  this->turnOnY();
  delay(250);
  
  this->turnOnR();
  delay(250);
  
  this->turnOff();
  delay(250);
}

void TrafficLight::statusUpdate(char actionStatus)
{
  char id[] = {(char)(this->_id / 10 + '0'), (char)(this->_id % 10 + '0')};
   
  ProtocolMessage::sendMessage('S', 'T', id, actionStatus);
}
