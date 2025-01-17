#include "DLL.h"

void DLL_Init(DLLNode* head, DLLNode* tail)
{
	head->next = tail;
	tail->prev = head;
}

DLLNode* DLL_CreateNode(DLL_ElementType data)
{
	DLLNode* new_node = NULL;
	new_node = (DLLNode*)calloc(1, sizeof(DLLNode));
	if (new_node == NULL) 
	{
		printf("메모리 부족\n");
		exit(0);
	}
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;
}

void DLL_DestroyNode(DLLNode** dnode)
{
	free(*dnode);
	*dnode = NULL;
}

void DLL_AppendNode(DLLNode* tail, DLLNode* newnode)
{
	newnode->next = tail;
	newnode->prev = tail->prev; //tail->prev: r-value

	tail->prev->next = newnode; //아래 코드와 순서 중요 //tail->prev: r-value
	tail->prev = newnode; //tail->prev: l-value => prev로 수정 불가
}

void DLL_InsertBefore(DLLNode* tail, DLLNode* newnode)
{
	newnode->next = tail;
	newnode->prev = tail->prev; //tail->prev: r-value

	tail->prev->next = newnode; //아래 코드와 순서 중요 //tail->prev: r-value
	tail->prev = newnode; //tail->prev: l-value => prev로 수정 불가
}

// 순서 고려 안해도 됨
void DLL_AppendNode2(DLLNode* tail, DLLNode* newnode)
{
	if (tail == NULL) return;

	DLLNode* prev = tail->prev;

	newnode->next = tail;
	newnode->prev = prev; //newnode: r-value, newnode->prev: l-value, prev: r-value

	prev->next = newnode; 
	tail->prev = newnode;
}

void DLL_InsertBefore2(DLLNode* tail, DLLNode* newnode)
{
	if (tail == NULL) return;

	DLLNode* prev = tail->prev;

	newnode->next = tail;
	newnode->prev = prev; //newnode: r-value, newnode->prev: l-value, prev: r-value

	prev->next = newnode;
	tail->prev = newnode;
}

void DLL_print(DLLNode* head, DLLNode* tail)
{
	DLLNode* curr = NULL;

	for (curr = head->next;curr != tail;curr = curr->next)
	{
		printf("%c ", curr->data);
	}
	printf("\n");
	/*for (curr = tail->prev;curr != head;curr = curr->prev)
	{
		printf("%c ", curr->data);
	}
	printf("\n");*/
}

DLLNode* DLL_FindNode(DLLNode* head, DLLNode* tail, DLL_ElementType data)
{
	DLLNode* curr = NULL;
	for (curr = head->next;curr != tail;curr = curr->next)
	{
		if (curr->data == data)
		{
			printf("%c 발견\n", curr->data);
			return curr;
		}
	}
	printf("미발견\n");
	return NULL;
}

void DLL_RemoveNode(DLLNode* rnode)
{
	if (rnode == NULL) return;
	rnode->prev->next = rnode->next;
	rnode->next->prev = rnode->prev;
}

DLLNode* DLL_GetAt(DLLNode* head, DLLNode* tail, int pos)
{
	DLLNode* curr = NULL;
	for (curr = head->next;(curr->next != tail) && pos;--pos, curr = curr->next);
	if (pos)
	{
		printf("position 입력 오류\n");
		return NULL;
	}
	return curr;
}

void DLL_InsertNode(DLLNode* head, DLLNode* tail, DLLNode* newnode, int pos)
{
	/*DLLNode* temp;
	temp = DLL_GetAt(head, tail, pos);
	if (temp)
	{
		DLL_AppendNode(temp, newnode);
	}*/

	DLL_AppendNode2(DLL_GetAt(head, tail, pos), newnode);
}

// head 뒤에 newnode 삽입
void DLL_InsertAfter(DLLNode* temp, DLLNode* newnode)
{
	if (!temp)return NULL;
	newnode->prev = temp;
	newnode->next = temp->next;

	temp->next->prev = newnode;
	temp->next = newnode;
}

void DLL_InsertAfter2(DLLNode* head, DLLNode* newnode)
{
	if (!head)return NULL;
	DLLNode* temp = head->next;
	newnode->prev = head;
	newnode->next = temp;

	temp->prev = newnode;
	head->next = newnode;
}