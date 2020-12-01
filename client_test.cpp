#include <string.h>
#include <iostream>
#include <cstdlib>
#include <regex>
#include "headers/errorHandler.h"

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
    ErrorHandler error("198.872.89.1", ERR_IP_FORMAT);
    error.printError();
    getchar();

    return 0;
}