#include <string.h>
#include <iostream>
#include <cstdlib>
#include <regex>
#include "Handlers/errorHandler.h"

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

    return 0;
}