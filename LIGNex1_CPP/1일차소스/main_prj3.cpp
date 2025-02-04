#include <iostream>

using namespace std;

//call by value: 값 복사
void swap1(int a, int b){//a=10, b=20;
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
    cout<<"a:"<<a<<endl;
    cout<<"b:"<<b<<endl;
}

//call by value: 주소 값 복사
void swap2(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    cout<<"*a:"<<*a<<endl;
    cout<<"*b:"<<*b<<endl;
}

//call by reference: 참조변수를 파라메터로 지정
void swap3(int &a, int &b){//main a,b의 별칭
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
    cout<<"swap1 결과 : a:"<<a<<", b:"<<b<<endl;

    a=10;
    b=20;

    swap2(&a, &b);
    cout<<"swap2 결과 : a:"<<a<<", b:"<<b<<endl;

    a=10;
    b=20;

    swap3(a, b);
    cout<<"swap3 결과 : a:"<<a<<", b:"<<b<<endl;

    return 0;
}
