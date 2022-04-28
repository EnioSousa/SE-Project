#ifndef PEDESTRIAN_BUTTON
#define PEDESTRIAN_BUTTON

#include <Arduino.h>
#include "Protocol.h"

class PedestrianButton
{
  public:
    /**
     * Constructor
     * 
     * @param id - id of object
     * @param inPort - port of the button that is connected with the arduino
     */
    PedestrianButton(int id, int inPort);

    /**
     * Get object id
     * 
     * @return the id of the object
     */
    int getId();

    /**
     * Checks if the button is pressed
     * 
     * @return true if button pressed, otherwise false
     */
    bool isPressed();
  private:
    int _inPort, _id;
    bool _prevPressed;
    
    void statusUpdate(char actionStatus);
};

#endif
