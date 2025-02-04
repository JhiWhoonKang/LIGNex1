#include <iostream>

using namespace std;

class Member{
    static int cnt;
    int num;  //자동할당
    string name;
    string tel;

public:
    Member(){}
    Member(string name, string tel){
        num = ++cnt;
        this->name = name;
        this->tel = tel;
    }
    int getNum(){
        return num;
    }

    string getName(){
        return name;
    }

    string getTel(){
        return tel;
    }

    void setTel(string tel){
        this->tel = tel;
    }

    friend ostream& operator<< (ostream& os, const Member& s);
};
ostream& operator<< (ostream& os, const Member& s)
{
	os<<"num:"<<s.num<<" / name:"<<s.name<<" / tel:"<<s.tel;
	return os;
}
int Member::cnt = 0;
template <typename T>
class Linked
{
private:
    struct node{
        T data;
        struct node *next;
    };
    struct node *head;
    struct node *tail;
public:
    Linked();
    void add(T x);
    void print();
};

template <typename T>
Linked<T>::Linked()
{
    head=NULL;
    tail=NULL;
}

template <typename T>
void Linked<T>::add(T x)
{
    struct node *bmp = new struct node;
    bmp->data = x;
    if(head==NULL){
        head=bmp;
    }else{
        tail->next=bmp;
    }

    tail=bmp;
    tail->next=NULL;
}
template <typename T>
void Linked<T>::print()
{
    struct node *bmp = head;
    while(bmp!=NULL){
        cout<<bmp->data<<endl;
        bmp=bmp->next;
    }
}


int main()
{
    Linked<int> l;
    l.add(1);
    l.add(2);
    l.add(3);
    l.print();

    Linked<char> l2;
    l2.add('a');
    l2.add('b');
    l2.add('c');
    l2.print();

    Linked<Member> l3;
    l3.add(Member("aaa","111"));
    l3.add(Member("bbb","222"));
    l3.add(Member("ccc","333"));
    l3.print();
    return 0;
}
