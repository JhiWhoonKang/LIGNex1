#include <iostream>

using namespace std;
class StaticTest{
public:
    static int a; //static 멤버 변수
    static int cnt;
    int b;          //일반 멤버 변수
    StaticTest():b(0){
        cout<<++cnt<<"번째 객체 생성"<<endl;
        cout<<"a:"<<a<<", b:"<<b<<endl;
    }

    void add(){
        a++;
        b++;
    }

    void print(){
        cout<<"a:"<<a<<", b:"<<b<<endl;
    }

    //static 멤버 함수에서는 static 멤버 변수만 사용 가능
    static void test1(){
        cout<<"test1() a:"<<a<<endl;
        //cout<<"b:"<<b<<endl;//b가 일반 멤버 변수라서 에러
    }

    //static 멤버 함수에서는 static 함수만 호출 가능
    static void test2(){
        cout<<"test2()"<<endl;
        test1();
       // print();
    }
};
//static 멤버변수 초기화 코드.
//static 멤버는 객체 생성 전에도 사용가능.
//프로그램 시작하자마자 할당됨
int StaticTest::a = 0;
int StaticTest::cnt = 0;

class Singletone{
    //내부에서 객체 생성
    static Singletone st;
    int a;
    Singletone(){}
public:
    //외부에서 객체 생성을 못하기 때문에 내부에서 생성한 객체를 반환
    static Singletone& getInstance(){
        return st;
    }
    void setA(int a){
        this->a = a;
    }
    int getA(){
        return a;
    }
};
//static 멤버 변수 선언
Singletone Singletone::st;

int main()
{
    /*
    //객체 생성전 static 멤버 사용
    cout<<"static 멤버 a:"<<StaticTest::a<<endl;

    //st1 객체 생성
    StaticTest st1;  //a=0, b=0
    st1.add();//a:1, b:1
    st1.add();//a:2, b:2
    st1.print();

    //st2 객체 생성. static 멤버는 공용. 새 객체 생성해도 a가 또 만들어지지 않음
    StaticTest st2;  //a=2, b=0
    st2.add(); //a:3, b:1
    st2.add(); //a:4, b:2
    st2.print();

    cout<<"static 멤버 a:"<<StaticTest::a<<endl;
 */
    StaticTest::test1();
    StaticTest::test2();

   // Singletone st;  //에러
    Singletone &s = Singletone::getInstance();
    s.setA(10);
    cout<<"s.a:"<<s.getA()<<endl;

    Singletone &s2 = Singletone::getInstance();
    s2.setA(20);
    cout<<"s2.a:"<<s2.getA()<<endl;
    cout<<"s.a:"<<s.getA()<<endl;
    return 0;
}
