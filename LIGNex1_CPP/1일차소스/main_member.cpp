
#include "member.h"

int main()
{
    Member m;
    /*
    m.num = 10; //. ��� ���� ���� ������
    m.name = "aaa";
    */
    cout<<"��ü ���� �Է� "<<endl;
    cin>>m.num;
    cin>>m.name;

    m.printInfo();

    Member m2;
    m2.num = 20;
    m2.name = "bbb";
    m2.printInfo();

    Member *p = new Member();//new ���� �޸� �Ҵ� ������
    p->num = 30;    //-> ��� ���� ���� ������
    p->name = "ccc";
    p->printInfo();

    delete p;

    return 0;
}
