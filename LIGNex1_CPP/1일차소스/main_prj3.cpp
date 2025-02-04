#include <iostream>

using namespace std;

//call by value: �� ����
void swap1(int a, int b){//a=10, b=20;
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
    cout<<"a:"<<a<<endl;
    cout<<"b:"<<b<<endl;
}

//call by value: �ּ� �� ����
void swap2(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    cout<<"*a:"<<*a<<endl;
    cout<<"*b:"<<*b<<endl;
}

//call by reference: ���������� �Ķ���ͷ� ����
void swap3(int &a, int &b){//main a,b�� ��Ī
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
    cout<<"a:"<<a<<endl;
    cout<<"b:"<<b<<endl;
}
int main()
{
    int a=10, b=20;
    swap1(a, b);
    cout<<"swap1 ��� : a:"<<a<<", b:"<<b<<endl;

    a=10;
    b=20;

    swap2(&a, &b);
    cout<<"swap2 ��� : a:"<<a<<", b:"<<b<<endl;

    a=10;
    b=20;

    swap3(a, b);
    cout<<"swap3 ��� : a:"<<a<<", b:"<<b<<endl;

    return 0;
}
