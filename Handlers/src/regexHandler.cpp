#include <string>
#include <regex>
#include "../regexHandler.h"

#include <iostream>

using namespace std;

RegexHandler::RegexHandler(){
    this->IP_pattern = "^([1-2]?[0-9]{2}|[1-9])\\.([1-2]?[0-9]{2}|[1-9]|0)\\.([1-2]?[0-9]{2}|[1-9]|0)\\.([1-2]?[0-9]{2}|[1-9]|0)$";
}

RegexHandler::~RegexHandler(){}

bool RegexHandler::_init_Handler(string argv, patternType p_Type){
    this->_SetMatchARGV(argv);
    this->_SetPattern(p_Type);

    patternType ListPattTypes[] = {IP_PATTERN, PORT_PATTERN};
    typedef bool (RegexHandler::*PTRFunction)();
    PTRFunction ListFunction[] = {&RegexHandler::_regMatch_IP, &RegexHandler::_regMatch_PORT};
    for(int i(0); i < 3; i++){
        if(this->p_Type == ListPattTypes[i]){
            return (this->*ListFunction[i])();
        }
    }

}
bool RegexHandler::_init_Handler(int argv, patternType p_Type){
    this->_SetMatchARGV(argv);
    this->_SetPattern(p_Type);

    patternType ListPattTypes[] = {IP_PATTERN, PORT_PATTERN};
    typedef bool (RegexHandler::*PTRFunction)();
    PTRFunction ListFunction[] = {&RegexHandler::_regMatch_IP, &RegexHandler::_regMatch_PORT};
    for(int i(0); i < 3; i++){
        if(this->p_Type == ListPattTypes[i]){
            return (this->*ListFunction[i])();
        }
    }
}

void RegexHandler::_SetPattern(patternType type){
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

void RegexHandler::_SetMatchARGV(int argv){
    this->i_argv = argv;
}
void RegexHandler::_SetMatchARGV(string argv){
    this->s_argv = argv;
}

bool RegexHandler::_regMatch_IP(){
    cmatch regMatch;
    if(regex_search(this->s_argv.c_str(), regMatch, this->IP_pattern)){
        return true;      
    }else {return false;}
}
bool RegexHandler::_regMatch_PORT(){
    cmatch regMatch;
    if(this->i_argv > 1 && this->i_argv < 65535){return true;}
    else{return false;}
}

bool RegexHandler::match(string argv, patternType p_Type) {
    return this->_init_Handler(argv, p_Type);
}
bool RegexHandler::match(int argv, patternType p_Type) {
    return this->_init_Handler(argv, p_Type);
}