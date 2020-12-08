#include "../eventHandler.h"
#include <iostream>
#include <string>

using namespace std;

EventHandler::EventHandler(){}
EventHandler::~EventHandler(){}

string EventHandler::wrongPORTFormat(int argv){
    return "[-]Wrong Port, " + to_string(argv) + " is not a valid Port! \n\nExample of Port :\t 6878\nTips:\t\t Please choose a port between 1 and 65535\n";
}
string EventHandler::wrongIPFormat(string argv){
    return "[-]Wrong IP format, " + argv + " is not a valid IP! \n\nExample of IP :\t 192.168.1.34\nTips:\t\t Don't use the network IP or the broadcast address (<Net-Id>.0 or <Net-Id>.255)\n";
}
string EventHandler::defaultError(){
    return "[-]Please use -h or --help flag to get help ! \n Usage : ./client -r 192.168.1.34 -p 6878 -m \"This is a message sent to 192.168.1.34 on port 6878 \" \n Usage : ./client -r 192.168.1.34 -p 6878 -u ";
}
string EventHandler::helpMessage(){
    return "Client/Server program Made by Rida VERDU \n \
    \t Made in 2020 \n \
    ------------------------------------------------------------------------------------ \n \
    -r   /  --remote\t\t Enter the remote addr (default : (localhost)127.0.0.1) \n \
    -p   /  --port\t\t Enter the port to send to \n \
    -m   /  --msg\t\t Enter the message to send using quotes \n \
    -u   /  --up\t\t Send only a ping request to ckeck if the host is up \n ";
}





