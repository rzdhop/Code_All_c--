#include <string>
#include <regex>
#include "../regexHandler.h"

using namespace std;

regexHandler::regexHandler(){
    this->IP_pattern = "^([1-2]?[0-9]{2}|[1-9])\\.([1-2]?[0-9]{2}|[1-9]|0)\\.([1-2]?[0-9]{2}|[1-9]|0)\\.([1-2]?[0-9]{2}|[1-9])$";
    this->PORT_pattern = "^([1-6]?[0-9]{4}|[0-9]{3}|[0-9]{2}|[1-9])$";
}

regexHandler::~regexHandler(){}

void regexHandler::_SetPattern(patternType type){
    this->p_Type = type;

    switch (this->p_Type)
    {
    case IP_PATTERN:
        this->pattern = this->IP_pattern;
        break;
    case PORT_PATTERN:
        this->pattern = this->PORT_pattern;
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

bool regexHandler::regMatch(string argv, patternType p_Type){
    this->_SetPattern(p_Type);
    this->_SetMatchARGV(argv);
    cmatch regMatch;
    if(regex_search(argv.c_str(), regMatch, this->PORT_pattern)){
        return true;            
    } 
    


}
bool regexHandler::regMatch(int argv, patternType p_Type){
    this->_SetPattern(p_Type);
    this->_SetMatchARGV(argv);


}
