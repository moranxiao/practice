#pragma warning(disable:4996)
#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* data;
	int top;
	int capacity;
}Stack;

void StackInit(Stack* ps);

void StackPush(Stack* ps, STDataType data);

void StackPop(Stack* ps);

STDataType StackTop(Stack* ps);

int StackEmpty(Stack* ps);

void StackDestroy(Stack* ps);

int StackSize(Stack* ps);