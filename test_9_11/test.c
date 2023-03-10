#pragma warning(disable:4996)

#include <stdio.h>
#include "queue.h"

#define RADIX 10
#define K 3
int GetKey(int num, int k)
{
	while (k > 0)
	{
		num /= 10;
		k--;
	}
	return num % 10;
}

void RadixSort(int arr[],int sz)
{
	Queue q[RADIX];
	for (int i = 0; i < RADIX; i++)
	{
		QueueInit(q+i);
	}
	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			int num = GetKey(arr[j], i);
			QueuePush(&q[num], arr[j]);
		}
		int k = 0;
		for (int j = 0; j < RADIX; j++)
		{
			while (!QueueEmpty(q + j))
			{
				arr[k++] = QueueFront(q + j);
				QueuePop(q + j);
			}
		}
	}
}

int main()
{
	int arr[] = { 278,109,63,930,589,184,505,269,8,83 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	RadixSort(arr, sz);
	return 0;
}