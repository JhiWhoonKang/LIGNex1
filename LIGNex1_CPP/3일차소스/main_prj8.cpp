#include <iostream>

using namespace std;
class Parent{
protected:
    int num;
    string str;
public:
    /*
    Parent(){
        cout<<"parent �⺻ ������"<<endl;
    }
    */
    Parent(int num, string str):num(num), str(str){
        cout<<"parent ������"<<endl;
    }
    void printInfo(){
        cout<<"num:"<<num<<", str:"<<str<<endl;
    }
    ~Parent(){
        cout<<"parent �Ҹ���"<<endl;
    }
};

class Child:public Parent{
    string hobby;
public:
    Child():Parent(0, "base"){
        cout<<"Child �⺻ ������"<<endl;
    }
    Child(int num, string str, string hobby):Parent(num, str), hobby(hobby){
        cout<<"Child ������"<<endl;
    }
    void printInfo2(){
        printInfo();
        cout<<"hobby:"<<hobby<<endl;
    }
    ~Child(){
        cout<<"Child �Ҹ���"<<endl;
    }
};
int main()
{
    Parent p(1, "aaa");
    p.printInfo();
    Child c(2, "bbb", "ccc");
    c.printInfo();
    c.printInfo2();

    Child c2;
    c2.printInfo();
    c2.printInfo2();
    return 0;
}
