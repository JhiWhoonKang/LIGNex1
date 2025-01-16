#include "SLL.h"

Node* SLL_Create_Node(ElementType data)
{
	Node* new_node = NULL;
	// 1. �Ҵ�
	new_node = (Node*)calloc(1, sizeof(Node));
	// 2. ���� �Ҵ� Ȯ��
	if (new_node == NULL)
	{
		printf("�޸� ����\n");
		exit(0);
	}
	// 3. �ʱ�ȭ
	new_node->data = data;
	new_node->next = NULL;

	return new_node;
}

Node* SLL_AppendNode(Node** head, Node* new_node)
{
	Node* curr = *head;

	if (*head == NULL) //*curr�� ����
	{
		*head = new_node; // *curr �Ұ��� => ����: ���� ����
		return;
	}
	for (;curr->next != NULL;curr = curr->next);
	curr->next = new_node;
}

Node* SLL_AppendNode2(Node* head, Node* new_node)
{
	Node* curr = head;
	if (curr == NULL)
	{
		return new_node;
	}
	for (;curr->next != NULL;curr = curr->next);
	curr->next = new_node;

	return head;
}

void SLL_InsertNode(Node** head, Node* new_node, int pos)
{
	Node* curr = NULL;
	Node* prev = NULL;
	// [1] - [2] - [3] - [4]
	for (curr = *head;\
		(curr != NULL) && (pos > 0);\
		--pos, prev = curr, curr = curr->next);
	if (pos > 0)
	{
		printf("��ġ ��ȣ�� �߸� ���Ǿ����ϴ�.\n");
		return;
	}

	if (prev == NULL)
	{
		new_node->next = *head;
		*head = new_node;		
	}
	else
	{
		new_node->next = prev->next;//new_node -> next = curr;
		prev->next = new_node;
	}
}

void SLL_RemoveNode(Node** head, ElementType data)
{
	Node* rnode = NULL;
	Node* prev = NULL;
	Node* curr = NULL;

	printf("���� ���� ���: %d\n", data);
	
	for (curr = *head;curr != NULL;prev = curr, curr = curr->next)
	{
		if (curr->data == data)
		{
			rnode = curr;
			break;
		}
	}

	if (curr == NULL)
	{
		printf("==������ ��尡 �����ϴ�.==\n");
		return;
	}

	if (*head == rnode)
	{
		*head = rnode->next;		
	}
	else
	{
		prev->next = rnode->next;
	}
	SLL_DestroyNode(&rnode);
}

void SLL_print(Node* head)
{
	if (head == NULL)
	{
		printf("����� ��尡 �����ϴ�.\n");
	}
	for (;head != NULL;head = head->next)
	{
		printf("%d ", head->data);
	}
	printf("\n");
	/*while (head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}*/
}

void SLL_DestroyNode(Node** dnode)
{
	free(*dnode);
	*dnode = NULL;
}