#include "binary.h"

static void check_code(const string & code)
{
    if(code.size() <= 1)
        throw runtime_error("code size error: code size must bigger than 1");

    for(auto & i : code)
    {
        if(i != '0' && i != '1')
            throw runtime_error("code error: code must binary,just (1/0)");
    }
}

string opposite_to_origin(const  string & code1)
{
    check_code(code1);

    if(code1[0] == '0') return code1;

    string code(code1);

    for(int i = 1;i < code.size();i++)
    {
        if(code[i] == '0') code[i] = '1';
        else if(code[i] == '1') code[i] = '0';
    }

    return code;
}

string opposite_to_complement(const string & code1)
{
    check_code(code1);

    if(code1[0] == '0') return code1;

    string code(code1);
    int overflow = 1;

    for(int i = code.size()-1;i>=0;i--)
    {
        int sum = 0;
        sum += overflow;

        sum += (code[i] - '0');

        code[i] = (sum % 2)+'0';

        overflow = sum / 2;
    }

    return code;
}

string origin_to_opposite(const string &code)
{
    return opposite_to_origin(code);
}

string origin_to_complement(const string &code)
{
    auto s =  origin_to_opposite(code);
    return opposite_to_complement(s);
}

string complement_to_opposite(const string &code)
{
    auto s = complement_to_origin(code);
    return origin_to_opposite(s);
}

string complement_to_origin(const string &code1)
{
    check_code(code1);

    if(code1[0] == '0') return code1;

    string code(code1);
    bool reverse = false;

    for(auto i = code.rbegin();i != code.rend() -1;i++)
    {
        if(reverse == false)
        {
            if(*i == '1') reverse = true;
        }
        else
        {
            if(*i == '1') *i = '0';
            else if(*i == '0') *i = '1';
        }
    }

    return code;
}

string negative_complement(const string &code1,bool & OF)
{
    check_code(code1);

    string basic(code1);

    string code(code1);

    for(int i = 0;i < code.size();i++)
    {
        if(code[i] == '0') code[i] = '1';
        else if(code[i] == '1') code[i] = '0';
    }

    int overflow = 1;
    for(int i = code.size()-1;i>=0;i--)
    {
        int sum = 0;
        sum += overflow;

        sum += (code[i] - '0');

        code[i] = (sum % 2)+'0';

        overflow = sum / 2;
    }

    //most negative number
    if(basic == code) OF = true;

    return code;
}