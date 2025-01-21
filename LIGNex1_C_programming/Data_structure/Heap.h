#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct _htNode {
    ElementType data;
}htNode;
typedef int (*compFunc)(ElementType, ElementType);
typedef struct _heapTree {
    htNode* node;
    int capacity;
    int usedsize;
    compFunc comp;
}heapTree;
heapTree* HT_CreateTree(int capacity, compFunc comp);
void HT_DestroyTree(heapTree* tree);
void HT_SwapNode(htNode* a, htNode* b);
int comp_min(ElementType a, ElementType b);
int comp_max(ElementType a, ElementType b);
void HT_InsertNode(heapTree* tree, ElementType data);
htNode HT_PopRoot(heapTree* tree);
htNode HT_PopRoot2(heapTree* tree);
void HT_PrintTree(heapTree* tree);
