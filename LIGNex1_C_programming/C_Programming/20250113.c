#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

#if 0
int sum(int x, int y)
{
	return x + y;
}

int sub(int x, int y)
{
	return x - y;
}

int mul(int x, int y)
{
	return x * y;
}

int div(int x, int y)
{
	return x / y;
}

int mod(int x, int y)
{
	return x % y;
}

int main(void)
{
	int a, b;
	(void)scanf_s("%d %d", &a, &b);

	int(*my_func[5])(int, int) = { sum, sub, mul, div, mod };
	int results[6] = { 0 };

	for (int i = 0;i < 5;++i)
	{
		results[i] = my_func[i](a, b);
		results[5] += results[i];
		printf("각각의 result: %d \n", results[i]);
	}
	printf("total result: %d \n", results[5]);

	return 0;
}
#endif

#if 0 //구조체 사용 01 버전
int sum(int x, int y)
{
	return x + y;
}

int sub(int x, int y)
{
	return x - y;
}

int mul(int x, int y)
{
	return x * y;
}

int div(int x, int y)
{
	return x / y;
}

int mod(int x, int y)
{
	return x % y;
}

struct funcs {
	const char* const op_n;
	int (* const op)(int, int);
	int res;
};

int main(void)
{
	int a, b;
	(void)scanf_s("%d %d", &a, &b);

	struct funcs funcs_arr[] = {
		{"sum", sum, 0},
		{"sub", sub, 0},
		{"mul", mul, 0},
		{"div", div, 0},
		{"mod", mod, 0},
	};
	
	int total = 0;
	printf("%d %d\n", sizeof(funcs_arr), sizeof(funcs_arr[0]));

	struct funcs *temp;

	for (int i = 0;i < sizeof(funcs_arr) / sizeof(funcs_arr[0]);++i)
	{
		temp = funcs_arr + i;
		temp->res = temp->op(a, b);
		funcs_arr[i].res = funcs_arr[i].op(a, b);
		total += funcs_arr[i].res;
		printf("%s: %d\n", funcs_arr[i].op_n, funcs_arr[i].res);
	}
	printf("total result: %d \n", total);

	return 0;
}
#endif

#if 0 //구조체 사용 02 버전 - 단순 복사
int sum(int x, int y)
{
	return x + y;
}

int sub(int x, int y)
{
	return x - y;
}

int mul(int x, int y)
{
	return x * y;
}

int div(int x, int y)
{
	return x / y;
}

int mod(int x, int y)
{
	return x % y;
}

struct funcs {
	const char* const op_n;
	int (* const op)(int, int);
	int res;
};

int main(void)
{
	int a, b;
	(void)scanf_s("%d %d", &a, &b);

	struct funcs funcs_arr[] = {
		{"sum", sum, 0},
		{"sub", sub, 0},
		{"mul", mul, 0},
		{"div", div, 0},
		{"mod", mod, 0},
	};

	int total = 0;
	printf("%d %d\n", sizeof(funcs_arr), sizeof(funcs_arr[0]));

	struct funcs temp;

	for (int i = 0;i < sizeof(funcs_arr) / sizeof(funcs_arr[0]);++i)
	{
		temp = funcs_arr[i];
		temp.res = temp.op(a, b);
		printf("%s: %d\n", temp.op_n, temp.res);
		total += temp.res;
	}
	printf("total result: %d \n", total);

	return 0;
}
#endif

#if 0 //구조체 사용 03 버전 call - by - reference
int sum(int x, int y)
{
	return x + y;
}

int sub(int x, int y)
{
	return x - y;
}

int mul(int x, int y)
{
	return x * y;
}

int div(int x, int y)
{
	return x / y;
}

int mod(int x, int y)
{
	return x % y;
}

struct funcs {
	const char* const op_n;
	int (* const op)(int, int);
	int res;
};

int main(void)
{
	int a, b;
	(void)scanf_s("%d %d", &a, &b);

	struct funcs funcs_arr[] = {
		{"sum", sum, 0},
		{"sub", sub, 0},
		{"mul", mul, 0},
		{"div", div, 0},
		{"mod", mod, 0},
	};

	int total = 0;
	printf("%d %d\n", sizeof(funcs_arr), sizeof(funcs_arr[0]));

	struct funcs* temp;

	for (int i = 0;i < sizeof(funcs_arr) / sizeof(funcs_arr[0]);++i)
	{
		temp = funcs_arr + i;
		temp->res = temp->op(a, b);
		printf("%s: %d\n", temp->op_n, temp->res);
		total += temp->res;
	}
	printf("total result: %d \n", total);

	return 0;
}
#endif

