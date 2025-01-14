#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define size_ary(x) (sizeof(x)/sizeof((x)[0]))

#if 0

struct student
{
	int id;
	int scores[3];
	char name[20];
};

struct student* input_data3(int, int);
void print_data3(struct student*, int, int);
void free_data(struct student* stu, int cnt);

int main(void)
{
	int arrSize, itemCnt;
	struct student* stu = { 0 };
	(void)freopen("student3.txt", "r", stdin);
	(void)scanf("%d %d", &arrSize, &itemCnt);
	stu = input_data3(arrSize, itemCnt);
	if (stu != NULL)
	{
		print_data3(stu, arrSize, itemCnt);
		free_data(&stu, itemCnt);
	}

	return 0;
}

struct student* input_data3(int size, int cnt)
{
	struct student temp = { 0 };
	struct student* stu = { 0 };
	stu = (struct student*)malloc(sizeof(struct student));

	if (stu == NULL)
	{
		printf("\n==Memory Failed==\n");
		exit(0);
	}

	for (int i = 0;i < size;++i)
	{
		temp = stu[i];
		(void)scanf("%d", &stu[i].id);
		for (int j = 0;j < cnt;++j)
		{
			(void)scanf("%d", &stu[i].scores[j]);
		}
		(void)scanf("%s", stu[i].name);
	}

	return stu;
}

void print_data3(struct student* stu, int size, int cnt)
{
	struct student* temp = 0;
	for (int i = 0; i < size; ++i)
	{	
		temp = stu + i;
		printf("id: %d, scores: %d %d %d, name: %s\n",
			temp->id,
			temp->scores[0],
			temp->scores[1],
			temp->scores[2],
			temp->name);
	}
}

void free_data(struct student** stu, int cnt)
{
	struct student* temp = *stu;
	for (int i = 0;i < cnt;++i)
	{
		if (temp[i].scores != NULL)
		{
			free(temp[i].scores);
		}		
	}
	free(temp);
	*stu = NULL;
}
#endif

#if 0 //구조체 배열 메모리 동적 하랃ㅇ, 파일 입력, 출력, 메모리 해제 - 강사님f 
// 구조체 배열 메모리 동적할당, 파일입력, 출력, 메모리 해제
#truct student {
	int num;
	int* scores;
	char name[20];
};
struct student* input_data3(int arySize, int itemCnt);
void print_data3(struct student* stu, int arySize, int itemCnt);
void free_data(struct student* stu, int itemCnt);

int main(void) {
	struct student* stu = { 0 };
	int arySize, itemCnt;
	(void)freopen("student2.txt", "r", stdin);
	(void)scanf("%d %d", &arySize, &itemCnt);
	stu = input_data3(arySize, itemCnt);
	if (stu != NULL) {
		print_data3(stu, arySize, itemCnt);
		free_data(stu, itemCnt);
		stu = NULL;
	}
	return 0;
}

struct student* input_data3(int arySize, int itemCnt) {
	struct student* stu = { 0 };
	struct student* temp = 0;
	int i, j;

	stu = (struct student*)malloc(arySize * sizeof(struct student));
	if (stu == NULL) {
		printf("Out of memory - 1\n");
		return NULL;
	}
	for (i = 0; i < arySize; ++i) {
		stu[i].scores = (int*)malloc(itemCnt * sizeof(int));
		if (stu[i].scores == NULL) {
			printf("Out of memory - 2\n");
			free_data(stu, i);
			return NULL;
		}
	}

	for (i = 0; i < arySize; ++i) {
		temp = stu + i;
		(void)scanf("%d", &temp->num);
		for (j = 0; j < itemCnt; ++j) {
			(void)scanf("%d", &temp->scores[j]);
		}
		(void)scanf("%s", temp->name);
	}

	return stu;
}

void print_data3(struct student* stu, int arySize, int itemCnt) {
	int i, j;
	struct student* temp = 0;
	for (i = 0; i < arySize; ++i) {
		temp = stu + i;
		printf("%d ", temp->num);
		for (j = 0; j < itemCnt; ++j) {
			printf("%d ", temp->scores[j]);
		}
		printf("%s\n", temp->name);
	}
}

