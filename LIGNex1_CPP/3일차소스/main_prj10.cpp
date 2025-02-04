#include <iostream>

using namespace std;

class Point{
protected:
    int x;
    int y;
public:
    Point():x(0),y(0){}
    Point(int x, int y):x(x), y(y){}

    void printPoint(){
        cout<<"x:"<<x<<", y:"<<y<<endl;
    }
    int getX(){
        return x;
    }
};

class Point3D:public Point{
    int z;
public:
    Point3D():z(0){}
    Point3D(int x, int y, int z):Point(x, y), z(z){   }

    //함수 재정의. 상속 받은 함수가 현재 클래스에 적합하지 않아서 수정
    void printPoint(){
        Point::printPoint();//부모 클래스의 함수 호출
        cout<<"z:"<<z<<endl;
    }

    int getZ(){
        return z;
    }
};
int main()
{
    //객체로 재정의한 함수 호출시 타입을 따라감
    //정적 호출: 타입을 따라감
    Point p2(4,5);
    p2.printPoint();

    Point3D p(1,2,3);
    p.printPoint();
    cout<<"p.x: "<<p.getX()<<endl;
    cout<<"p.z: "<<p.getZ()<<endl;

    //업 캐스팅: 상속관계에서 하위 객체 주소를 상위 타입 포인터에 할당
    //가상함수가 아니면 재정의 함수 호출은 포인터의 타입을 따라감
    //타입이 부모이므로 부모 클래스에 정의된 멤버만 사용가능
    Point *pp = &p;
    pp->printPoint();
    cout<<"pp.x: "<<pp->getX()<<endl;
    cout<<"((Point3D *)pp).z: "<<((Point3D *)pp)->getZ()<<endl;

    Point3D *ppp = &p;
    ppp->printPoint();
    cout<<"ppp.x: "<<ppp->getX()<<endl;
    cout<<"ppp.z: "<<ppp->getZ()<<endl;
    return 0;
}
