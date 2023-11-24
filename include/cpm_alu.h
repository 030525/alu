/*
*   description : stimulate complement code alu
*   start  date : 11/24/2023
*   finish date :
*
*/

#ifndef _cpm_alu_h_
#define _cpm_alu_h_

#include "alu.h"

class CPM_ALU : public ALU
{
public:
    CPM_ALU(size_t size);

    void valid_resize(size_t size)override;
    int valid_index()const override;


    void set_acc(const string & code) override;
    void set_x(const string & code) override;
    void set_mq(const string & code) override;

    void mul() override;
    void div() override;
    void add() override;
    void sub() override;
};

#endif