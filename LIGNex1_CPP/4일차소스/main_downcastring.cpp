#include <iostream>
#include <typeinfo>

using namespace std;

class Parent{
public:
    int a;

    Parent():a(0){}
    Parent(int a):a(a){}

    virtual void printData(){
        cout<<"a:"<<a<<endl;
    }
};

class Child:public Parent{
public:
    int b;
    Child():b(0){}
    Child(int a, int b):Parent(a), b(b){}

    virtual void printData(){
        Parent::printData();
        cout<<"b:"<<b<<endl;
    }
};

int main()
{
    Parent *p = new Parent(3);
    Child *c = new Child(1,2);
    Parent *pc = c; //업캐스팅
    cout << typeid(p).name() << endl;
    cout << typeid(c).name() << endl;
    cout << typeid(pc).name() << endl;
    cout << typeid(*p).name() << endl;
    cout << typeid(*c).name() << endl;
    cout << typeid(*pc).name() << endl;
    cout << (typeid(*pc) == typeid(Child)) << endl;
    cout << (typeid(*pc) == typeid(Parent)) << endl;
    if(typeid(*pc) == typeid(Child)){
        ((Child*)pc)->b = 13;
    }
    pc->printData();
    return 0;
}
