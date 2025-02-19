#include <stdio.h>
#include <string.h>  // strlen
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

// 구조체 배열 메모리 동적할당, 파일입력, 출력, 메모리 해제
#if 0
struct student {
	int num;
	int * scores;
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

// 비트필드 구조체
#if 0

typedef struct {
	unsigned int blue : 8;
	unsigned int green : 8;
	unsigned int red : 8;
	unsigned int red2 : 8;
	unsigned int red3: 8;
}color1;

int main(void) {
	color1 a;
	a.blue = 255;
	a.green = 2;
	a.red = 3;
	printf("%d %d %d\n", a.blue, a.green, a.red);
	printf("%d\n", sizeof(color1));
	return 0;
}

#endif

// 메모리에 저장되는 방식 확인
#if 0

int main(void) {
	int a = 0x12345678;
	char b = a;  // 78
	short c = a; // 5678
	printf("%x %x %x\n", a, b, c);
	return 0;
}
#endif

// 비트필드 구조체의 대입연산, 메모리 사용확인
#if 0

struct bitF1 {
	unsigned int a : 3;
	unsigned int b : 3;
	unsigned int c : 3;
};
/*
x.a = 7; 
0013576B  mov         eax,dword ptr [x]
0013576E  or          eax,7
00135771  mov         dword ptr [x], eax
x.b = 1;
005B5774  mov         eax,dword ptr [x]
005B5777  and         eax,0FFFFFFC7h
005B577A  or          eax,8
005B577D  mov         dword ptr [x],eax
*/
int main(void) {
	struct bitF1 x = { 0 };
	x.a = 7;
	x.b = 1;
	x.c = 5;
	printf("%d %d %d\n", x.a, x.b, x.c);
	printf("%x\n", *(char*)&x);  // 4f
	printf("%x\n", *((char*)&x + 1));  // 1
	return 0;
}

#endif

// 자기참조구조체
#if 0
typedef struct _node {
	int value;
	struct _node* prev;
	struct _node* next;	
}node;

int main(void) {
	node a = { 10 }, b = { 20 }, c = { 30 };
	node* head = &a;
	node* tail = &c;
	a.next = &b;
	b.next = &c;
	c.prev = &b;
	b.prev = &a;

	for (node* curr = head; curr != NULL; curr = curr->next) {
		printf("%d ", curr->value);
	}
	printf("\n");

	for (node* curr = tail; curr != NULL; curr = curr->prev) {
		printf("%d ", curr->value);
	}
	printf("\n");

	printf("%d %d %d\n", a.value, a.next->value, a.next->next->value);
	printf("%d %d %d\n", b.prev->value, b.value, b.next->value);
	printf("%d %d %d\n", c.prev->prev->value, c.prev->value, c.value);
	return 0;
}
#endif

// 공용체(union)
#if 0

typedef struct _rgb {
	unsigned short blue : 5;
	unsigned short green : 6;
	unsigned short red : 5;
}tRGB;

typedef union _tcolor {
	tRGB rgb;
	unsigned short color;
}tPColor;

int main(void) {
	tRGB a;
	tPColor dot1 = { 0 }, dot2 = { 0 };
	                      // bit번호   76543210 FEDCBA98                   FEDCBA9876543210
	dot1.color = 0x1234;  // (메모리) |00110100|00010010| (개념 15 ~ 0bit) 0001001000110100
	dot2.color = 100;     //          |01100100|00000000|                  0000000001100100
	printf("%x %x %x\n", dot1.rgb.red, dot1.rgb.green, dot1.rgb.blue);  // 2 11 14
	printf("%x %x %x\n", dot2.rgb.red, dot2.rgb.green, dot2.rgb.blue);  // 0 3 4
	dot1.rgb.blue = 12;  // 0001 0010 0010 1100
	printf("%x\n", dot1.color);
	printf("%d %d\n", sizeof(tRGB), sizeof(tPColor));
	return 0;
}

#endif

// 가독성, 유지보수성 높이기
// typedef 연습 1
#if 0
int comp_str_asc(const void* a, const void* b);
int comp_str_desc(const void* a, const void* b);

typedef int (*int4ap_t)[4];
typedef int (*comp_t)(const void*, const void*);

/*
int (* func2(int num))(const void*, const void*) {
	int (*p[2])(const void*, const void*) = { comp_str_asc, comp_str_desc };
	return p[num];
}
*/
comp_t func2(int num) {
	comp_t p[2] = { comp_str_asc, comp_str_desc };
	return p[num];
}

//int (*func(void))[4] {
int4ap_t func(void) {
	static int arr[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	return arr;
}

//void print_ary(int (*p)[4], int row) {
void print_ary(int4ap_t p, int row){
	int i;
	int* arr = (int*)p -1;
	int size = sizeof(*p) / sizeof(**p) * row;
	printf("size=%d\n", size);
	for (i = 0; i < size; ++i) {
		printf("%d ", *++arr);
	}
	printf("\n");
}
int main(void) {
	int (*p)[4] = 0;
	char* arr[3] = { "cat", "dog", "rabbit" };
	p = func();
	print_ary(p, 3);
	printf("%d\n", func2(0)(&arr[1], &arr[0]));
	return 0;
}


int comp_str_asc(const void* a, const void* b) {
	char* a1 = *(char**)a;
	char* b1 = *(char**)b;
	return strcmp(a1, b1);
}

int comp_str_desc(const void* a, const void* b) {
	char* a1 = *(char**)a;
	char* b1 = *(char**)b;
	return strcmp(b1, a1);
}

#endif

// typedef 연습 2
#if 0
typedef int (*calc_t)(int, int);

int sum(int a, int b) {
	return a + b;
}
void print_ary(int* arr, int size) {
	int i;
	for (i = 0; i < size; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main(void) {
	void* parr[] = { sum, print_ary };
	int result = 0;
	result = ((calc_t)parr[0])(10, 20);
	printf("%d\n", result);

	return 0;
}
#endif

// typedef 연습 3 (함수 포인터 배열 호출)
#if 0
#include "my_arylib.h"
typedef int (*aryop1_t)(int*, int);
typedef double (*aryop2_t)(int*, int);
typedef double (*aryop3_t)(int*, int, int);
enum {AVG=6, VAR1, VAR2};

int main(void) {
	int ary[5];
	int size = sizeof(ary) / sizeof(*ary);
	int op = 0;
	void* ary_funcs[] = { 0, 
		print_ary, sort_ary, findmax_ary, findmin_ary, sum_ary,
	    avg_ary, var_ary, var_ary};
	void* func = 0;
	char temp[20] = { 0 };

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
				sprintf(temp, "res: %lf\n", ((aryop3_t)func)(ary, size, op - 7));
				break;
			default:
				sprintf(temp, "res: %d\n", ((aryop1_t)func)(ary, size));
				break;
		}
		printf(temp);
	}
	printf("Thank you *^-^*\n");
	return 0;
}


#endif


#if 0
int main(void) {
	int a;
	int arr[5] = { 1, 2, 3, 4, 5 };
	a = (int)arr;
	printf("%d\n", *((int*)a + 2));
	printf("%d\n", ((int*)a)[2]);
	return 0;
}
#endif

#if 0
typedef int (*F4)[4];

int main(void) {
	int score[3][4] = { 11,10,9,8,7,6,5,4,3,2,1,0 };
	int x;
	F4 sp;
	F4 sa[5];
	F4* sd;
	sd = (F4*)malloc(sizeof(F4) * 5);
	x = (int)score;
	sp = (F4)x;

	printf("%d ", *(int*)x + 1);  // x를 사용해 12출력
	printf("%d ", *((int*)x + 5));  // x를 사용해 6출력
	printf("%d\n", *((int*)sp + 10));  // sp를 사용해 1출력
	return 0;
}
#endif

#if 0
#define TC
#undef TC

#ifdef TC
#include <conio.h>
#define MAX_INT 32767
#else
#define MAX_INT 2147483647
#endif

#endif

#if 0
#define ALPHA 0

#if ALPHA
int main(void) {

}
#endif
#endif

#if 0

#include "myheader.h"  // #ifndef 사용
#include "myheader.h"
#include "myheader.h"
#include "wrong.h"  // 변수의 초기화 하지 않음
#include "wrong.h"

int main(void) {
	b = 2000;
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	return 0;
}
#endif


#if 0

#define SOUND_DEVICE_TYPE 0

int main(void) {
#if !SOUND_DEVICE_TYPE
	printf("사운드 장치를 사용하지 않음\n");
#else
#error CODE 10 : Unknown Device!
#endif
	printf("사운드 모드= %d\n", SOUND_DEVICE_TYPE);
	return 0;
}
#endif


#if 0
#define SWAP(temp, a, b){temp = a; a = b; b = temp;}
#define Assert(x) {\
	if((x) >= 4) printf("Range error : %s, %s, %d\n", __FILE__, __FUNCTION__, __LINE__);\
}

int main(void) {
	int a[4] = { 10, 20, 30, 40 };
	int i;
	for (i = 0; i <= 4; ++i) {
#line 200
		Assert(i);
		printf("a[%d] = %d\n", i, a[i]);
	}
}
#endif


#if 0
#define A(x) A##x

int main(void) {
	int A1 = 5, A2 = 10;
	int Aa = 20;
	int i = 1;
	printf("%d\n", A(1) + A(2)+ A(a));
	//printf("%d\n", A(i));  // 전처리에서 Ai 로 치환됨
	return 0;
}
#endif

#if 0

#define string(x) printf(#x" is %d\n", x)
#define charr(x) printf("%c is %c\n", #@x, x)
#define concat(x, i) printf("c%s is %d\n", #i, x##i)

int main(void) {
	int s = 10, c = 97, ca = 7, cb = 9;
	//string(ca);  // printf("ca""is %d\n", ca);  // 변수명 + 값을 출력
	//charr(c);    // printf("%c is %c\n", 'c', c)  // char가 필요시 사용
	concat(c, a);  // printf("c%s is %d\n", "a", ca)
	concat(c, b);
	return 0;
}

#endif

#if 0
#define NDEBUG
#include <assert.h>

int main() {
	int x;
	printf("\nEnter an integer value: ");
	(void)scanf("%d", &x);
	assert(x >= 0);
	printf("You entered %d.", x);
	return 0;
}
#endif

//----------------------------

#if 0

#include "point.h"
#include "line.h"

#include "a.h"
extern void print_b(void);
extern int a;
static int x = 10;
int count = 100;

int main(void) {
	printf("Hello!\n");
	printf("main x : %d\n", x);
	printf("main count : %d\n", count);
	++a;
	print_a();
	print_count();
	return 0;
}
#endif


