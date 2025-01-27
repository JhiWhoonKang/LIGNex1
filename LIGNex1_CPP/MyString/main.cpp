#include <iostream>
#include <cstring>

using namespace std;

class MyString{
    char *str;
    int len;

public:
    MyString():str(nullptr), len(0){}
    MyString(char *str)
    {
        len = strlen(str);
        this->str=new char[len + 1];
        strcpy(this->str, str);
    }
    MyString(const char *str)
    {
        len = strlen(str);
        this->str=new char[len + 1];
        strcpy(this->str, str);
    }
    MyString(const MyString&s)
    {
        len = s.len;
        str = new char[len + 1];
        strcpy(str, s.str);
    }
    MyString(const char *str1, const char *str2)
    {
        if(strcmp(str1, str2))
        {
            cout<<"different str"<<endl;
            return;
        }
        cout<<"same str"<<endl;
    }
};

int main()
{
    char str[] = {'a', 'b', 'c', '\0'};
    MyString m1;
    MyString m2(str);
    MyString m3("apple");
    MyString m4(m3);

    cout<<m1<<endl;
    cout<<m2<<endl;
    cout<<m3<<endl;
    cout<<m4<<endl;

    MyString&

    MyString m5("hello", "hello");



    return 0;
}
