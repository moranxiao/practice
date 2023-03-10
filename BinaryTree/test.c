#pragma warning(disable:4996)

#include "tree.h"

BTNode* CreateTree()
{
	BTNode* n1 = (BTNode*)malloc(sizeof(BTNode));
	assert(n1);
	BTNode* n2 = (BTNode*)malloc(sizeof(BTNode));
	assert(n2);
	BTNode* n3 = (BTNode*)malloc(sizeof(BTNode));
	assert(n3);
	BTNode* n4 = (BTNode*)malloc(sizeof(BTNode));
	assert(n4);
	BTNode* n5 = (BTNode*)malloc(sizeof(BTNode));
	assert(n5);
	BTNode* n6 = (BTNode*)malloc(sizeof(BTNode));
	assert(n6);
	BTNode* n7 = (BTNode*)malloc(sizeof(BTNode));
	assert(n7);
	BTNode* n8 = (BTNode*)malloc(sizeof(BTNode));
	assert(n8);
	BTNode* n9 = (BTNode*)malloc(sizeof(BTNode));
	assert(n9);

	n1->data = 1;
	n2->data = 2;
	n3->data = 3;
	n4->data = 4;
	n5->data = 5;
	n6->data = 6;
	n7->data = 7;
	n8->data = 8;
	n9->data = 9;
	
	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n3->left = n6;
	n3->right = n7;
	n4->left = NULL;
	n4->right = n8;
	n5->left = NULL;
	n5->right = NULL;
	n6->left = NULL;
	n6->right = NULL;

	n7->left = NULL;
	n7->right = NULL;
	n8->left = NULL;
	n8->right = NULL;
	n9->left = NULL;
	n9->right = NULL;

	return n1;
}

int main()
{
	BTNode* root = CreateTree();
	printf("%d", BinaryTreeComplete(root));
	//BinaryTreeDestory(root);
	//BinaryTreeLevelOrder(root);
	return 0;
}
