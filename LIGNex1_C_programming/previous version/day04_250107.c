#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)

void Swap(int* a, int* b)
{
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;
}

int Add(int a, int b)
{
	return a + b;
}

int Sub(int a, int b)
{
	return a - b;
}

int Mul(int a, int b)
{
	return a * b;
}

int Div(int a, int b)
{
	return a / b;
}

void printMenu(void)
{
	printf("+----------------------+\n");
	printf("+ [1] 더하기		   +\n");
	printf("+ [2] 빼  기		   +\n");
	printf("+ [3] 곱하기		   +\n");
	printf("+ [4] 나누기		   +\n");
	printf("+ [0] 종  료		   +\n");
	printf("+----------------------+\n");
}

int calculate(int a, int b, char op) {
	int (*operation[4])(int, int) = { Add, Sub, Mul, Div };
	char operators[4] = { '+', '-', '*', '/' };
	for (int i = 0; i < 4; i++) {
		if (op == operators[i]) {
			return operation[i](a, b);
		}
	}
}

void scanf_ary(int* arr, int size)
{
	for (int i = 0;i < size;++i)
	{
		printf("%d번 째 수 입력: ", i + 1);
		scanf_s("%d", arr + i);
	}
}

/*
void print_ary(int* arr, int size)
{
	printf("\n---print_ary---\n");
	for (int i = 0;i < size;++i)
	{
		printf("%d ", *(arr + i));
	}
}*/

void findmax_ary(int* arr, int size)
{
	printf("\n---findmax_ary---\n");
	int max = arr[0];
	for (int i = 0;i < size;++i)
	{
		if (max < *(arr + i))
		{
			max = *(arr + i);
		}
	}
	printf("가장 큰 정수: %d", max);
}

void findmin_ary(int* arr, int size)
{
	printf("\n---findmin_ary---\n");
	int min = arr[0];
	for (int i = 0;i < size;++i)
	{
		if (min > *(arr + i))
		{
			min = *(arr + i);
		}
	}
	printf("가장 작은 정수: %d", min);
}

void sum_ary(int* arr, int size)
{
	printf("\n---sum_ary---\n");
	int sum = 0;
	for (int i = 0;i < size;i++)
	{
		sum += *(arr + i);
	}
	printf("배열 총 합: %d", sum);
}

double avg_ary(int* arr, int size)
{
	printf("\n---avg_ary---\n");
	double sum = 0.0;
	for (int i = 0;i < size;i++)
	{
		sum += *(arr + i);
	}
	return sum / size;
}

void var_ary(int* arr, int size, int ddof, double mean)
{
	printf("\n---var_ary---\n");
	double var = 0.0;

	for (int i = 0;i < size;++i)
	{
		var += pow(*(arr + i) - mean, 2);
	}
	
	if (!ddof)
	{		
		printf("분산값: %lf", var / size);
		return ; // 모집단
	}	
	printf("분산값: %lf", var / (size - 1));
}

void sort_ary(int* arr, int size)
{
	printf("\n---sort_ary---\n");
	int temp;
	for (int i = 0;i < size;++i)
	{
		for (int j = i + 1;j < size;++j)
		{
			if (*(arr + i) > *(arr + j))
			{
				temp = *(arr + i);
				*(arr + i) = *(arr + j);
				*(arr + j) = temp;
			}
		}
	}
	for (int i = 0;i < size;i++)
		printf("%d ", *(arr + i));
}

//int my_strlen(char string[])
int my_strlen(char *string)
{
	/*int cnt = 0;
	while (*string++ != '\0')
	{
		cnt++;
	}
	
	return cnt - 1;*/
	/*char* org = string;
	while (*(string++) != NULL);

	return (string - org) - 1;*/
	const char* s;
	if (string == 0)
		return 0;
	for (s = string; *s;++s);
	return s - string;
}

