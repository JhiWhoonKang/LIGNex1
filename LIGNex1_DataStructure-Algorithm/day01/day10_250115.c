#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

// ȸ���ʹ� - % ���� ���
// https://www.acmicpc.net/problem/2531

#if 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

//NUM �ʹ��� ���� �迭, ������ ���� �ʹ��� � �ִ��� ������ �迭
int NUM[30000] = { 0 }, D[3001] = { 0 };
//N �ʹ�� , d ������, k ���� Ƚ��, c ����
int N, d, k, c;

int main() {
    //�ʹ� �Ա� �����ϴ� ��ġ, �� ���� �� ��ġ�� ������ index ������
    int start = 0, end = 0;
    //������ ���� ������ ����, �ִ��� ������ ����
    int kind_num = 0, max = 0;

    (void)freopen("data_2531.txt", "r", stdin);
    //�Է� ��
    scanf("%d %d %d %d", &N, &d, &k, &c);

    for (int i = 0;i < N;i++)
        scanf("%d", NUM + i);

    // NUM �迭 �ڿ� NUM�� �պκ��� ����   


    //���� ���� ó���ϱ�
    D[c]++; kind_num++;

    //ù��° �ʹ���� �Ծ��� ���� ����Ǽ� ���ϱ�
    for (int i = 0;i < k;i++) {
        if (!D[NUM[i]]++)
            kind_num++;
    }
    max = kind_num;
    for (start = 0, end = k; start < N;)
    {
        //���� �ʹ��� ������ �ϳ����ٸ�
        if (1 == D[NUM[start]]--) {
            kind_num--;
        }
        //���� ���� �ʹ��� ������ ���ο� ���̶��
        if (0 == D[NUM[end % N]]++) {
            kind_num++;
        }
        //�̶� �ִ��� �������� ������
        if (max < kind_num)
            max = kind_num;

        start++; end++;
    }
    printf("%d", max);
}

#endif

// ȸ���ʹ� - % ���� ���� ȸ�� ����
#if 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
//NUM �ʹ��� ���� �迭, ������ ���� �ʹ��� � �ִ��� ������ �迭
int NUM[33000] = { 0 }, D[3001] = { 0 };
//N �ʹ�� , d ������, k ���� Ƚ��, c ����
int N, d, k, c;

int main() {
    //sliding window ����� ����, �߰� ��ġ�� ��� (start, start+k)
    int start = 0;
    //������ ���� ������ ����, �ִ��� ������ ����
    int kind_num = 1, max = 0;

    (void)freopen("data_2531.txt", "r", stdin);
    //�Է� ��
    scanf("%d %d %d %d", &N, &d, &k, &c);

    for (int i = 0;i < N;i++)
        scanf("%d", NUM + i);   

    //���� ���� ó���ϱ�
    D[c]=1;

    //ù��° �ʹ���� �Ծ��� ���� ����Ǽ� ���ϱ�, NUM �迭 ����
    for (int i = 0;i < k;i++) {
        if (!D[NUM[i]]++)
            ++kind_num;
        NUM[N + i] = NUM[i];
    }
    max = kind_num;
    for (start = 0; start < N; ++start)
    {
        // �����Ϳ� �����ϰ� �׻� �߻��ϴ� ���� �ƴ�! - �̷� ���� ������ �ð� ���� ������ �� ����
        //if (max == (k + 1)) break;  
        //���� �ʹ��� ������ �ϳ����ٸ�
        if (1 == D[NUM[start]]--)
        {
            --kind_num;
        }
        //���� ���� �ʹ��� ������ ���ο� ���̶��
        if (0 == D[NUM[start+k]]++)
        {
            ++kind_num;
        }
        //�̶� �ִ��� �������� ������
        if (max < kind_num)
            max = kind_num;
    }
    printf("%d", max);
}
#endif

// ����Լ� �ۼ� ����
// ���� �޸� ����Ͽ� ����, ȣ��Ƚ���� ���ѵ�
// parameter �� local ������ ������ ȣ��Ƚ���� �پ��
#if 0

int cnt;
struct student {
    int arr[100];
};

void test(struct student a) {
    printf("%d\n", ++cnt);
    test(a);
}

int N = 5;
void test1(int L) {
    if (L > N) return;
    printf("L = %d\n", L);
    test1(L + 1);
}

void test2(int L) {
    if (L < 1) return;
    printf("L = %d\n", L);
    test2(L - 1);
}
// 1 2 3 4 5 5 4 3 2 1 
void test3(int L) {
    if (L > N) return;
    printf("%d ", L);
    test3(L + 1);
    printf("%d ", L);
}

// 1 2 3 4 5 4 3 2 1 
void test4(int L) {
    printf("%d ", L);
    if (L >= N) return;
    test4(L + 1);
    printf("%d ", L);
}

// 1 2 3 4 5 1 2 3 4 5
void test5(int L)
{
    if (L > N) return;
    printf("%d ", L);
    test5(L + 1);
    printf("%d ", N-L+1);
}

//1
//1 2
//1 2 3
//1 2 3 4
//1 2 3 4 5
void test6(int L) {
    if (L > N) return;
    for (int i = 1; i <= L; ++i) {
        printf("%d ", i);
    }
    printf("\n");
    test6(L + 1);
}

void func() {
    func();
    func();
}

int main(void) {
    struct student a = { 0 };
    //test(a);
    //test1(1);
    //test2(N);
    //test3(1);
    test6(1);
    return 0;
}
#endif


// ������ȣ ���̱�
#if 0
int map[25+2][25+2];
int N;
int cnt;
int danji[(25 * 25) / 2];
int danji_cnt;

void input_data(void) {
    int i, j;
    (void)scanf("%d", &N);
    for (i = 1; i <= N; ++i) {
        for (j = 1; j <= N; ++j) {
            (void)scanf("%1d", &map[i][j]);
        }
    }
}
void print_map(void) {
    int i, j;
    for (i = 1; i <= N; ++i) {
        for (j = 1; j <= N; ++j) {
            printf("%d", map[i][j]);
        }
        printf("\n");
    }
}

void miro(int r, int c) {
    if (map[r][c] == 0) return;
    map[r][c] = 0;
    ++cnt;
    miro(r-1, c);
    miro(r+1, c);
    miro(r, c-1);
    miro(r, c+1);
}

void solve(void) {
    int i, j;
    danji_cnt = 0;
    for (i = 1; i <= N; ++i) {
        for (j = 1; j <= N; ++j) {
            if (map[i][j] == 1) {
                cnt = 0;
                miro(i, j);
                danji[danji_cnt++] = cnt;
            }
        }
    }
}
void print_result(void) {
    int i;
    printf("%d\n", danji_cnt);
    for (i = 0; i < danji_cnt; ++i) {
        printf("%d\n", danji[i]);
    }
}

void sort_ary(void) {
    int i, j;
    int temp;
    for (i = 0; i < danji_cnt - 1; ++i) {
        for (j = i + 1; j < danji_cnt; ++j) {
            if (danji[i] > danji[j]) {
                temp = danji[i];
                danji[i] = danji[j];
                danji[j] = temp;
            }
        }
    }
}
int main(void) {

    (void)freopen("data_2667.txt", "r", stdin);
    input_data();
    print_map();
    solve();
    sort_ary();
    print_result();
    return 0;
}

#endif