#include <iostream>
#include <cstring>

using namespace std;
class Point{
    int x;
    int y;
public:
    //�Ķ����� ������
    Point(){
        x = 0;
        y = 0;
    }

    //�Ķ�2�� ������
    Point(int x, int y):x(x),y(y){
        /*
        this->x = x;
        this->y = y;
        */
    }

    //����Լ�
    void printPoint(){
        cout<<"x:"<<x<<", y:"<<y<<endl;
    }
};

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

class Node{
public:
    Person *person;
    Node *next;

    //������
    Node(Person *person):person(person){}

    //�Ҹ���
    ~Node(){
        person->printInfo();
        cout<<"��� �Ҹ��ڿ��� person ��ü ����"<<endl;
        delete person;
    }
};

class MyLinkedList{
    //header:ù ��� �ּ�, tail:������ ��� �ּ�
    Node *header=NULL, *tail=NULL;

public:

    void addNode(Person *p){
        //�� ��� ����
        Node *bmp = new Node(p);

        if(header==NULL){//���� bmp�� ù ����� header�� bmp�Ҵ�
            header = bmp;
        }else{ //�׷��� �ʴٸ� tail �ڿ� bmp ����
            tail->next = bmp;
        }

        tail = bmp; //bmp�� ������ ����̹Ƿ� tail�� bmp�Ҵ�
        tail->next = NULL; //������ ����� ���� ���� �����Ƿ� next�� NULL�Ҵ�
    }

    //header~tail �� ��� �湮
    void printAllNode(){
        Node *cur = header; //cur:ù ��� �ּ� �Ҵ�
        while(cur!=NULL){ //���� ��尡 ���������� �ݺ�
            cur->person->printInfo(); //���� ����� person �� ���
            cur=cur->next; //cur�� ���� ���� �̵�
        }
    }

    //��� ����� �޸� ����
    void delAllNode(){
        while(header!=NULL){ //header�� �� ��带 ����������
            Node *delNode = header;
            header=header->next; //header�� ���� ���� �̵�
            delete delNode; //������ ��� �޸� ����
        }
    }
};

int main()
{
    MyLinkedList my;

    char name[20];
    int age, i;

    for(i=0;i<3;i++){
        cout<<"name:";
        cin>>name;
        cout<<"age:";
        cin>>age;
        my.addNode(new Person(name, age));//���� Person��ü �����ؼ� �ּҸ� �迭�� ����
    }

    my.printAllNode();
    my.delAllNode();

    /*
    Person *arr[3];//Person �ּ� 3�� ����. Person ��ü ����
    //Person data[3]; //Person ��ü 3���� �Ķ����� �����ڷ� ������

    //�Է¹��� ������ �ӽ� ����
    char name[20];
    int age, i;

    for(i=0;i<3;i++){
        cout<<"name:";
        cin>>name;
        cout<<"age:";
        cin>>age;
        arr[i] = new Person(name, age);//���� Person��ü �����ؼ� �ּҸ� �迭�� ����
    }

    for(i=0;i<3;i++){
        arr[i]->printInfo();
    }

    for(i=0;i<3;i++){
        delete arr[i];//Person ��ü �޸� ����
    }

    Point p1;//����Ʈ ������ ȣ��
    p1.printPoint();
    Point arr[3];
    Point p2(4,5);//�Ķ�2�� ������ ȣ��
    p2.printPoint();
    */
    return 0;
}
