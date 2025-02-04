#include <iostream>
#include <cstring>

using namespace std;

class MyString{
    char *str;
    int len;
public:
    MyString():str(NULL), len(0){}
    MyString(char *str){
        len = strlen(str);
        this->str = new char[len+1];
        strcpy(this->str, str);
    }
    MyString(const char *str){
        len = strlen(str);
        this->str = new char[len+1];
        strcpy(this->str, str);
    }
    MyString(const MyString &s){
        len = s.len;
        str = new char[len+1];
        strcpy(str, s.str);
    }

    ~MyString(){
        delete []str;
    }

    int getLen(){
        return len;
    }

    MyString& operator=(const MyString& copy){ //m1 = m2
        if(str!=NULL){//현재 객체에 값이 있으면
            delete []str;
        }
        len = strlen(copy.str);
        str = new char[len+1];
        strcpy(str, copy.str);
        return *this;
    }

    bool operator==(const MyString& s){
        return strcmp(str, s.str)? false:true;
    }

    friend ostream& operator<<(ostream& os, const MyString& s);
};

ostream& operator<<(ostream& os, const MyString& s){
        os<<s.str;
        return os;
}

int main()
{
    char str[] = {'a','b','c','\0'};
    MyString m1 = "zxvc";
    MyString m2(str);
    MyString m3("apple");
    MyString m4(m3);
    m1 = "kkk";

    cout<<m1<<endl;
    cout<<m2<<endl;
    cout<<m3<<endl;
    cout<<m4<<endl;

    cout<<"m1==m2:"<<(m1==m2)<<endl;
    cout<<"m1==kkk:"<<(m1=="kkk")<<endl;
    return 0;
}
