#include <string>
#include <regex>
#include "../regexHandler.h"

#include <iostream>

using namespace std;

regexHandler::regexHandler(){
    this->IP_pattern = "^([1-2]?[0-9]{2}|[1-9])\\.([1-2]?[0-9]{2}|[1-9]|0)\\.([1-2]?[0-9]{2}|[1-9]|0)\\.([1-2]?[0-9]{2}|[1-9]|0)$";
}

regexHandler::~regexHandler(){}

bool regexHandler::_init_Handler(string argv, patternType p_Type){
    this->_SetMatchARGV(argv);
    this->_SetPattern(p_Type);

    patternType ListPattTypes[] = {IP_PATTERN, PORT_PATTERN};
    typedef bool (regexHandler::*PTRFunction)();
    PTRFunction ListFunction[] = {&regexHandler::_regMatch_IP, &regexHandler::_regMatch_PORT};
    for(int i(0); i < 3; i++){
        if(this->p_Type == ListPattTypes[i]){
            return (this->*ListFunction[i])();
        }
    }

}
bool regexHandler::_init_Handler(int argv, patternType p_Type){
    this->_SetMatchARGV(argv);
    this->_SetPattern(p_Type);

    patternType ListPattTypes[] = {IP_PATTERN, PORT_PATTERN};
    typedef bool (regexHandler::*PTRFunction)();
    PTRFunction ListFunction[] = {&regexHandler::_regMatch_IP, &regexHandler::_regMatch_PORT};
    for(int i(0); i < 3; i++){
        if(this->p_Type == ListPattTypes[i]){
            return (this->*ListFunction[i])();
        }
    }
}

void regexHandler::_SetPattern(patternType type){
    this->p_Type = type;

    switch (this->p_Type)
    {
    case IP_PATTERN:
        this->pattern = this->IP_pattern;
        break;
    default:
        break;
    }
}

void regexHandler::_SetMatchARGV(int argv){
    this->i_argv = argv;
}
void regexHandler::_SetMatchARGV(string argv){
    this->s_argv = argv;
}

bool regexHandler::_regMatch_IP(){
    cmatch regMatch;
    if(regex_search(this->s_argv.c_str(), regMatch, this->IP_pattern)){
        return true;      
    }else {return false;}
}
bool regexHandler::_regMatch_PORT(){
    cmatch regMatch;
    if(this->i_argv > 1 && this->i_argv < 65535){return true;}
    else{return false;}
}

bool regexHandler::match(string argv, patternType p_Type) {
    return this->_init_Handler(argv, p_Type);
}
bool regexHandler::match(int argv, patternType p_Type) {
    return this->_init_Handler(argv, p_Type);
}