#include "SerialCommunication.h"

SerialCommunication::SerialCommunication(PinName tx, PinName rx, int baudRate): tx(tx), rx(rx){
        serial = new Serial(tx, rx); // tx, rx
        serial->baud(baudRate);
        messageLength = 4; // tam palavra + 1 ('\n')
        
        debug = new DigitalOut(LED1); // debug send info
}


int SerialCommunication::ReceiveCommand(){ // RECEIVE  INFO
    
    char commandReceived[messageLength];    
        
    
    if(serial->readable()){   
        serial->gets(commandReceived,messageLength);           
                
        if (strcmp(commandReceived, "s0b") == 0){ //s0b : ex de palavra q desejo receber"
            return 1;               
        }
    }   
    return 0;
}


void SerialCommunication::SendCommand(string commandSended){ // SEND INFO
    
    // SEND INFO
    //while(1){
            serial->printf("%s",commandSended);         
            debug->write(1);
            wait(DELAY_COMMAND);
            debug->write(0);
            wait(DELAY_COMMAND);  
    //}
}