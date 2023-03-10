#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
int main()
{
	char arr[] = { 'a','b','c','d','e','f' };//1
	//printf("%d\n", sizeof(arr));//2
	//printf("%d\n", sizeof(arr + 0));//3
	//printf("%d\n", sizeof(*arr));//4
	//printf("%d\n", sizeof(arr[1]));//5
	//printf("%d\n", sizeof(&arr));//6
	//printf("%d\n", sizeof(&arr + 1));//7
	//printf("%d\n", sizeof(&arr[0] + 1));//8
	//printf("%d\n", strlen(arr));//9
	//printf("%d\n", strlen(arr + 0));//10
	printf("%d\n", strlen(*arr));//11
	printf("%d\n", strlen(arr[1]));//12
	//printf("%d\n", strlen(&arr));//13
	//printf("%d\n", strlen(&arr + 1));//14
	//printf("%d\n", strlen(&arr[0] + 1));//15
	return 0;
}