void free_data(struct student* stu, int itemCnt) {
	int i;
	for (i = 0; i < itemCnt; ++i) {
		free(stu[i].scores);
	}
	free(stu);
}
#endif

#if 0
struct bitF1
{
	unsigned a : 3;
	unsigned b : 3;
	unsigned c : 3;
};

struct bitF3
{
	unsigned a : 8;
	unsigned b : 8;
	unsigned c : 8;
	unsigned d : 8;
};

int main(void)
{
	struct bitF1 x;
	x.a = 7;
	x.b = 1;
	x.c = 5;
	printf("%d %d %d\n", x.a, x.b, x.c);

	return 0;
}

#endif

#if 0
#include <stdint.h>

typedef struct _TCP
{
	uint16_t Source_Port;
	uint16_t Destination_Port;
	uint32_t Sequence_Number;
	uint32_t ACK_Number;
	uint8_t Offset : 4;
	uint8_t Reserved : 4;
	uint8_t TCP_Flags_C : 1;
	uint8_t TCP_Flags_E : 1;
	uint8_t TCP_Flags_U : 1;
	uint8_t TCP_Flags_A : 1;
	uint8_t TCP_Flags_P : 1;
	uint8_t TCP_Flags_R : 1;
	uint8_t TCP_Flags_S : 1;
	uint8_t TCP_Flags_F : 1;
	uint16_t Window;
	uint16_t Checksum;
	uint16_t Urgent_Pointer;
	uint32_t TCP_Options;
}TCP_Header;

typedef struct _IP
{
	uint16_t Version : 4;
	uint16_t IHL : 4;
	uint16_t TOS : 8;
	uint16_t Total_Length;
	uint16_t identification;
	uint16_t IP_Flags_x : 1;
	uint16_t IP_Flags_D : 1;
	uint16_t IP_Flags_M : 1;
	uint16_t Fragment_Offset : 13;
	uint8_t TTL : 8;
	uint8_t Protocol : 8;
	uint32_t Source_Address;
	uint32_t Destination_Address;
	uint32_t IP_Option;
}IP_Header;

struct bit
{
	unsigned a : 3;
	unsigned b : 3;
	unsigned c : 3;
}x;

int main(void)
{
	x.a = 7;
	x.b = 1;
	x.c = 5;
	printf("%x\n", *((char*)(&x) + 1));
	return 0;
}
#endif

#if 0
typedef struct _node
{
	int value;
	struct _node* prev;
	struct _node* next;
}node;

int main(void)
{
	node a = { 10 }, b = { 20 }, c = { 30 };
	node* head = &a;
	node* tail = &c;
	a.next = &b;
	b.next = &c;
	c.prev = &b;
	b.prev = &a;	

	printf("%d %d %d\n", a.value, a.next->value, a.next->next->value);
	printf("%d %d %d\n", b.prev->value, b.value, b.next->value);
	printf("%d %d %d\n", c.prev->prev->value, c.prev->value, c.value);

	for (node* curr = head;curr != NULL;curr = curr->next)
	{
		printf("%d ", curr->value);
	}

	printf("\n");

	for (node* curr = tail;curr != NULL;curr = curr->prev)
	{
		printf("%d ", curr->value);
	}
	return 0;
}
#endif

#if 0 //공용체
typedef struct trgb
{
	unsigned short blue : 5;
	unsigned short green : 6;
	unsigned short red : 5;
}tRGB;

typedef union pixelcolor
{
	tRGB rgb;
	unsigned short color;
}tPColor;

