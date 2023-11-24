#include "../include/cpm_alu.h"

CPM_ALU::CPM_ALU(size_t size)
:ALU(size)
{
    valid_resize(size);
}

static inline void SIZE_ERROR(size_t size)
{
    if(size <= 0 || size > 64) 
        throw std::runtime_error("alu size error:"+to_string(size));
}

void CPM_ALU::valid_resize(size_t size)
{
    SIZE_ERROR(size);
    MQ = X = ACC = deque<char>(size+2,'0');
}

int CPM_ALU::valid_index() const
{
    return ACC.size()-2;
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

static void set_reg(const string & code,deque<char> & reg,bool & OF)
{
    check_code(code);

    char sign = code[0];

    reg[0] = reg[1] = sign;

    int last = code.size() - 1;

    for(int i = reg.size()-1;i >=2;i--)
    {
        if(last > 0)
        {
            reg[i] = code[last--];
        }
        else
        {
            reg[i] = sign;
        }
    }

    if(last > 0) 
    {
        OF = true;
    }
    else OF = false;
}

void CPM_ALU::set_acc(const string &code)
{
    set_reg(code,ACC,OF);
}

void CPM_ALU::set_x(const string &code)
{
    set_reg(code,X,OF);
}

void CPM_ALU::set_mq(const string &code)
{
    check_code(code);

    char sign = code[0];

    MQ[0] = sign;
    MQ[MQ.size()-1] = '0';

    int last = code.size() - 1;

    for(int i = MQ.size()-2;i >=1;i--)
    {
        if(last > 0)
        {
            MQ[i] = code[last--];
        }
        else
        {
            OF = true;
            MQ[i] = sign;
        }
    }
}

void CPM_ALU::mul()
{
}

void CPM_ALU::div()
{
}

void CPM_ALU::sub()
{
}
