#include "WarningLight.h"

WarningLight::WarningLight(int id, int port)
{
  _id = id;
  _port = port;

  pinMode(port, OUTPUT);
  
  this->statusUpdate('O');
}

int WarningLight::getId()
{
  return _id;
}

void WarningLight::turnOff()
{
  digitalWrite(_port, LOW);

  this->statusUpdate('O');
}

void WarningLight::turnOn()
{
  digitalWrite(_port, HIGH);

  this->statusUpdate('Y');
}

void WarningLight::testLight()
{
  this->turnOn();
  delay(250);

  this->turnOff();
  delay(250);
}

void WarningLight::statusUpdate(char actionStatus)
{
  char id[] = {(char)(this->_id / 10 + '0'), (char)(this->_id % 10 + '0')};
   
  ProtocolMessage::sendMessage('S', 'W', id, actionStatus);
}
