
#include "member.h"

int main()
{
    Member m;
    /*
    m.num = 10; //. 멤버 직접 접근 연산자
    m.name = "aaa";
    */
    cout<<"객체 정보 입력 "<<endl;
    cin>>m.num;
    cin>>m.name;

    m.printInfo();

    Member m2;
    m2.num = 20;
    m2.name = "bbb";
    m2.printInfo();

    Member *p = new Member();//new 힙에 메모리 할당 연산자
    p->num = 30;    //-> 멤버 간접 접근 연산자
    p->name = "ccc";
    p->printInfo();

    delete p;

    return 0;
}
