#include "PedestrianButton.h"

PedestrianButton::PedestrianButton(int id, int inPort)
{
  _id = id;
  
  _inPort = inPort;
  pinMode(inPort, INPUT);
}

int PedestrianButton::getId() 
{
  return _id;
}

bool PedestrianButton::isPressed() 
{   
  bool pressed = digitalRead(_inPort) == HIGH;

  if ( pressed ) 
  {
    this->statusUpdate('P');
    return true;
  }

  else 
  {
    return false;
  }
}

void PedestrianButton::statusUpdate(char actionStatus)
{
  char id[] = {(char)(this->_id / 10 + '0'), (char)(this->_id % 10 + '0')};
   
  ProtocolMessage::sendMessage('S', 'p', id, actionStatus);
}
