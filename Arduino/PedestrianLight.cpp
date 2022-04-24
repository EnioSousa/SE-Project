#include "PedestrianLight.h"

PedestrianLight::PedestrianLight(int id, int portG, int portR)
{
  _id = id;
  
  _portG = portG;
  pinMode(portG, OUTPUT);
  
  _portR = portR;
  pinMode(portR, OUTPUT);
}

int PedestrianLight::getId() 
{
  return _id;
}

void PedestrianLight::turnOnG()
{
  digitalWrite(_portG, HIGH);
  digitalWrite(_portR, LOW);
  
  this->statusUpdate('G');
}

void PedestrianLight::turnOnR()
{
  digitalWrite(_portG, LOW);
  digitalWrite(_portR, HIGH);
  
  this->statusUpdate('R');
}

void PedestrianLight::turnOff()
{
  digitalWrite(_portG, LOW);
  digitalWrite(_portR, LOW);

  this->statusUpdate('O');
}

void PedestrianLight::testLight()
{
  this->turnOnG();
  delay(250);
  
  this->turnOnR();
  delay(250);

  this->turnOff();
  delay(250);
}

void PedestrianLight::statusUpdate(char actionStatus) 
{
  char id[] = {(char)(this->_id / 10 + '0'), (char)(this->_id % 10 + '0')};
   
  ProtocolMessage::sendMessage('S', 'P', id, actionStatus);
}
