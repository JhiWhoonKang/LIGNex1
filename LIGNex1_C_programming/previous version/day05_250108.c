#include <stdio.h>

int my_strlen_(char* p)
{
	int cnt = 0;
	while (p[cnt++]);
	return cnt;
}

int my_strlen2_(char* p)
{
	int cnt;
	for (cnt = 0;p[cnt];++cnt);
	return cnt;
}

int my_strlen3_(char* p)
{
	char* org = p;	
	while (*p++);
	return (p - org) - 1;
}

int my_strlen4_(char* p)
{
	int cnt = 0;
	while (*(p++)) cnt++;
	return cnt;
}

int my_strlen5_(const char* str)
{
	const char* s; // const 사용 이유: 
	for (s = str;*s;++s);
	return s - str;
}

#if 00
int main(void)
{
	char* input = "lignex1";
	printf("%d", my_strlen5_(input));
	return 0;
}
#endif


#if 00
void print_ary(char* arr)
{
	while(*arr++)
	{
		printf("%c", *(arr-1));
	}
}

void to_upper(char* org, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (*(org+i) >= 'a' && *(org + i) <= 'z')
		{
			*(org + i) -=  32;
		}
	}
}

int size_ary(char* org)
{
	int cnt;
	for (cnt = 0; *org++;cnt++);
	
	return cnt;
}

int main(void)
{
	char name[40] = "Tom & Jerry!";
	to_upper(name, size_ary(name));
	print_ary(name);

	return 0;
}
#endif

#if 0
#include <memory.h>

void* my_memcpy(void* dest, const void* src, size_t n)
{
	char* a = (char*)dest;
	char* b = (char*)src;
}

int main(void)
{
	int ary[5] = { 1,2,3,4,5 };
	int bry[5];

	memcpy(bry, ary, sizeof(ary));

	for (int i = 0;i < 5;i++)
	{
		printf("%d ", bry[i]);
	}
	printf("\n");

	char buffer[20] = "Hello, World!";
	
	memmove(buffer + 6, buffer, 5);
	printf("%s\n", buffer);

	return 0;
}
#endif

#if 0
int main(void)
{
	char* dessert1 = "apple";
	const char* dessert2 = "banana";
	char const* dessert3 = "banana";

	//dessert1[0] = 'X';
	//dessert2[0] = 'X';
	//dessert3[0] = 'X';

	dessert2 = "melon";

	char const* const dessert4 = "hi";

	printf("%s", dessert1);

	return 0;
}
#endif

#if 0
#define A 3.14

int main(void)
{
	int a = 3.14;
	int res1;
	double res2;

	res1 = a + 10.5;
	res2 = a + 10.5;
	printf("%d %.1f\n", res1, res2);


	return 0;
}


#endif

#if 00
#define Tax_Rate 0.11
double TaxA(int income) {
	return ((double)income * Tax_Rate);
}
double TaxB(int income) {
#define Tax_Rate 0.03

	return ((double)income * Tax_Rate);
}
int main(void) {
	printf("Tax_Rate (11%%) : %.1lf\n", TaxB(1000000));
	printf("Tax_Rate (3%%) : %.1lf\n", TaxA(1000000));

	return 0;
}
#endif

#if 0
int main(void)
{
	char ary[20] = "watermelon";
	char* name = "orange";
	char* temp = name;
	printf("%s\n", temp);
	temp = &ary[5];
	temp[0] = 'k';
	printf("%s", temp);
	return 0;
}
#endif

#if 0
int main(void)
{
	char* ch = "melon";

	printf("%p\n", ch);
	printf("%s", ch);

	return 0;
}
#endif

#if 0
#include <string.h>

int str_cmp(const char* s1, const char* s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == 0)
		{
			return 0;
		}
		s1++;
		s2++;
	}
	return *(unsigned const char*)s1 - *(unsigned const char*)(s2);
}

int main(void)
{
	/*int a = 0x61626364;
	char* b = &a;
	printf("%X", *(int*)b);*/

	char* a = "cat";
	char* b = "cats";
	
	printf("%d\n", strcmp(a, b));


	return 0;
}
#endif

#if 0
int a1;
int a2 = 10;
static int b1;
static int b2 = 10;

int main(void)
{
	int x1;
	int x2 = 100;
	static int y1;
	static int y2 = 200;
	int* p = malloc(100);
	b1 = 10;

	const int c = 400;
	int* ap = &c;
	*ap = 1000;
	printf("%d\n", c);

	return 0;
}
#endif

#if 0
extern int GetNum();
extern void Increment();

int main(void)
{
	printf("num: %d\n", GetNum());
	Increment();
	printf("num: %d\n", GetNum());
	Increment();
	printf("num: %d\n", GetNum());


	return 0;
}

#endif

#if 0
int* func(int a, int b)
{
	int c = a + b;
	return &c;
}
int main(void)
{
	printf("%d\n", *func(10, 20));

	return 0;
}
#endif

#if 0

int main(void)
{
	char a[20] = "abcdefghijklmnop";
	char* p = a;
	printf("%c\n", *(int*)p++);
	printf("%c\n", *((double*)p)++);
	printf("%c\n", *p);

	return 0;
}

#endif