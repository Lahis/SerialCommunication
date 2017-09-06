#include "mbed.h"
#include "SerialCommunication.h"

DigitalOut myled(LED1);
SerialCommunication  *serialCommunication = new SerialCommunication(p9,p10,115200);

int main() {
    int commandReceived = 0;
    
    while(1){
        commandReceived = serialCommunication->ReceiveCommand();
        if (commandReceived == 1){ // informação correta recebida
            myled = 1;
            break;    
        }
    
    }
    
}
