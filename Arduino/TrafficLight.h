#ifndef TRAFFIC_LIGHT
#define TRAFFIC_LIGHT

#include <Arduino.h>
#include "Protocol.h"

class TrafficLight
{
  public:
    /**
     * Constructor for the object
     * 
     * @param id - id of the object
     * @param portG - Port of connection of the green ligth with the arduino
     * @param portY - Port of connection of the yeallow ligth with the arduino
     * @param portR - Port of connection of the red ligth with the arduino
     */
    TrafficLight(int id, int portG, int portY, int portR);
    /**
     * Get if of object
     * 
     * @return id of object
     */
    int getId();

    /**
     * Turn the green light on, and turns off the others
     */
    void turnOnG();

    /**
     * Turn the yellow light on, and turns off the others
     */
    void turnOnY();

    /**
     * Turn the red light on, and turn off the others
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
    int _portG, _portY, _portR, _id;

    void statusUpdate(char actionStatus);
};


#endif
