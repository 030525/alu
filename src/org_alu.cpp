#include "../include/org_alu.h"
#include "org_alu.h"


ORG_ALU::ORG_ALU(size_t size)
:ALU(size)
{
}

static inline void SIZE_ERROR(size_t size)
{
    if(size <= 0 || size > 64) 
        throw std::runtime_error("alu size error:"+to_string(size));
}

void ORG_ALU::valid_resize(size_t size)
{
    SIZE_ERROR(size);
    MQ = X = ACC = deque<char>(size,'0');
}

int ORG_ALU::valid_index() const
{
    return ACC.size();
}

bool ORG_ALU::get_sf_acc() const
{
    return SF_ACC;
}

bool ORG_ALU::get_sf_mq() const
{
    return SF_MQ;
}

bool ORG_ALU::get_sf_x() const
{
    return SF_X;
}

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

static void set_reg(const string & code,deque<char> & reg,bool & OF,bool & SF)
{
    check_code(code);

    SF = bool(code[0]-'0');

    int last = code.size() - 1;

    for(int i = reg.size()-1;i >=0;i--)
    {
        if(last > 0)
        {
            reg[i] = code[last--];
        }
        else
        {
            OF = true;
            reg[i] = '0';
        }
    }
}

void ORG_ALU::set_acc(const string &code)
{
    set_reg(code,ACC,OF,SF_ACC);
}

void ORG_ALU::set_x(const string &code)
{
    set_reg(code,X,OF,SF_X);
}

void ORG_ALU::set_mq(const string &code)
{
    set_reg(code,MQ,OF,SF_MQ);
}

void ORG_ALU::mul()
{

}

void ORG_ALU::div()
{
}

void ORG_ALU::add()
{
    int sum = 0;
    int overflow = 0;

    for(int i = ACC.size()-1;i>=0;i--)
    {
        sum = 0;
        sum += overflow;

        sum += (ACC[i] - '0');
        sum += (X[i] - '0');

        ACC[i] = (sum % 2)+'0';

        overflow = sum / 2;
    }

    if(overflow) 
    {
        OF = true;
    }
}

void ORG_ALU::sub()
{
}
