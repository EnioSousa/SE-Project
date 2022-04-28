#ifndef TRAFFIC_BUTTON
#define TRAFFIC_BUTTON

#include <Arduino.h>
#include "Protocol.h"

class TrafficButton
{
  public:
    /**
     * Constructor
     * 
     * @param id - id of object
     * @param inPort - port of connection of the button with the arduino
     */
    TrafficButton(int id, int inPort);

    /**
     * Get id of the object
     * 
     * @return Id of the object
     */
    int getId();

    /**
     * Check if the button is pressed, and if true, increases the number
     * of cars waiting
     * 
     * @return true if the button is pressed, otherwise false
     */
    bool isPressed();
  private:
    int _inPort, _id;
    bool _prevPressed;
    
    void statusUpdate(char actionStatus);
};

#endif