int main(void)
{
	tRGB a;
	tPColor dot1 = { 0 }, dot2 = { 0 };
	dot1.color = 0x1234;	// (메모리) |00110100|00010010| (개념 15 ~ 0 bit) 00010|010001|10100
	dot2.color = 100;		//			|01100100|00000000|					  00000|000011|00100
	
	printf("dot1 rgb 주소: %x %x %x\n", dot1.rgb.red, dot1.rgb.green, dot1.rgb.blue);		// 2 11 14
	printf("dot1 rgb 값: %2d %2d %2d\n", dot1.rgb.red, dot1.rgb.green, dot1.rgb.blue);
	
	printf("dot2 rgb 주소: %x %x %x\n", dot2.rgb.red, dot2.rgb.green, dot2.rgb.blue);		// 0 3 4
	printf("dot2 rgb 값: %2d %2d %2d\n", dot2.rgb.red, dot2.rgb.green, dot2.rgb.blue);	
	
	dot1.rgb.blue = 25; // 00010|010001|11001
	printf("dot1 blue 주소: %x %x %x\n", dot1.rgb.red, dot1.rgb.green, dot1.rgb.blue);

	printf("tRGB 크기: %d, tPColor 크기: %d\n", sizeof(tRGB), sizeof(tPColor));
	printf("%#x\n", dot1.color);
	printf("%d %#x\n", dot2.color, dot2.color);	

	dot1.rgb.red = 13;
	dot1.rgb.green = 20;
	dot1.rgb.blue = 25;

	printf("%2d %2d %2d\n", dot1.rgb.red, dot1.rgb.green, dot1.rgb.blue);
	printf("%#x\n", dot1.color);

	return 0;
}
#endif

#if 0 //typedef 연습 1

int comp_str_asc(const void* a, const void* b);
int comp_str_desc(const void* a, const void* b);

typedef int (*int4ap_t)[4];
typedef int(*comp_t)(const void*, const void*);

int(*func2(int num))(const void*, const void*)
{
	int(*p[2])(const void*, const void*, const void*) = { comp_str_asc, comp_str_desc };
	return p[num];
}

comp_t fun2_(int num)
{
	comp_t p[2] = { comp_str_asc, comp_str_desc };
	return p[num];
}

