#include "member.h"

int main()
{
    Member m;
    cin>>m.num>>m.name;
    //m.num = 2000; // .: ��� ���� ���� ������
    //m.name = "Kang";

    m.printInfo();

    Member m2;
    m2.num = 26;
    m2.name = "jhiwhoon";

    m2.printInfo();

    Member *p=new Member(); //new ������ => Heap�� �Ҵ�, ũ: Member Class ũ��
    //p->num=21; // -> : ��� ���� ���� ������
    //p->name="kangjhiwhoon";
    cin>>p->num>>p->name;
    p->printInfo();


    delete p;

    cout<<("int * size: %d", sizeof(int*))<<endl;

    return 0;
}
