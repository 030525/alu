#include "../include/org_alu.h"

namespace py = pybind11;

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

string ORG_ALU::get_acc_sign() const
{
    return to_string(int(get_sf_acc()))+get_acc();
}

string ORG_ALU::get_mq_sign() const
{
    return to_string(int(get_sf_mq()))+get_mq();
}

string ORG_ALU::get_x_sign() const
{
    return to_string(int(get_sf_x()))+get_x();
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
            reg[i] = '0';
        }
    }

    if(last > 0) 
    {
        OF = true;
    }
    else OF = false;
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
    string s;

    bool to_cpm = false;

    //pos + neg
    //neg + pos
    if(SF_ACC ^ SF_X)
    {
        to_cpm = true;
        if(SF_ACC == true) 
        {
            // get complement ,overflow sign
            set_acc(origin_to_complement(get_acc_sign()));
        }
        else if(SF_X == true) 
        {
            //record x,use complement to do add
            s = get_x_sign();

            // get complement ,overflow sign
            set_x(origin_to_complement(s));
        }
    }

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

    if(to_cpm)
    {
        SF_ACC = ((1+overflow) % 2) ;
        set_acc(complement_to_origin(get_acc_sign()));
    }
    else
    {
        OF = overflow;
    }

    if(SF_X && to_cpm)
    {
        set_x(s);
    }

    
}

void ORG_ALU::sub()
{
}




PYBIND11_MODULE(ORG, m) {
    m.doc() = "stimulate origin alu";
    py::class_<ORG_ALU>(m, "ORG")
        .def(py::init<size_t>())
        .def("resize", &ORG_ALU::valid_resize)
        .def("index",&ORG_ALU::valid_index)

        .def("acc",&ORG_ALU::get_acc_sign)
        .def("mq",&ORG_ALU::get_mq_sign)
        .def("x",&ORG_ALU::get_x_sign)

        .def("cf",&ORG_ALU::get_cf)
        .def("of",&ORG_ALU::get_of)

        .def("sf_acc",&ORG_ALU::get_sf_acc)
        .def("sf_mq",&ORG_ALU::get_sf_mq)
        .def("sf_x",&ORG_ALU::get_sf_x)

        .def("acc",&ORG_ALU::set_acc)
        .def("mq",&ORG_ALU::set_mq)
        .def("x",&ORG_ALU::set_x)
        .def("add",&ORG_ALU::add)
        .def("__repr__", [](const ORG_ALU &obj) {
            string s;
            
            string acc = obj.get_acc_sign();
            string mq = obj.get_mq_sign();
            string x = obj.get_x_sign();

            s = "ACC:"+obj.get_acc_sign().insert(1, 1,',')+" , "+to_string(origin_to_value(acc))+"\n"+
                " MQ:"+obj.get_mq_sign().insert(1, 1,',')+" , "+to_string(origin_to_value(mq))+"\n"+
                "  X:"+obj.get_x_sign().insert(1, 1,',')+" , "+to_string(origin_to_value(x))+"\n"+
                " OF:"+to_string((obj.get_of()));

            return s;
        });
}