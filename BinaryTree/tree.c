#pragma warning(disable:4996)

#include "tree.h"

BTNode* BinaryTreeCreate(BTDataType* a,int* pi)
{
    if (a[*pi] == '#')
    {
        (*pi)++;
        return NULL;
    }
    BTNode* node = (BTNode*)malloc(sizeof(BTNode));
    if (node == NULL)
    {
        perror("malloc fail");
        exit(-1);
    }
    node->data = a[*pi];
    (*pi)++;
    node->left = BinaryTreeCreate(a, pi);
    node->right = BinaryTreeCreate(a, pi);
    return node;
}

void BinaryTreeDestory(BTNode* root)
{
    if (root == NULL)
        return;
    BinaryTreeDestory(root->left);
    BinaryTreeDestory(root->right);
    free(root);
}

int BinaryTreeSize(BTNode* root)
{
    if (root == NULL)
        return 0;
    return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

int BinaryTreeLeafSize(BTNode* root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->left);
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
    if (root == NULL)
        return 0;
    if (k == 1)
        return 1;
    return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
    if (root == NULL)
        return NULL;
    if (root->data == x)
        return root;
    BTNode* L = BinaryTreeFind(root->left, x);
    BTNode* R = BinaryTreeFind(root->right, x);
    if (L != NULL)
        return L;
    if (R != NULL)
        return R;
    return NULL;
}

void BinaryTreeLevelOrder(BTNode* root)
{
    Queue q;
    QueueInit(&q);
    if(root)
        QueuePush(&q, root);
    while (!QueueEmpty(&q))
    {
        BTNode* front = QueueFront(&q);
        QueuePop(&q);
        printf("%d ", front->data);
        if (front->left)
            QueuePush(&q, front->left);

        if (front->right)
            QueuePush(&q, front->right);
    }
    printf("\n");
    QueueDestroy(&q);
}

int BinaryTreeComplete(BTNode* root)
{
    Queue q;
    QueueInit(&q);
    if(root)
        QueuePush(&q, root);
    int flag = 0;
    while (!QueueEmpty(&q))
    {
        BTNode* front = QueueFront(&q);
        if (front == NULL)
        {
            flag = 1;
        }
        else
        {
            if (flag)
                return 0;
            QueuePush(&q, front->left);
            QueuePush(&q, front->right);
        }
        QueuePop(&q);
    }
    return 1;
}