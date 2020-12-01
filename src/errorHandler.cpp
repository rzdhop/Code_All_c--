#include "../headers/errorHandler.h"
#include <iostream>
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
}

ErrorHandler::~ErrorHandler(){}

void ErrorHandler::_SetErrorType(ErrorType errorType) {this->errorType = errorType;}
void ErrorHandler::_SetPrintError(){
    ErrorType ListErrTypes[] = {ERR_PORT_FORMAT, ERR_IP_FORMAT, ERR_DFLT};
    typedef void (ErrorHandler::*ListPTRFunction)(void);
    ListPTRFunction ListFunction[] = {&ErrorHandler::wrongPORTFormat, &ErrorHandler::wrongIPFormat, &ErrorHandler::defaultError};
    cout << this->errorType << endl;
    cout << "aaaaa :" << ListFunction[0]()<< endl;
    for(int i(0); i < 2 ; i++){
        if(this->errorType == ListErrTypes[i]){
            cout << ListFunction[i];
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

void ErrorHandler::printError(){
    cout << this->printedERROR;
}

void ErrorHandler::wrongPORTFormat(){

}
void ErrorHandler::wrongIPFormat(){

}
void ErrorHandler::defaultError(){

}





