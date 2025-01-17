#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if 01
typedef int ElementType;

typedef struct _node
{
	ElementType data;
	struct _node* next;
}Node;

typedef struct _queue
{
	Node* front;
	Node* rear;
	int count;
}ListQueue;

ListQueue* LQ_CreateQueue(void)
{
	ListQueue* temp;
	temp = (ListQueue*)calloc(1, sizeof(ListQueue));
	if (temp == NULL)
	{
		printf("메모리 부족!\n");
		return NULL;
	}
	temp->front = NULL;
	temp->rear = NULL;
	temp->count = 0;
	return temp;
}

Node* LQ_CreateNode(ElementType data)
{
	Node* temp;
	temp = (Node*)calloc(1, sizeof(Node));
	if (temp == NULL)
	{
		printf("메모리 부족2\n");
		return NULL;
	}
	temp->data = data;
	temp->next = NULL;
	return temp;
}

// rear의 뒤에 추가
// 초기에는 rear가 NULL
void LQ_EnQueue(ListQueue* Queue, Node* newnode)
{
	if (newnode == NULL) return;
	if (Queue->count == 0)	//	Queue->rear == NULL, Queue->front == NULL
	{
		Queue->front = newnode;
	}
	else
	{
		Queue->rear->next = newnode;
	}
	//Node** temp = (Queue->count) ? &Queue->rear->next : &Queue->front;
	//*temp = newnode;
	Queue->rear = newnode;
	++Queue->count;
}

ElementType LQ_DeQueue(ListQueue* Queue)
{
	if (Queue->count == 0)
	{
		printf("Queue Empty!");
		return NULL;
	}
	ElementType temp = Queue->front->data;
	if (Queue->count == 1)
	{
		Queue->rear = NULL;
		Queue->count = 0;
	}
	Queue->front = Queue->front->next;
	--Queue->count;
	if (!Queue->count)Queue->rear = NULL;
	return temp;
}

void LQ_print(ListQueue* Queue)
{
	Node* curr;
	for (curr = Queue->front;curr != NULL;curr = curr->next)
	{
		printf("%d ", curr->data);
	}
	printf("\n");
}

void searching(char name)
{
	
}

int main(void)
{
	char input;
	(void)scanf("%s", &input);
	char c;
	for (c != '\n')
	{

	}
}

#endif