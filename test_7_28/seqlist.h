#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLDataType;

typedef struct SL
{
	SLDataType* data;
	size_t sz;
	size_t capacity;
}SL;

extern void SeqListInit(SL* s);

extern void SeqListDestroy(SL* ps);

extern void SeqListPrint(SL* ps);

extern void SeqListPushBack(SL* ps, SLDataType x);

extern void SeqListPushFront(SL* ps, SLDataType x);

extern void SeqListPopFront(SL* ps);

extern void SeqListPopBack(SL *ps);

extern int SeqListFind(SL* ps, SLDataType x);

extern void SeqListInsert(SL* ps, size_t pos, SLDataType x);

extern void SeqListErase(SL* ps, size_t pos);