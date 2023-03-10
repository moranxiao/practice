#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ListDataType;

typedef struct ListNode
{
	ListDataType data;
	struct ListNode* prev;
	struct ListNode* next;
}LTNode;

extern LTNode* ListCreate();

extern void ListDestory(LTNode* pHead);

extern void ListPrint(LTNode* pHead);

extern void ListPushBack(LTNode* pHead, ListDataType x);

extern void ListPopBack(LTNode* pHead);

extern void ListPushFront(LTNode* pHead, ListDataType x);

extern void ListPopFront(LTNode* pHead);

extern LTNode* ListFind(LTNode* pHead, ListDataType x);

extern void ListInsert(LTNode* pos, ListDataType x);

extern void ListErase(LTNode* pos);