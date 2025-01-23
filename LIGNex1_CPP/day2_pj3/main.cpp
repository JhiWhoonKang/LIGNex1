#include <iostream>

using namespace std;

class StaticTest{
public:
    static int a;
    static int cnt;
    int b;
    StaticTest():b(0){}
    void add()
    {
        ++a;
        ++b;
    }
    void print()
    {
        cout<<"A: "<<a<<", B: "<<b<<endl;
    }
};

//static 멤버는 객체 생성 전에도 사용 가능
// 프로그램 시작하자 할당되기 때문
int StaticTest::a=0;
int StaticTest::cnt=0;
int main()
{
    cout<<"static member a: "<<StaticTest::a<<endl;
    StaticTest st1;
    st1.add();
    st1.add();
    st1.print();

    StaticTest st2;
    st2.add();
    st2.add();
    st2.print();
    cout<<"static member a: "<<StaticTest::a<<endl;



    return 0;
}
