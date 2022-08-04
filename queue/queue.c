#pragma warning(disable:4996)

#include "queue.h"

void QueueInit(Queue* q)
{
	assert(q);
	q->front = NULL;
	q->rear = NULL;
}

void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->next = q->front;
	newnode->data = data;
	if (q->front == NULL)
	{
		q->front = q->rear = newnode;
	}
	else
	{
		q->front = newnode;
	}
}

void QueuePop(Queue* q)
{
	assert(q);
	assert(q->front);
	QNode* del = q->front;
	q->front = q->front->next;
	free(del);
	if (q->front == NULL)
	{
		q->rear = NULL;
	}

}

QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->front);
	return q->front->data;
}

QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->rear);
	return q->rear->data;
}

int QueueEmpty(Queue* q)
{
	assert(q);
	if (q->front == NULL)
		return 1;
	else
		return 0;
}

void QueueDestroy(Queue* q)
{
	assert(q);
	assert(q->front);
	QNode* cur = q->front;
	while (cur)
	{
		QNode* del = cur;
		free(del);
		cur = cur->next;
	}
	q->rear = NULL;
}