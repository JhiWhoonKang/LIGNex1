#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

// 회전초밥 - % 연산 사용
// https://www.acmicpc.net/problem/2531

#if 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

//NUM 초밥을 받을 배열, 종류에 따른 초밥이 몇개 있는지 저장할 배열
int NUM[30000] = { 0 }, D[3001] = { 0 };
//N 초밥수 , d 가짓수, k 연속 횟수, c 쿠폰
int N, d, k, c;

int main() {
    //초밥 먹기 시작하는 위치, 다 먹은 후 위치를 저장할 index 변수들
    int start = 0, end = 0;
    //종류의 수를 저장할 변수, 최댓값을 저장할 변수
    int kind_num = 0, max = 0;

    (void)freopen("data_2531.txt", "r", stdin);
    //입력 부
    scanf("%d %d %d %d", &N, &d, &k, &c);

    for (int i = 0;i < N;i++)
        scanf("%d", NUM + i);

    // NUM 배열 뒤에 NUM의 앞부분을 복사   


    //먼저 쿠폰 처리하기
    D[c]++; kind_num++;

    //첫번째 초밥부터 먹었을 때의 경우의수 구하기
    for (int i = 0;i < k;i++) {
        if (!D[NUM[i]]++)
            kind_num++;
    }
    max = kind_num;
    for (start = 0, end = k; start < N;)
    {
        //버릴 초밥의 종류가 하나였다면
        if (1 == D[NUM[start]]--) {
            kind_num--;
        }
        //새로 들어올 초밥의 종류가 새로운 것이라면
        if (0 == D[NUM[end % N]]++) {
            kind_num++;
        }
        //이때 최대의 종류수를 가지면
        if (max < kind_num)
            max = kind_num;

        start++; end++;
    }
    printf("%d", max);
}

#endif

// 회전초밥 - % 연산 없이 회전 구현
#if 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
//NUM 초밥을 받을 배열, 종류에 따른 초밥이 몇개 있는지 저장할 배열
int NUM[33000] = { 0 }, D[3001] = { 0 };
//N 초밥수 , d 가짓수, k 연속 횟수, c 쿠폰
int N, d, k, c;

int main() {
    //sliding window 적용시 제거, 추가 위치로 사용 (start, start+k)
    int start = 0;
    //종류의 수를 저장할 변수, 최댓값을 저장할 변수
    int kind_num = 1, max = 0;

    (void)freopen("data_2531.txt", "r", stdin);
    //입력 부
    scanf("%d %d %d %d", &N, &d, &k, &c);

    for (int i = 0;i < N;i++)
        scanf("%d", NUM + i);   

    //먼저 쿠폰 처리하기
    D[c]=1;

    //첫번째 초밥부터 먹었을 때의 경우의수 구하기, NUM 배열 복사
    for (int i = 0;i < k;i++) {
        if (!D[NUM[i]]++)
            ++kind_num;
        NUM[N + i] = NUM[i];
    }
    max = kind_num;
    for (start = 0; start < N; ++start)
    {
        // 데이터와 무관하게 항상 발생하는 것이 아님! - 이런 것은 오히려 시간 낭비를 가져올 수 있음
        //if (max == (k + 1)) break;  
        //버릴 초밥의 종류가 하나였다면
        if (1 == D[NUM[start]]--)
        {
            --kind_num;
        }
        //새로 들어올 초밥의 종류가 새로운 것이라면
        if (0 == D[NUM[start+k]]++)
        {
            ++kind_num;
        }
        //이때 최대의 종류수를 가지면
        if (max < kind_num)
            max = kind_num;
    }
    printf("%d", max);
}
#endif

// 재귀함수 작성 연습
// 스택 메모리 사용하여 동작, 호출횟수가 제한됨
// parameter 및 local 변수가 많으면 호출횟수가 줄어듦
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


// 단지번호 붙이기
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