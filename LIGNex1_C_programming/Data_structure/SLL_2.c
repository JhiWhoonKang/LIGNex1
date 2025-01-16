#include "SLL_2.h"

Node* SLL_CreateNode2(ElementType data) {
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

	printf("������� : %d\n", data);
	// prev, rnode Ž��

	for (prev = head, curr = head->next; curr != NULL; prev = curr, curr = curr->next) {
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
	prev->next = rnode->next;

	SLL_DestroyNode2(&rnode);
}*/

// curr: ������ ����� ������
// prev: ������ ����� �� ��� ������
// curr = head->next�� �������� �� ����: head�� dummy�̱� ������ �� �񱳰� �ʿ� ����
// ���� ���� ���� ù ��尡 ������ ����� prev = head, curr = head->next���� ���۵Ǵ� ���̹Ƿ�
void SLL_RemoveNode2(Node* head, ElementType data) {
	Node* prev = NULL;
	Node* curr = NULL;

	printf("������� : %d\n", data);
	// prev, rnode Ž��

	for (prev = head, curr = head->next; curr != NULL; prev = curr, curr = curr->next) 
	{
		if (curr->data == data) 
		{
			prev->next = curr->next;
			SLL_DestroyNode2(&curr);
			return;
		}
	}
	// ������ ��尡 ���� ���
	printf("������ ��尡 �����ϴ�.\n");
	return;
}

// prev - new_node - curr ���� ����
// curr�� pos��° node
// prev: pos�� ° ����� �� ��� ������
// curr = head->next�� �������� �� ����: head�� dummy�̱� ������ �� �񱳰� �ʿ� ����
void SLL_InsertNode2(Node* head, Node* new_node, int pos) {
	Node* curr = NULL;
	Node* prev = NULL;

	// [0] - [1] - [2] //[3]
	for (prev = head, curr = head->next;
		(curr != NULL) && (pos > 0);
		--pos, prev = curr, curr = curr->next);

	if (pos > 0) {
		printf("��ġ ��ȣ�� �߸� ���Ǿ����ϴ�.\n");
		return;
	}
	new_node->next = prev->next;  // new_node->next = curr;
	prev->next = new_node;
}

void SLL_print2(Node* head) {
	head = head->next;
	if (head == NULL) {
		printf("����� ��尡 �����ϴ�.\n");
		return;
	}
	for (;head != NULL;head = head->next) {
		printf("%d ", head->data);
	}
	printf("\n");
}