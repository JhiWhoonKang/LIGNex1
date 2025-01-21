//tree
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#if 0
typedef int ElementType;
typedef struct _treeNode
{
	ElementType data;
	struct _treeNode* left;
	struct _treeNode* right;
}tNode;
typedef tNode* tNodeP;
tNode* Tree_CreateNode(ElementType data)
{
	tNode* newNode;
	newNode = (tNode*)calloc(1, sizeof(tNode));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void Tree_DestroyNode(tNode** node)
{
	free(*node);
	*node = NULL;
}

void Tree_PreorderPrint(tNodeP node)
{
	if (node == NULL)return;
	printf("%d ", node->data);
	Tree_PreorderPrint(node->left);
	Tree_PreorderPrint(node->right);
}

void Tree_InorderPrint(tNodeP node)
{
	if (node == NULL)return;	
	Tree_PreorderPrint(node->left);
	printf("%d ", node->data);
	Tree_PreorderPrint(node->right);
}

void Tree_PostorderPrint(tNodeP node)
{
	if (node == NULL)return;	
	Tree_PreorderPrint(node->left);
	Tree_PreorderPrint(node->right);
	printf("%d ", node->data);
}

void Tree_DestroyNode(tNodeP node)
{
	if (node == NULL)return;
	Tree_DestroyTree(node->left);
	Tree_DestroyTree(node->right);
	Tree_DestroyNode(&node);
}


int main(void)
{
	tNodeP a, b, c;
	tNodeP root;
	a = Tree_CreateNode(10); printf("\nn");
	b = Tree_CreateNode(20); printf("\nn");
	c = Tree_CreateNode(30); printf("\nn");
	root = a;
	root->left = b;
	root->right = c;
	//Tree_PreorderPrint(root);
	Tree_PostorderPrint(root);

	return 0;
}


#endif

#if 0
#include "Heap.h"

int main(void) {
	heapTree* hTree;
	int N, num;
	FILE* fp = NULL;
	htNode result = { 0 };

	fp = fopen("data_heap.txt", "r");
	if (fp == NULL) {
		return 1;
	}
	(void)fscanf(fp, "%d", &N);
	hTree = HT_CreateTree(20, comp_max);
	for (int i = 0; i < N; ++i) {
		(void)fscanf(fp, "%d", &num);
		HT_InsertNode(hTree, num);
	}
	HT_PrintTree(hTree);
	for (int i = 0; i < N; ++i) {
		result = HT_PopRoot(hTree);
		printf("%d ", result.data);
	}
	printf("\n");
	HT_DestroyTree(hTree);
	hTree = NULL;
	return 0;
}
#endif

#if 0
#include <stdint.h>
#include "Heap.h"  // 위 코드가 포함된 헤더 파일

int main() {
	int N, K;
	scanf("%d %d", &N, &K);

	int* arr = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	// 최대 힙과 최소 힙 생성
	heapTree* maxHeap = HT_CreateTree(K, comp_max); // 중앙값 이하 저장
	heapTree* minHeap = HT_CreateTree(K, comp_min); // 중앙값 이상 저장

	int64_t sum = 0;

	for (int i = 0; i < N; i++) {
		// 새로운 값 삽입
		if (maxHeap->usedsize == 0 || arr[i] <= maxHeap->node[1].data) {
			HT_InsertNode(maxHeap, arr[i]);
		}
		else {
			HT_InsertNode(minHeap, arr[i]);
		}

		// 힙 균형 유지
		if (maxHeap->usedsize > minHeap->usedsize + 1) {
			HT_InsertNode(minHeap, HT_PopRoot(maxHeap).data);
		}
		else if (minHeap->usedsize > maxHeap->usedsize) {
			HT_InsertNode(maxHeap, HT_PopRoot(minHeap).data);
		}

		// 중앙값 계산 및 합산
		if (i >= K - 1) {
			sum += maxHeap->node[1].data;

			// 슬라이딩 윈도우: 윈도우에서 제외될 값 제거
			int toRemove = arr[i - K + 1];
			if (toRemove <= maxHeap->node[1].data) {
				for (int j = 1; j <= maxHeap->usedsize; j++) {
					if (maxHeap->node[j].data == toRemove) {
						maxHeap->node[j] = HT_PopRoot(maxHeap).data;
						break;
					}
				}
			}
			else {
				for (int j = 1; j <= minHeap->usedsize; j++) {
					if (minHeap->node[j].data == toRemove) {
						minHeap->node[j] = HT_PopRoot(minHeap).data;
						break;
					}
				}
			}

			// 힙 균형 유지
			if (maxHeap->usedsize > minHeap->usedsize + 1) {
				HT_InsertNode(minHeap, HT_PopRoot(maxHeap).data);
			}
			else if (minHeap->usedsize > maxHeap->usedsize) {
				HT_InsertNode(maxHeap, HT_PopRoot(minHeap).data);
			}
		}
	}

	printf("%lld\n", sum);

	// 힙 메모리 해제
	HT_DestroyTree(maxHeap);
	HT_DestroyTree(minHeap);
	free(arr);

	return 0;
}

#endif

//이진탐색
#if 0
int comp_int(const void* a, const void* b)
{
	return *(int*)a - *(int*)b; //양수 1
}
void print_ary(int* arr, int size)
{
	int i;
	for(i=0;i<size;++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int BinarySearch(int *arr, int size, int data)
{
	int mid;
	int start, end;
	start = 0;
	end = size - 1;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (arr[mid] == data)
		{
			return mid;
		}
		if (arr[mid] < data)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}		
	}
	return -1;
}

int main(void)
{
	int idx;
	int data = 10;
	int arr[] = { 4,10,3,5,2,8,1,9,6,7 };
	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), comp_int);
	print_ary(arr, sizeof(arr) / sizeof(arr[0]));
	idx = BinarySearch(arr, sizeof(arr) / sizeof(arr[0]), data);
	printf("arr[%d] = %d\n", idx, data);
	return 0;
}
#endif

