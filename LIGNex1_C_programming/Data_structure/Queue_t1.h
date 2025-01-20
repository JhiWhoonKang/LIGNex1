#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// M : ����ĭ�� ��, N : ����ĭ�� ��
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
int rear;  // Node * rear �� ����� �� ��
int front;

void input_data2(void);
void destroy_data2(void);
void print_data(int** arr);
void Enqueue2(int r, int c, int d);
Node* Dequeue2(void);
void init_Queue(void);
void destroy_Queue(void);
