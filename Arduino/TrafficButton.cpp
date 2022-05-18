#include "TrafficButton.h"

TrafficButton::TrafficButton(int id, int inPort)
{
  _id = id;

  _inPort = inPort;
  pinMode(inPort, INPUT);

  _prevPressed = false;
}

int TrafficButton::getId()
{
  return _id;
}

bool TrafficButton::isPressed()
{
  bool pressed = digitalRead(_inPort) == HIGH;
  
  if ( pressed && !_prevPressed )
  {
    _prevPressed = true;
    this->statusUpdate('P');
    return true;
  }

  else if ( !pressed )
  {
    _prevPressed = false;
    return false;
  }
  
  else
  { 
    return false;
  }
}

void TrafficButton::statusUpdate(char actionStatus)
{
  char id[] = {(char)(this->_id / 10 + '0'), (char)(this->_id % 10 + '0')};

  ProtocolMessage::sendMessage('S', 't', id, actionStatus);
}
