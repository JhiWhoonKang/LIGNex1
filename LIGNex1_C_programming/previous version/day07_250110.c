#include <stdio.h>

#if 0
#include <stdio.h>
int main(void)
{
    int ar[3][4] = { {1,2},{3,4,5},{6,7,8,9} };
    printf("1) %d\n", ar[2][1]);
    printf("2) %d\n", *(*(ar + 2) + 1));
    printf("3) %d\n", sizeof(ar + 2));
    printf("4) %d\n", sizeof(*(ar + 2)));
    printf("5) %d\n", sizeof(*(ar + 2) + 1));


    int arr[2][3] = { 0, };
    printf("1) %d\n", sizeof(arr));
    printf("2) %d\n", sizeof(arr[0]));
    printf("3) %d\n", sizeof(&arr[0]));
    printf("4) %d\n", sizeof(arr[0][0]));
    return 0;
}
#endif

#if 0
#include <stdio.h>

int main(void)
{
    int a = 10;
    int* ap = &a;
    int** app = &ap;
    printf("%p %p %p\n", &a, &ap, &app);
    printf("%p %p %p", &a, &ap, *app);
    return 0;
}

#endif

#if 0
void exchange0(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void exchange1(int** ap, int** bp)
{
    int temp = **ap;
    ** ap = **bp;
    **bp = temp;
}

void exchange2(int*** app, int*** bpp)
{
    int temp = ***app;
    *** app = ***bpp;
    ***bpp = temp;
}

void exchange3(int** ap, int** bp)
    {
    
    int *temp = *ap;
    *ap = *bp;
    *bp = temp;
}

void exchange4(int*** app, int*** bpp)
{
    int *temp = **app;
    **app = **bpp;
    **bpp = temp;
}

void exchange5(int*** app, int*** bpp)
{
    int **temp = *app;
    *app = *bpp;
    *bpp = temp;
}


int main(void)
{
    int a = 10, b = 5;
    int* ap = &a, * bp = &b;
    int** app = &ap, ** bpp = &bp;

    // ===
    exchange0(&a, &b);
    printf("exchange0 실행 결과: %d %d\n", a, b);
    // ===
    exchange1(&ap, &bp);
    printf("exchange1 실행 결과: %d %d\n", a, b);
    // ===
    exchange2(&app, &bpp);
    printf("exchange2 실행 결과: %d %d\n", a, b);
    // ===
    exchange3(&ap, &bp);
    printf("exchange3 실행 결과: %d %d\n", *ap, *bp);
    // ===
    exchange4(&app, &bpp);
    printf("exchange4 실행 결과: %d %d\n", *ap, *bp);
    // ===
    exchange5(&app, &bpp);
    printf("exchange5 실행 결과: %d %d\n", **app, **bpp);

    return 0;
}
#endif

#if 0

int main(void)
{
    int a = 0x11223344;
    int* p1 = &a;
    printf("%x\n", *p1);
    printf("%x\n", *(char *)p1);
    printf("%x\n", *(short *)p1);
    printf("%x\n", **(char(*)[2])p1);
    char(*p2)[2] = &a;
    printf("%x\n", p2[1][1]);
    printf("%x\n", *(*p2+3));

    return 0;
}
#endif

#if 0
int main(void)
{
    char* pary[5] = { "dog", "elephant", "cat", "tiger", "lion" };
    char* pary2[2][3] = { {"dog", "elephant, ant"}, {"cat", "tiger", "lion"} };

    printf("%d %d\n", sizeof(pary), sizeof(pary[1]));
    printf("%d %d %d", sizeof(pary2), sizeof(pary2[1], sizeof(pary2[0][1])));

    return 0;
}
#endif

#if 0
#define size_ary(x) (sizeof(x)/sizeof((x)[0]))
void print_ary(char** pary, int size)
{
    for (int i = 0;i < 5;i++)
    {
        printf("%s\n", pary[i]);
    }
}

int main(void)
{
    /*char name[] = "cat";
    pary[0] = name;*/
    
    char animal[5][10] = { "dog", "elephant", "cat", "tiger", "lion" };
    char(*p1)[10] = animal;
    char* pary[5] = { "dog", "elephant", "cat", "tiger", "lion" };
    char** p2 = pary;

    printf("%s %s\n", p1[0], animal[0]);
    p1[0][3] = 's'; //=>dog->dogs
    printf("%s %s\n", p1[0], animal[0]);
    printf("%s %s\n", p2[0], pary[0]);
    
    //p2[0][3] = 's'; //error
    //printf("%s %s\n", p2[0], pary[0]);

    //animal[0] = "rabbit";//error , 포인터 상수여서
    pary[0] = "ghi";
    printf("%s %s\n", p2[0], pary[0]);
    printf("%d %d\n", sizeof(p1), sizeof(*p1)); //포인터 변수니까 4바이트
    printf("%d %d %d\n", sizeof(p2), sizeof(*p2), sizeof(**p2)); //포인터 변수니까 4바이트
    //print_ary(pary, size_ary(pary));

    return 0;
}
#endif
#include <stdlib.h>
#if 01
int main(void)
{
    int N; //행의 수
    int C; //열의 수
    //int* ary[N];
    int** ary = 0;
 
    (void)freopen("myfile.txt", "r", stdin);

    scanf("%d", &N);
    ary = (int**)malloc(sizeof(int*) * N); // ary => 0x1000 ary+1 => 0x1004

    for (int i = 0;i < N;++i)
    {
        scanf("%d", &C);
        ary[i] = (int*)malloc(sizeof(int) * (C + 1));        
        for (int j = 1;j < C + 1;j++)
        {
            scanf("%d", ary[i][j]);
            printf("%d ", ary[i][j]);
        }
    }

    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < C;j++)
        {
            printf("%d ", *(ary[N] + C));
        }
        printf("\n");
    }

    return 0;
}
#endif