void my_gets(char* str, int size)
{
	int i = 0;
	char ch;
	while ((ch = getchar()) != '\n' && i < size-1)
	{
		*(str + i) = ch;
		i++;
	}
	str[i] = '\0';
}
//
//int main(void)
//{
//#if 0 //swap 실습
//	int a, b;
//	scanf_s("%d %d", &a, &b);
//	printf("a: %d\tb: %d\n", a, b);
//
//	swap(&a, &b);
//	printf("---swap---\n");
//	printf("a: %d\tb: %d", a, b);
//#endif
//
//#if 0
//	int a, b, result = 0;
//	char op;
//
//	int a2, b2, result2 = 0;
//	int menu;
//
//	int a3, b3, result3 = 0;
//	char op2;
//	int menu3;
//
//	for (;;)
//	{
//		printMenu();
//		(void)scanf("%d", &menu);
//		if (menu == 0) break;
//		printf("\n두 변수를 입력하세요. : ");
//		(void)scanf("%d %d", &a2, &b2);
//		int (*calculate2[4])(int, int) = {Add, Sub, Mul, Div};
//		result2 = calculate2[menu - 1](a2, b2);
//		printf("%d\n", result2);
//
//		(void)scanf("%d %c %d", &a3, &op2, &b3);
//		int (*calc[6])(int, int) = { Mul, Add, 0, Sub, 0, Div };
//		result3 = calc[op2 - 42](a3, b3);
//		printf("%d %c %d = %d\n", a3, op2, b3, result3);
//
//		/*
//		printf("\n연산식 입력하세요. : ");
//		(void)scanf("%d %c %d", &a, &op, &b);
//
//		if (op == '+')
//		{
//			result = Add(a, b);
//		}
//		else if (op == '-')
//		{
//			result = Sub(a, b);
//		}
//		else if (op == '*')
//		{
//			result = Mul(a, b);
//		}
//		else if (op == '/')
//		{
//			if (b == 0)
//			{
//				printf("몫은 0이 될 수 없습니다.\n");
//				break;
//			}
//			result = Div(a, b);
//		}
//		else
//		{
//			printf("연산자 오류\n");
//			break;
//		}
//
//		printf("%d %c %d = %d", a, op, b, result);
//
//		result = calculate(a, b, op);
//		printf("%d %c %d = %d\n", a, op, b, result);*/
//	}	
//#endif
//
//#if 0
//	int a[3][4] = { 1,12,3,4,5,6,37,889,9,710,511,212 };
//	int i;
//	//int* pa = a;
//	int *pa = (int*)a;
//
//	for (i = 0;i < 12;++i)
//	{
//		//printf("%d ", ((int*)a)[i]); //우선순위 () > (type)
//		//printf("%d ", *((int*)a + i));
//		//printf("%d ", (*a)[i]);
//		//printf("%d ", a[0][i]);
//		//printf("%d ", pa[i]);
//		////printf("%d ", *pa + i); // 아님
//		//printf("%d ", *(pa + i));
//		////printf("%d ", **a + i); // 아님
//		//printf("%d ", *(*a + i));
//		//printf("%d ", *(a[0] + i));	
//		//printf("%d ", (&a[0][0])[i]);
//		//printf("%d ", pa++[0]); // 주의사항: p에 저장된 값이 변경됨
//		printf("%d ", *pa++); // 주의사항: p에 저장된 값이 변경됨
//	}
//
//#endif
//
//#if 0 //my_strlen 만들어보기
//	char a[] = "hi nice to ";
//	printf("%s : %d", a, my_strlen(a));
//#endif
//
//#if 0
//	int a = 10;
//	if (a = 20) {
//		printf("%d\n", a);
//	}
//	printf("%d\n", a);
//#endif
//
//
//#if 0
//	int arr[5] = { 0 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	scanf_ary(arr, size);
//	print_ary(arr, size);
//
//	double mean = avg_ary(arr, size);
//	printf("배열 요소 평균: %lf\n", mean);
//	
//	int ddof = 0;
//	printf("\nddof 결정\n0: 모집단, 1: 표본 집단\t");
//	scanf_s("%d", &ddof);
//	var_ary(arr, size, ddof, mean);
//	sort_ary(arr, size);
//#endif
//
//#if 0
//	char str[5] = { 0 };
//
//	my_gets(str, 5);
//	printf("%s\n", str);
//#endif
//
//	return 0;
//}