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
    //���� ������ : �Ķ����� ���� ������ Ÿ���� ��ü�� �����ؼ� ��ü�� �����ϴ� ������
    //������ �ʾƵ� �����Ϸ��� ���� ���� �����ڴ� �ڵ����� ����
    //Person p1 = p2;
    //Person p2(p1);
    //�� �ڵ� ����� ���� ������ �����
    //���� ���� ������
    Person(const Person &person):age(person.age){
        int len = strlen(person.name)+1;
        this->name = new char[len]; //���� �̸������� �޸𸮸� ���� �Ҵ�
        strcpy(this->name, person.name); //�̸����� �״�� ����
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
    //�Ҹ���
    ~Person(){
        cout<<"�޸� ���� :"<<name<<endl;
        delete []name;
    }
};


int main()
{
    Person p1("aaa", 12);
    Person p2 = p1; //���� ����. ������� �� ����
    p1.printInfo();
    p2.printInfo();
    p1.setName("bbb");
    p1.setAge(345);
    p1.printInfo();
    p2.printInfo();
    return 0;
}