int4ap_t func(void)
{
	static int arr[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	return arr;
}

void print_ary(int(*p)[4], int row)
{
	int i;
	int* arr = (int*)p - 1;
	int size = sizeof(*p) / sizeof(**p) * row;
	printf("Size = %d\n", size);
	for (i = 0;i < size;++i)
	{
		printf("%d ", *++arr);
	}
	printf("\n");
}

int main(void)
{
	int(*p)[4] = 0;
	char* arr[3] = { "cat", "dog", "rabbit" };
	p = func();
	print_ary(p, 3);
	printf("%d\n", func2(0)(&arr[1], &arr[0]));
	return 0;
}

int comp_str_asc(const void* a, const void* b)
{
	char* a1 = *(char**)a;
	char* b1 = *(char**)b;
	return strcmp(a1, b1);
}

int comp_str_desc(const void* a, const void* b)
{
	char* a1 = *(char**)a;
	char* b1 = *(char**)b;
	return strcmp(b1, a1);
}
#endif

#if 0
#include "my_arylib.h"

//int sum(int a, int b)
//{
//	return a + b;
//}s
//	
//void print_ary(int* arr, int size)
//{
//	int i;
//	for (i = 0;i < size;++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}

//int main(void)
//{
//	void* parr[] = { sum, print_ary };
//	// ((int(*)(int, int))parr[0])(10, 20)
//	//printf("%d ", ((int(*)(int, int))parr[0])(10, 20));
//	printf("%d ", ((calc_t)parr[0])(10, 20));
//
//	return 0;
//}
typedef


int main(void) {
	int ary[5];
	int size = sizeof(ary) / sizeof(*ary);
	int op = 0;
	void* ary_funcs[] = { 0, print_ary, sort_ary, findmax_ary, findmin_ary, sum_ary, avg_ary, var_ary, var_ary };
	void* func = 0;
	scanf_ary(ary);
	while (1) {
		print_menu();
		(void)scanf("%d", &op);
		if (op == 0)
			break; // break 뒤 else if는 의미가 없다.
		func = ary_funcs[op];
		if (0 < op && op < 6)
			printf("res: %d\n", ((int(*)(int*, int)func)(ary, size));
		else if (op == 6) {
			printf("res: %lf\n", ((double(*)(int*, int))func)(ary, size));
		}
		else if (op == 7 || op == 8) {
			printf("res: %lf\n", ((double(*)(int*, int, int))func)(ary, size, op - 7));
		}
		else {
			printf("Error: wrong instruction\n");
		}
	}
	printf("Thank you *^-^*\n");

	return 0;
}
#endif

// typedef 연습 3 (함수 포인터 배열 호출)
#if 0
#include "my_arylib.h"
typedef int (*aryop1_t)(int*, int);
typedef double (*aryop2_t)(int*, int);
typedef double (*aryop3_t)(int*, int, int);
enum { AVG = 6, VAR1, VAR2 };
int main(void) {
	int ary[5];
	int size = sizeof(ary) / sizeof(*ary);
	int op = 0;
	void* ary_funcs[] = { 0,
		print_ary, sort_ary, findmax_ary, findmin_ary, sum_ary,
		avg_ary, var_ary, var_ary };
	void* func = 0;
	char temp[1000];
	scanf_ary(ary);
	while (1) {
		print_menu();
		(void)scanf("%d", &op);
		if (op <= 0 || op > 8) {
			if (op != 0) {
				printf("Error: wrong instruction\n");
			}
			break; // break 뒤 else if는 의미가 없다.
		}
		func = ary_funcs[op];
		switch (op) {
		case AVG:
			//printf("res: %lf\n", ((aryop2_t)func)(ary, size));
			sprintf(temp, "res: %lf\n", ((aryop2_t)func)(ary, size));
			break;
		case VAR1:
		case VAR2:
			//printf("res: %lf\n", ((aryop3_t)func)(ary, size, op - 7));
			sprintf(temp, "res: %lf\n", ((aryop3_t)func)(ary, size, op - 7));
			break;
		default:
			//printf("res: %d\n", ((aryop1_t)func)(ary, size));
			sprintf(temp, "res: %d\n", ((aryop1_t)func)(ary, size));
			break;
		}
		printf(temp);
	}
	printf("Thank you *^-^*\n");
	return 0;
}


#endif

#if 0 //19-07번 1번

int main(void)
{
	int a;
	int arr[5] = { 1,2,3,4,5 };
	a = (int)arr;
	printf("%d\n", *((int*)a + 2));
	printf("%d\n", ((int*)a)[2]);
}
#endif

#if 0
typedef int(*F4)[4];
int main(void)
{
	int score[3][4] = { 11,10,9,8,7,6,5,4,3,2,1,0 };
	int x;
	F4 sp;
	F4 sa[5];
	F4* sd;
	sd = (F4*)malloc(sizeof(F4) * 5);
	x = (int)score;
	sp = (F4)x;

	printf("%d ", *((int*)x) + 1);
	printf("%d ", *((int*)x + 5));
	printf("%d\n", sp[2][2]);
	printf("%d\n", *((int*)sp + 10));

	return 0;
}
#endif

#if 0

#define TC

#ifdef TC
	#include <conio.h>
	#define MAX_INT 32767
#else
	#define MAX_INT 2147483647
#endif

#endif

#if 0

#define ALPHA 1

#if ALPHA
int main(void)
{

}
#endif

#endif

#if 0

#include "myheader.h"
#include "myheader.h"
#include "wrong.h"
#include "wrong.h"

int main(void)
{
	b = 2000; //초기화되지 않은 것에 대해서는 여러번 읽어도 괜찮, 초기화 시킨 순간에는 오류 발생
	printf("%d\n", a);
	printf("%d\n", b);
	return 0;
}

#endif

#if 0

#define SOUND_DEVICE_TYPE 01

int main(void)
{
#if !SOUND_DEVICE_TYPE
	printf("사운드 장치를 사용하지 않음\n");
#else
#error CODE 10 : Unknown Device!
#endif
	printf("사운드 모드 = %d\n", SOUND_DEVICE_TYPE);
}

#endif

#if 0

#define SWAP(temp, a, b){\
temp = a;\
a = b;\
b = temp;\
}
#define Assert(x) {\
	if ((x) >= 4)printf("Range error: %s, %d\n", __FILE__, __LINE__);\
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