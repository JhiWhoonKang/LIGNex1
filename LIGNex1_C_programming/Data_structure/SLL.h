#pragma once
#include <stdio.h>

typedef int ElementType;

//typedef struct student
//{
//	int number;
//	char* name;
//	int scores[5];
//}ElementType;

typedef struct _node
{
	ElementType data;
	struct _node* next;
}Node;

Node* SLL_Create_Node(ElementType data);
Node* SLL_AppendNode(Node** head, Node* newnode);
void SLL_InsertNode(Node** head, Node* new_node, int pos);
void SLL_RemoveNode(Node** head, ElementType data);
void SLL_print(Node* head);
void free(void* memblock);
void SLL_DestroyNode(Node** dnode);