//https://jungol.co.kr/problem/2788
#if 01
#include "Heap.h"
int BinarySearch_upper(int* arr, int size, int data)
{
	int mid, curr;
	int start, end;
	start = 0;
	end = size - 1;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (arr[mid] == data)
		{
			return mid;
		}
		if (arr[mid] < data)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
			curr = mid;
		}
	}
	return curr;
}

int BinarySearch_lower(int* arr, int size, int data)
{
	int mid, curr;
	int start, end;
	start = 0;
	end = size - 1;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (arr[mid] == data)
		{
			return mid;
		}
		if (arr[mid] < data)
		{
			start = mid + 1;
			curr = mid;
		}
		else
		{
			end = mid - 1;
		}
	}
	return curr;
}

int comp_int(const void* a, const void* b)
{
	return *(int*)a - *(int*)b; //양수 1
}
int main(void)
{
	int N;
	(void)scanf("%d", &N);
	int arr[1001] = { 0 };
	for (int i = 0;i < N;++i)
	{
		(void)scanf("%d", &arr[i]);
	}
	int cnt = 0;
	int d1, d2;
	qsort(arr, N, sizeof(int), comp_int);
#if 01
	d1 = printf("%d ", BinarySearch_lower(arr, N, 8));
	d2 = printf("%d ", BinarySearch_upper(arr, N, 8));
	
#endif
#if 0
	printf("arr: ");
	for (int i = 0;i < N;++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n\n");
	for (int i = 0;i < N - 2;++i)
	{
		for (int j = i + 1;j < N - 1;++j)
		{
			d1 = arr[j] - arr[i];
			for (int k = j + 1;k < N;++k)
			{
				d2 = arr[k] - arr[j];
				if (d1 * 2 < d2) break;
				if ((d1 <= d2) && (d2 <= d1 * 2))
				{
					++cnt;
				}
			}
		}
	}

	printf("%d", cnt);
#endif

#if 01
	int r_start, r_end;
	for (int i = 0;i < N - 2;++i)
	{
		for (int j = i + 1;j < N - 1;++j)
		{
			d1 = arr[j] - arr[i];
			r_start = BinarySearch_upper(arr, N, arr[j] + d1);
			r_end = BinarySearch_lower(arr, N, arr[j] + d1 * 2);
			if (r_start == -1)continue;
			printf("%d %d\n", r_start, r_end);
			cnt += (r_end - r_start + 1);
		}
	}
	printf("%d\n", cnt);
#endif
	return 0;
}
#endif

//https://www.acmicpc.net/problem/1715
#if 0
#include "Heap.h";

int comp_int(const void* a, const void* b)
{
	return *(int*)a - *(int*)b; //양수 1
}

int main(void)
{
	heapTree* tree = NULL;
	int N, num, res;
	ElementType a, b;
	(void)freopen("data_1715.txt", "r", stdin);
	(void)scanf("%d", &N);
	tree = HT_CreateTree(N + 1, comp_min);

	for (int i = 0;i < N;++i)
	{
		(void)scanf("%d", &num);
		HT_InsertNode(tree, num);
	}
	res = 0;
	for (int i = 0; i < N - 1; ++i) {
		a = HT_PopRoot(tree).data;
		b = HT_PopRoot(tree).data;
		c = a + b;
		HT_InsertNode(tree, c);
		res += c;
	}
	printf("%d\n", res);
	return 0;
}
#endif

//
#if 0
#include "Heap.h"

int main(void)
{
	int N;
	(void)scanf("%d", &N);
	heapTree* maxHeap = HT_CreateTree(N / 2 + 2, comp_max);
	heapTree* minHeap = HT_CreateTree(N / 2 + 2, comp_min);
	htNode* maxArr = maxHeap->node;
	htNode* minArr = minHeap->node;
	for (int i = 0;i < N;++i)
	{
		int num;
		(void)scanf("%d", &num);
		if (i % 2)
		{
			HT_InsertNode(minHeap, num);
			//printf("%d\n", maxArr[1].data);
		}
		else
		{
			HT_InsertNode(maxHeap, num);			
			
		}
		if (minHeap->usedsize > 0 && maxArr[1].data > minArr[1].data)
		{
			htNode temp1 = HT_PopRoot2(maxHeap);
			htNode temp2 = HT_PopRoot2(minHeap);
			HT_InsertNode(maxHeap, temp2.data);
			HT_InsertNode(minHeap, temp1.data);
		}
		printf("%d\n", maxArr[1].data);
	}

	return 0;
}
#endif

//강사님
#if 0
#include "Heap.h";

int main(void)
{
	heapTree* minHeap = NULL;
	heapTree* maxHeap = NULL;
	int N, num, data1, data2, result;
	
	(void)freopen("data_1655.txt", "r", stdin);
	(void)scanf("%d", &N);
	maxHeap = HT_CreateTree(N / 2 + 2, comp_max);
	minHeap = HT_CreateTree(N / 2 + 2, comp_min);
	htNode a, b;
	for (int i = 0;i < N;++i)
	{
		scanf("%d", &num);
		if (maxHeap->usedsize == minHeap->usedsize)
		{
			HT_InsertNode(maxHeap, num);
		}
		else
		{
			HT_InsertNode(minHeap, num);
		}
		if (minHeap->usedsize > 0)
		{
			if (maxHeap->node[1].data > minHeap->node[1].data)
			{
				a = HT_PopRoot(maxHeap);
				b = HT_PopRoot(minHeap);			
				HT_InsertNode(maxHeap, b.data);
				HT_InsertNode(minHeap, a.data);
			}
		}
		printf("%d\n", maxHeap->node[1].data);
	}
	HT_DestroyTree(maxHeap);
	HT_DestroyTree(minHeap);
	return 0;
}
#endif

#if 0
// 두 개의 힙큐(트리) 사용 - minHeap, maxHeap 필요
// https://www.acmicpc.net/problem/1655
#include "Heap.h"
#include <stdio.h>
#include <stdlib.h>


int main(void) {
	heapTree* minHeap = NULL;
	heapTree* maxHeap = NULL;
	heapTree* heap[2] = { 0 };
	htNode a, b;
	int N;
	int num;

	(void)freopen("data_1655.txt", "r", stdin);
	(void)scanf("%d", &N);
	maxHeap = HT_CreateTree(N / 2 + 2, comp_max);
	minHeap = HT_CreateTree(N / 2 + 2, comp_min);
	heap[0] = maxHeap;
	heap[1] = minHeap;
	for (int i = 0; i < N; ++i) {
		(void)scanf("%d", &num);
		HT_InsertNode(heap[i % 2], num);

		if ((minHeap->usedsize > 0)
			&& (maxHeap->node[1].data > minHeap->node[1].data)) {
			a = HT_PopRoot(maxHeap);
			b = HT_PopRoot(minHeap);
			HT_InsertNode(maxHeap, b.data);
			HT_InsertNode(minHeap, a.data);
		}
		printf("%d\n", maxHeap->node[1].data);
	}
	HT_DestroyTree(maxHeap);
	HT_DestroyTree(minHeap);

	return 0;
}
#endif

#if 0
// data와 같은 값을 갖는 배열요소 번호르 ㄹ반환
// 같은 값이 없는 경우, 큰 것 중 가장 작은 값의 index 반환
int BinarySearch_upper(int* arr, int size, int data)
{
	int mid, curr;
	int start, end;
	start = 0;
	end = size - 1;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (arr[mid] == data)
		{
			return mid;
		}
		if (arr[mid] < data)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
			curr = mid;
		}
	}
	return curr;
}

int BinarySearch_lower(int* arr, int size, int data)
{
	int mid, curr;
	int start, end;
	start = 0;
	end = size - 1;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (arr[mid] == data)
		{
			return mid;
		}
		if (arr[mid] < data)
		{
			start = mid + 1;
			curr = mid;
		}
		else
		{
			end = mid - 1;
		}
	}
	return curr;
}
#endif