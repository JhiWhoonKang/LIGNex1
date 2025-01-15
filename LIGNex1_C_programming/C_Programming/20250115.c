#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define size_ary(x) (sizeof(x)/sizeof((x)[0]))

#if 0

#define SWAP(temp, a, b){\
temp = a;\
a = b;\
b = temp;\
}
#define Assert(x) {\
	if ((x) >= 4)printf("Range error: %s, %s, %d\n", __FILE__, __FUNCTION__, __LINE__);\
}
int main(void)
{
	int a[4] = { 10, 20, 30, 40 };
	int i;
	for (i = 0;i <= 4;++i)
	{
#line 100
		Assert(i);
		printf("a[%d] = %d\n", i, a[i]);
	}
}
#endif

#if 0
#define ToString(x) #x
#define A(a) A##a

int main(void)
{
	int A1 = 4, A2 = 5;
	int i = 1;
	printf("%d", A(1) + A(2));
	//printf("%d\n", A(i));

	return 0;
}
#endif

#if 0
#define string(x) printf(#x" is %d\n", x)
#define charr(x) printf("%c is %c\n", #@x, x)
#define concat(x, i) printf("%s is %d\n", #i, x##i)
int main(void)
{
	int s = 10, c = 97, ca = 7, db = 0;
	string(s);
	charr(c);
	concat(c, a);
	concat(c, a);
}

#endif

#if 0
#define NDEBUG
#include<assert.h>


int main(void)
{
	int x;
	printf("\nEnger an integer value: ");
	(void)scanf("%d", &x);
	assert(x >= 0);
	printf("You entered %d", x);

	return(0);
}

#endif

#if 0
#include "point.h"
#include "line.h"
#include "a.h"

extern int a;
static int x = 10;
int count;
int count = 100; //여러 번 정의된 기호가 있습니다.
				 //_count이(가) 20250115.obj에 이미 정의되어 있습니다.
				 //초기값은 한 곳에서만 가능!! 보통 extern keyword가 없는 곳에 초기값 설정
extern int a;
extern void print_b(void);

int main(void)
{
	printf("Hello!\n");
	printf("main x : %d\n", x);
	printf("main count : %d\n", count);
	++a;
	print_a();
	print_count();
	print_b();
	return 0;
}
#endif