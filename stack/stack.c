#pragma warning(disable:4996)

#include "stack.h"

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
	return ps->data[ps->top-1];
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