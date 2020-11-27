#include "../headers/errorHandler.h"
using namespace std;

ErrorHandler::ErrorHandler(string argv, ErrorType errorType) {
    this->_SetErrorType(errorType);
    this->_SetARGVError(argv);
}
//surcharge
ErrorHandler::ErrorHandler(int argv, ErrorType errorType) {
    this->_SetErrorType(errorType);
    this->_SetARGVError(argv);
}

ErrorHandler::~ErrorHandler(){this->printError();}

void ErrorHandler::_SetErrorType(ErrorType errorType) {this->errorType = errorType;}
void ErrorHandler::_SetPrintError(){
    ErrorType ListErrTypes[] = {ERR_PORT_FORMAT, ERR_IP_FORMAT, ERR_DFLT};
    typedef void (ErrorHandler::*ListPTRFunction)(void);
    ListPTRFunction ListFunction[] = {ErrorHandler::wrongPORTFormat, ErrorHandler::wrongIPFormat, ErrorHandler::defaultError};
}

void ErrorHandler::_SetARGVError(string argv){
    this->STRprocARGV = argv;
}
//surcharge
void ErrorHandler::_SetARGVError(int argv){
    this->INTprocARGV = argv;
}




