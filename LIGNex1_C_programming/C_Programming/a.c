#if 0
#include "a.h"
int a;
extern int x; //static�̱� ������ �Ǹ� �ȵ�
extern int count;
void print_a(void)
{
	printf("A.C : a = %d\n", a);
	//printf("A.C : x = %d\n", x); //Ȯ���� �� ���� �ܺ� ��ȣ _x
								 //1���� Ȯ���� �� ���� �ܺ� �����Դϴ�.
	print_count();
}

void print_count(void)
{
	printf("A.C : count = %d\n", ++count); //Ȯ���� �� ���� �ܺ� ��ȣ _x
}

#endif