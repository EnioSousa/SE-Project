# Embuted Systems Project- Traffic light Simulator 

This Project consists of an implementation of a system capble of control the traffic lights in order to reduce queues sizes and time on queues.
For the implementation of the system we use 3 different systems: Arduino, Raspberry Pi and Android and also the integration between this 3 that corresponds to the 4 system(InterGitDoc).

# Requirements for the Project:

- The system has to have at least one crossing, with pedestrian lights in at least one street
- The cars should not wait more than 15 sec on a red light
- The system should detect congestion (more than 10 cars stopped at a light) in less than 2 sec
- Queues with 10 or more cars should not have the red light on for more than 10 sec

# Project Structure 
- The Arduino directory contains all the code necessary to run the Arduino. For this project its advised that we use the  [Arduino IDE](https://www.arduino.cc/en/software) for the compilation of the Arduino code. 
- The Pi directory contains all the logic nedeed for this simulation.
- The Application folder contains the android application

# How to run the project 

To run the project, we will need to first compile it, and then connect the computer running the [Arduino IDE](https://www.arduino.cc/en/software) with the Arduino, though a serial port. After the necessary configurations are done, i.e. choose the correct Arduino model, in our case the Arduino MEGA, we need to send the binary code to the Arduino.

After the binary is in the Arduino, we can connect it with the raspbery pi. A power source is advised if the rasperry pi doesn't have the capability to compile the source code of the arduino, otherwise, once we disconect the serial port, the Arduino will suffer a reset and the compiled code will be lost.

Once the Arduino is connected to the raspberrypi the android application should be initiaded either using a android emulator or with a USB communication with a physical device. If the emulator route is chosen, it requires a android image that can be downloaded throw the android studio IDE. It is also requiered that in the BIOS settings virtualization is enabled. Then we need to run the java code in the pi. To run the java code a ssh connection to the raspberry pi is needed. At this point we wait some seconds to garantee that all conections are established and we can start interacting with the system. 

## SSH Information
 **run:** ssh pi@raspberrypi.local
 
 **pass:** root

# Other considerations
 For more detailed information about the project development and structure, see SE_Final_Report.pdf

# Developed by:

- João Diniz
- José Sousa
- Luís Negrão
- Sara de Sá 
