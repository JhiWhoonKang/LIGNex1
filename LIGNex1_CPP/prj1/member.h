#ifndef MEMBER_H_INCLUDED
#define MEMBER_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Member{
public:
    int num;
    string name;

    //멤버 함수, 멤버 변수 사용 가능, 전역 변수처럼 사용
    //객체 이름으로 호출
    void printInfo()
    {
        cout << "num: " << num << endl;
        cout << "name: " << name << endl;
    }
};

#endif // MEMBER_H_INCLUDED
