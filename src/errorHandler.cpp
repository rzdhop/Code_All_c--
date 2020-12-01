#include "../headers/errorHandler.h"
#include <iostream>
#include <string>

using namespace std;

ErrorHandler::ErrorHandler(string argv, ErrorType errorType) {
    this->_SetErrorType(errorType);
    this->_SetARGVError(argv);
    this->_SetPrintError();
}
//surcharge
ErrorHandler::ErrorHandler(int argv, ErrorType errorType) {
    this->_SetErrorType(errorType);
    this->_SetARGVError(argv);
    this->_SetPrintError();
}

ErrorHandler::~ErrorHandler(){}

void ErrorHandler::_SetErrorType(ErrorType errorType) {this->errorType = errorType;}
void ErrorHandler::_SetPrintError(){
    ErrorType ListErrTypes[] = {ERR_PORT_FORMAT, ERR_IP_FORMAT, ERR_DFLT};
    typedef void (ErrorHandler::*PTRFunction)();
    PTRFunction ListFunction[] = {&ErrorHandler::wrongPORTFormat, &ErrorHandler::wrongIPFormat, &ErrorHandler::defaultError};
    for(int i(0); i < 3; i++){
        if(this->errorType == ListErrTypes[i]){
            (this->*ListFunction[i])();
            break;
        }
    }
}
void ErrorHandler::_SetARGVError(string argv){
    this->STRprocARGV = argv;
}
//surcharge
void ErrorHandler::_SetARGVError(int argv){
    this->INTprocARGV = argv;
}

void ErrorHandler::wrongPORTFormat(){
     this->printedERROR = "Wrong Port, " + to_string(this->INTprocARGV) + " is not a valid Port! \n\nExample of Port :\t 6878\nTips:\t\t Please choose a port between 1 and 65535\n";
}
void ErrorHandler::wrongIPFormat(){
    this->printedERROR = "Wrong IP format, " + this->STRprocARGV + " is not a valid IP! \n\nExample of IP :\t 192.168.1.34\nTips:\t\t Don't use the network IP or the broadcast address (<Net-Id>.0 or <Net-Id>.255)\n";
}
void ErrorHandler::defaultError(){
    this->printedERROR = "Please use -h or --help flag to get help ! \n Usage : ./client -r 192.168.1.34 -p 6878 -m \"This is a message sent to 192.168.1.34 on port 6878 \" \n Usage : ./client -r 192.168.1.34 -p 6878 -u ";
}

void ErrorHandler::printError(){
    cout << this->printedERROR;
}





