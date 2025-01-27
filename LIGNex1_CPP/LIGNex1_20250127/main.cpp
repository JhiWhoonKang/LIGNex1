#include <iostream>
#include <typeinfo>

using namespace std;

class Parent{
public:
    int a;
    Parent():a(0){}
    Parent(int a):a(0){}
    virtual void printData(){
        cout<<"a: "<<a<<endl;
    }
};

class Child:public Parent{
public:
    int b;
    Child():b(0){}
    Child(int a, int b):Parent(a), b(b){}

    virtual void printData(){
        Parent::printData();
        cout<<"b: "<<b<<endl;
    }

};

int main()
{
    Parent *p=new Parent(3);
    Child *c=new Child(1, 2);
    Parent *pc=c; //up-casting
    cout<<typeid(p).name()<<endl;
    cout<<typeid(c).name()<<endl;
    cout<<typeid(pc).name()<<endl;
    cout<<typeid(*p).name()<<endl;
    cout<<typeid(*c).name()<<endl;
    cout<<typeid(*pc).name()<<endl;
    if(typeid(*pc)==typeid(Child))
    {
        ((Child)pc)->b=13;
    }
    pc->printData();
    return 0;
}
