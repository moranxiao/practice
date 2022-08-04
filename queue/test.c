#pragma warning(disable:4996)

#include "queue.h"

void test()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	printf("%d ", QueueFront(&q));
	printf("%d ", QueueBack(&q));
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	//printf("%d ", QueueFront(&q));
}

int main()
{
	test();
	return 0;
}