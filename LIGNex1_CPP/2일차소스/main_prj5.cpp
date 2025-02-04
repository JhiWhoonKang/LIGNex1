#include <iostream>
#include <cstring>

using namespace std;
class Point{
    int x;
    int y;
public:
    //파람없는 생성자
    Point(){
        x = 0;
        y = 0;
    }

    //파람2개 생성자
    Point(int x, int y):x(x),y(y){
        /*
        this->x = x;
        this->y = y;
        */
    }

    //멤버함수
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
    //소멸자
    ~Person(){
        cout<<"메모리 해제 :"<<name<<endl;
        delete []name;
    }
};

class Node{
public:
    Person *person;
    Node *next;

    //생성자
    Node(Person *person):person(person){}

    //소멸자
    ~Node(){
        person->printInfo();
        cout<<"노드 소멸자에서 person 객체 삭제"<<endl;
        delete person;
    }
};

class MyLinkedList{
    //header:첫 노드 주소, tail:마지막 노드 주소
    Node *header=NULL, *tail=NULL;

public:

    void addNode(Person *p){
        //새 노드 생성
        Node *bmp = new Node(p);

        if(header==NULL){//만약 bmp가 첫 노드라면 header에 bmp할당
            header = bmp;
        }else{ //그렇지 않다면 tail 뒤에 bmp 연결
            tail->next = bmp;
        }

        tail = bmp; //bmp가 마지막 노드이므로 tail에 bmp할당
        tail->next = NULL; //마지막 노드의 다음 노드는 없으므로 next에 NULL할당
    }

    //header~tail 각 노드 방문
    void printAllNode(){
        Node *cur = header; //cur:첫 노드 주소 할당
        while(cur!=NULL){ //읽을 노드가 있을때까지 반복
            cur->person->printInfo(); //현재 노드의 person 값 출력
            cur=cur->next; //cur을 다음 노드로 이동
        }
    }

    //모든 노드의 메모리 해제
    void delAllNode(){
        while(header!=NULL){ //header가 끝 노드를 만날때까지
            Node *delNode = header;
            header=header->next; //header를 다음 노드로 이동
            delete delNode; //삭제할 노드 메모리 해제
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
        my.addNode(new Person(name, age));//힙에 Person객체 생성해서 주소를 배열에 저장
    }

    my.printAllNode();
    my.delAllNode();

    /*
    Person *arr[3];//Person 주소 3개 저장. Person 객체 없음
    //Person data[3]; //Person 객체 3개가 파람없는 생성자로 생성됨

    //입력받은 데이터 임시 저장
    char name[20];
    int age, i;

    for(i=0;i<3;i++){
        cout<<"name:";
        cin>>name;
        cout<<"age:";
        cin>>age;
        arr[i] = new Person(name, age);//힙에 Person객체 생성해서 주소를 배열에 저장
    }

    for(i=0;i<3;i++){
        arr[i]->printInfo();
    }

    for(i=0;i<3;i++){
        delete arr[i];//Person 객체 메모리 해제
    }

    Point p1;//디폴트 생성자 호출
    p1.printPoint();
    Point arr[3];
    Point p2(4,5);//파람2개 생성자 호출
    p2.printPoint();
    */
    return 0;
}
