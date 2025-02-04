#include <iostream>

using namespace std;
class Parent{
protected:
    int num;
    string str;
public:
    /*
    Parent(){
        cout<<"parent 기본 생성자"<<endl;
    }
    */
    Parent(int num, string str):num(num), str(str){
        cout<<"parent 생성자"<<endl;
    }
    void printInfo(){
        cout<<"num:"<<num<<", str:"<<str<<endl;
    }
    ~Parent(){
        cout<<"parent 소멸자"<<endl;
    }
};

class Child:public Parent{
    string hobby;
public:
    Child():Parent(0, "base"){
        cout<<"Child 기본 생성자"<<endl;
    }
    Child(int num, string str, string hobby):Parent(num, str), hobby(hobby){
        cout<<"Child 생성자"<<endl;
    }
    void printInfo2(){
        printInfo();
        cout<<"hobby:"<<hobby<<endl;
    }
    ~Child(){
        cout<<"Child 소멸자"<<endl;
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
