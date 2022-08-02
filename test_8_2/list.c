#pragma warning(disable:4996)
#include "list.h"

LTNode* ListCreate()
{
	LTNode* head = (LTNode*)malloc(sizeof(LTNode));
	if (!head)
	{
		perror("malloc fail");
		exit(-1);
	}
	head->next = head;
	head->prev = head;
	return head;
}
LTNode* BuyLTNode(ListDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->prev = newnode->next = NULL;
	return newnode;
}
//void ListPushBack(LTNode* pHead, ListDataType x)
//{
//	assert(pHead);
//	LTNode* newnode = BuyLTNode(x);
//	newnode->prev = pHead->prev;
//	newnode->next = pHead;
//	pHead->prev = newnode;
//	newnode->prev->next = newnode;
//}

void ListPushBack(LTNode* pHead, ListDataType x)
{
	assert(pHead);
	ListInsert(pHead,x);
}

void ListPrint(LTNode* pHead)
{
	assert(pHead);
	LTNode* cur = pHead->next;
	printf("phead");
	while (cur != pHead)
	{
		printf("<->%d", cur->data);
		cur = cur->next;
	}
}

void ListDestory(LTNode* pHead)
{
	assert(pHead);
	LTNode* cur = pHead->next;
	while (cur != pHead)
	{
		LTNode* del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
	free(pHead);
	pHead = NULL;
}

//void ListPopBack(LTNode* pHead)
//{
//	assert(pHead);
//	assert(pHead->next != pHead);
//	pHead->prev = pHead->prev->prev;
//	free(pHead->prev->next);
//	pHead->prev->next = pHead;
//}

void ListPopBack(LTNode* pHead)
{
	assert(pHead);
	assert(pHead->next != pHead);
	ListErase(pHead->prev);
}

//void ListPushFront(LTNode* pHead, ListDataType x)
//{
//	assert(pHead);
//	LTNode* newnode = BuyLTNode(x);
//	newnode->next = pHead->next;
//	newnode->prev = pHead;
//	pHead->next = newnode;
//	newnode->next->prev = newnode;
//}

void ListPushFront(LTNode* pHead, ListDataType x)
{
	assert(pHead);
	ListInsert(pHead->next, x);
}

//void ListPopFront(LTNode* pHead)
//{
//	assert(pHead);
//	assert(pHead->next != pHead);
//	pHead->next = pHead->next->next;
//	free(pHead->next->prev);
//	pHead->next->prev = pHead;
//}

void ListPopFront(LTNode* pHead)
{
	assert(pHead);
	assert(pHead->next != pHead);
	ListErase(pHead->next);
}

LTNode* ListFind(LTNode* pHead, ListDataType x)
{
	assert(pHead);
	LTNode* cur = pHead->next;
	while (cur != pHead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void ListInsert(LTNode* pos, ListDataType x)
{
	assert(pos);
	LTNode* newnode = BuyLTNode(x);
	newnode->next = pos;
	newnode->prev = pos->prev;
	newnode->prev->next = newnode;
	pos->prev = newnode;
}

void ListErase(LTNode* pos)
{
	assert(pos);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
}