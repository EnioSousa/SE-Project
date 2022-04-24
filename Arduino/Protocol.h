#ifndef PROTOCOL
#define PROTOCOL

#include <Arduino.h>

/**
   TODO: Improve the get function. Some of them read int, and we are doing incorrectly
   TODO: Improve the way we read the messages
*/

class ProtocolMessage
{
  public:
    static const int len = 6;

    ProtocolMessage(char msgType, char objType, char objId[], char actionStatus);
    ProtocolMessage();

    static bool isMessageReady();
    
    static String* buildMessage(char msgType, char objType, char objId[], char actionStatus);

    static bool sendMessage(String *msg);
    static bool sendMessage(char msgType, char objType, char objId[], char actionStatus);
    bool sendMessage();
    
    int getObjId();
    char getMsgType();
    char getObjType();
    char getActionStatus();

  private:
    char _objId[2];
    char _msgType, _objType, _actionStatus;
};

#endif
