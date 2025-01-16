#include "SLL_2.h"

Node* SLL_CreateNode2(ElementType data) {
	Node* new_node = NULL;

	new_node = (Node*)calloc(1, sizeof(Node));
	if (new_node == NULL) {
		printf("메모리 부족\n");
		exit(0);
	}
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

void SLL_DestroyNode2(Node** dnode) {
	free(*dnode);
	*dnode = NULL;
}

void SLL_AppendNode21(Node* head, Node* new_node) {
	Node* curr = NULL;
	for (curr = head; curr->next != NULL;curr = curr->next);
	curr->next = new_node;
}

void SLL_AppendNode3(Node* head, Node* new_node) {
	for (; head->next != NULL;head = head->next);
	head->next = new_node;
}
/*
void SLL_RemoveNode2(Node* head, ElementType data) {
	Node* rnode = NULL;
	Node* prev = NULL;
	Node* curr = NULL;

	printf("삭제노드 : %d\n", data);
	// prev, rnode 탐색

	for (prev = head, curr = head->next; curr != NULL; prev = curr, curr = curr->next) {
		if (curr->data == data) {
			rnode = curr;
			break;
		}
	}
	// 삭제할 노드가 없는 경우
	if (rnode == NULL) {
		printf("삭제할 노드가 없습니다.\n");
		return;
	}
	prev->next = rnode->next;

	SLL_DestroyNode2(&rnode);
}*/

// curr: 삭제할 노드의 포인터
// prev: 삭제할 노드의 앞 노드 포인터
// curr = head->next를 시작으로 한 이유: head는 dummy이기 때문에 값 비교가 필요 없음
// 만일 값을 가진 첫 노드가 삭제할 노드라면 prev = head, curr = head->next부터 시작되는 것이므로
void SLL_RemoveNode2(Node* head, ElementType data) {
	Node* prev = NULL;
	Node* curr = NULL;

	printf("삭제노드 : %d\n", data);
	// prev, rnode 탐색

	for (prev = head, curr = head->next; curr != NULL; prev = curr, curr = curr->next) 
	{
		if (curr->data == data) 
		{
			prev->next = curr->next;
			SLL_DestroyNode2(&curr);
			return;
		}
	}
	// 삭제할 노드가 없는 경우
	printf("삭제할 노드가 없습니다.\n");
	return;
}

// prev - new_node - curr 으로 연결
// curr은 pos번째 node
// prev: pos번 째 노드의 앞 노드 포인터
// curr = head->next를 시작으로 한 이유: head는 dummy이기 때문에 값 비교가 필요 없음
void SLL_InsertNode2(Node* head, Node* new_node, int pos) {
	Node* curr = NULL;
	Node* prev = NULL;

	// [0] - [1] - [2] //[3]
	for (prev = head, curr = head->next;
		(curr != NULL) && (pos > 0);
		--pos, prev = curr, curr = curr->next);

	if (pos > 0) {
		printf("위치 번호가 잘못 사용되었습니다.\n");
		return;
	}
	new_node->next = prev->next;  // new_node->next = curr;
	prev->next = new_node;
}

void SLL_print2(Node* head) {
	head = head->next;
	if (head == NULL) {
		printf("출력할 노드가 없습니다.\n");
		return;
	}
	for (;head != NULL;head = head->next) {
		printf("%d ", head->data);
	}
	printf("\n");
}