/*
*   description : stimulate origin code alu
*   start  date : 11/24/2023
*   finish date :
*
*/

#ifndef _org_alu_h_
#define _org_alu_h_

#include "alu.h"

class ORG_ALU : public ALU
{
public:
    ORG_ALU(size_t size);

    void valid_resize(size_t size)override;
    int valid_index()const override;

    bool get_sf_acc()const;
    bool get_sf_mq()const;
    bool get_sf_x()const;

    void set_acc(const string & code) override;
    void set_x(const string & code) override;
    void set_mq(const string & code) override;

    void mul() override;
    void div() override;
    void add() override;
    void sub() override;

private:
    bool SF_ACC = false,SF_MQ=false,SF_X =false;
};

#endif