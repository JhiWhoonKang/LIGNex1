#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

// SLL_CreateNode, SLL_DestroyNode, SLL_print 확인코드
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

// free 함수의 이해
#if 0
int main(void) {
	int* temp = NULL;
	int a = 100;
	int* p = (int*)malloc(20);
	//free(temp);  // 이상 없음 - 정상 (NULL인 경우)
	//free(p);     // 이상 없음 - 정상 (할당받은 메모리의 시작주소인 경우)
	
	//free(&a);    // heap memory 아닌 경우 - 오류
	//free(p + 1); // heap memory 이지만, 할당받은 시작주소가 아닌 경우 - 오류
	return 0;
}
#endif

// head의 갱신에 대한 제어
#if 0
#include "SLL.h"
// curr의 사용이 필수
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

// SLL_InsertNode의 동작 확인
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