#include "linklist.h"

SListNode* BuySListNode(SLTDataType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		perror("BuySListNode");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void SListPrint(SListNode* plist)
{
	while (plist != NULL)
	{
		printf("%d->", plist->data);
		plist = plist->next;
	}
	printf("NULL\n");
}

void SListPushFront(SListNode** pplist, SLTDataType x)
{
	assert(pplist);
	SListNode* newnode = BuySListNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}

void SListPushBack(SListNode** pplist, SLTDataType x)
{
	assert(pplist);
	if (*pplist == NULL)
	{
		SListPushFront(pplist, x);
	}
	else
	{
		SListNode* ptr = *pplist;
		SListNode* newnode = BuySListNode(x);
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = newnode;
	}
}

void SListPopBack(SListNode** pplist)
{
	assert(pplist);
	assert(*pplist);
	if ((*pplist)->next == NULL)
	{
		SListPopFront(pplist);
		return;
	}
	SListNode* ptr = *pplist;
	SListNode* del = NULL;
	while (ptr->next != NULL)
	{
		del = ptr;
		ptr = ptr->next;
	}
	free(ptr);
	del->next = NULL;
}

void SListPopFront(SListNode** pplist)
{
	assert(pplist);
	assert(*pplist);
	SListNode* del = *pplist;
	(*pplist) = (*pplist)->next;
	free(del);
	del = NULL;
}

SListNode* SListFind(SListNode* plist, SLTDataType x)
{
	assert(plist);
	while (plist != NULL)
	{
		if (plist->data == x)
			return plist;
		plist = plist->next;
	}
	return NULL;
}

void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);
	SListNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SListInsert(SListNode** pplist, SListNode* pos, SLTDataType x)
{
	assert(pplist);
	assert(pos);
	if (*pplist == pos)
	{
		SListPushFront(pplist, x);
		return;
	}
	SListNode* ptr = *pplist;
	while(ptr->next !=  NULL)
	{
		if (ptr->next == pos)
		{
			SListNode* newnode = BuySListNode(x);
			ptr->next = newnode;
			newnode->next = pos;
			return;
		}
		ptr = ptr->next;
	}
}

void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	assert(pos->next);
	SListNode* del = pos->next;
	pos->next = pos->next->next;
	free(del);
	del = NULL;
}

void SListErase(SListNode** pplist, SListNode* pos)
{
	assert(pplist);
	assert(pos);
	assert(*pplist);
	if (*pplist == pos)
	{
		SListPopFront(pplist);
		return;
	}
	SListNode* ptr = *pplist;
	while (ptr->next != NULL)
	{
		if (ptr->next == pos)
		{
			SListNode* del = pos;
			ptr->next = pos->next;
			free(del);
			del = NULL;
			return;
		}
		ptr = ptr->next;
	}
}

void SListDestroy(SListNode** plist)
{
	assert(plist);
	while (*plist)
	{
		SListNode* del = *plist;
		*plist = (*plist)->next;
		free(del);
	}
}