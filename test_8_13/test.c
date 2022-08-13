#pragma warning(disable:4996)
#include <stdio.h>

void InsertSort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int tmp = a[i];
		int j = i - 1;
		while (a[j] > tmp&&j >= 0)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j+1] = tmp;
	}
}

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap>1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int tmp = a[i + gap];
			int j = i;
			while (a[j] > tmp && j >= 0)
			{
				a[j + gap] = a[j];
				j -= gap;
			}
			a[j + gap] = tmp;
		}
	}
}
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int maxi = begin;
		int mini = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] < a[mini])
				mini = i;
			if (a[i] > a[maxi])
				maxi = i;
		}
		Swap(&a[mini], &a[begin]);
		if (maxi == begin)
			maxi = mini;
		Swap(&a[maxi], &a[end]);
		end--;
		begin++;
	}
}
void AdjustDwon(int* a, int n, int root)
{
	int son = root * 2+1;
	if (son+1 < n&&a[son] < a[son + 1])
		son++;
	while (son < n)
	{
		if (a[root] < a[son])
			Swap(&a[root], &a[son]);
		else
			break;
		root = son;
		son = root * 2+1;
		if (son + 1 < n && a[son] < a[son + 1])
			son++;
	}
}

void HeapSort(int* a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}
	for (int i = n - 1; i > 0; i--)
	{
		Swap(&a[0], &a[i]);
		AdjustDwon(a, i, 0);
	}
}

void BubbleSort(int* a, int n)
{
	for (int j = 1; j < n; j++)
	{
		int flag = 1;
		for (int i = 0; i < n - j; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				flag = 0;
			}
		}
		if (flag)
		{
			break;
		}
	}
}

int PartSort1(int* a, int left, int right)
{
	int key = left;
	int i = left;
	int j = right;
	while (left < right)
	{
		while (left<right && a[right] >= a[key])
		{
			right--;
		}
		while (left < right && a[left] <= a[key])
		{
			left++;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[key], &a[left]);
	return left;
}

void QuickSort(int* a, int left, int right)
{
	if (right-left <= 0)
		return;
	int mid = PartSort1(a, left, right);
	QuickSort(a, left, mid - 1);
	QuickSort(a, mid+1, right);
}

void test()
{
	int a[] = { 34, 56, 25, 65, 86, 99, 72, 66 };
	int sz = sizeof(a) / sizeof(a[0]);
	QuickSort(a, 0,sz-1);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", a[i]);
	}
	
}

int main()
{
	test();
	return 0;
}