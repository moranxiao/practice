#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//	int n = 0;
//	int count = 0;
//	for (n = 1; n <= 100; n++)
//	{
//		if (((n%10)!= 0 &&n % 10 % 9 == 0) ||((n/10)!= 0&& n / 10 % 9 == 0))
//			count++;
//	}
//	printf("%d\n", count);
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	double a = 0;
//	int b = -1;
//	double ret = 0;
//	for (a = 1; a <= 100; a++)
//	{
//		b *= -1;
//		ret = ret + 1 / a * b;
//	}
//	printf("%f\n", ret);
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int n = 0;
//	int arr[10] = { 0 };
//	for (n = 0; n < 10; n++)
//	{
//		scanf("%d", &arr[n]);
//	}
//	int i = 0;
//	for (i = 0; i < 9; i++)
//	{
//		int ret = 0;
//		if (arr[i] > arr[i + 1])
//		{
//			ret = arr[i];
//			arr[i] = arr[i + 1];
//			arr[i + 1] = ret;
//		}
//	}
//	printf("%d\n", arr[9]);
//}
//#include <stdio.h>
//int main()
//{
//	int i, j = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = i; j <= 9; j++)
//		{
//			printf("%d×%d=%-3d ",i,j ,i * j);
//		}
//		printf("\n");
//	}
//	return 0; 
//}
#include <stdio.h>
int main()
{
	int a = 0;
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	scanf("%d", &a);
	int sz = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = sz - 1;
	int mid = (right + left) / 2;
	while (left <= right)	
	{
		if (a > arr[mid])
		{
			left = mid + 1;
			mid = (left + right) / 2;
		}
		else if (a < arr[mid])
		{
			right = mid - 1;
			mid = (left + right) / 2;
		}
		else
		{
			printf("找到了,下标为%d\n", mid);
			break;
		}
	}
	if (left > right)
		printf("找不到了\n");
	return 0;
}