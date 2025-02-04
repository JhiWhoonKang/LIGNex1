#include <iostream>

using namespace std;

class Point{
public:
    int x;
    int y;
    Point(){}
    Point(int x, int y):x(x), y(y){}
    void print(){
        cout<<"x:"<<x<<", y:"<<y<<endl;
    }
};

template<typename T>
class MyArr{
    T *arr;  //임의의 타입 배열 주소
    int len; //배열의 길이

    MyArr(const MyArr& m){} //복사 생성자
    MyArr& operator=(const MyArr& m){}//대입 연산자

public:
    MyArr(){
        arr = new T[6];
        len = 6;
    }
    MyArr(int len){
        arr = new T[len];
        this->len = len;
    }
    //요소 접근 연산자
    const T& operator[](int idx) const {
        if(idx<0 || idx>=len){
            cout<<"outofbounds exception"<<endl;
            exit(-1);
        }
        return arr[idx];
    }

    //요소 접근 연산자
    T& operator[](int idx){
        if(idx<0 || idx>=len){
            cout<<"outofbounds exception"<<endl;
            exit(-1);
        }
        return arr[idx];
    }

    int getLen(){
        return len;
    }

    ~MyArr(){
        delete []arr;
    }
};

int main()
{
    MyArr<Point> a;
    cout<<a.getLen()<<endl;
    a[0]=Point(1,2);
    a[1]=Point(3,4);
    a[0].print();
    a[1].print();
    return 0;
}
