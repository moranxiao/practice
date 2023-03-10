#pragma warning(disable:4996)
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int HPDataType;

typedef struct
{
	HPDataType* data;
	int sz;
	int capacity;
}Heap;

void HeapInit(Heap* hp);

void HeapPush(Heap* hp, HPDataType x);

int HeapEmpty(Heap* hp);

void HeapPrint(Heap* hp);

void HeapPop(Heap* hp);

HPDataType HeapTop(Heap* hp);

int HeapSize(Heap* hp);

void HeapDestory(Heap* hp);