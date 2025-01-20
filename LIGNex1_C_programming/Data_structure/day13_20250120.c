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

#if 01
typedef int ElementType;
typedef struct _tNode
{
	ElementType data;
}htNode;
typedef struct _heapTree
{
	htNode* node;
	int capacity;
	int usedsize;
}heapTree;

heapTree* HT_CreateHeapTree(int capacity)
{
	heapTree* tree;
	tree = (heapTree*)calloc(1, sizeof(heapTree));
	if (tree == NULL) return NULL;
	tree->node = (htNode*)calloc(capacity, sizeof(htNode));
	tree->capacity = capacity;
	tree->usedsize = 0;
	return  tree;
}

void HT_DestroyTree(heapTree* tree)
{
	free(tree->node);
	free(tree);	
}

void HT_InsertNode(heapTree* tree, ElementType data)
{

}

int main(void)
{
	heapTree* hTree;
	hTree = HT_CreateHeapTree(20);
	HT_DestroyTree(hTree);
	hTree = NULL;


	return 0;
}
#endif