#include "member.h"

int main()
{
    Member m;
    cin>>m.num>>m.name;
    //m.num = 2000; // .: 멤버 직접 접근 연산자
    //m.name = "Kang";

    m.printInfo();

    Member m2;
    m2.num = 26;
    m2.name = "jhiwhoon";

    m2.printInfo();

    Member *p=new Member(); //new 연산자 => Heap에 할당, 크: Member Class 크기
    //p->num=21; // -> : 멤버 간접 접근 연산자
    //p->name="kangjhiwhoon";
    cin>>p->num>>p->name;
    p->printInfo();


    delete p;

    cout<<("int * size: %d", sizeof(int*))<<endl;

    return 0;
}
