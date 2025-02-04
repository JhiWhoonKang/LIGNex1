#ifndef MEMBER_H_INCLUDED
#define MEMBER_H_INCLUDED
//vo
#include <iostream>
#include <cstring>
using namespace std;

class Member{

    int num;  //자동할당
    char name[20];
    char tel[20];

public:
    static int cnt;
    Member(){}
    Member(char* name, char* tel){
        num = ++cnt;
        strcpy(this->name, name);
        strcpy(this->tel, tel);
    }
    Member(int num, char* name, char* tel){
        this->num = num;
        strcpy(this->name, name);
        strcpy(this->tel, tel);
    }
    int getNum(){
        return num;
    }

    char* getName(){
        return name;
    }

    char* getTel(){
        return tel;
    }

    void setTel(char* tel){
        strcpy(this->tel, tel);
    }

    void setName(char* name){
        strcpy(this->name, name);
    }

    void setNum(int num){
        this->num = num;
    }
};
int Member::cnt = 0;
#endif // MEMBER_H_INCLUDED