#if 0 //구조체 사용 04 버전
struct result {
	int value;
	char* name;
};

struct result sum(int x, int y) {
	struct result a = { x + y, __func__ };
	return a;
}
struct result sub(int x, int y) {
	struct result a = { x - y, __func__ };
	return a;
}
struct result mul(int x, int y) {
	struct result a = { x * y, __func__ };
	return a;
}
struct result divi(int x, int y) {
	struct result a = { x / y, __func__ };
	return a;
}
struct result mod(int x, int y) {
	struct result a = { x % y, __func__ };
	return a;
}

int main() {
	struct result(*func[])(int, int) = { sum, sub, mul, divi, mod };
	int x = 10, y = 20, sum = 0, i;
	//struct result temp;
	for (i = 0; i < sizeof(func) / sizeof(func[0]); ++i) {
		//temp = func[i](x, y);
		//printf("%s : %d \n", temp.name, temp.value);
		printf("%s : %d \n", func[i](x, y).name, func[i](x, y).value);
		//sum += temp.value;
		sum += func[i](x, y).value;
	}
	printf("tot : %d", sum);
	return 0;
}
#endif

#if 0 // 정렬프로그램  - 원본
void print_ary(int* arr, int size);
//void sort_ary(int* arr, int size);
void sort_ary(int* arr, int size, int(*comp)(int, int));
void sort_ary2(int* arr, int size, int reverse);
int comp_asc(int a, int b);
int comp_desc(int a, int b);
#define size_ary(x) sizeof(x)/sizeof((x)[0]) // x보다는 (x)로 묶는게 더 좋음

enum { ASC, DESC };

int main(void) {
	int a = 0;
	int ary[] = { 8, 5, 2, 12, 7, 9, 4, 6, 10, 3 };

	print_ary(ary, size_ary(ary));
	//sort_ary(ary, size_ary(ary), comp_asc);
	sort_ary2(ary, size_ary(ary), DESC);
	print_ary(ary, size_ary(ary));

	return 0;
}

