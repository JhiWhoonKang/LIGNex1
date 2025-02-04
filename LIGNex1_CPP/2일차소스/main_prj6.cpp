#include <iostream>
#include <cstring>
using namespace std;

class Person{
    char *name;
    int age;

public:
    Person(){}
    Person(char *name, int age):age(age){
        int len = strlen(name)+1;
        this->name = new char[len];
        strcpy(this->name, name);
    }
    //복사 생성자 : 파람으로 받은 동일한 타입의 객체를 복사해서 객체를 생성하는 생성자
    //만들지 않아도 컴파일러가 얕은 복사 생성자는 자동으로 제공
    //Person p1 = p2;
    //Person p2(p1);
    //위 코드 실행시 복사 생성자 실행됨
    //깊은 복사 생성자
    Person(const Person &person):age(person.age){
        int len = strlen(person.name)+1;
        this->name = new char[len]; //힙에 이름저장할 메모리를 새로 할당
        strcpy(this->name, person.name); //이름값은 그대로 복사
    }

    void setName(char *name){
        strcpy(this->name, name);
    }
    void setAge(int age){
        this->age = age;
    }
    void printInfo(){
        cout<<"name:"<<name<<endl;
        cout<<"age:"<<age<<endl;
    }
    //소멸자
    ~Person(){
        cout<<"메모리 해제 :"<<name<<endl;
        delete []name;
    }
};


int main()
{
    Person p1("aaa", 12);
    Person p2 = p1; //얕은 복사. 멤버변수 값 복사
    p1.printInfo();
    p2.printInfo();
    p1.setName("bbb");
    p1.setAge(345);
    p1.printInfo();
    p2.printInfo();
    return 0;
}
