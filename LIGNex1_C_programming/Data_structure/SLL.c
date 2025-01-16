#include "SLL.h"

Node* SLL_Create_Node(ElementType data)
{
	Node* new_node = NULL;
	// 1. 할당
	new_node = (Node*)calloc(1, sizeof(Node));
	// 2. 정상 할당 확인
	if (new_node == NULL)
	{
		printf("메모리 부족\n");
		exit(0);
	}
	// 3. 초기화
	new_node->data = data;
	new_node->next = NULL;

	return new_node;
}

Node* SLL_AppendNode(Node** head, Node* new_node)
{
	Node* curr = *head;

	if (*head == NULL) //*curr도 가능
	{
		*head = new_node; // *curr 불가능 => 이유: 쓰기 동작
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
		printf("위치 번호가 잘못 사용되었습니다.\n");
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

	printf("삭제 예정 노드: %d\n", data);
	
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
		printf("==삭제할 노드가 없습니다.==\n");
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
		printf("출력할 노드가 없습니다.\n");
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