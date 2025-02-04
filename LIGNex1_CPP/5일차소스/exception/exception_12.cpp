#include <iostream>
#include <exception>
#include <stdlib.h>

using namespace std;

void myunex()
{
     cout<<"발생해서는 안되는 에러 발생";
     exit(-2);
}

void calc() throw(int)
{
     throw "string";
}

int main()
{
     set_unexpected(myunex);
     try {
          calc();
     }
     catch(int) {
          cout<<"정수형 예외 발생";
     }
     cout<<"프로그램 종료";
}


