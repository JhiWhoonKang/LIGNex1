#include "Queue_t1.h"

// M,N �Է� �ް�, map, visit�� �޸� �Ҵ� �� �ʱ�ȭ
// �̷� ���� �ึ�� ���� ������ �ٸ� ��� ���
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
// �࿡ ���Ե� ���� ������ ������ ��� ���
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
            // ���� �丶�� Queue�� �ְ�, �湮ǥ��
            if (map[i][j] == 1) {
                Enqueue2(i, j, 1);
                visit[i][j] = 1;
            }
            // ������ �丶�� ��������
            if (map[i][j] == 0) {
                ++zero_tomato;
            }
        }
    }

    printf("�ִ��丶�䰳�� : %d, �����丶�� : %d, �������丶�� : %d\n", M * N, rear, zero_tomato);
}

// �Ҵ���� �޸� �ݳ�
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
    // Queue Full ���� ���� ��� ��
    Queue[rear].row = r;
    Queue[rear].col = c;
    Queue[rear].day = d;
    rear += 1;
}

Node* Dequeue1(void) {
    int ret = front;
    // Queue Empty ���� ����
    if (front == rear) return NULL;
    front += 1;
    return Queue + ret;
}

// Queue�� Full, Empty ���� ���� ���� �ۼ�
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