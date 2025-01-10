#include <stdio.h>
#include <string.h>  // strlen
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

#if 0
d main(void)
{
	char grade, grade2;
	char name[20];
	(void)scanf("%c", &grade);
	(void)scanf(" %c", &grade2);
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}

	if (fgets(name, (int)sizeof(name), stdin) != NULL) {
		size_t len = strlen(name);
		if (len > 0 && name[len - 1] == '\n') {
			name[len - 1] = '\0';
		}
	}
	printf("%s의 학점은 %c입니다.\n", name, grade);
	printf("grade2 = %c이다.", grade2);
}
#endif

#if 0
int main(void)
{
	int a = 5;
	int b = 2;
	int result_i = a / b;
	float result_f = (float)a / b;

	printf("result_i = %d\n", result_i);
	printf("result_f = %.1f\n", result_f);

	int a2 = -1;
	unsigned int b2 = 1;
	if (a2 < b2)
	{
		printf("a si less than b\n");
	}
	else
	{
		printf("a is not less than b\n");
	}

	return 0;
}
#endif

#if 0
int main(void)
{
	//int a[5][3] = -1;
	int a[5][3] = { 1,2,3,4,5,6,7,8,9,10, 11, 12, 13, 14, 15 };

	printf("%d\n", a[0][0]);
	printf("%d\n", a[5][-8]);


	int a2 = 20;
	int b2 = 10;

	(a2 < b2) ? printf("%d\n", a2) : printf("%d\n", b2);
	
	printf("%d\n", (a2 < b2) ? a2 : b2);

	return 0;
}
#endif

#if 0

#include <math.h>
unsigned int setBit(unsigned int num, int bitPosition)
{
	num |= (1 << bitPosition);
	return num;
}

unsigned int clearBit(unsigned int num, int bitPosition)
{
	num &= ~(1 << bitPosition);

	return num;
}

unsigned int toggleBit(unsigned int num, int bitPosition)
{
	num ^= (1 << bitPosition);
	return num;
}

unsigned int setBits(unsigned int num, int start, int count)
{
	num |= ((1 << count) - 1 << start);
	return num;
}

unsigned int clearBits(unsigned int num, int start, int count)
{
	num &= ~((1 << count) - 1 << start);

	return num;
}

unsigned int toggleBits(unsigned int num, int start, int count)
{
	num ^= ((1 <<count ) - 1 << start);
	return num;
}

static unsigned int isBitSet(unsigned int num, int bitPosition)
{
	return (num & (1 << bitPosition)) != 0;
}

int main(void)
{
	/*int a = 10;
	int b = 12;

	printf("a & b : %d\n", a & b);
	printf("a ^ b : %d\n", a ^ b);
	printf("a | b : %d\n", a | b);
	printf("~a : %d\n", ~a);
	printf("a << 1 : %d\n", a <<1);
	printf("a >> 2 : %d\n", a >>2);*/

	unsigned int num = 0b1010;
	printf("Initial value: %X\n", num);
	//printf(" (binary: %0b)", num);
	num = setBit(num, 2);
	printf("After setting bit %d: %X\n", 2, num);
	num = clearBit(num, 1);
	printf("After clearing bit %d: %X\n", 1, num);
	num = toggleBit(num, 3);
	printf("After toggling bit %d: %X\n", 3, num);

	num = 0b10101010;
	num = setBits(num, 2, 3);
	printf("After setting bit %d: %X\n", 2, num);
	num = clearBits(num, 4, 2);
	printf("After clearing bit %d: %X\n", 1, num);
	num = toggleBits(num, 1, 5);
	printf("After toggling bit %d: %X\n", 3, num);


	printf("Enter a number: ");
	unsigned int number;
	scanf_s("%d", &number);

	printf("Enter bit position to check (0~31): ");
	int bitPosition;
	scanf_s("%d", &bitPosition);

	unsigned int res = isBitSet(number, bitPosition);
	printf("Bit %d of number %u is %u.\n", bitPosition, number, res);


	return 0;
}

#endif

#if 0
int main(void)
{
	char x = 127;
	char y = x + 1;
	printf("x = %d, x+1 = %d, y = %d\n", x, x + 1, y);

	x = -128;
	y = x - 1;
	printf("x = %d, x-1 = %d, y = %d\n", x, x - 1, y);

	
	printf("%x\n", !10);
	printf("%x\n", ~10);
	printf("%x\n", ~(10<20));
	printf("%x\n", ~~(10<20));

	int a = 20;
	int b = 5;
	a += b * 3;
	printf("%d", a);
	return 0;
}
#endif

#if 0

int main(void)
{
	unsigned char a = 0xf0;
	char b = 0xf0;

	unsigned char c = 0x0f;
	char d = 0x0f;

	if (a > b) printf("A<B\n");
	else if (a < b) printf("A<B\n");
	else printf("A == B\n");

	if (c > d) printf("C > D\n");

	unsigned int a2 = 1;
	char b2 = -1;

	printf("%d\n", a2 < b2);
	printf("%d\n", sizeof(char));

	return 0;
}

#endif