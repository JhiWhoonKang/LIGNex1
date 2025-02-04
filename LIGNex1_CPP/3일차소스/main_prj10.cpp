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

    //�Լ� ������. ��� ���� �Լ��� ���� Ŭ������ �������� �ʾƼ� ����
    void printPoint(){
        Point::printPoint();//�θ� Ŭ������ �Լ� ȣ��
        cout<<"z:"<<z<<endl;
    }

    int getZ(){
        return z;
    }
};
int main()
{
    //��ü�� �������� �Լ� ȣ��� Ÿ���� ����
    //���� ȣ��: Ÿ���� ����
    Point p2(4,5);
    p2.printPoint();

    Point3D p(1,2,3);
    p.printPoint();
    cout<<"p.x: "<<p.getX()<<endl;
    cout<<"p.z: "<<p.getZ()<<endl;

    //�� ĳ����: ��Ӱ��迡�� ���� ��ü �ּҸ� ���� Ÿ�� �����Ϳ� �Ҵ�
    //�����Լ��� �ƴϸ� ������ �Լ� ȣ���� �������� Ÿ���� ����
    //Ÿ���� �θ��̹Ƿ� �θ� Ŭ������ ���ǵ� ����� ��밡��
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
