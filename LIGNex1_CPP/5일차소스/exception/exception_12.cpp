#include <iostream>
#include <exception>
#include <stdlib.h>

using namespace std;

void myunex()
{
     cout<<"�߻��ؼ��� �ȵǴ� ���� �߻�";
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
          cout<<"������ ���� �߻�";
     }
     cout<<"���α׷� ����";
}


