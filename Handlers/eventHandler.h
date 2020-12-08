#pragma once
#include <string>

using namespace std;

class EventHandler
{
    public:
        EventHandler();
        ~EventHandler();
        string wrongPORTFormat(int arg);
        string wrongIPFormat(string argv);
        string defaultError();
        string helpMessage();
};