#include "SLL.h"

Node* SLL_CreateNode(ElementType data) {
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

void SLL_DestroyNode(Node** dnode) {
	free(*dnode);
	*dnode = NULL;
}


void SLL_AppendNode(Node** head, Node* new_node) {
	Node* curr = *head;
	if (curr == NULL) {
		*head = new_node;
		return;
	}
	for (;curr->next != NULL;curr = curr->next);
	curr->next = new_node;
}

void SLL_RemoveNode(Node** head, ElementType data) {
	Node* rnode = NULL;
	Node* prev = NULL;
	Node* curr = NULL;

	printf("삭제노드 : %d\n", data);
	// prev, rnode 탐색
	for (curr = *head; curr != NULL; prev = curr, curr = curr->next) {
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

	// rnode가 head인 경우 제거
	if (*head == rnode) 
		*head = rnode->next;
	else // rnode가 head가 아닌 경우 제거
		prev->next = rnode->next;

	//  C = (      ) ? A : B
	//  C = rnode->next;

	SLL_DestroyNode(&rnode);
}

// prev - new_node - curr 으로 연결
// curr은 pos번째 node
void SLL_InsertNode(Node** head, Node* new_node, int pos) {
	Node* curr = NULL;
	Node* prev = NULL;
    
	// [0] - [1] - [2] //[3]
	for (curr = *head;
		(curr != NULL) && (pos > 0);
		--pos, prev = curr, curr = curr->next);

	if (pos > 0) {
		printf("위치 번호가 잘못 사용되었습니다.\n");
		return;
	}

	if (prev == NULL) {
		new_node->next = *head;
		*head = new_node;
	}
	else {
		new_node->next = prev->next;  // new_node->next = curr;
		prev->next = new_node;
	}
}

void SLL_print(Node* head) {
	if (head == NULL) {
		printf("출력할 노드가 없습니다.\n");
		return;
	}
	while (head != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}
