#include <string.h>
#include <iostream>
#include <cstdlib>
#include <regex>
#include "Handlers/errorHandler.h"
#include "Handlers/regexHandler.h"

#ifdef __unix__
#include <sys/socket.h>
#include <sys/types.h>
#endif

#if defined(_Win32) || defined(_Win64)
#include <winsock2.h>
#endif

using namespace std;

int main(int argc, char **argv)
{
    int arg;
    regexHandler regex;
    bool stopBit(true);

    while (stopBit){
        cin >> arg;
        if (regex.match(arg, PORT_PATTERN)){
            cout << "passed"<< endl;
        }else {
            cout << "failed" << endl;
        } 
    }

    return 0;
}