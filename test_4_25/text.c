#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//	int arr1[] = { 0,1,2,3,4 };
//	int arr2[] = { 5,6,7,8,9 };
//	int ret = sizeof(arr1) / sizeof(arr1[0]);
//	int i = 0;
//	while (i <= ret - 1)
//	{
//		int t = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = t;
//		i++;
//	}
//	return 0;
//}
#include <stdio.h>
int* init(int* arr,int sz)//sz为数组大小
{
	int* p = arr;
	int i = 0;
	for (i = 0; i <= sz - 1; i++)
	{
		arr[i] = 0;
	}
	return p;
}
void print(int* arr, int sz)//sz为数组大小
{
	int i = 0;
	for (i = 0; i <= sz - 1; i++)
	{
		printf("%d ", arr[i]);
	}
}
int* reverse(int* arr, int sz)
{
	int i = 0;
	int j = 0;
	for (j = 0; j < sz - 1; j++)
	{
		for (i = 0; i < sz - 1 - j; i++)
		{
			int t = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = t;
		}
	}
	return arr;
}
int main()
{
	int arr[] = { 1,2,3,4,5,6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	init(arr, sz);
	print(arr, sz);
}