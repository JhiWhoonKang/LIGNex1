#include <iostream>

using namespace std;

class Point{
int x;
int y;

public:
    Point():x(0), y(0){}
    Point(int x, int y):x(x), y(y){}

    // + 연산자 오버로딩
    Point operator+(const Point& p){
        Point res(x+p.x, y+p.y);
        return res;
    }

    void print(){
        cout<<"x:"<<x<<", y:"<<y<<endl;
    }

    friend Point operator+(const Point &p1, const Point &p2);
};


Point operator+(const Point &p1, const Point &p2){
     Point res(p1.x+p2.x, p1.y+p2.y);
     return res;
}

int main()
{
    Point p1(1,2);
    Point p2(3,4);
    Point p3 = p1.operator+(p2);
    p3.print();
    return 0;
}
