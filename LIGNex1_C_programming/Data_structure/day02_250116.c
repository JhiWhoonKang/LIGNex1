#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//#include "SLL.h"

//Create_SLL_Node, print_SLL Ȯ�� �ڵ�
#if 0

int main(void)
{
	Node* head = NULL;
	Node* a;
	Node* b;
	Node* c;
	a = SLL_Create_Node(100);
	b = SLL_Create_Node(200);
	c = SLL_Create_Node(300);

	head = a;
	a->next = b;
	b->next = c;

	SLL_print(head);
	SLL_DestroyNode(&a);
	SLL_DestroyNode(&b);
	SLL_DestroyNode(&c);

	return 0;
}
#endif

//SLL_Append 
#if 0

int main(void)
{
	Node* head = NULL;
	SLL_AppendNode(&head, SLL_Create_Node(100));
	SLL_AppendNode(&head, SLL_Create_Node(200));
	SLL_AppendNode(&head, SLL_Create_Node(300));
	SLL_print(head);
	
	return 0;
}
#endif

//SLL_Destroy
#if 0

int main(void)
{
	Node* head = NULL;
	SLL_AppendNode(&head, SLL_Create_Node(100));
	SLL_AppendNode(&head, SLL_Create_Node(200));
	SLL_AppendNode(&head, SLL_Create_Node(300));
	SLL_print(head);

	SLL_RemoveNode(&head, 400);
	SLL_print(head);

	SLL_RemoveNode(&head, 100);
	SLL_print(head);
	
	SLL_RemoveNode(&head, 300);
	SLL_print(head);

	SLL_RemoveNode(&head, 200);
	SLL_print(head);
	
	return 0;
}
#endif

// free �Լ��� ����
#if 0
int main(void)
{
	int* temp = NULL;
	int a = 100;
	int* p = (int*)malloc(20);

	//free(temp); //�̻� ���� - ���� (NULL�� ���)
	//free(p); // �̻� ���� - ���� (�Ҵ���� �޸��� �����ּ��� ���)

	//free(&a);		// heap memory �ƴ� ��� - ����
	//free(p + 1);	// heap memory ������, �Ҵ���� �����ּҰ� �ƴ� ��� - ����

	return 0;
}
#endif

// heap�� ���ſ� ���� ����
#if 0
int main(void)
{
	Node* head = NULL;
	head = SLL_AppendNode2(head, SLL_Create_Node(100));
	SLL_print(head);

	return 0;
}
#endif

// SLL_InsertNode�� ���� Ȯ��
#if 0
int main(void)
{
	Node* head = NULL;
	
	SLL_print(head);
	SLL_InsertNode(&head, SLL_Create_Node(10), 0);
	SLL_AppendNode(&head, SLL_Create_Node(100));
	SLL_AppendNode(&head, SLL_Create_Node(200));
	SLL_AppendNode(&head, SLL_Create_Node(300));
	SLL_AppendNode(&head, SLL_Create_Node(400));
	SLL_print(head);

	SLL_InsertNode(&head, SLL_Create_Node(50), 0);
	SLL_print(head);
	
	SLL_InsertNode(&head, SLL_Create_Node(500), 5);
	SLL_print(head);
	
	SLL_InsertNode(&head, SLL_Create_Node(600), 5);
	SLL_print(head);

	return 0;
}
#endif

// SLL_2
#if 0
#define _STRUCT_NODE_
#include "SLL_2.h"

int main(void)
{
	Node head = { 0 };

	SLL_AppendNode2(&head, SLL_Create_Node2(100));
	SLL_AppendNode2(&head, SLL_Create_Node2(100));
	SLL_AppendNode2(&head, SLL_Create_Node2(300));

	
	SLL_print2(&head);

	return 0;
}
#endif
#include <stdio.h>
#if 01
int main(void)
{
	int i = 5;
	for (;i > 0;--i)
	{
		printf("%d", i);
	}
	printf("\n%d", i);
	
}
#endif