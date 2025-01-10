#if 0
#include <stdio.h>
#include <string.h>

int main() {
    int arr[10] = { 10, 20, 40, 80, 160, 320, 640, 1280, 2560, 5120 };
    printf("%d\n", *(int*)(((unsigned char*)((long long*)((char*)(arr + (int)5.5) - 1) - 2) + 1)));

    return 0;
}
#endif

#if 0
#include <stdio.h>

int func(void* num) {
    (*(float*)num)++;
    const int const* a = (int)*(float*)num;
    int pa = ++a;
    --pa;
    return pa;
}

int main() {
    const float num_ = 10.2461;
    int a = func((void*)&num_);

    printf("============\n");
    printf("%.3f\n", num_);
    printf("%d\n", a);

    return 0;
}
#endif

#if 0
#include <stdio.h>
#include <string.h>

int main() {
    char* p = "good";
    char q[100] = "oh! good things are happening!";
    char* r = q + 4;

    if (!strcmp(r, p)) {
        printf("have a ");
    }
    else if (*(r + 5) == *(p + 1)) {
        printf("great ");
    }
    else if (strcmp(p, r + 10) < 0) {
        printf("wonderful ");
    }
    printf("%s choice!\n", p);
    return 0;
}
#endif

#if 0
int main() {
    int arr[3] = { 10, 20, 30 };
    int* ptr = arr;

    int** pptr = &ptr;
    **pptr += 5;                       // (1)
    ptr++;                             // (2)
    *ptr += *--(*pptr);                // (3)
    ptr++;                             // (4)
    *ptr = *(char*)(ptr - 1) + 10;     // (5)
    *(char*)(arr + 2) = 1;             // (6)

    printf("%d %d %d\n", arr[0], arr[1], arr[2]);

    return 0;
}
#endif

#if 0
int main(void) {
    int a[3] = { 1,2,3 };   // 1   
    int* p = ++(*a);   // 2
    printf("%X\n", p);  // 3

    return 0;
}
#endif

#if 0
int main(void) {
    char ary[20] = "arraytest!";
    char* name = "pointertest";

    char* temp = name;   // 1
    temp = &ary[5];    //2
    temp[0] = 'k';   // 3
    printf("%s\n", temp);   // 4

    temp = name;   // 5
    temp[0] = 'k';  // 6
    printf("%s\n", temp);   //7

    return 0;
}
#endif

#if 0
void main()
{
    const char* food1 = "apple";
    const char food2[] = "apple";

    printf("%c\n", *food1);    // 1
    printf("%c\n", *++food1);   // 2
    printf("%c\n", *food1++);     // 3
    printf("%c\n", *food2);      // 4
    printf("%c\n", *++food2);  // 5
    printf("%c\n", *food2++);  // 6
}
#endif

#if 0
int main(void)
{
    char a[20] = "abcdefghijklmnop";
    char* p = a;
    printf("%c\n", *(int*)p++);
    printf("%c\n", *((double*)p)++);
    printf("%c\n", *p);

    return 0;
}
#endif

#if 0
#include<stdio.h>

int main(void) {

    char* Name = "LIGNex1";
    int temp[3];
    temp[0] = *(char*)++((int*)Name);
    for (int i = 0;i < sizeof(temp);i++) {
        printf("%c", ++temp[0]);
    }
}
#endif

#if 0
#include <stdio.h>
int main() {
    int arr[5] = { 10, 20, 30 };
    int* p = arr;
    *p++ = 50;
    printf("%d %d %d\n", arr[0], arr[1], *p);
    return 0;
}
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#if 0

int main(void)
{
    int score[3][4] = { 0 };
    int i, j;
    (void)freopen("scores.txt", "r", stdin);
    for (int i = 0;i < 3;++i)
    {
        for (int j = 0;j < 4;++j)
        {
            //(void)scanf_s("%d", &score[i][j]);
            //(void)scanf_s("%d", *(score + i) + j);
            (void)scanf_s("%d", i[score] + j);
        }
    }
    for (int i = 0;i < 3;++i)
    {
        for (int j = 0;j < 4;++j)   
        {
            printf("%5d", score[i][j]);
        }
        printf("\n");
    }

    return 0; 
}
#endif

#if 0
int main(void)
{
    int a1 = 10, a2 = 20, a3 = 30, a4 = 40;
    int* a[4] = { &a1, &a2, &a3, &a4 };
    int** p = a;
    printf("%d", *p[0]);
    printf("\n%d", sizeof(p[0]));

}
#endif

#if 0
int main(void)
{    
    int a[2][3] = { 1,2,3,4,5,6 };
    int(*p)[3] = a;
    
    printf("%d %d %d\n", *(*(p + 1)), **(p + 1), *p[1]);
    printf("%d %d\n", p[1][0], (*(p+1))[0]);
    printf("%d", sizeof(p[0]));
    return 0;
}
#endif

#if 0
#define size_ary(x) (sizeof(x)/sizeof((x)[0]))

//static void print_ary(char[(*ary)[][10], int size)
static void print_ary(char(*ary)[10], int size) // 배열을 보낸게 아님
{
    printf("%d %d %d\n", sizeof(ary), sizeof(ary[0]), sizeof(ary[0][0]));
    for (int i = 0;i < size;i++)
    {
        printf("%s ", ary[i]);
        printf("\n%c\n", ary[i][0]);
    }
    printf("\n");
}

int main(void)
{
    char animal[5][10] = { 0 };
    int i;
    (void)freopen("animal.txt", "r", stdin);
    for (i = 0;i < size_ary(animal);i++)
    {
        (void)scanf("%s", animal[i]);
    }
    print_ary(animal, size_ary(animal));
}
#endif

#if 0
int main(void)
{
    int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
    printf("%d\n", a);
    
    return 0;
}
#endif