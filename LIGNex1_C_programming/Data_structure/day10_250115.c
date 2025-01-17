//[�ǹ�1] 2531.ȸ���ʹ� https://www.acmicpc.net/problem/2531
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#if 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//NUM �ʹ��� ���� �迭, ������ ���� �ʹ��� � �ִ��� ������ �迭
int NUM[33000] = { 0 }, D[3001] = { 0 };
//N �ʹ�� , d ������, k ���� Ƚ��, c ����
int N, d, k, c;

int main(void) {
    //�ʹ� �Ա� �����ϴ� ��ġ, �� ���� �� ��ġ�� ������ index ������
    int start = 0, end = 0;
    //������ ���� ������ ����, �ִ��� ������ ����
    int kind_num = 0, max = 0;
    //�Է� ��
    (void)scanf("%d %d %d %d", &N, &d, &k, &c);
    for (int i = 0;i < N;i++)
        (void)scanf("%d", NUM + i);

    for (int i = 0; i < 3; i++) 
    {
        NUM[N + i] = NUM[i];
    }

    //���� ���� ó���ϱ�
    D[c]++; kind_num++;

    //ù��° �ʹ���� �Ծ��� ���� ����Ǽ� ���ϱ�
    for (int i = 0;i < k;i++) {
        if (!D[NUM[i]]++)
            kind_num++;
    }
    max = kind_num;
    for (start = 0; start < N;++start)
    {
        // ���� �ʹ��� ������ �ϳ����ٸ�
        if (--D[NUM[start]] == 0) 
        {
            kind_num--;
        }
        // ���� ���� �ʹ��� ������ ���ο� ���̶��
        if (++D[NUM[start + k]] == 1)
        {
            kind_num++;
        }
        //�̶� �ִ��� �������� ������
        if (max < kind_num)
            max = kind_num;        
    }
    printf("%d", max);
}
#endif

#if 0
#include<stdio.h>
#define size_arr(x) sizeof(x)/sizeof(x[0])
#define MAX_D 3001

int slideWindow(int* sushi, int size, int k, int d, int c);

// �����̵� ������ Ȱ���ϱ� -> start & end Ȱ��
int main(void) {
    int N, d, k, c; // ���� ��, �ʹ� ������, �����ؼ� �Դ� ��, ���� �ʹ� ��ȣ
    int* sushi;


    (void)scanf("%d %d %d %d", &N, &d, &k, &c);
    sushi = (int*)malloc((N + k - 1) * sizeof(int));
    for (int i = 0; i < N; ++i) {
        (void)scanf("%d", sushi + i);
    }
    printf("%d", slideWindow(sushi, N, k, d, c));
    free(sushi);
    return 0;
}

int slideWindow(int* sushi, int N, int k, int d, int c) {
    int sushi_count[MAX_D] = { 0 };
    int current_sushis = 0;    // ���� �ʹ� ���� ��
    int max_result = 0; // ���
    for (int i = 0; i < k; ++i) {
        if (sushi_count[sushi[i]] == 0) {
            current_sushis++;
        }
        sushi_count[sushi[i]]++;
    }

    max_result = current_sushis + (sushi_count[c] == 0 ? 1 : 0);
    for (int i = 0; i < N; ++i) {
        int start = i;
        int end = (i + k) % N;
        if (--sushi_count[sushi[start]] == 0) {
            current_sushis--;
        }
        if (sushi_count[sushi[end]]++ == 0) {
            current_sushis++;
        }
        int result = current_sushis + (sushi_count[c] == 0 ? 1 : 0);
        max_result = max_result < result ? result : max_result;
    }
    return max_result;
}
#endif

// ����Լ� ����
// ���� �޸� ����Ͽ� ���� => ȣ��Ƚ���� ������
// parameter �� local ������ ������ ȣ�� Ƚ���� �پ��
#if 0
// ��Ŀ -> �ý���
int cnt;
void test(void)
{
    printf("%d\n", ++cnt);
    test();
}

int N = 5;
void test2(int L)
{
    if (L > N)
    {
        return;
    }
    printf("%d\n", L);
    test2(L + 1);
}
void test3(int L)
{
    if (L < 1) return;
    printf("%d\n", L);
    test3(L - 1);    
}

bool flag = false;
void test4(int L)
{
    printf("%d ", L);
    if (L == 5) flag = true;
    if (L == 1 && flag) return;

    if (!flag) test4(L + 1);
    else test4(L - 1);
}

void test5(int L)
{
    if (L > N) return;
    printf("%d ", L);
    test5(L + 1);
    printf("%d ", L);
}

void test6(int L)
{
    printf("%d ", L);
    if (L > N - 1) return;
    test6(L + 1);
    printf("%d ", L);
}

void test7(int L)
{    
    if (L > N) return;
    printf("%d ", L);
    test7(L + 1);   
    printf("%d ", N - L + 1);
}

void test8(int L)
{
    int i;
    if (L < 1) return;
    for (i = 0; i < N - L + 1;++i)
    {
        printf("%d ", i + 1);                
    }
    printf("\n");
    test8(L - 1);
}

int main(void)
{
    test8(5);
    return 0;
}
#endif

#if 0

int main(void)
{
    int N, index;
    (void)scanf("%d", &N);

    int arr[5] = { 0 };
    for (index = 0;N != 0;N /= 2, ++index)
    {
        arr[index] = N % 2;
    }
    for (index = 3;index >= 0;--index)
    {
        printf("%d", arr[index]);
    }

    return 0;
}

#endif

#if 0
int main() {
    int num; // ��ȯ�� ����
    int digit = 0;   
    (void)scanf("%d", &num);
    int tmp = num;
    // ������ ��Ʈ�� ī��Ʈ�Ͽ� �ڸ���(digit) ���
    while (tmp > 0) {
        tmp >>= 1;
        digit++;
    }

    printf("to binary %d: ", num);

    // 2���� ���
    for (int i = digit - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1); // 
    }

    printf("\n");

    return 0;
}
#endif

#if 01
int N, i;
int nums[] = { 0 };

void print_nums()
{

}

void make_nums(int L)
{
    if (L >= N)
    {
        print_nums();
        return;
    }
    nums[L] = 0;
    make_nums(L + 1);
    nums[L] = 1;
    make_nums(L + 1);
}

int main(void)
{    
    (void)scanf("%d", &N);
    make_nums(0);
    
    return 0;
}
#endif