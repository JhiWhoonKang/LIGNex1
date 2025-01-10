#include <stdio.h>
#include <stdlib.h>

#if 0
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
        ary[i][0] = C;
        for (int j = 1;j < C + 1;++j)
        {
            //scanf("%d", &ary[i][j]);
            scanf("%d ", ary[i] + j);
        }
    }

    for (int i = 0;i < N;i++)
    {
        for (int j = 1; j <= ary[i][0];++j)
        {
            printf("%4d ", ary[i][j]);
        }
        printf("\n");
    }


	return 0;
}
#endif

#if 01
// call by reference
void input_ary(int ***ary, int *N)
{
    int C;
    *ary = (int**)malloc(sizeof(int*) * (*N)); // ary => 0x1000 ary+1 => 0x1004

    for (int i = 0;i < *N;++i)
    {
        (void)scanf("%d", &C);
        (*ary)[i] = (int*)malloc(sizeof(int) * (C + 1));
        (*ary)[i][0] = C;
        for (int j = 1;j < C + 1;++j)
        {
            //scanf("%d", &ary[i][j]);
            (void)scanf("%d", &(*ary)[i][j]);
        }
    }
}

int main(void)
{
    int N;
    int** ary = 0;
    (void)freopen("myfile.txt", "r", stdin);
    (void)scanf("%d", &N);
    input_ary(&ary, &N);

    for (int i = 0;i < N;i++)
    {
        for (int j = 1; j <= ary[i][0];++j)
        {
            printf("%4d ", ary[i][j]);
        }
        printf("\n");
    }

    return 0;
}
#endif