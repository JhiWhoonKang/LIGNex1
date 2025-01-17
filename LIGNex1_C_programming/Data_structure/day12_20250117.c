#include "DLL.h"
// CREATE
#if 0


int main(void)
{
	DLLNode head = { 'A' };
	DLLNode tail = { 'B' };
	DLL_Init(&head, &tail);
	
	DLLNode* a;
	DLLNode* b;
	DLLNode* c;
	a = DLL_CreateNode('A');
	b = DLL_CreateNode('B');
	c = DLL_CreateNode('C');

	a->next = b;
	b->next = c;
	
	b->prev = a;
	c->prev = b;

	printf("%c %c %c\n", a->data, a->next->data, a->next->next->data);
	printf("%c %c %c\n", b->prev->data, b->data, b->next->data);
	printf("%c %c %c", c->prev->prev->data, c->prev->data, c->data);

	return 0;
}
#endif

#if 0
int main(void)
{
	DLLNode head = { 'A' };
	DLLNode tail = { 'B' };
	DLL_Init(&head, &tail);

	DLL_AppendNode(&tail, DLL_CreateNode('A'));
	DLL_AppendNode(&tail, DLL_CreateNode('B'));
	DLL_AppendNode(&tail, DLL_CreateNode('C'));

	DLL_print(&head, &tail);

	return 0;
}
#endif

// data와 같은 값을 가지는 노드 찾기
#if 0
int main(void)
{
	DLLNode head = { 'A' };
	DLLNode tail = { 'B' };
	DLLNode* temp = NULL;
	DLL_Init(&head, &tail);

	DLL_AppendNode(&tail, DLL_CreateNode('A'));
	DLL_AppendNode(&tail, DLL_CreateNode('B'));
	DLL_AppendNode(&tail, DLL_CreateNode('C'));

	DLL_print(&head, &tail);

	temp = DLL_FindNode(&head, &tail, 'A');
	if (temp) printf("%c\n", temp->data);
	
	temp = DLL_FindNode(&head, &tail, 'B');
	if (temp) printf("%c\n", temp->data);
	
	temp = DLL_FindNode(&head, &tail, 'C');
	if (temp) printf("%c\n", temp->data);
	
	temp = DLL_FindNode(&head, &tail, 'F');
	if (temp) printf("%c\n", temp->data);

	return 0;
}
#endif

//REMOVE
#if 0
int main(void)
{
	DLLNode head = { 'A' };
	DLLNode tail = { 'B' };
	DLLNode* temp = NULL;
	DLL_Init(&head, &tail);

	DLL_AppendNode(&tail, DLL_CreateNode('A'));
	DLL_AppendNode(&tail, DLL_CreateNode('B'));
	DLL_AppendNode(&tail, DLL_CreateNode('C'));

	DLL_print(&head, &tail);
	
	DLL_RemoveNode(DLL_FindNode(&head, &tail, 'A'));
	DLL_print(&head, &tail);

	DLL_RemoveNode(DLL_FindNode(&head, &tail, 'C'));
	DLL_print(&head, &tail);

	DLL_RemoveNode(DLL_FindNode(&head, &tail, 'D'));
	DLL_print(&head, &tail);

	return 0;
}
#endif

//GETAT
#if 0
int main(void)
{
	int i = 5;
	for (;i > 0;--i);
	printf("%d\n", i);

	DLLNode head = { 0 };
	DLLNode tail = { 0 };
	DLLNode* temp = NULL;
	DLL_Init(&head, &tail);

	DLL_AppendNode(&tail, DLL_CreateNode('A'));
	DLL_AppendNode(&tail, DLL_CreateNode('B'));
	DLL_AppendNode(&tail, DLL_CreateNode('C'));

	DLL_print(&head, &tail);
	temp = DLL_GetAt(&head, &tail, 3);

	if(temp) printf("%c", temp->data);

	return 0;
}
#endif

//INSERT
#if 0

