#include <stdio.h>
#include <limits.h>
#include <stdint.h>

#define _countof(array) (sizeof(array)/sizeof(array[0]))

#if 0
int func(void)
{
	int a = 10;
	return a = 20;
}

int main(void)
{
	printf("Hellow C!\n");
	printf("%d", func());



	return 0;
}
#endif

#if 0
//�ѱ� �̸� ����
int main(void)
{
	int age = 26;
	printf("%d\n", age);

	
	char ch1 = 'A';
	char ch2 = 65;

	printf("���� %c�� �ƽ�Ű �ڵ� �� : %d\n", ch1, ch1);
	printf("�ƽ�Ű �ڵ� ���� %d�� ���� : %c\n", ch2, ch2);
	
	unsigned char uch1 = -1;		//0xffffffff -> 0xff
	unsigned char uch2 = 128;		//0x00000080 -> 0x80
	signed char ch3 = -1;
	signed char ch4 = 128;

	//0xff -> 0x000000ff -> 0xff, 0x80 -> 0x00000080 -> 0x80
	printf("unsigned char(%%u)	: %u %u\n", uch1, uch2);
	//0xff -> 0xffffffff -> 2�� ���� -> -1
	//0x80 -> 0xffffff80 -> 2�� ���� -> -128
	printf("signed char(%%d)	: %d %d \n", ch3, ch4);
	
	double num = 123456789.0f;
	printf("num: %.lf\n", num);

	int num2 = 10;
	int* p = &num2;
	printf("%zu %zu\n", sizeof(num2), sizeof(p));
	printf("%p %d\n", p, *p);

	int income = 0;
	double tax;
	const double tax_Rate = 0.12;
	double* tax_p = &tax_Rate;
	*tax_p = 0.15;
	scanf_s("%d", &income);
	//income = 456;	
	tax = income * tax_Rate;
	printf("������ : %.1lf�Դϴ�.\n", tax);

	char grade;
	char name[20];

	(void)scanf_s("%c", &grade);\
	scanf_s("%s", name, (unsigned int)_countof(name));
	printf("%s�� ������ %c�Դϴ�.\n", name, grade);
	
	char grade;
	char name[20];

	(void)scanf("%c", &grade);

	int c;
	while((c=getchar())!='\n'&&c!=EOF){}

	if (fgets(name, (int)sizeof(name), stdin) != NULL)
	{
		size_t len = strlen(name);
		if (len > 0 && name[len - 1] == '\n')
		{
			name[len - 1] = '\0';
		}
	}

	printf("%s�� ������ %c�Դϴ�.\n", name, grade);

	return 0;
}
#endif

