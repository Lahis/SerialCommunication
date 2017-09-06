
#ifndef SERIAL_COMMUNICATION_H
#define SERIAL_COMMUNICATION_H

#include "mbed.h"
#include <string.h>
#include <string>
#include <iostream>


#define DELAY_COMMAND 0.5
#define DEBUG_SERIAL_COMUNNICATION 1

using namespace std;


class SerialCommunication{
    
    public:
            SerialCommunication(PinName tx, PinName rx, int baudRate);
            
            int  ReceiveCommand();
            void SendCommand(string commandSended);
        
        
    private:
            Serial *serial;
        
            DigitalOut tx;
            DigitalOut rx;
            DigitalOut *debug;
            
            int baudRate;           
            int messageLength;
            
};

#endif



