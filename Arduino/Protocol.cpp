#include "Protocol.h"


ProtocolMessage::ProtocolMessage(char msgType, char objType, char objId[], char actionStatus)
{
  _msgType = msgType;
  _objType = objType;
  
  _objId[0] = objId[0];
  _objId[1] = objId[1];

  _actionStatus = actionStatus;
}

ProtocolMessage::ProtocolMessage()
{
  _msgType = Serial.read();
  _objType = Serial.read();

  _objId[0] = Serial.read();
  _objId[1] = Serial.read();

  _actionStatus = Serial.read();

  // read new line
  Serial.read();
}

bool ProtocolMessage::isMessageReady()
{
  return Serial.available() >= ProtocolMessage::len;
}

String* ProtocolMessage::buildMessage(char msgType, char objType, char objId[], char actionStatus)
{
  String *msg = new String("\n\n\n\n\n\n");

  msg->setCharAt(0, msgType);
  msg->setCharAt(1, objType);

  msg->setCharAt(2, objId[0]);
  msg->setCharAt(3, objId[1]);

  msg->setCharAt(4, actionStatus);

  return msg;
}

bool ProtocolMessage::sendMessage(String *msg)
{
  return Serial.write(msg->c_str()) == ProtocolMessage::len;
}

bool ProtocolMessage::sendMessage(char msgType, char objType, char objId[], char actionStatus)
{
  String *msg = ProtocolMessage::buildMessage(msgType, objType, objId, actionStatus);
  
  ProtocolMessage::sendMessage(msg);

  delete msg;
  
  return true;
}

bool ProtocolMessage::sendMessage()
{
  return ProtocolMessage::sendMessage(_msgType, _objType, _objId, _actionStatus);
}

int ProtocolMessage::getObjId()
{
  return (_objId[0] - '0') * 10 + (_objId[1] - '0');
}

char ProtocolMessage::getMsgType()
{
  return _msgType;
}

char ProtocolMessage::getObjType()
{
  return _objType;
}

char ProtocolMessage::getActionStatus()
{
  return _actionStatus;
}
