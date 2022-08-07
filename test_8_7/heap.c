#pragma warning(disable:4996)

#include "heap.h"

void swap(HPDataType* a, HPDataType* b)
{
	HPDataType tmp = *a;
	*a = *b;
	*b = tmp;
}

void HeapInit(Heap* hp)
{
	assert(hp);
	hp->data = (HPDataType*)malloc(sizeof(HPDataType) * 4);
	hp->capacity = 4;
	hp->sz = 0;
}

void HeapDownToUp(HPDataType* data,int son)
{
	assert(data);
	int parent = (son - 1) / 2;
	while (son)
	{
		if (data[son] < data[parent])
		{
			swap(&data[son], &data[parent]);
			son = parent;
			parent = (son - 1) / 2;
		}
		else
			break;
	}
}
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->sz == hp->capacity)
	{
		HPDataType* newdata = (HPDataType*)realloc(hp->data, sizeof(HPDataType) * 2 * hp->capacity);
		if (newdata == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		hp->data = newdata;
		hp->capacity *= 2;
	}
	hp->data[hp->sz] = x;
	HeapDownToUp(hp->data,hp->sz);
	hp->sz++;
}

void HeapPrint(Heap* hp)
{
	assert(hp);
	for (int i = 0; i < hp->sz; i++)
	{
		printf("%d ", hp->data[i]);
	}
}

void HeapUpToDown(HPDataType* data, int parent,int sz)
{
	int son = parent * 2 + 1;
	if (data[son] > data[son + 1] && son + 1 < sz)
	{
		son++;
	}
	while (son < sz)
	{
		if (data[parent] > data[son])
		{
			swap(&data[parent], &data[son]);
		}
		parent = son;
		son = son * 2 + 1;
		if (data[son] > data[son + 1] && son + 1 < sz)
		{
			son++;
		}
	}
}

void HeapPop(Heap* hp)
{
	assert(hp);
	assert(hp->sz!=0);
	swap(&hp->data[0], &hp->data[hp->sz - 1]);
	hp->sz--;
	HeapUpToDown(hp->data, 0, hp->sz);
}

int HeapEmpty(Heap* hp)
{
	assert(hp);
	if (hp->sz == 0)
	{
		return 1;
	}
	return 0;
}

HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(hp->sz != 0);
	return hp->data[0];
}

int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->sz;
}

void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->data);
}
