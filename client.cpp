#include <string>
#include <iostream>
#include <cstdlib>
#include <regex>

#ifdef __unix__
#include <sys/socket.h>
#include <sys/types.h>
#endif

#if defined(_Win32) || defined(_Win64)
#include <winsock2.h>
#endif

using namespace std;

int wrongPORTFormat(int port) {
    cout << endl << "Wrong Port, " << port << " is not a valid Port! \n\nExample of Port :\t 6878\nTips:\t\t\t Please choose a port between 1 and 65535\n" << endl;
    return 0;
}

int wrongIPFormat(string argv) {
    cout << endl << "Wrong IP format, " << argv << " is not a valid IP! \n\nExample of IP :\t 192.168.1.34\nTips:\t\t\t Don't use the network IP or the broadcast address (<Net-Id>.0 or <Net-Id>.255)\n" << endl;
    return 0;
}

int errorMessage() {
    cout << endl << "Please use -h or --help flag to get help !" << endl;
    cout << "Usage : ./client -r 192.168.1.34 -p 6878 -m \"This is a message sent to 192.168.1.34 on port 6878 \"" << endl;
    cout << "Usage : ./client -r 192.168.1.34 -p 6878 -u " << endl << endl;
    return 0;
}

int ping (char RHOST) {
    int errorStatus(0);
    return errorStatus;
}

int main(int argc, char **argv)
{
    int variable;
    fonction(variable, HTTP_ERR);
    regex addrPattern("^([1-2]?[0-9]{2}|[1-9])\\.([1-2]?[0-9]{2}|[1-9]|0)\\.([1-2]?[0-9]{2}|[1-9]|0)\\.([1-2]?[0-9]{2}|[1-9])$");
    regex portPattern("^([1-6]?[0-9]{4}|[0-9]{3}|[0-9]{2}|[1-9])$");
    int hostID(0), skipArg(0);
    cmatch regMatch;
    cmatch regMatch2;
    string remoteAddr("127.0.0.1");
    int remotePort(0);
    string message("");
    string helpMessage = \
    "Client/Server program Made by Rida VERDU \n \
    \t Made in 2020 \n \
    ------------------------------------------------------------------------------------ \n \
    -r   /  --remote\t\t Enter the remote addr (default : (localhost)127.0.0.1) \n \
    -p   /  --port\t\t Enter the port to send to \n \
    -m   /  --msg\t\t Enter the message to send using quotes \n \
    -u   /  --up\t\t Send only a ping request to ckeck if the host is up \n ";
    if(argc < 2 || argc > 7) {errorMessage(); return 1;}
    else {
        if(!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")){
            cout << endl << helpMessage << endl;
            return 0;        
        }
        if(!strcmp(argv[1], "-r") || !strcmp(argv[1], "--remote")){
            if(argc <= 3) {errorMessage(); return 1;}
            else if(!strcmp(argv[2], "-p") || !strcmp(argv[2], "--port")) {
                if(regex_search(argv[3], regMatch2, portPattern)){
                    remotePort = stoi(regMatch2.str(0).c_str());                
                } 
                else {wrongPORTFormat(atoi(argv[3])); return 1;}
                skipArg = 1;
            }
            else if(regex_search(argv[2], regMatch, addrPattern)) {
                hostID = stoi(regMatch.str(regMatch.size()-1).c_str());
                if(hostID != 255) {
                    remoteAddr = regMatch.str(0);
                }
                else{wrongIPFormat(argv[2]); return 1;}
            }
            if((!strcmp(argv[3], "-p") || !strcmp(argv[3], "--port") && !skipArg)){
                if(argc < 5) {errorMessage(); return 1;}
                if(regex_search(argv[2], regMatch2, addrPattern)){
                    hostID = stoi(regMatch.str(regMatch.size()-1).c_str());
                    if(hostID != 255) {
                    remoteAddr = regMatch.str(0);
                    }            
                } 
                else {wrongPORTFormat(atoi(argv[3])); return 1;}
            }
            if(regex_search(argv[4], regMatch2, portPattern)){
                    remotePort = stoi(regMatch2.str(0).c_str());                
                } 
            else {wrongPORTFormat(atoi(argv[4])); return 1;}
        }
        else if(!(!strcmp(argv[3], "-p") || !strcmp(argv[3], "--port") && !skipArg)) {errorMessage(); return 1;}
        if(!(remotePort < 1) && !(remotePort > 65535)) {wrongPORTFormat(remotePort); return 1;}
        // ERROR HERE TO FIX

        cout << endl << "[+] Remote addr set to : " << remoteAddr << endl;
        cout << "[+] Remote Port set to : " << remotePort << endl << endl;

        if(skipArg) {
            if(!strcmp(argv[4], "-u") || !strcmp(argv[4], "--up")){
                cout << "Pinged ! \n\n";
            } else if(!strcmp(argv[4], "-m") || !strcmp(argv[4], "--msg")) {
                cout << "message is : " << argv[5] << "\n\n";
            } else {errorMessage(); return 1;}
        }
        else if(!skipArg) {
            if(!strcmp(argv[5], "-u") || !strcmp(argv[5], "--up")){
                cout << "Pinged ! \n\n";
            } else if(!strcmp(argv[5], "-m") || !strcmp(argv[5], "--msg")) {
                cout << "message is : " << argv[6] << "\n\n";
            } else {errorMessage(); return 1;}
        }
    }
    return 0;
}