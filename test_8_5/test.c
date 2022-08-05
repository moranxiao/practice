#pragma warning(disable:4996)
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char STDataType;

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
	if (ps->top == 0)
	{
		return -1;
	}
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

bool isValid(char* s) {
	Stack* a = (Stack*)malloc(sizeof(Stack));
	StackInit(a);
	while (*s)
	{
		if (*s == '['
			|| *s == '{'
			|| *s == '(')
		{
			StackPush(a, *s);
		}
		else
		{
			if (*s - StackTop(a) == 2
				|| *s - StackTop(a) == 1)
			{
				StackPop(a);
			}
			else
			{
				return false;
			}
		}
		s++;
	}
	if (!StackEmpty(a))
		return false;
	return true;
}
