#pragma warning(disable:4996)
#include <stdio.h>
#include "stack.h"
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int PartSort2(int* a, int left, int right)
{
	int key = a[left];
	int hole = left;
	while (left < right)
	{
		while (left < right && a[right] >= key)
		{
			right--;
		}
		a[hole] = a[right];
		hole = right;
		while (left < right && a[left] <= key)
		{
			left++;
		}
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return hole;
}

int PartSort3(int* a, int left, int right)
{
	int key = left;
	int prev = left;
	int cur = left+1;
	while (cur <= right)
	{
		if (a[cur] < a[key] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		else
		{
			cur++;
		}
	}
	Swap(&a[key], &a[prev]);
	return prev;
}

int PartSort1(int* a, int left, int right)
{
	int key = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[key])
		{
			right--;
		}
		while (left < right && a[left] <= a[key])
		{
			left++;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[key], &a[right]);
	return left;
}
int SearchMid(int* a,int left,int right)
{
	int mid = left + (right - left) / 2;
	if (a[left] > a[right])
	{
		if (a[right] > a[mid])
		{
			return right;
		}
		else if (left < mid)
		{
			return left;
		}
		else
		{
			return mid;
		}
	}
	else
	{
		if (a[right] < a[mid])
		{
			return right;
		}
		else if (a[mid] > a[left])
		{
			return mid;
		}
		else
		{
			return left;
		}
	}
}
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;
	int mid = SearchMid(a, left, right);
	Swap(&a[left], &a[mid]);
	int key = PartSort3(a, left, right);
	QuickSort(a, left, key - 1);
	QuickSort(a, key + 1, right);
}

void QuickSortNonR(int* a, int left, int right)
{
	Stack s;
	StackInit(&s);
	StackPush(&s, left);
	StackPush(&s, right);
	while (!StackEmpty(&s))
	{
		right = StackTop(&s);
		StackPop(&s);
		left = StackTop(&s);
		StackPop(&s);
		if (right > left)
		{
			int key = PartSort1(a, left, right);
			StackPush(&s, key+1);
			StackPush(&s, right);
			StackPush(&s, left);
			StackPush(&s, key-1);
		}
	}
}

int main()
{
	int a[] = {1 };
	int sz = sizeof(a) / sizeof(a[0]);
	QuickSortNonR(a, 0, sz-1);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", a[i]);
	}
}
