#pragma once
#include <string>
#include <regex>

using namespace std;

enum patternType{
    PORT_PATTERN,
    IP_PATTERN
};

class regexHandler
{
    public:
        regexHandler();
        bool _init_Handler(string argv, patternType p_Type);
        bool _init_Handler(int argv, patternType p_Type);
        void _SetPattern(patternType type);
        void _SetMatchARGV(int type);
        void _SetMatchARGV(string type);
        bool _regMatch_IP();
        bool _regMatch_PORT();  
        bool match(int argv, patternType p_Type);
        bool match(string argv, patternType p_Type);
        ~regexHandler();
    
    private:
        string s_argv;
        int i_argv;
        patternType p_Type;
        regex IP_pattern;
        regex PORT_pattern;
        regex pattern;
    
};