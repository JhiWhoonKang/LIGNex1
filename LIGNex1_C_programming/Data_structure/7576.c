// 토마토 2D 문제 - 백준 7576 (BFS, Queue 사용)
#if 0
#define _CRT_SECURE_NO_WARNINGS

#include "Queue_t1.h"

//int dr[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
//int dc[] = { 1, 2, 2, 1, -1, -2, -2, 1 };

int solve_BFS()
{
    Node* curr = NULL;
    int dr[] = { -1, 1,0,0 };
    int dc[] = { 0,0,-1,1 };
    int nr, nc;
    int i;
    
    if (!zero_tomato)
    {
        return 0;
    }

    while (front != rear)
    {
        curr = Dequeue2();
        for (i = 0;i < 4;++i)
        {
            nr = curr->row + dr[i];
            nc = curr->col + dc[i];
            if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
            if (map[nr][nc] == 0 && visit[nr][nc] == 0)
            {
                --zero_tomato;
                if (zero_tomato == 0)return curr->day;
                Enqueue2(nr, nc, curr->day + 1);
                visit[nr][nc] = 1;
            }
        }
    }
    return -1;
    // if (zero_tomato != 0) return -1;
    //printf("r=%d, c=%d, day=%d\n", curr->row, curr->col, curr->day);
    
    //return curr->day - 1;
}
 
int main(void) {
    int TC;
#if 1
    (void)freopen("7576.txt", "r", stdin);
    (void)scanf("%d", &TC);
    getchar();
#endif
#if 1
    while (TC--) {
        (void)scanf("%d %d", &M, &N);
        init_Queue();
        input_data2();
        print_data(map);
        print_data(visit);

        printf("%d\n", solve_BFS());
        destroy_data2();
        destroy_Queue();
        printf("Done\n");
    }
#endif
    return 0;
}
#endif