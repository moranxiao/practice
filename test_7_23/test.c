#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
void merge(int* arr, int L, int M,int R)
{
	int* help =(int*)malloc(4*(R-L+1));
	if (help == NULL)
		exit(0);
	int i = 0;
	int p1 = L;
	int p2 = M+1;
	while (p1 <= M && p2 <= R)
	{
		help[i++] = arr[p1] > arr[p2] ? arr[p2++] : arr[p1++];
	}
	while (p1 <= M)
	{
		help[i++] = arr[p1++];
	}
	while (p2 <= R)
	{
		help[i++] = arr[p2++];
	}
	for (i = 0; i < R - L + 1; i++)
	{
		arr[L+i] = help[i];
	}
	free(help);
	help = NULL;
}
void merge_sort(int* arr, int L, int R)
{
	if (L == R)
		return;
	int mid = ((R - L) >> 1) + L;
	merge_sort(arr, L, mid);
	merge_sort(arr, mid + 1, R);
	merge(arr,L, mid, R);
}

int main()
{
	int arr[] = { 2,5,1,3,6,5,1,23,4,1,8,65,231 };
	merge_sort(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1);
	return 0;
}