#ifndef PEDESTRIAN_LIGHT
#define PEDESTRIAN_LIGHT

#include <Arduino.h>
#include "Protocol.h"

class PedestrianLight
{
  public:
    /**
     * Constructor
     * 
     * @param id - id of object
     * @param portG - port of connection of the green light with the arduino
     * @param portR - port of connection of the red light with the arduino
     */
    PedestrianLight(int id, int portG, int portR);
    
    /**
     * Get id of the object
     * 
     * @return Id of the object
     */
    int getId();
    
    /**
     * Turn the green light on, and turns off the others
     */
    void turnOnG();
    
    /**
     * Turn the red light on, and turns off the others
     */
    void turnOnR();
    
    /**
     * Turns off every light
     */
    void turnOff();
    
    /**
     * Tests lights, bye turning on and off in a predetermined order
     */
    void testLight();
  private:
    void statusUpdate(char actionStatus);
    int _portG, _portR, _id;
};

#endif 
