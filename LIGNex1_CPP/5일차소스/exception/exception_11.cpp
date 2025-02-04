#include <iostream>
#include <exception>
#include <stdlib.h>
using namespace std;

void myterm()
{
    cout<<"처리되지 않은 예외 발생";
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