int main(void)
{
	int i = 5;
	for (;i > 0;--i);
	printf("%d\n", i);

	DLLNode head = { 0 };
	DLLNode tail = { 0 };
	DLLNode* temp = NULL;
	DLL_Init(&head, &tail);

	DLL_AppendNode(&tail, DLL_CreateNode('A'));
	DLL_AppendNode(&tail, DLL_CreateNode('B'));
	DLL_AppendNode(&tail, DLL_CreateNode('C'));

	DLL_print(&head, &tail);

	DLL_InsertAfter(DLL_GetAt(&head, &tail, 0), DLL_CreateNode('0'));
	DLL_print(&head, &tail);
	return 0;
}
#endif

//큐 만들기
#if 0
typedef int ElementType;
#define SIZE (5)
ElementType Queue[SIZE];
int front, rear;

//삽입 연산
void EnQueue(ElementType data)
{
	//Queue가 가득찬 경우(Full)
	if (rear == SIZE)
	{
		printf("Full Queue\n");
		return;
	}
	Queue[rear++] = data;
	return;
}

//삭제 연산
ElementType DeQueue()
{
	//Queue가 비어있는 경우(Empty)
	if (front == rear) 
	{ 
		printf("Empty Queue\n");
		return;
	}
	return Queue[front++];
}

void printQueue(int start, int end)
{
	for (int i = front;i < rear;++i)
	{
		printf("%d ", Queue[i]);
	}
	printf("\n");
}

int main(void)
{
	//Queue의 사용 준비
	front = rear = 0;
	EnQueue(1); printQueue(front, rear);
	EnQueue(2); printQueue(front, rear);
	printf("DeQueue: %d\n", DeQueue());
	EnQueue(3); printQueue(front, rear);
	EnQueue(4); printQueue(front, rear);
	printf("DeQueue: %d\n", DeQueue());
	printQueue(front, rear);
	EnQueue(5); printQueue(front, rear);
	EnQueue(6); printQueue(front, rear);
	EnQueue(7); printQueue(front, rear);
	EnQueue(8); printQueue(front, rear);

	return 0;
}
#endif

//원형 큐
#if 0
typedef int ElementType;
#define SIZE (5)
ElementType Queue[SIZE];
int front, rear;

//삽입 연산
void EnQueue(ElementType data)
{
	//Queue가 가득찬 경우(Full)
	if ((rear + 1) % SIZE == front)
	{
		printf("Full Queue\n");
		return;
	}
	Queue[rear++] = data;
	return;
}

//삭제 연산
ElementType DeQueue()
{
	ElementType ret;
	//Queue가 비어있는 경우(Empty)
	if (front == rear)
	{
		printf("Empty Queue\n");
		return;
	}
	ret = Queue[front];
	Queue[front] = 0;//확인을 위한 것. 필수 x
	front = (front + 1) % SIZE;
	return ret;
}

void printQueue(void)
{
	for (int i = 0;i < SIZE;++i)
	{
		printf("%d ", Queue[i]);
	}
	printf("\n");
}

int main(void)
{
	//Queue의 사용 준비
	front = rear = 0;
	EnQueue(1); printQueue();
	EnQueue(2); printQueue();
	printf("DeQueue: %d\n", DeQueue());
	EnQueue(3); printQueue();
	EnQueue(4); printQueue();
	printf("DeQueue: %d\n", DeQueue());
	printQueue();
	EnQueue(5); printQueue();
	EnQueue(6); printQueue();
	EnQueue(7); printQueue();
	EnQueue(8); printQueue();

	return 0;
}
#endif

#if 0
typedef int ElementType;
typedef struct _node
{
	ElementType data;
}Node;

typedef struct _cq
{
	int capacity;
	int front;
	int rear;
	Node* node;
}CircularQueue;

CircularQueue* CQ_CreateQueue(int capacity)
{
	CircularQueue* temp;
	temp = (CircularQueue*)calloc(1, sizeof(CircularQueue));
	if (temp == NULL)
	{
		printf("메모리 부족 1\n");
		return NULL;
	}
	temp->node = (Node*)calloc(capacity + 1, sizeof(Node));
	if (temp->node == NULL)
	{
		printf("메모리 부족 2\n");
		return NULL;
	}
	temp->capacity = capacity;
	temp->front = 0;
	temp->rear = 0;

	return temp;
}

