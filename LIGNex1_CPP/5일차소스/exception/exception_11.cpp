#include <iostream>
#include <exception>
#include <stdlib.h>
using namespace std;

void myterm()
{
    cout<<"ó������ ���� ���� �߻�";
     exit(-1);
}

int main()
{
     set_terminate(myterm);
     try {
          throw 1;
     }
     catch(char *m) {
     }
}


