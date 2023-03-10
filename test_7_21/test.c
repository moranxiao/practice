#pragma warning(disable:4996)
#include <stdio.h>
void swap(int* arr, int i, int j)
{
	if (i == j)
		return;
	arr[i] = arr[i] ^ arr[j];
	arr[j] = arr[i] ^ arr[j];
	arr[i] = arr[i] ^ arr[j];
}
int* select_sort(int* arr,int sz)
{
	int i = 0;
	int j = 0;
	int m = 0;
	for (i = 0; i < sz - 1; i++)
	{
		m = i;
		for (j = i + 1; j < sz; j++)
		{
			m = arr[m] > arr[j] ? j : m;
		}
		swap(arr, m, i);
	}
	return arr;
}
int main()
{
	int arr[] = { 9,8,7,6,5,4 };
	select_sort(arr, 6);
	return 0;
}