#include "../include/alu.h"
#include "alu.h"

ALU::ALU(size_t size)
:ACC(size,'0'),MQ(size,'0'),X(size,'0')
{
    
}

int ALU::real_index() const
{
    return ACC.size();
}


// ========================================================================== //

string get_reg(const deque<char> & reg)
{
    string s;
    for(auto & i : reg)
    {
        s = s + i;
    }

    return s;
}

string ALU::get_acc() const
{
    return get_reg(ACC);
}

string ALU::get_mq() const
{
    return get_reg(MQ);
}

string ALU::get_x() const
{
    return get_reg(X);
}

bool ALU::get_cf() const
{
    return CF;
}

bool ALU::get_of() const
{
    return OF;
}


