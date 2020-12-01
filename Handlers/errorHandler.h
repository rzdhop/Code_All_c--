#pragma once
#include <string>

using namespace std;

enum ErrorType {
        ERR_PORT_FORMAT,
        ERR_IP_FORMAT,
        ERR_DFLT
};

class ErrorHandler
{
    public:
        ErrorHandler(string argv, ErrorType errorType);
        ErrorHandler(int argv, ErrorType errorType);
        ~ErrorHandler();
        void _SetErrorType(ErrorType errorType);
        void _SetPrintError();
        void _SetARGVError(string argv);
        void _SetARGVError(int argv); 
        void printError();
        void wrongPORTFormat();
        void wrongIPFormat();
        void defaultError();
       
    private:
        ErrorType errorType;
        string procError; 
        string STRprocARGV;
        int INTprocARGV;
        string printedERROR;
};