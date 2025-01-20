//https://www.acmicpc.net/problem/2563

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int main() {
    int n;
    int x, y;
    bool paper[MAX_SIZE][MAX_SIZE] = { false };

    (void)scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        (void)scanf("%d %d", &x, &y);

        for (int j = x; j < x + 10; j++) {
            for (int k = y; k < y + 10; k++) {
                paper[j][k] = true;
            }
        }
    }

    int area = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            if (paper[i][j]) {
                area++;
            }
        }
    }

    printf("%d\n", area);

    return 0;
}

#endif