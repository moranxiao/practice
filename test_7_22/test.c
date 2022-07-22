#pragma warning(disable:4996)
#include <stdio.h>
void swap(int* arr, int i, int j)
{
	arr[i] = arr[i] ^ arr[j];
	arr[j] = arr[i] ^ arr[j];
	arr[i] = arr[i] ^ arr[j];
}
int* insert_sort(int* arr, int sz)
{
	int i = 0;
	int j = 0;
	for (i = 1; i < sz; i++)
	{
		for (j = i - 1; arr[j] > arr[j + 1] && j >= 0; j--)
		{
			swap(arr, j, j + 1);
		}
	}
	return arr;
}
int main()
{
	int arr[] = { 2,5,3,6,8,9,1,3,5 };
	insert_sort(arr, 9);
	return 0;
}