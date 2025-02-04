#include <iostream>

using namespace std;

class Car{
public:
    virtual void horn(){
        cout<<"����"<<endl;
    }
};
class Ambulance:public Car{
    virtual void horn(){
        cout<<"���深�� ������"<<endl;
    }
};

class FireCar:public Car{
    virtual void horn(){
        cout<<"�Ҳ��� ��"<<endl;
    }
};

class PoliceCar:public Car{
    virtual void horn(){
        cout<<"���۳� ��ƶ�"<<endl;
    }
};
int main()
{
    Car *arr[] = {new Car(), new Ambulance(), new FireCar(), new PoliceCar()};
    for(int i=0;i<4;i++){
        arr[i]->horn();
    }
    for(int i=0;i<4;i++){
        delete arr[i];
    }
    return 0;
}
