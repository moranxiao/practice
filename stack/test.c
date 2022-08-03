#pragma warning(disable:4996)

#include "stack.h"


void test()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	printf("%d ", StackTop(&s));
	StackPush(&s, 2);
	printf("%d ", StackTop(&s));
	StackPush(&s, 3);
	printf("%d ", StackTop(&s));
	StackPush(&s, 4);
	printf("%d ", StackTop(&s));
	StackPush(&s, 5);
	printf("%d ", StackTop(&s));
	//while (!StackEmpty(&s))
	//{
	//	printf("%d ", StackTop(&s));
	//	StackPop(&s);
	//}
	StackDestroy(&s);
}

int main()
{
	test();
	return 0;
}