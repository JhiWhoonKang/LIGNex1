#include <iostream>

using namespace std;

class Car{
public:
    virtual void horn(){
        cout<<"»§»§"<<endl;
    }
};
class Ambulance:public Car{
    virtual void horn(){
        cout<<"¿¥ºæ·±½º À§±ÞÇÔ"<<endl;
    }
};

class FireCar:public Car{
    virtual void horn(){
        cout<<"ºÒ²ô·¯ °¨"<<endl;
    }
};

class PoliceCar:public Car{
    virtual void horn(){
        cout<<"³ª»Û³ð Àâ¾Æ¶ó"<<endl;
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
