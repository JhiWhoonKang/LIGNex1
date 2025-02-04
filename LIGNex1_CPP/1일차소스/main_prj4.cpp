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

//학생 1명의 정보 저장
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
        cout<<"학생의 번호, 이름, 국, 영, 수 입력 "<<endl;
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
    Member m1; //스택에 객체 생성
    //m1.name = "aaa"; //name이 private이라 에러
    m1.inputData("aaa", "111", "대한민국");
    m1.printData();

    Member *m2 = new Member(); //힙에 객체 생성
    m2->inputData("bbb", "222", "구로");
    m2->printData();
    */
    return 0;
}
