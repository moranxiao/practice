#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

void _MergeSort(int a[], int tmp[], int left, int right)
{
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
	_MergeSort(a, tmp, left, mid);
	_MergeSort(a, tmp, mid+1, right);
	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right)
	{
		if (a[i] <= a[j])
		{
			tmp[k++] = a[i++];
		}
		else
		{
			tmp[k++] = a[j++];
		}
	}
	while (i <= mid)
	{
		tmp[k++] = a[i++];
	}
	while (j <= right)
	{
		tmp[k++] = a[j++];
	}
	while (left <= right)
	{
		a[left] = tmp[left];
		left++;
	}
}
void MergeSort(int a[], int sz)
{
	if (sz == 1)
		return;
	int* tmp = (int*)malloc(sizeof(int) * sz);
	if (tmp == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	_MergeSort(a,tmp,0,sz-1);
	free(tmp);
	tmp = NULL;
}

int main()
{

	return 0;
}