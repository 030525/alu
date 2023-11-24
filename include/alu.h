/*
*   description : basic alu template
*   start  date : 11/24/2023
*   finish date : 11/24/2023
*
*/

#ifndef _alu_h_
#define _alu_h_

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <stdexcept>
#include <deque>
#include <string>
#include "binary.h"

using namespace std;

class ALU
{
public:
    int real_index()const;
    
    virtual void valid_resize(size_t size) = 0;
    virtual int valid_index()const = 0;

    virtual void set_acc(const string & code) = 0;
    virtual void set_x(const string & code) = 0;
    virtual void set_mq(const string & code) = 0;

    string get_acc()const;
    string get_mq()const;
    string get_x()const;

    bool get_cf()const;
    bool get_of()const;

    virtual void mul() = 0;
    virtual void div() = 0;
    virtual void add() = 0;
    virtual void sub() = 0;

protected:
    ALU(size_t size);

    deque<char> ACC;
    deque<char> MQ;
    deque<char> X;

    bool CF = false;
    bool OF = false;
};


#endif