#include <iostream>
#include <cstring>

using namespace std;

class Person {
    char *name;
    int age;

public:
    Person() {}

    Person(const char *name, int age) : age(age)
    {
        int len = strlen(name) + 1;
        this->name = new char[len];
        strcpy(this->name, name);
    }

    void printInfo() const
    {
        cout << "name: " << (name ? name : "Unknown") << endl;
        cout << "age: " << age << endl;
    }

    ~Person()
    {
        if (name)
        {
            cout << "메모리 해제: " << name << endl;
            delete[] name;
        }
    }
};

class Node{
public:
    Person *person;
    Node *next;

    Node(Person &person) : data(person), next(nullptr) {}
};

class MyLinkedList{
    Node *header;
    Node *tail;
public:
    MyLinkedList() : header(nullptr), tail(nullptr) {}

    void addNode(Person *person)
    {
        Node *newNode = new Node(person);

        if (!header)
        {
            header = newNode;
        }
        else
        {
            tail->next = newNode;
        }
        tail =  newNode;
        tail->next = nullptr;
    }

    void printAllNodes() const
    {
        if (!header)
        {
            cout << "No Nodes" << endl;
            return;
        }

        Node *current = header;
        while (current)
        {
            current->person->printInfo();
            current = current->next;
        }
    }
    void deleteAllNodes() const
    {
        if (!header)
        {
            cout << "No Nodes" << endl;
            return;
        }

        Node *current = header;
        while (current)
        {
            header = header->next;
            delete current;
        }
    }
};


// second ex.
#if 01
int main(void)
{
    MyLinkedList *LL[3];
    char name[20];
    int age;
    for (int i = 0; i < 3; ++i)
    {
        cout << "Enter name: ";
        cin >> name;

        cout << "Enter age: ";
        cin >> age;

        Person p(name, age);
        LL[i] = new MyLinkedList();
        LL[i]->addNode(p);
    }

    cout << "\n--- Linked List Contents ---" << endl;
    for(int i = 0; i < 3; ++i)
    {
        LL[i]->printNodes();
    }

    return 0;
}
#endif // 01


// first ex.
#if 0
int main() {
    Person *person[3]; //Person 주소 3개 저저ㅏㅇ, Person 객체 없음
    Person person2[3]; //Person 객체 3개가 파람없는 생성자로 생성됨
    char name[20];
    int age;
    for (int i = 0; i < 3; ++i)
    {
        cout << "Enter name: ";
        cin >> name;

        cout << "Enter age: ";
        cin >> age;

        person[i] = new Person(name, age);
    }

    cout << "\n--- Info ---" << endl;
    for (int i = 0; i < 3; ++i)
    {
        person[i]->printInfo();
    }

    for(int i = 0; i < 3; ++i)
    {
        delete person[i]; //Person 객체 삭제
    }

    return 0;
}
#endif // 01
