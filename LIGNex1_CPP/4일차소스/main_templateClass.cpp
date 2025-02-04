#include <iostream>

using namespace std;

template<typename T>
class MyTempl{
    T a;
    T b;
public:
    MyTempl(T a, T b):a(a), b(b){}
    T getA(){
        return a;
    }
    void setA(T a){
        this->a = a;
    }
    void print(){
        cout<<"a:"<<a<<", b:"<<b<<endl;
    }
};

int main()
{
    MyTempl<int> m1(3, 4);
    m1.print();
    m1.setA(10);
    cout<<m1.getA()<<endl;

    MyTempl<string> m2("aaa", "bbb");
    m2.print();
    m2.setA("asdf");
    cout<<m1.getA()<<endl;
    return 0;
}
