#include <iostream>

using namespace std;


namespace Add{
    int add (int a, int b){
        return a+b;
    }

    int add (int a, int b, int c){
        return a+b+c;
    }

    float add(float a, float b){
        return a+b;
    }

}

using namespace Add;

int main()
{
    cout<<"add(1,2):"<<add(1,2)<<endl;
    cout<<"add(1,2,3):"<<add(1,2,3)<<endl;
    cout<<"add(1.2f,2.3f):"<<add(1.2f,2.3f)<<endl;
    return 0;
}
