#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// M : 가로칸의 수, N : 세로칸의 수
int M, N;
int** map;
int** visit;
int zero_tomato;

typedef struct _node {
    int row;
    int col;
    int day;
}Node;
Node* Queue;
int rear;  // Node * rear 도 사용해 볼 것
int front;

void input_data2(void);
void destroy_data2(void);
void print_data(int** arr);
void Enqueue2(int r, int c, int d);
Node* Dequeue2(void);
void init_Queue(void);
void destroy_Queue(void);
