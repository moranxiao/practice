#pragma warning(disable:4996)
#include <stdio.h>
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void sort1(int arr[], int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(arr + j, arr + j + 1);
				flag = 1;
			}
		}
		if (0 == flag)
			return;
	}
}
void sort2(int arr[], int sz)
{
	int begin = 0;
	int end = sz-1;
	while (begin < end)
	{
		int min = begin;
		int max = begin;
		for (int i = begin+1; i <= end; i++)
		{
			if (arr[i] > arr[max])
			{
				max = i;
			}
			else if(arr[i] < arr[min])
			{
				min = i;
			}
		}
		Swap(arr + begin, arr + min);
		if (max == begin)
		{
			Swap(arr + min, arr + end);
		}
		else
		{
			Swap(arr + max, arr + end);
		}
		end--;
		begin++;
	}
}
void sort3(int arr[], int sz)
{
	for (int i = 1; i < sz; i++)
	{
		int tmp = arr[i];
		int j = i - 1;
		while (j >= 0 &&arr[j] >tmp)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = tmp;
	}
}
void sort4(int arr[], int sz)
{
	int n = sz;
	while (n)
	{
		n = n / 3;
		int key = n + 1;
		for (int k = 0; k < key; k++)
		{
			for (int i = k+key; i < sz; i += key)
			{
				int tmp = arr[i];
				int j = i - key;
				while (j >= 0 && arr[j] > tmp)
				{
					arr[j + key] = arr[j];
					j -= key;
				}
				arr[j + key] = tmp;
			}
		}
	}
}
AdjustDown(int arr[], int parent,int sz)
{
	int son = parent * 2 + 1;
	if (son + 1 < sz && arr[son] < arr[son + 1])
	{
		son = son + 1;
	}
	while (son < sz)
	{
		if (arr[parent] < arr[son])
		{
			Swap(arr + parent, arr + son);
		}
		else
			break;
		parent = son;
		son = parent * 2 + 1;
		if (son + 1 < sz && arr[son] < arr[son + 1])
		{
			son = son + 1;
		}
	}
}
void sort5(int arr[], int sz)
{
	for (int i = (sz - 2) / 2; i >= 0; i--)
	{
		AdjustDown(arr, i, sz);
	}
	for (int i = sz - 1; i >= 0; i--)
	{
		Swap(arr, arr + i);
		AdjustDown(arr, 0, i);
	}
}
int partion1(int arr[], int left, int right)
{
	int key = left;
	while (left < right)
	{
		while (left < right && arr[right] >= arr[key])
		{
			right--;
		}
		while (left < right && arr[left] <= arr[key])
		{
			left++;
		}
		Swap(arr + left, arr + right);
	}
	Swap(arr + key, arr + left);
	return left;
}
int partion2(int arr[], int left, int right)
{
	int key = arr[left];
	int hole = left;
	while (left < right)
	{
		while (left < right && arr[right] >= key)
		{
			right--;
		}
		arr[hole] = arr[right];
		hole = right;
		while (left < right && arr[left] <= key)
		{
			left++;
		}
		arr[hole] = arr[left];
		hole = left;
	}
	arr[hole] = key;
	return hole;
}
int partion3(int arr[], int left, int right)
{
	int key = left;
	int cur = left;
	int prev = left+1;
	while (prev <= right)
	{
		while (prev <= right && arr[prev] >= arr[key])
		{
			prev++;
		}
		if (prev > right)
		{
			break;
		}
		++cur;
		Swap(arr + prev, arr + cur);
		++prev;
	}
	Swap(arr +cur, arr + key);
	return cur;
}
void sort6(int arr[], int left, int right)
{
	if (right - left < 1)
		return;
	int key = partion3(arr, left, right);
	sort6(arr, left, key - 1);
	sort6(arr, key + 1, right);
}
int main()
{
	int arr[] = { 4, 5,61,21,321,42,12,31,52,12,23,51,4,7 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	sort6(arr, 0,sz-1);
	return 0;
}