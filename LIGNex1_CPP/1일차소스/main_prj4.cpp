#include <iostream>

using namespace std;
class Member{
	string name;
	string tel;
	string addr;
public:
    void inputData(string n, string t, string a){
		name = n;
		tel = t;
		addr = a;
    }
    void printData(){
		cout<<"name:"<<name<<endl;
		cout<<"tel:"<<tel<<endl;
		cout<<"addr:"<<addr<<endl;
    }
};

//�л� 1���� ���� ����
class Student{
    int num;
    string name;
    int score[4];

public:
    void inputData(int n, string n2, int kor, int eng, int math){
        num = n;
        name = n2;
        score[0] = kor;
        score[1] = eng;
        score[2] = math;
        score[3] = kor + eng + math;
    }

    void printData(){
        cout<<"num:"<<num<<endl;
        cout<<"name:"<<name<<endl;
        for(int i=0;i<4;i++){
            cout<<score[i]<<"\t";
        }
        cout<<endl;
    }
};

int main()
{
    int i, num, k, e, m;
    string name;
    Student arr[3];

    for(i=0;i<3;i++){
        cout<<"�л��� ��ȣ, �̸�, ��, ��, �� �Է� "<<endl;
        cin>>num;
        cin>>name;
        cin>>k;
        cin>>e;
        cin>>m;
        arr[i].inputData(num, name, k, e, m);
    }

    for(i=0;i<3;i++){
        arr[i].printData();
    }
    /*
    Member m1; //���ÿ� ��ü ����
    //m1.name = "aaa"; //name�� private�̶� ����
    m1.inputData("aaa", "111", "���ѹα�");
    m1.printData();

    Member *m2 = new Member(); //���� ��ü ����
    m2->inputData("bbb", "222", "����");
    m2->printData();
    */
    return 0;
}
