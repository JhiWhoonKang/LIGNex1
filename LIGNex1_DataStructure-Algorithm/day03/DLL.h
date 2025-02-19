#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef char DLL_ElementType;

typedef struct _dll_node {
	DLL_ElementType data;
	struct _dll_node* prev;
	struct _dll_node* next;
}DLLNode;

void DLL_Init(DLLNode* head, DLLNode* tail);
DLLNode* DLL_CreateNode(DLL_ElementType data);
void DLL_DestroyNode(DLLNode** dnode);
void DLL_InsertBefore(DLLNode* tail, DLLNode* newnode);
void DLL_print(DLLNode* head, DLLNode* tail);
DLLNode* DLL_FindNode(DLLNode* head, DLLNode* tail, DLL_ElementType data);
void DLL_RemoveNode(DLLNode* rnode);
DLLNode* DLL_GetAt(DLLNode* head, DLLNode* tail, int pos);
void DLL_InsertAfter(DLLNode* head, DLLNode* newnode);