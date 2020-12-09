#include <string.h>
#include <iostream>
#include <cstdlib>
#include <regex>
#include "Handlers/eventHandler.h"
#include "Handlers/regexHandler.h"
#include "Handlers/argh.h"


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
    argh::parser cmdl(argv);
    RegexHandler regex;
    EventHandler event;

    cout << (cmdl[{"-v", "--verbose"}] ? "verbose" : "NOT verbose") << endl;

    return 0;
}