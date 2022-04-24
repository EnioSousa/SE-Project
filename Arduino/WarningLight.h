#ifndef WARNINGLIGHT
#define WARNINGLIGHT

#include <Arduino.h>
#include "Protocol.h"

class WarningLight
{
  public:
    /**
     * Constructor
     * 
     * @param id - id of the object
     * @param port - port of connection from the warining light with the arduino
     */
     WarningLight(int id, int port);

    /**
     * Get the current object id
     * 
     * @return the current object id
     */
    int getId();

    /**
     * Turns the light on
     */
    void turnOn();

    /**
     * Turns the light off
     */
    void turnOff();

    /**
     * Test if the light is working, by blinking it
     */
    void testLight();
  private:
    int _id, _port;
    void statusUpdate(char actionStatus);
};

#endif
