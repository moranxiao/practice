#pragma warning(disable:4996)
#include <stdio.h>

//int func(int x)
//{
//	int count = 0;
//	while (x)
//	{
//		count++;
//		x = x & (x - 1);//与运算
//	}
//	return count;
//}
//int main()
//{
//	printf("%d", func(-1));
//	int count = 0;
//	int x = -1;
//	while (x)
//	{
//		count++;
//		x = x >> 1;
//	}
//	printf("%d", count);
//	return 0;
//}

// 挖坑法
int PartSort2(int* a, int left, int right)
{
	// 三数取中
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);

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
}

// 前后指针法
int PartSort3(int* a, int left, int right)
{
	// 三数取中
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);
	int key = left;
	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < a[key]&&++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	Swap(&a[prev], &a[key]);
}