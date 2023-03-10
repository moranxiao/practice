#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int QDataType;

typedef struct QListNode
{
	QDataType data;
	struct QListNode* next;
}QNode;

typedef struct Queue
{
	QNode* front;
	QNode* rear;
	int sz;
}Queue;

//��ʼ��
void QueueInit(Queue* q);
// ��β�����
void QueuePush(Queue* q, QDataType data);
// ��ͷ������
void QueuePop(Queue* q);
// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* q);
// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* q);

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
int QueueEmpty(Queue* q);
// ���ٶ���
void QueueDestroy(Queue* q);
