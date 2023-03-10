#pragma warning(disable:4996)
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SListNode;

extern SListNode* BuySListNode(SLTDataType x);

extern void SListPrint(SListNode* plist);

extern void SListPushFront(SListNode** pplist, SLTDataType x);

extern void SListPushBack(SListNode** pplist, SLTDataType x);

extern void SListPopBack(SListNode** pplist);

extern void SListPopFront(SListNode** pplist);

extern SListNode* SListFind(SListNode* plist, SLTDataType x);

extern void SListInsertAfter(SListNode* pos, SLTDataType x);

extern void SListInsert(SListNode** pplist,SListNode* pos, SLTDataType x);

extern void SListEraseAfter(SListNode* pos);

extern void SListErase(SListNode** pplist,SListNode* pos);

extern void SListDestroy(SListNode** plist);