void print_ary(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//void sort_ary(int* arr, int size) {
void sort_ary(int* arr, int size, int(*comp)(int, int)) {
	int tmp;

	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			//if (arr[i] < arr[j]) {
			if (comp(arr[i], arr[j])) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

void sort_ary2(int* arr, int size, int reverse) {
	int tmp;
	int (*comp)(int, int);
	comp = reverse ? comp_desc : comp_asc; // reverse == 0(오름차순), == 1(내림차순)

	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (comp(arr[i], arr[j])) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

int comp_asc(int a, int b)
{
	return a > b;
}

int comp_desc(int a, int b)
{
	return a < b;
}
#endif

#if 0 //함수 포인터 변수에 전달할 함수 생성 - qsort -> 정수 배열
#define size_ary(x) (sizeof(x)/sizeof((x)[0]))

void print_ary(int* arr, int n);
int comp_int_asc(const void* a, const void* b);
int comp_int_desc(const void* a, const void* b);

int main(void)
{
	int arr[] = { 3,5,2,6,1,9,4 };
	print_ary(arr, size_ary(arr));
	qsort(arr, size_ary(arr), sizeof(arr[0]), comp_int_desc);
	print_ary(arr, size_ary(arr));

	return 0;
}

void print_ary(int* arr, int n)
{
	int i;
	for (i = 0;i < n;i++)
	{
		printf("%5d ", arr[i]);
	}
	printf("\n");
}

//오름차순
int comp_int_asc(const void* a, const void* b)
{
	//0 교환 x , -1, 1 각각의 경우
	/*if (*(int*)a > *(int*)b) 
	{
		return 1;
	}
	else if (*(int*)a == *(int*)b)
	{
		return 0;
	}
	else 
	{
		return -1;
	}*/
	return *(int*)a - *(int*)b;
}

int comp_int_desc(const void* a, const void* b)
{
	return *(int*)b - *(int*)a;
}
#endif

#if 0 //함수 포인터 변수에 전달할 함수 생성 - qsort -> 실수 배열
#define size_ary(x) (sizeof(x)/sizeof((x)[0]))

void print_ary(double* arr, int n);
int comp_double_asc(const void* a, const void* b);
int comp_double_desc(const void* a, const void* b);

int main(void)
{
	double arr[] = { 3.1,5.1,2.1,6.1,1.1,9.1,4.1,1.2,5.2,4.0 };
	print_ary(arr, size_ary(arr));
	qsort(arr, size_ary(arr), sizeof(arr[0]), comp_double_desc);
	print_ary(arr, size_ary(arr));

	return 0;
}

void print_ary(double* arr, int n)
{
	int i;
	for (i = 0;i < n;i++)
	{
		printf("%.2lf ", arr[i]);
	}
	printf("\n");
}

//오름차순
int comp_double_asc(const void* a, const void* b)
{
	//return (*(double*)a - *(double*)b) + 1;
	return (*(double*)a > *(double*)b) ? 1 : (*(double*)a < *(double*)b) ? -1 : 0;
}

int comp_double_desc(const void* a, const void* b)
{
	//return (*(double*)a - *(double*)b) > 0.0 ? 1 : *(double*)a == *(double*)b ? 0 : -1;
	return (*(double*)a > *(double*)b) ? -1 : (*(double*)a < *(double*)b) ? 1 : 0;

}
#endif

#if 0
#include <string.h>
#define size_ary(x) (sizeof(x)/sizeof((x)[0]))

void print_ary(char** arr, int n);
int comp_char_asc(const void* a, const void* b);
int comp_char_desc(const void* a, const void* b);

int main(void)
{
	char* arr[] = { "rabbit", "lion", "tiger", "elephant" };
	print_ary(arr, size_ary(arr));
	qsort(arr, size_ary(arr), sizeof(arr[0]), comp_char_desc);
	print_ary(arr, size_ary(arr));

	return 0;
}

void print_ary(char** arr, int n)
{
	int i;
	for (i = 0;i < n;i++)
	{
		printf("%s ", arr[i]);
	}
	printf("\n");
}

//오름차순
int comp_char_asc(const void* a, const void* b)
{
	return strcmp(*(char**)a, *(char**)b);
}

int comp_char_desc(const void* a, const void* b)
{
	return strcmp(*(char**)b, *(char**)a);
}
#endif

// int, double 배열 메모리 동적할당 - 입력, 출력
#if 0
#include <stdlib.h>

// (정수 N개를 저장할 공간을 할당 받아 그 공간에 입력 받고), 출력, 메모리 반환

int* input_data(int N) {
	int* temp = 0;
	int i;
	temp = (int*)malloc(N * sizeof(int));
	if (temp == NULL) {
		return NULL;
	}
	for (i = 0; i < N; i++) {
		(void)scanf("%d", temp + i);
	}
	return temp;
}
void print_data(int* data, int N) {
	int i;
	for (i = 0; i < N; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
}
int main(void) {
	int* pi = 0;
	int loopCnt, N;

	(void)freopen("numbers2.txt", "r", stdin);
	(void)scanf("%d", &loopCnt);
	for (int i = 0; i < loopCnt; i++) {
		(void)scanf("%d", &N);
		pi = input_data(N);
		if (pi == NULL) {
			printf("메모리 부족");
			exit(1);
		}
		print_data(pi, N);
		free(pi);
		pi = NULL;
	}
	return 0;
}

// (정수 N개를 저장할 공간을 할당 받아 그 공간에 입력 받고), 출력, 메모리 반환

int* input_data(int N) {
	int* temp = 0;
	int i;
	temp = (int*)malloc(N * sizeof(int));
	if (temp == NULL) {
		return NULL;
	}
	for (i = 0; i < N; i++) {
		(void)scanf("%d", temp + i);
	}
	return temp;
}
void print_data(int* data, int N) {
	int i;
	for (i = 0; i < N; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
}
int main(void) {
	int* pi = 0;
	int loopCnt, N;

	(void)freopen("number2.txt", "r", stdin);
	(void)scanf("%d", &loopCnt);
	for (int i = 0; i < loopCnt; i++) {
		(void)scanf("%d", &N);
		pi = input_data(N);
		if (pi == NULL) {
			printf("메모리 부족");
			exit(1);
		}
		print_data(pi, N);
		free(pi);
		pi = NULL; //NULL을 넣으면 멈춤. 이런 습관 중요
		printf("%d\n", pi[0]); //free 후 접근하면? => 쓰레기값. 이러면 안됨
		free(pi);// free 2번 하면 error
		//pi = NULL;
	}
	return 0;
}
#endif

#if 0
// int, double 배열 메모리 동적할당 - 입력, 출력
#include <stdlib.h>

// (정수 N개를 저장할 공간을 할당 받아 그 공간에 입력 받고), 출력, 메모리 반환

int(* input_data(int N))[4] {
	int(*temp)[4] = 0;
	int i;
	temp = (int(*)[4])malloc(N * sizeof(int[4]));
	//temp = (int(*)[4])malloc(N * 4 * sizeof(int[4])); //단순한 방법
	if (temp == NULL) {
		return NULL;
	}
	//for (i = 0; i < N * 4; i++) {
	//	//(void)scanf("%d", temp + i);
	//	(void)scanf("%d", (int*)temp + i); // temp + i로 하면 16씩 커지기 때문에 형 변환 필요
	//}

	/* 2차원으로 받기 */
	for (i = 0; i < N; ++i) 
	{		
		for (int j = 0;j < 4;++j)
		{
			//(void)scanf("%d", temp + i);
			(void)scanf("%d", temp[i] + i);
		}		
	}

	return temp;
}
void print_data(int (*data)[4], int N) {
	int i;
	for (i = 0; i < N; i++) {
		printf("%d ", ((int*)data)[i]);
	}
	printf("\n");
}
int main(void) {
	int (*pi)[4] = 0;
	int loopCnt, N;

	(void)freopen("number3.txt", "r", stdin);
	(void)scanf("%d", &loopCnt);
	for (int i = 0; i < loopCnt; i++) {
		(void)scanf("%d", &N);
		pi = input_data(N);
		if (pi == NULL) {
			printf("메모리 부족");
			exit(1);
		}
		print_data(pi, N);
		free(pi);
		pi = NULL;
	}
	return 0;
}
#endif

// int(*)[4]
// 강사님 코드
#if 0
// (정수 N개를 저장할 공간을 할당 받아 그 공간에 입력 받고), 출력, 메모리 반환

int (*input_data(int N))[4] {
	int (*temp)[4] = 0;
	int i, j;

	//temp = (int(*)[4])malloc(N * 4 * sizeof(int));
	temp = (int(*)[4])malloc(N * sizeof(int[4]));
	if (temp == NULL) {
		return NULL;
	}
	for (i = 0; i < N; ++i) {
		for (j = 0; j < 4; ++j) {
			(void)scanf("%d", temp[i] + j);
		}
	}
	return temp;
}
void print_data(int(*data)[4], int N) {
	int i;
	for (i = 0; i < N * 4; i++) {
		printf("%d ", ((int*)data)[i]);
	}
	printf("\n");
}
int main(void) {
	int (*pi)[4] = 0;
	int loopCnt, N;

	(void)freopen("numbers2.txt", "r", stdin);
	(void)scanf("%d", &loopCnt);

	for (int i = 0; i < loopCnt; i++) {
		(void)scanf("%d", &N);
		pi = input_data(N);
		if (pi == NULL) {
			printf("메모리 부족");
			exit(1);
		}
		print_data(pi, N);
		free(pi);
		pi = NULL;
	}
	return 0;
}
#endif

#if 0 //메모리 동적 할당, 함수로 분리

void init_data(char***, int*);
void print_data(char**, int);
void destroy_data(char**, int);

int main(void) {
	char** str = 0;
	int N;
	(void)freopen("data.txt", "r", stdin);
	init_data(&str, &N);
	print_data(str, N);
	destroy_data(str, N);
	str = NULL;

	return 0;
}

void init_data(char*** s, int* n)
{
	int i, N;
	char temp[80] = { 0 };
	char** str = 0;

	(void)scanf("%d ", &N);
	str = (char**)calloc(N, sizeof(char*));
	if (str == NULL) {
		printf("메모리 부족\n");
		exit(0);
	}
	for (i = 0; i < N; ++i) {
		gets(temp);
		str[i] = (char*)malloc(strlen(temp) + 1);
		if (str[i] == NULL)
		{
			printf("메모리 부족\n");
			free(str);
			exit(0);
		}
		strcpy(str[i], temp);
	}
	*s = str;
	*n = N;
}

void print_data(char**str, int N)
{
	int i;
	for (int i = 0;i < N;++i)
	{
		printf("%s\n", str[i]);
	}
}

void destroy_data(char** str, int N)
{
	int i;
	for (i = 0;i < N;++i)
	{
		free(str[i]);
	}
	free(str);
}
#endif

#if 0

typedef struct student
{
	int num;
	double grade;
	char name[20];
}student_t;

//typedef struct student student_t;

int main(void)
{
	student_t s1 = { 0 };
	student_t* p1 = &s1;
	
	s1.num = 2;
	s1.grade = 2.7;
	strcpy(s1.name, "홍길동");
	printf("이름: %s\n", s1.name);
	printf("학번: %d\n", s1.num);
	printf("학점: %.1lf\n", s1.grade);
	p1->num = 3;
	p1->grade = 3.4;

	printf("학번: %d\n", s1.num);
	printf("학점: %.1lf\n", s1.grade);
	printf("학번: %d\n", p1->num);
	printf("학점: %.1lf\n", p1->grade);
	printf("%d %d %d", p1->num, (*p1).num, p1[0].num);

	return 0;
}
#endif

#if 0
struct profile
{
	int age;
	double height;
	char* name;
};

struct student
{
	struct profile pf;
	int num;
	double grade;
};

int main(void)
{
	struct student s1 = { {20, 160, "홍길동"}, 1, 4.0 };
	struct student* p1 = &s1;
	
	printf("나이: %d, 키: %.1f, 이름: %s, 숫자: %d, 성적: %.1f\n", s1.pf.age, s1.pf.height, s1.pf.name, s1.num, s1.grade);
	printf("(p1->)이용 | 나이: %d, 키: %.1f, 이름: %s, 숫자: %d, 성적: %.1f\n", p1->pf.age, p1->pf.height, p1->pf.name, p1->num, p1->grade);
	printf("(*p1)이용 | 나이: %d, 키: %.1f, 이름: %s, 숫자: %d, 성적: %.1f\n", (*p1).pf.age, (*p1).pf.height, (*p1).pf.name, (*p1).num, (*p1).grade);
	printf("(p1[0])이용 | 나이: %d, 키: %.1f, 이름: %s, 숫자: %d, 성적: %.1f\n", p1[0].pf.age, p1[0].pf.height, p1[0].pf.name, p1[0].num, p1[0].grade);


	return 0;
}
#endif
/*
&stu[i].scores[0]
(stu + i)->scores
*/
#if 0
#define size_ary(x) sizeof(x) / sizeof((x)[0])

struct student {
	int id;
	//int scores[3];
	int scores[1];
	char name[20];
};

void input_data(struct student*, int);
void input_data2(struct student*, int);
void print_data2(struct student*, int);

int main(void) {
	struct student stu[5] = { 0 };
	(void)freopen("student.txt", "r", stdin);

	input_data(stu, size_ary(stu));
	print_data2(stu, size_ary(stu));

	return 0;
}

void input_data(struct student* stu, int size) 
{
	struct student temp = { 0 };
	for (int i = 0; i < size; ++i) 
	{
		//temp = stu + i;
		temp = stu[i];
		/*(void)scanf("%d %d %d %d %s",
			&stu[i].id,
			&stu[i].scores[0],
			&stu[i].scores[1],
			&stu[i].scores[2],
			stu[i].name);*/
		(void)scanf("%d %d %d %d %s",
			&temp.id,
			temp.scores,
			temp.scores + 1,
			temp.scores + 2,
			temp.name);
		/*(void)scanf("%d %d %s",
			&stu[index].id,
			stu[index].scores,			
			stu[index].name);*/
	}
}

void input_data2(struct student* stu, int size)
{
	struct student temp = { 0 };
	for (int i = 0; i < size; ++i)
	{
		//temp = stu + i;
		temp = stu[i];
		/*(void)scanf("%d %d %d %d %s",
			&stu[i].id,
			&stu[i].scores[0],
			&stu[i].scores[1],
			&stu[i].scores[2],
			stu[i].name);*/
		(void)scanf("%d %d %d %d %s",
			&temp.id,
			temp.scores,
			temp.scores + 1,
			temp.scores + 2,
			temp.name);
		/*(void)scanf("%d %d %s",
			&stu[index].id,
			stu[index].scores,
			stu[index].name);*/
	}
}

void print_data2(struct student* stu, int size) 
{	
	struct student* temp = 0;
	for (int i = 0; i < size; ++i) 
	{
		temp = stu + i;
		printf("id: %d, scores: %d %d %d, name: %s\n",
			temp->id,
			temp->scores,
			temp->scores+1,
			temp->scores+2,
			temp->name);
		/*printf("id: %d, scores: %d, name: %s\n",
			stu[index].id,
			stu[index].scores[0],
			stu[index].name);*/
	}
}
#endif

#if 01
typedef struct {
	unsigned int blue : 8;
	unsigned int green : 8;
	unsigned int red : 8;
}color1;

typedef struct {
	unsigned char blue;
	unsigned char green;
	unsigned char red;
}color2;

int main(void)
{
	printf("%d %d\n", sizeof(color1), sizeof(color2));

	color1 a;
	a.blue = 255;
	a.green = 2;
	a.red = 3;

	printf("%d %d %d\n", a.blue, a.green, a.red);


	return 0;
}

#endif