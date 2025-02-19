#include "DLL.h"

void DLL_Init(DLLNode* head, DLLNode* tail) {
	head->next = tail;
	tail->prev = head;
}

DLLNode* DLL_CreateNode(DLL_ElementType data) {
	DLLNode* newnode = NULL;
	newnode = (DLLNode*)calloc(1, sizeof(DLLNode));
	if (newnode == NULL) {
		printf("�޸� ����!\n");
		exit(0);
	}
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;
}

void DLL_DestroyNode(DLLNode** dnode) {
	free(*dnode);
	*dnode = NULL;
}

// tail �տ� newnode�� �߰��ϴ�
void DLL_InsertBefore(DLLNode *tail, DLLNode *newnode) {
	if (!tail) return;
	DLLNode* prev = tail->prev;
	newnode->next = tail;
	newnode->prev = prev;
	prev->next = newnode;
	tail->prev = newnode;
}

void DLL_print(DLLNode* head, DLLNode* tail) {
	DLLNode* curr = NULL;
	for (curr = head->next; curr != tail; curr = curr->next) {
		printf("%c ", curr->data);
	}
	printf("\n");
	for (curr = tail->prev; curr != head; curr = curr->prev) {
		printf("%c ", curr->data);
	}
	printf("\n");
}

// data�� ���� ���� ���� ���ã��
DLLNode* DLL_FindNode(DLLNode* head, DLLNode* tail, DLL_ElementType data) {
	DLLNode* curr = NULL;
	for (curr = head->next; curr != tail; curr = curr->next) {
		if (curr->data == data) {
			return curr;
		}
	}
	printf("��� Ž�� ����!\n");
	return NULL;
}

void DLL_RemoveNode(DLLNode* rnode) {
	if (rnode == NULL) {
		return;
	}
	rnode->prev->next = rnode->next;
	rnode->next->prev = rnode->prev;
}

DLLNode* DLL_GetAt(DLLNode* head, DLLNode* tail, int pos) {
	DLLNode* curr = NULL;
	for (curr = head->next; (curr->next != tail) && pos; --pos, curr = curr->next);

	if (pos) {
		return NULL;
	}
	return curr;
}

// head�� �ڿ� newnode ����
void DLL_InsertAfter(DLLNode* head, DLLNode* newnode) {
	if (!head) return;
	DLLNode* temp = head->next;
	newnode->prev = head;
	newnode->next = temp;
	temp->prev = newnode;
	head->next = newnode;
}