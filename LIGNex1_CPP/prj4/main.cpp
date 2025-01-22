#include <iostream>
#include <vector>

#define MAX_ADDRESS_BOOK_SIZE 10

using namespace std;

class Member{
    string name;
    string tel;
    string addr;
public:
    void inputData(string n, string t, string a)
    {
        name=n;
        tel=t;
        addr=a;
    }
    void printData()
    {
        cout<<"name: "<<name<<endl;
        cout<<"tel: "<<tel<<endl;
        cout<<"addr: "<<addr<<endl;
    }

};

class Student{
    string tel;
    string name;
    int score;
public:
    void inputData(string t, string n, int k, int e, int m)
    {

        tel=t;
        name=n;
        score=k+e+m;
    }
    void printData()
    {
        cout<<"tel: "<<tel<<endl;
        cout<<"name: "<<name<<endl;
        cout<<"score: "<<score<<endl;
    }

};

class AddressBook{
    int idx[MAX_ADDRESS_BOOK_SIZE];
    string name[MAX_ADDRESS_BOOK_SIZE];
    string tel[MAX_ADDRESS_BOOK_SIZE];
public:
    /*
    AddressBook()
    {
        idx = -1;
        name = "";
        tel = "";
    }
    */
    void inputData(int i, string n, string t)
    {
        if(i > 10)
        {
            cout<< "only 10 people Max" <<endl;
        }
        idx[i] = i;
        name[i] = n;
        tel[i] = t;
    }

    void Search(int i)
    {
        string result;
        if(idx[i] == NULL)\
        {
            cout << "not found" <<"\n";
        }
        cout << "Print Inform. => " << name[i] << tel[i] << "\n";
    }
    void ConfigTel(int i, string t)
    {
        if(!idx[i])
        {
            return;
        }
        tel[i] = t;
    }
    void Del(int i)
    {
        if(!idx[i])
        {
            return;
        }
        idx[i] = -1;
        name[i] = "";
        tel[i] = "";
        cout<<"Deleted"<<"\n";
    }
    void PrintAll()
    {
        for(int i=0; i<MAX_ADDRESS_BOOK_SIZE; ++i)
        {
            cout <<"number: " << idx[i] << ", name: " << name[i] << ", phone: " << tel[i] << "\n";
        }
    }
};

int main()
{
    Member m1;
    m1.inputData("aaa", "111","Korea");
    m1.printData();

    Member *m2=new Member();
    m2->inputData("bbb", "222", "Guro");
    m2->printData();

    #if 0
    cout<<"student class code"<<endl;
    string tel, name;
    int kor, eng, math;
    cout<<"telephone number, name, Korean, English, Math score 순으로 작성"<<endl;
    cin>>tel>>name>>kor>>eng>>math;

    Student *student[3];
    for(int i=0;i<3;++i)
    {
        student[i] = new Student();
        student[i]->inputData(tel, name, kor, eng, math);
        student[i]->printData();
    }
    #endif


    #if 01
    AddressBook *ab[MAX_ADDRESS_BOOK_SIZE];

    for(int i=0;i<MAX_ADDRESS_BOOK_SIZE; ++i)
    {
        string name, phone;
        ab[i] = new AddressBook();
        cout<<"Wrtie your name and phone number: "<<"\n";
        cin>>name>>phone;
        ab[i]->inputData(i, name, phone);
    }

    string cmd;
    while(true)
    {
        cin>>string;
        if(cmd.== "search")
        {

        }
        else if(cmd == "edit")
        {

        }
        else if(cmd == "del")
        {

        }
        else if(cmd == "print")
        {

        }
        else
        {
            break;
        }
    }
    #endif // 01

    return 0;
}
