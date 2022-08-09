#pragma warning(disable:4996)

//#include <stdio.h>
//
////int TreeSize(BTNode* root)
////{
////	if (root == NULL)
////		return 0;
////	
////	return PreOrder(root->left) + PreOrder(root->right)+1;
////}
//
//int TreeHigh(BTNode* root)
//{
//	if (root == NULL)
//		return 0;
//	int left = TreeHigh(root->left);
//	int right = TreeHigh(root->right);
//	return (left > right ? left : right)+1;
//}
