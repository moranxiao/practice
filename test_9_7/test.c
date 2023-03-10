#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
void CountSort(int arr[], int sz)
{
	int min = arr[0];
	int max = arr[0];
	for (int i = 1; i < sz; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		else if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	int* tmp = (int*)calloc(max-min+1, sizeof(int));
	if (tmp == NULL)
	{
		perror("calloc fail");
		exit(-1);
	}
	for (int i = 0; i < sz; i++)
	{
		tmp[arr[i] - min]++;
	}
	int k = 0;
	for (int i = 0; i < max - min + 1; i++)
	{
		while (tmp[i])
		{
			arr[k++] = i + min;
			tmp[i]--;
		}
	}
}
int main()
{
	int arr[] = { 3,41,12,61,23,52,12,5,8,191 };
	int sz = sizeof(arr) / sizeof(int);
	CountSort(arr, sz);
	return 0;
}