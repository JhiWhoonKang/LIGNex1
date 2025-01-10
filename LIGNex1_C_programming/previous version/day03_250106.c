#include <stdio.h>
#include <string.h>

char getGrade(int score)
{
	char grade[] = "FFFFFFDCBAA";
	
	if (score < 0 || score>100)
	{
		printf("wrong score\nrewrite\n");
		int score;
		(void)scanf_s("%d", &score);
		getGrade(score);
	}

	return grade[score / 10];
}

void getOddEven(int num)
{	
	printf("%s", (num % 2) ? "Ȧ��" : "¦��");
}

void getMul(int num)
{
	printf("%s�� ���\n", (num % 2 == 0) ? "2" : (num % 3 == 0) ? "3" : (num % 5 == 0) ? "5" : "0");
}

void getPassNpass(int score)
{
	printf("%s", (score >= 70) ? "�հ��Դϴ�.\n�����մϴ�." : (score < 60) ? "���հ��Դϴ�.\n�����մϴ�." : "����躸����.\n�����մϴ�.");
}

int getOdd(int start_num)
{
	int sum = 0;
	for (int i = (start_num % 2) ? start_num : start_num + 1; i < 101; i += 2)
	{
		sum += i;
	}
	return sum;
}

//void inputAry(int* ary, int size)
//void inputAry(int ary[], int size)
//void inputAry(int ary[1], int size) // [] �ȿ� �� �Է��ص� �ƹ� �ǹ� x
//{
//	int i;
//	for (i = 0;i < size;++i)
//	{
//		scanf_s("%d", ary + i);
//		//scanf_s("%d", &ary[i]);
//	}
//}
//
//void inputAry(int ary[3][4], int size) // [3]�� ���� ���� �Ǵ� �ƹ� ���� ����. ������ [4]�� �����. ary[]�� �����Ͷ�� ���������� �����ϴµ�, [4]�� type�̶�
//{
//	
//}
//
//void printAry(int* ary, int size)
//{
//	
//}
//
//void printAry(int(* ary)[4], int size)
//{
//	for (int i = 0;i < size;++i)
//	{
//		printf("%d ", *(ary + i));
//		//printf("%d ", ary[i]);
//	}
//}

//int main(void)
//{
#if 0
	int score;	
	scanf_s("%d", &score);
		
	if (score >= 90 && score <= 100)
	{
		printf("A\n");
	}

	else if (score >= 80 && score < 90)
	{
		printf("B\n");
	}

	else if (score >= 70 && score < 80)
	{
		printf("C\n");
	}

	else if (score >= 60 && score < 70)
	{
		printf("D\n");
	}

	else
	{
		printf("F\n");
	}
#endif

#if 0
	int score;
	(void)scanf_s("%d", &score);
	printf("%c\n", getGrade(score));
#endif

#if 0
	int num;
	(void)scanf_s("%d", &num);
	getOddEven(num);
	
	char *A[]={"¦��", "Ȧ��"};
	printf("%s", A[num % 2]);		
#endif

#if 0
	int num;
	(void)scanf_s("%d", &num);
	getMul(num);
#endif

#if 0
	int score;
	(void)scanf_s("%d", &score);
	getPassNpass(score);
#endif

#if 0
	int sum = 0;
	/*for (int i = 1; i < 101; ++i)
	{
		if (i % 2 == 1)
		{
			sum += i;
		}
	}*/

	/*for (int i = 1; i < 101; i += 2)
	{
		sum += i;
	}*/

	int start_num;
	scanf_s("%d", &start_num);
	printf("%d", getOdd(start_num));
#endif

#if 0
	int N = 5;

	for (int i = 0;i < N;++i) {
		for (int j = N - 1;j > i;--j) {
			printf(" ");
		}
		for (int j = 0;j < i * 2 + 1;++j) {
			printf("*");
		}

		printf("\n");
	}

	for (int i = 0;i < N - 1;++i) {
		for (int j = 0;j <= i;++j) {
			printf(" ");
		}
		for (int j = (N - 1) * 2 - 1;j >= i * 2 + 1;--j) {
			printf("*");
		}
		printf("\n");
	}
#endif

#if 0
	int PW;
	
	for (int i = 0;i < 3;++i)
	{
		scanf_s("%d", &PW);
		if (PW == 1357)
		{
			printf("�α��� ����!");
			return 0;
		}
	}

	printf("�����ڿ��� �����ϼ���.");
#endif	

#if 0
	char input[100];
	char result[100];
	int length;

	printf("���ڿ��� �Է��ϼ���: ");
	scanf_s("%s", input, 100);

	length = strlen(input);

	for (int i = 0; i < length; ++i) 
	{
		result[i] = input[length - i - 1];
	}
	result[length] = '\0';

	printf("������ ���ڿ�: %s\n", result);	

#endif

#if 0
	int i = 0;
	int ary[5] = { 1,2,3,4,5 };

	for (int i = 0;i < 5;i++)
	{
		printf("%d\t%p\t%d\n", ary[i], ary + i, *(ary + i));	
	}

	printf("<�迭> %p\t%p\n", ary, &ary);
	printf("<�迭 + 1> %p\t%p\n", ary + 1, &ary + 1);

	printf("<sizeof> %d %d\n", sizeof(ary), sizeof(&ary));
#endif

#if 0
	int score[5];
	int i;
	int total = 0;
	int* p = score;
	for (i = 0;i < 5;i++)
	{
		scanf_s("%d", score + i);
	}

	for (i = 0;i < 5;i++)
	{
		printf("%d ", *(score+i));
	}
	
#endif

#if 0
	int inputs[5] = { 0 };
	for (int i = 0;i < 5;i++)
	{
		scanf_s("%d", &inputs[i]);
	}

	for (int i = 4;i >= 0;i--)
	{
		printf("%d ", inputs[i]);
	}

#endif

#if 0
	int ary[5] = { 0 };
	int size = sizeof(ary) / sizeof(ary[0]);

	inputAry(ary, size);
	printAry(ary, size);
#endif

#if 0
	//int ary[3][4] = { 0 }; // ary: ary[0]�� �ּ� interger 4��¥�� �迭�� ������
	//inputAry(ary, 3);
	//printAry(ary, 3);

	int ary[5] = { 0 };
	printf("%d %d", sizeof(ary), sizeof(&ary[0]));
#endif
//	return 0;
//}