#pragma warning(disable:4996)
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

void StackInit(Stack* ps)
{
	assert(ps);
	ps->data = NULL;
	ps->top = 0;
	ps->capacity = 0;
}


void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		ps->capacity = (ps->capacity == 0) ? 4 : 2 * ps->capacity;
		STDataType* newdata = (STDataType*)realloc(ps->data, sizeof(STDataType) * ps->capacity);
		if (newdata == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		ps->data = newdata;
	}
	ps->data[ps->top] = data;
	ps->top++;
}

void StackPop(Stack* ps)
{
	assert(ps);
	ps->top--;
}

STDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->data[ps->top - 1];
}

int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}

int StackEmpty(Stack* ps)
{
	assert(ps);
	return !ps->top;
}

void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->data);
	ps->data = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

typedef struct {
	Stack stout;
	Stack stin;
} MyQueue;


MyQueue* myQueueCreate() {
	MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&obj->stout);
	StackInit(&obj->stin);
	return obj;
}

void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->stin, x);
}

int myQueuePop(MyQueue* obj) {
	if (!StackEmpty(&obj->stout))
	{
		int ret = StackTop(&obj->stout);
		StackPop(&obj->stout);
		return ret;
	}
	while (!StackEmpty(&obj->stin))
	{
		StackPush(&obj->stout, StackTop(&obj->stin));
		StackPop(&obj->stin);
	}
	int ret = StackTop(&obj->stout);
	StackPop(&obj->stout);
	return ret;
}

int myQueuePeek(MyQueue* obj) {
	if (!StackEmpty(&obj->stout))
		return StackTop(&obj->stout);
	while (!StackEmpty(&obj->stin))
	{
		StackPush(&obj->stout, StackTop(&obj->stin));
		StackPop(&obj->stin);
	}
	return StackTop(&obj->stout);
}

bool myQueueEmpty(MyQueue* obj) {
	return StackEmpty(&obj->stout) && StackEmpty(&obj->stin);
}

void myQueueFree(MyQueue* obj) {
	StackDestroy(&obj->stout);
	StackDestroy(&obj->stin);
	free(obj);
}