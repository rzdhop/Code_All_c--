#include <string>
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

int main(void)
{
    ErrorHandler error = new ErrorHandler("SALUT", ERR_DFLT);
}