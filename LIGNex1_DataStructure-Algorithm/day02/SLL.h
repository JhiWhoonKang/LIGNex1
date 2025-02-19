#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef int ElementType;

//typedef struct student {
//	int number;
//	char* name;
//	int scores[5];
//}ElementType;

#ifndef _STRUCT_NODE_
#define _STRUCT_NODE_
typedef struct _node {
	ElementType data;
	struct _node* next;
}Node;
#endif

Node* SLL_CreateNode(ElementType data);
void SLL_DestroyNode(Node** dnode);
void SLL_AppendNode(Node** head, Node* new_node);
void SLL_RemoveNode(Node** head, ElementType data);
void SLL_InsertNode(Node** head, Node* new_node, int pos);
void SLL_print(Node* head);