//삽입 연산
void EnQueue(CircularQueue*Queue,ElementType data)
{
	//Queue가 가득찬 경우(Full)
	if ((Queue->rear + 1) % (Queue->capacity+1) == Queue->front)
	{
		printf("Full Queue\n");
		return;
	}
	//Queue->node[Queue->rear].data = data;
	(Queue->node + Queue->rear)->data = data;
	Queue->rear = (Queue->rear + 1) % (Queue->capacity + 1);
}

//삭제 연산
ElementType DeQueue(CircularQueue* Queue)
{
	ElementType ret;
	//Queue가 비어있는 경우(Empty)
	if (Queue->front == Queue->rear)
	{
		printf("Empty Queue\n");
		return NULL;
	}
	ret = Queue->node[Queue->front].data;//	Queue[front]
	Queue->front = (Queue->front + 1) % (Queue->capacity + 1);
	return ret;
}

int main(void)
{
	CircularQueue* Queue;
	Queue = CQ_CreateQueue(5);

	EnQueue(Queue, 10);
	EnQueue(Queue, 20);
	printf("DeQueue: %d\n", DeQueue(Queue));
	EnQueue(Queue, 30);
	EnQueue(Queue, 40);
	printf("DeQueue: %d\n", DeQueue(Queue));
	EnQueue(Queue, 50);
	EnQueue(Queue, 60);
	EnQueue(Queue, 70);
	EnQueue(Queue, 80);

	return 0;
}
#endif

// 링크드리스트를 활용한 큐(Queue) 만들기 (더미 없음)
#if 01
typedef int ElementType;

typedef struct _node
{
	ElementType data;
	struct _node* next;
}Node;

typedef struct _queue
{
	Node* front;
	Node* rear;
	int count;	
}ListQueue;

ListQueue* LQ_CreateQueue(void)
{
	ListQueue* temp;
	temp = (ListQueue*)calloc(1, sizeof(ListQueue));
	if (temp == NULL)
	{
		printf("메모리 부족!\n");
		return NULL;
	}
	temp->front = NULL;
	temp->rear = NULL;
	temp->count = 0;
	return temp;
}

Node* LQ_CreateNode(ElementType data)
{
	Node* temp;
	temp = (Node*)calloc(1, sizeof(Node));
	if (temp == NULL)
	{
		printf("메모리 부족2\n");
		return NULL;
	}
	temp->data = data;
	temp->next = NULL;
	return temp;
}

// rear의 뒤에 추가
// 초기에는 rear가 NULL
void LQ_EnQueue(ListQueue* Queue, Node* newnode)
{
	if (newnode == NULL) return;
	if (Queue->count == 0)	//	Queue->rear == NULL, Queue->front == NULL
	{		
		Queue->front = newnode;		
	}
	else
	{
		Queue->rear->next = newnode;
	}
	//Node** temp = (Queue->count) ? &Queue->rear->next : &Queue->front;
	//*temp = newnode;
	Queue->rear = newnode;
	++Queue->count;
}

ElementType LQ_DeQueue(ListQueue* Queue)
{
	if (Queue->count == 0)
	{
		printf("Queue Empty!");
		return NULL;
	}
	ElementType temp = Queue->front->data;
	if (Queue->count == 1)
	{
		Queue->rear = NULL;
		Queue->count = 0;
	}
	Queue->front = Queue->front->next;
	--Queue->count;
	if (!Queue->count)Queue->rear = NULL;
	return temp;
}

void LQ_print(ListQueue* Queue)
{
	Node* curr;
	for (curr = Queue->front;curr != NULL;curr = curr->next)
	{
		printf("%d ", curr->data);
	}
	printf("\n");
}

int main(void)
{
	ListQueue* Queue = LQ_CreateQueue();
	LQ_EnQueue(Queue, LQ_CreateNode(100));
	LQ_EnQueue(Queue, LQ_CreateNode(200));
	LQ_EnQueue(Queue, LQ_CreateNode(300));
	LQ_EnQueue(Queue, LQ_CreateNode(400));
	LQ_print(Queue);
	printf("%d \n", LQ_DeQueue(Queue));
	printf("%d \n", LQ_DeQueue(Queue));
	LQ_print(Queue);
	return 0;
}
#endif