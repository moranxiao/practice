#pragma warning(disable:4996)
#include <stdio.h>
int main()
{
	char arr[] = "abcdef";
	printf("%d\n", sizeof(arr));//1
	printf("%d\n", sizeof(arr + 0));//2
	printf("%d\n", sizeof(*arr));//3
	printf("%d\n", sizeof(arr[1]));//4
	printf("%d\n", sizeof(&arr));//5
	printf("%d\n", sizeof(&arr + 1));//6
	printf("%d\n", sizeof(&arr[0] + 1));//7
	printf("%d\n", strlen(arr));//8
	printf("%d\n", strlen(arr + 0));//9
	//printf("%d\n", strlen(*arr));//10
	//printf("%d\n", strlen(arr[1]));//11
	printf("%d\n", strlen(&arr));//12
	printf("%d\n", strlen(&arr + 1));//13
	printf("%d\n", strlen(&arr[0] + 1));//14
	return 0;
}