#pragma once
#include <stdio.h>

typedef int ElementType;

//typedef struct student
//{
//	int number;
//	char* name;
//	int scores[5];
//}ElementType;

#ifndef _STRUCT_NODE_
#define _STRUCT_NODE_
typedef struct _node
{
	ElementType data;
	struct _node* next;
}Node;
#endif

Node* SLL_Create_Node2(ElementType data);
void SLL_AppendNode2(Node* head, Node* newnode);
void SLL_InsertNode2(Node* head, Node* new_node, int pos);
void SLL_RemoveNode2(Node* head, ElementType data);
void SLL_print2(Node* head);
void free2(void* memblock);
void SLL_DestroyNode2(Node** dnode);