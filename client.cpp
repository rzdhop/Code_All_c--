#include <string>
#include <iostream>
#include <cstdlib>
#include "Handlers/regexHandler.h"
#include "Handlers/eventHandler.h"

#ifdef __unix__
#include <sys/socket.h>
#include <sys/types.h>
#endif

#if defined(_Win32) || defined(_Win64)
#include <winsock2.h>
#endif

using namespace std;

int ping (char RHOST) {
    int errorStatus(0);
    return errorStatus;
}

int main(int argc, char **argv)
{
    EventHandler event;
    RegexHandler regex;
    int skipArg(0), remotePort(0);
    string remoteAddr("127.0.0.1");

    if(argc < 2 || argc > 7) {cout << event.defaultError(); return 1;}
    else {
        if(!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")){
            cout << endl << event.helpMessage() << endl;
            return 0;        
        }
        if(!strcmp(argv[1], "-r") || !strcmp(argv[1], "--remote")){
            if(argc <= 3) {cout << event.defaultError(); return 1;}
            else if(!strcmp(argv[2], "-p") || !strcmp(argv[2], "--port")) {
                if(regex.match(argv[3], PORT_PATTERN)){
                    remotePort = stoi(argv[3]);                
                } 
                else {cout << event.wrongPORTFormat(stoi(argv[3])); return 1;}
                skipArg = 1;
            }
            else if(regex.match(argv[2], IP_PATTERN)) {
                remoteAddr = argv[2];
                }
                else{cout << event.wrongIPFormat(argv[2]); return 1;}
            }
            if((!strcmp(argv[3], "-p") || !strcmp(argv[3], "--port") && !skipArg)){
                if(argc < 5) {cout << event.defaultError(); return 1;}
                if(regex.match(argv[2], IP_PATTERN)){
                    remoteAddr = argv[2];
                } 
                else {cout << event.wrongIPFormat(argv[3]); return 1;}
            }
            if(regex.match(argv[4], PORT_PATTERN)){
                remotePort = stoi(argv[4]);                
            } 
            else {cout << event.wrongPORTFormat(atoi(argv[4])); return 1;}
    }
    if(!(!strcmp(argv[3], "-p") || !strcmp(argv[3], "--port") && !skipArg)) {cout << event.defaultError(); return 1;}
    cout << endl << "[+] Remote addr set to : " << remoteAddr << endl;
    cout << "[+] Remote Port set to : " << remotePort << endl << endl;
    
    if(skipArg) {
        if(!strcmp(argv[4], "-u") || !strcmp(argv[4], "--up")){
            cout << "Pinged ! \n\n";
        } else if(!strcmp(argv[4], "-m") || !strcmp(argv[4], "--msg")) {
            cout << "message is : " << argv[5] << "\n\n";
        } else {cout << event.defaultError(); return 1;}
    }
    else if(!skipArg) {
        if(!strcmp(argv[5], "-u") || !strcmp(argv[5], "--up")){
            cout << "Pinged ! \n\n";
        } else if(!strcmp(argv[5], "-m") || !strcmp(argv[5], "--msg")) {
            cout << "message is : " << argv[6] << "\n\n";
        } else {cout << event.defaultError(); return 1;}
    }
     return 0;   
}
    
