#if 0
#include "a.h"
int a;
extern int x; //static이기 때문에 되면 안됨
extern int count;
void print_a(void)
{
	printf("A.C : a = %d\n", a);
	//printf("A.C : x = %d\n", x); //확인할 수 없는 외부 기호 _x
								 //1개의 확인할 수 없는 외부 참조입니다.
	print_count();
}

void print_count(void)
{
	printf("A.C : count = %d\n", ++count); //확인할 수 없는 외부 기호 _x
}

#endif