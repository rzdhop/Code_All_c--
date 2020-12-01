#pragma once
#include <string>

using namespace std;

enum patternType{
    PORT_PATTERN,
    IP_PATTERN
};

class regexHandler
{
    public:
        regexHandler();
        void _SetPattern(patternType type);
        void _SetMatchARGV(int type);
        void _SetMatchARGV(string type);
        bool regMatch(string argv, patternType p_Type);
        bool regMatch(int argv, patternType p_Type);  
        ~regexHandler();
    
    private:
        string s_argv;
        int i_argv;
        patternType p_Type;
        regex IP_pattern;
        regex PORT_pattern;
        regex pattern;
    
};