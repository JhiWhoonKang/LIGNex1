#include "SLL.h"

Node* SLL_CreateNode(ElementType data) {
	Node* new_node = NULL;

	new_node = (Node*)calloc(1, sizeof(Node));
	if (new_node == NULL) {
		printf("�޸� ����\n");
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

	printf("������� : %d\n", data);
	// prev, rnode Ž��
	for (curr = *head; curr != NULL; prev = curr, curr = curr->next) {
		if (curr->data == data) {
			rnode = curr;
			break;
		}
	}
	// ������ ��尡 ���� ���
	if (rnode == NULL) {
		printf("������ ��尡 �����ϴ�.\n");
		return;
	}

	// rnode�� head�� ��� ����
	if (*head == rnode) 
		*head = rnode->next;
	else // rnode�� head�� �ƴ� ��� ����
		prev->next = rnode->next;

	//  C = (      ) ? A : B
	//  C = rnode->next;

	SLL_DestroyNode(&rnode);
}

// prev - new_node - curr ���� ����
// curr�� pos��° node
void SLL_InsertNode(Node** head, Node* new_node, int pos) {
	Node* curr = NULL;
	Node* prev = NULL;
    
	// [0] - [1] - [2] //[3]
	for (curr = *head;
		(curr != NULL) && (pos > 0);
		--pos, prev = curr, curr = curr->next);

	if (pos > 0) {
		printf("��ġ ��ȣ�� �߸� ���Ǿ����ϴ�.\n");
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
		printf("����� ��尡 �����ϴ�.\n");
		return;
	}
	while (head != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}
