#ifndef MEMBER_H_INCLUDED
#define MEMBER_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Member{
public: //����������
    int num;
    string name;

    //����Լ�. ��� ���� ��� ����. ��������ó�� ���
    //��ü�̸����� ȣ��
    void printInfo(){
        cout<<"num:"<<num<<endl;
        cout<<"name:"<<name<<endl;
    }
};

#endif // MEMBER_H_INCLUDED
