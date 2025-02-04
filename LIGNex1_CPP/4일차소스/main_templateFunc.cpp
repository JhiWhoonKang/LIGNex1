#include <iostream>
#include <cstring>

using namespace std;

template<typename T>
T Max(T v1, T v2){
    return v1>v2?v1:v2;
}

template<>
char* Max(char* v1, char* v2){
    cout<<"char*비교"<<endl;
    return (strlen(v1)>strlen(v2))?v1:v2;
}

template<>
const char* Max(const char* v1, const char* v2){
    cout<<"const char*비교"<<endl;
    return (strlen(v1)>strlen(v2))?v1:v2;
}

int main()
{

    char buf1[]={'a','b'};
    char buf2[]={'a','b','c','d'};
    cout<<"max(1,2):"<<Max(1,2)<<endl;
    cout<<"max(2.3, 4.5):"<<Max(2.3, 4.5)<<endl;
    cout<<"max('aaa', 'asdf'):"<<Max("aaa","asdf")<<endl;
    cout<<"max(buf1, buf2):"<<Max(buf1, buf2)<<endl;

    return 0;
}
