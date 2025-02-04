#include <iostream>

using namespace std;
class StaticTest{
public:
    static int a; //static ��� ����
    static int cnt;
    int b;          //�Ϲ� ��� ����
    StaticTest():b(0){
        cout<<++cnt<<"��° ��ü ����"<<endl;
        cout<<"a:"<<a<<", b:"<<b<<endl;
    }

    void add(){
        a++;
        b++;
    }

    void print(){
        cout<<"a:"<<a<<", b:"<<b<<endl;
    }

    //static ��� �Լ������� static ��� ������ ��� ����
    static void test1(){
        cout<<"test1() a:"<<a<<endl;
        //cout<<"b:"<<b<<endl;//b�� �Ϲ� ��� ������ ����
    }

    //static ��� �Լ������� static �Լ��� ȣ�� ����
    static void test2(){
        cout<<"test2()"<<endl;
        test1();
       // print();
    }
};
//static ������� �ʱ�ȭ �ڵ�.
//static ����� ��ü ���� ������ ��밡��.
//���α׷� �������ڸ��� �Ҵ��
int StaticTest::a = 0;
int StaticTest::cnt = 0;

class Singletone{
    //���ο��� ��ü ����
    static Singletone st;
    int a;
    Singletone(){}
public:
    //�ܺο��� ��ü ������ ���ϱ� ������ ���ο��� ������ ��ü�� ��ȯ
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
//static ��� ���� ����
Singletone Singletone::st;

int main()
{
    /*
    //��ü ������ static ��� ���
    cout<<"static ��� a:"<<StaticTest::a<<endl;

    //st1 ��ü ����
    StaticTest st1;  //a=0, b=0
    st1.add();//a:1, b:1
    st1.add();//a:2, b:2
    st1.print();

    //st2 ��ü ����. static ����� ����. �� ��ü �����ص� a�� �� ��������� ����
    StaticTest st2;  //a=2, b=0
    st2.add(); //a:3, b:1
    st2.add(); //a:4, b:2
    st2.print();

    cout<<"static ��� a:"<<StaticTest::a<<endl;
 */
    StaticTest::test1();
    StaticTest::test2();

   // Singletone st;  //����
    Singletone &s = Singletone::getInstance();
    s.setA(10);
    cout<<"s.a:"<<s.getA()<<endl;

    Singletone &s2 = Singletone::getInstance();
    s2.setA(20);
    cout<<"s2.a:"<<s2.getA()<<endl;
    cout<<"s.a:"<<s.getA()<<endl;
    return 0;
}
