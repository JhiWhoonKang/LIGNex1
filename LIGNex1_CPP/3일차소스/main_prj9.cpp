#include <iostream>

using namespace std;

class Person{
protected:
    string num;
    string name;
    string addr;
public:
    Person(){}
    Person(string num, string name, string addr)
    :num(num), name(name), addr(addr){}
    void printInfo(){
        cout<<"num:"<<num<<endl;
        cout<<"name:"<<name<<endl;
        cout<<"addr:"<<addr<<endl;
    }
};
class Student:public Person{
    string subj[3];
    int cnt=0;
public:
    Student(){}
    Student(string num, string name, string addr):Person(num, name, addr){}
    void addSubj(string sub){
        if(cnt>=3){
            cout<<"�ʰ���"<<endl;
            return;
        }
        subj[cnt++] = sub;
    }
    void printSubj(){
        cout<<"������û ���"<<endl;
        for(int i=0;i<cnt;i++){
            cout<<subj[i]<<", ";
        }
        cout<<endl;
    }
};

class Prof:public Person{
    string subj[3];
    int cnt=0;
public:
    Prof(){}
    Prof(string num, string name, string addr):Person(num, name, addr){}
    void addSubj(string sub){
        if(cnt>=3){
            cout<<"�ʰ���"<<endl;
            return;
        }
        subj[cnt++] = sub;
    }
    void printSubj(){
        cout<<"���� ���"<<endl;
        for(int i=0;i<cnt;i++){
            cout<<subj[i]<<", ";
        }
        cout<<endl;
    }
};

class Staff:public Person{
    string job;
public:
    Staff(){}
    Staff(string num, string name, string addr):Person(num, name, addr){}
    void addJob(string job){
        this->job = job;
    }
    void printJob(){
        cout<<"job:"<<job<<endl;
    }
};
int main()
{
    Student s("stu001", "aaa", "����");
    s.addSubj("C");
    s.addSubj("C++");
    s.printInfo();
    s.printSubj();

    Prof pf("prof002", "bbb", "�ٶ�");
    pf.addSubj("�����а���");
    pf.addSubj("��ǻ�ͱ�����");
    pf.addSubj("�����Ϸ���");
    pf.printInfo();
    pf.printSubj();

    Staff st("staff003", "ccc", "����");
    st.addJob("hr");
    st.printInfo();
    st.printJob();
    return 0;
}
