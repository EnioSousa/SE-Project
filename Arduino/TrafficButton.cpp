#include "TrafficButton.h"

TrafficButton::TrafficButton(int id, int inPort)
{
  _id = id;

  _inPort = inPort;
  pinMode(inPort, INPUT);

  _count = 0;
}

int TrafficButton::getId()
{
  return _id;
}

int TrafficButton::getCount()
{
  return _count;
}

bool TrafficButton::isPressed()
{
  bool pressed = digitalRead(_inPort) == HIGH;

  if ( pressed )
  {
    _count++;
    this->statusUpdate('P');
    return true;
  }

  else
  {
    return false;
  }
}

void TrafficButton::reset()
{
  _count = 0;

  this->statusUpdate('R');
}

void TrafficButton::statusUpdate(char actionStatus)
{
  char id[] = {(char)(this->_id / 10 + '0'), (char)(this->_id % 10 + '0')};

  ProtocolMessage::sendMessage('S', 't', id, actionStatus);
}
