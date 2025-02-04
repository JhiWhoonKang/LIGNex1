#include <iostream>
#include <cstring>
using namespace std;

class Person{
    char *name;
    int age;
public:
    Person(char *name, int age){
        int len = strlen(name)+1;
        this->name = new char[len];
        strcpy(this->name, name);
        this->age = age;
    }

    void printPerson(){
        cout<<"name:"<<name<<endl;
        cout<<"age:"<<age<<endl;
    }

    Person& operator=(const Person& p){
        delete []name;
        int len = strlen(p.name)+1;
        name = new char[len];
        strcpy(name, p.name);
        age = p.age;
        return *this;
    }

    ~Person(){
        delete []name;
    }
    void setName(char *str){
        strcpy(name, str);
    }
};

int main()
{
    Person p1("aaa", 12);
    Person p2("bbb", 23);
    p1.printPerson();
    p2.printPerson();
    p2 = p1;
    p1.printPerson();
    p2.printPerson();
    p1.setName("asdf");
    p1.printPerson();
    p2.printPerson();
    return 0;
}
