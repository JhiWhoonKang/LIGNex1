#include "Queue_t1.h"

// M,N 입력 받고, map, visit의 메모리 할당 및 초기화
// 이런 경우는 행마다 열의 개수가 다른 경우 사용
void input_data1(void) {
    int i, j;
    (void)scanf("%d %d", &M, &N);
    map = (int**)calloc(N, sizeof(int*));
    if (!map) return;
    for (i = 0; i < N; i++) {
        map[i] = (int*)calloc(M, sizeof(int));
        if (!map[i]) return;
        for (j = 0; j < M; j++) {
            (void)scanf("%d", map[i] + j);
        }
    }
    visit = (int**)calloc(N, sizeof(int*));
    if (!visit) return;
    for (i = 0; i < N; i++) {
        visit[i] = (int*)calloc(M, sizeof(int));
        if (!visit[i]) return;
    }
}
// 행에 포함된 열의 개수가 동일한 경우 사용
void input_data2(void) {
    int i, j;
    int* temp;
    visit = (int**)calloc(N, sizeof(int*));
    if (!visit) return;
    temp = (int*)calloc(N * M, sizeof(int));
    if (!visit) return;
    for (i = 0; i < N; i++) {
        visit[i] = temp + (i * M);
    }

    map = (int**)calloc(N, sizeof(int*));
    if (!map) return;
    temp = (int*)calloc(N * M, sizeof(int));
    if (!temp) return;

    zero_tomato = 0;
    for (i = 0; i < N; i++) {
        map[i] = temp + (i * M);
        for (j = 0; j < M; j++) {
            (void)scanf("%d", map[i] + j);
            // 익은 토마토 Queue에 넣고, 방문표시
            if (map[i][j] == 1) {
                Enqueue2(i, j, 1);
                visit[i][j] = 1;
            }
            // 안익은 토마토 개수세기
            if (map[i][j] == 0) {
                ++zero_tomato;
            }
        }
    }

    printf("최대토마토개수 : %d, 익은토마토 : %d, 안익은토마토 : %d\n", M * N, rear, zero_tomato);
}

// 할당받은 메모리 반납
void destroy_data1(void) {
    int i;
    for (i = 0; i < N; ++i) {
        free(map[i]);
        free(visit[i]);
    }
    free(map);
    free(visit);
    map = NULL;
    visit = NULL;
}

void destroy_data2(void) {
    free(map[0]);
    free(map);
    free(visit[0]);
    free(visit);
    map = NULL;
    visit = NULL;
}

void print_data(int** arr) {
    int i, j;
    for (i = 0; i < N; ++i) {
        for (j = 0; j < M; ++j) {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void Enqueue1(int r, int c, int d) {
    if (!Queue | (rear == M * N)) return;
    // Queue Full 상태 점검 없어도 됨
    Queue[rear].row = r;
    Queue[rear].col = c;
    Queue[rear].day = d;
    rear += 1;
}

Node* Dequeue1(void) {
    int ret = front;
    // Queue Empty 상태 점검
    if (front == rear) return NULL;
    front += 1;
    return Queue + ret;
}

// Queue의 Full, Empty 상태 점검 없이 작성
void Enqueue2(int r, int c, int d) {
    Queue[rear].row = r;
    Queue[rear].col = c;
    Queue[rear].day = d;
    rear += 1;
    //Queue[rear++] = data;
}

Node* Dequeue2(void) {
    return Queue + front++;
}

void init_Queue(void) {
    Queue = (Node*)calloc(M * N, sizeof(Node));
    front = rear = 0;
}
void destroy_Queue(void) {
    free(Queue);
    Queue = NULL;
}