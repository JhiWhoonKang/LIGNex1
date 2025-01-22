#include <iostream>

using namespace std;

// call by value: �� ����
void swap1(int a, int b)
{
    int tmp;
    tmp=a;
    a=b;
    b=tmp;
    cout<<"===swap1==="<<endl;
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;
}

// call by reference:�ּ� ��
void swap2(int *a, int *b)
{
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
    cout<<"===swap2==="<<endl;
    cout<<"a: "<<*a<<endl;
    cout<<"b: "<<*b<<endl;
}

// call by reference: ����
void swap3(int &a, int &b)
{
    int tmp;
    tmp=a;
    a=b;
    b=tmp;
    cout<<"===swap3==="<<endl;
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;
}

int main()
{
    int a, b;
    cin>>a>>b;

    swap1(a, b);
    cout<<"===main swap1==="<<endl;
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;

    swap2(&a, &b);
    cout<<"===main swap1==="<<endl;
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;

    swap3(a, b);
    cout<<"===main swap1==="<<endl;
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;

    cout<<0%4<<endl;
    cout<<1%4<<endl;
    cout<<2%4<<endl;
    cout<<3%4<<endl;
    cout<<4%4<<endl;

    return 0;
}
