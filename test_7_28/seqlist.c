#pragma warning(disable:4996)

#include "seqlist.h"

void SeqListInit(SL* s)
{
	assert(s);
	SLDataType* p = (SLDataType*)calloc(2, sizeof(SLDataType));
	if (p == NULL)
	{
		perror("SLInit");
		exit(-1);
	}
	s->data = p;
	s->sz = 0;
	s->capacity = 2;
}

void SeqListDestroy(SL* ps)
{
	free(ps->data);
	ps->data = NULL;
	ps->capacity = 0;
	ps->sz = 0;
}

void SeqListPrint(SL* ps)
{
	assert(ps);
	for (size_t i = 0; i < ps->sz; i++)
	{
		printf("%d ", ps->data[i]);
	}
}
void CheckCapa(SL* ps)
{
	assert(ps);
	if (ps->capacity == ps->sz)
	{
		SLDataType* ptr = (SLDataType*)realloc(ps->data, 2 * ps->capacity * sizeof(SLDataType));
		if (ptr == NULL)
		{
			perror("CheckCapa");
			exit(-1);
		}
		ps->data = ptr;
		ps->capacity = 2 * ps->capacity;
	}
}
void SeqListPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	CheckCapa(ps);
	ps->data[ps->sz] = x;
	ps->sz++;
}

void SeqListPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	CheckCapa(ps);
	for (size_t i = ps->sz; i > 0; i--)
	{
		ps->data[i] = ps->data[i - 1];
	}
	ps->data[0] = x;
	ps->sz++;
}

void SeqListPopFront(SL* ps)
{
	assert(ps);
	assert(ps->sz > 0);
	for (size_t i = 1; i < ps->sz; i++)
	{
		ps->data[i - 1] = ps->data[i];
	}
	ps->sz--;
}
void SeqListPopBack(SL* ps)
{
	assert(ps);
	assert(ps->sz > 0);
	ps->sz--;
}

int SeqListFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (size_t i = 0; i < ps->sz; i++)
	{
		if (ps->data[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SeqListInsert(SL* ps, size_t pos, SLDataType x)
{
	assert(pos >= 0 && pos < ps->sz);
	assert(ps);
	CheckCapa(ps);
	for (size_t i = ps->sz; i > pos; i--)
	{
		ps->data[i] = ps->data[i - 1];
	}
	ps->data[pos] = x;
	ps->sz++;
}

void SeqListErase(SL* ps, size_t pos)
{
	assert(ps);
	assert(ps->sz > 0);
	assert(pos >= 0 && pos < ps->sz);
	for (size_t i = pos; i < ps->sz-1; i++)
	{
		ps->data[i] = ps->data[i + 1];
	}
	ps->sz--;
}