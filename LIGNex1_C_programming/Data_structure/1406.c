//https://www.acmicpc.net/problem/1406
/*
* 초기 cursor 위치: 맨 뒤
* 최대 600,000 글자
* L -> cursor->왼쪽 이동
* D -> cursor->오른쪽 이동
* B -> cursor 왼쪽 문자 삭제
* P _ -> cursor 왼쪽 문자 _ 추가
*/
#if 0
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 600000

typedef char ElementType;

typedef struct _node
{
	char data;
	struct _node* prev;
	struct _node* next;
}Node;

typedef struct _bus
{
	Node* head;
	Node* tail;
	Node* cursor;
}Bus;

Node* createNode(char data)
{
	Node* newnode = (Node*)calloc(1, sizeof(Node));
	if (!newnode)
	{
		printf("Memory Allocation Failed\n");
		exit(1);
	}

	newnode->data = data;
	return newnode;
}

Bus* createBus(char* input)
{
	Bus* bus = (Bus*)calloc(1, sizeof(Bus));
	if (!bus)
	{
		printf("Memory Allocation Failed\n");
		exit(1);
	}
	for (int i = 0; input[i] != '\0'; ++i)
	{
		Node* newnode = createNode(input[i]);
		if (!bus->head)
		{
			bus->head = newnode;
			bus->tail = newnode;
		}
		else
		{
			bus->tail->next = newnode;
			newnode->prev = bus->tail;
			bus->tail = newnode;
		}
	}
	bus->cursor = bus->tail;
	return bus;
}

void Left(Bus* bus)
{
	bus->cursor = bus->cursor->prev;
}

void Right(Bus* bus)
{
	if (bus->cursor == NULL)
	{
		return;
	}
	bus->cursor = bus->cursor->next;
}

// cursor 왼쪽 추가 => cursor->prev
void Insert(Bus* bus, char data)
{
	Node* newnode = createNode(data);

	if (bus->cursor == bus->tail) {
		newnode->next = bus->cursor;
		newnode->prev = bus->cursor->prev;
		if (bus->tail) {
			bus->tail->prev = newnode;
			newnode->next = bus->tail;
		}
		else {
			bus->head = newnode;
			bus->tail = newnode;
		}
	}
	else {
		newnode->next = bus->cursor;
		newnode->prev = bus->cursor->prev;
		if (bus->cursor->prev) 
		{
			bus->cursor->prev->next = newnode;
		}
		else 
		{
			bus->head = newnode;
		}
		bus->cursor->prev = newnode;
	}
}

void delete(Bus* bus)
{
	if (bus->cursor->prev)
	{
		Node* deletenode = bus->cursor->prev;
		if (deletenode->prev)
		{
			deletenode->prev->next = bus->cursor;
		}
		else
		{
			bus->head = bus->cursor;
		}
		bus->cursor->prev = deletenode->prev;
		free(deletenode);
	}
}

void freeBus(Bus** bus)
{	
	free(*bus);
	*bus = NULL;
}

void printBus(Bus* bus)
{
	Node* current = bus->head;
	while (current) 
	{
		printf("%c", current->data);
		current = current->next;
	}
	printf("\n");
}

int main(void)
{
	char input[MAX_LEN + 1];
	int cmd_cnt;

	(void)scanf("%s", input);
	(void)scanf("%d", &cmd_cnt);

	Bus* bus = createBus(input);

	for (int i = 0; i < cmd_cnt; ++i)
	{
		char cmd;
		(void)scanf(" %c", &cmd);

		if (cmd == 'L')
		{
			Left(bus);
		}
		else if (cmd == 'D')
		{
			Right(bus);
		}
		else if (cmd == 'B')
		{
			delete(bus);
		}
		else if (cmd == 'P')
		{
			char data;
			(void)scanf(" %c", &data);
			Insert(bus, data);
		}
		else
		{
			return 0;
		}
	}

	printBus(bus);
	freeBus(&bus);

	return 0;
}

#endif