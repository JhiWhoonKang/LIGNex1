#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

// SLL_CreateNode, SLL_DestroyNode, SLL_print Ȯ���ڵ�
#if 0
#include "SLL.h"

int main(void) {
	Node* head = NULL;
	Node* a;
	Node* b;
	Node* c;
	a = SLL_CreateNode(100);
	b = SLL_CreateNode(200);
	c = SLL_CreateNode(300);
	head = a;
	a->next = b;
	b->next = c;
	printf("%d %d %d\n", head->data, head->next->data, head->next->next->data);
	SLL_print(head);
	SLL_DestroyNode(&a);
	SLL_DestroyNode(&b);
	SLL_DestroyNode(&c);
	return 0;
}
#endif

// SLL_AppendNode
#if 0
#include "SLL.h"

int main(void) {
	Node* head = NULL;
	SLL_AppendNode(&head, SLL_CreateNode(100));
	SLL_AppendNode(&head, SLL_CreateNode(200));
	SLL_AppendNode(&head, SLL_CreateNode(300));
	SLL_print(head);
	SLL_RemoveNode(&head, 100);
	SLL_print(head);
	SLL_RemoveNode(&head, 300);
	SLL_print(head);
	SLL_RemoveNode(&head, 400);
	SLL_print(head);
	SLL_RemoveNode(&head, 200);
	SLL_print(head);
	return 0;
}

#endif

// free �Լ��� ����
#if 0
int main(void) {
	int* temp = NULL;
	int a = 100;
	int* p = (int*)malloc(20);
	//free(temp);  // �̻� ���� - ���� (NULL�� ���)
	//free(p);     // �̻� ���� - ���� (�Ҵ���� �޸��� �����ּ��� ���)
	
	//free(&a);    // heap memory �ƴ� ��� - ����
	//free(p + 1); // heap memory ������, �Ҵ���� �����ּҰ� �ƴ� ��� - ����
	return 0;
}
#endif

// head�� ���ſ� ���� ����
#if 0
#include "SLL.h"
// curr�� ����� �ʼ�
Node* SLL_AppendNode2(Node* head, Node* new_node) {
	Node* curr = head;
	if (curr == NULL) {
		return new_node;
	}
	for (;curr->next != NULL;curr = curr->next);
	curr->next = new_node;
	return head;
}

int main(void) {
	Node* head = NULL;
	head = SLL_AppendNode2(head, SLL_CreateNode(100));
	SLL_print(head);
	return 0;
}

#endif

// SLL_InsertNode�� ���� Ȯ��
#if 0
#include "SLL.h"

int main(void) {
	Node* head = NULL;

	SLL_print(head);
	SLL_InsertNode(&head, SLL_CreateNode(10), 0);  // 10
	SLL_AppendNode(&head, SLL_CreateNode(100));    // 10 100
	SLL_AppendNode(&head, SLL_CreateNode(200));    // 10 100 200
	SLL_AppendNode(&head, SLL_CreateNode(300));    // 10 100 200 300
	SLL_AppendNode(&head, SLL_CreateNode(400));    // 10 100 200 300 400
	SLL_print(head);
	SLL_InsertNode(&head, SLL_CreateNode(50), 0);  // 50 10 100 200 300 400
	SLL_print(head);
	SLL_InsertNode(&head, SLL_CreateNode(500), 6); // 50 10 100 200 300 400 500
	SLL_print(head);
	SLL_InsertNode(&head, SLL_CreateNode(600), 3); // 50 10 100 600 200 300 400 500
	SLL_print(head);
	return 0;
}
#endif


// SLL_2 
#if 1
#include "SLL_2.h"
int main(void) {


	return 0;
}
#endif