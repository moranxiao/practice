#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void bubble_sort(int arr[10], int sz)
{
	int n = 0;
	for (n = 0; n < sz - 1; n++)
	{
		int i = 0;
		for (i = 0; i < sz - n - 1; i++)
		{
			if (arr[i] >= arr[i + 1])
			{
				int ret = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = ret;
			}
		}
	}
}
int main()
{
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz);
	int i = 0;
	for (i = 0; i <= sz - 1; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}