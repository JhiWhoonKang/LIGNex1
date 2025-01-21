#include "Heap.h"

heapTree* HT_CreateTree(int capacity, compFunc comp) {
    heapTree* tree;
    tree = (heapTree*)calloc(1, sizeof(heapTree));
    if (tree == NULL) return NULL;
    tree->node = (htNode*)calloc(capacity, sizeof(htNode));
    tree->capacity = capacity;
    tree->usedsize = 0;  // 1부터 사용
    tree->comp = comp;
    return tree;
}

void HT_DestroyTree(heapTree* tree) {
    free(tree->node);
    free(tree);
}

void HT_SwapNode(htNode* a, htNode* b) {
    htNode temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


int comp_min(ElementType a, ElementType b) {
    return  (a < b);
}
int comp_max(ElementType a, ElementType b) {
    return  (a > b);
}
void HT_InsertNode(heapTree* tree, ElementType data) {
    int curr, parent;
    htNode* node = tree->node;
    tree->usedsize += 1;
    curr = tree->usedsize;
    node[curr].data = data;
    parent = curr / 2;
    while (curr > 1 && tree->comp(node[curr].data, node[parent].data)) {
        HT_SwapNode(node + curr, node + parent);
        curr = parent;
        parent = curr / 2;
    }
}

htNode HT_PopRoot(heapTree* tree) {
    htNode root = { 0 };
    htNode* node = tree->node;
    int parent, left, right;
    int minChild;

    if (tree->usedsize == 0) {
        printf("노드 없음!");
        return root;
    }

    root = node[1];  // 0번 사용하지 않음 1번이 root
    node[1] = node[tree->usedsize];
    tree->usedsize -= 1;  // 2
    parent = 1;
    left = parent * 2;
    right = left + 1;

    while (left <= tree->usedsize) {
        if (tree->usedsize < right) {
            minChild = left;
        }
        else {         // min/max에 사용할 수 있게 comp 함수 사용
            minChild = tree->comp(node[left].data, node[right].data) ? left : right;
        }

        if (tree->comp(node[minChild].data, node[parent].data)) {
            HT_SwapNode(node + parent, node + minChild);
            parent = minChild;
            left = parent * 2;
            right = left + 1;
        }
        else {
            break;
        }
    }
    return root;
}

htNode HT_PopRoot2(heapTree* tree)
{
    htNode root = { 0 };
    htNode* node = tree->node;
    int parent, child;
    int minChild;

    if (tree->usedsize == 0) {
        printf("노드 없음!");
        return root;
    }

    root = node[1];  // 0번 사용하지 않음 1번이 root
    node[1] = node[tree->usedsize];
    tree->usedsize -= 1;  // 2
    parent = 1;
    child = 2;

    while (child <= tree->usedsize) {
        if ((child < tree->usedsize) && tree->comp(node[child + 1].data, node[child].data)) {
            ++child;
        }

        if (tree->comp(node[child].data, node[parent].data)) {
            HT_SwapNode(node + parent, node + child);
            parent = child;
            child = parent * 2;
        }
        else {
            break;
        }
    }
    return root;
}
void HT_PrintTree(heapTree* tree) {
    int i;
    int size = tree->usedsize;
    htNode* arr = tree->node;
    for (i = 1; i <= size; ++i) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}