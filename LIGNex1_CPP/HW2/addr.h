#ifndef ADDR_H_INCLUDED
#define ADDR_H_INCLUDED

#include "member.h"

class AddrProcess{
    Member*datas[10];
    int cnt;

public:
    AddrProcess() :cnt(0) {}
    bool addMember(Member*m)
    {
        bool flag = true;
        if(cnt>=9)
        {
            flag = false;
        }
        else
        {
            datas[cnt++] = m;
        }
        return flag;
    }
    int getByNum(int num)
    {
        for(int i = 0; i < cnt; ++i)
        {
            if(datas[i]->num == num)
            {

            }
        }
    }

};

#endif // ADDR_H_INCLUDED
