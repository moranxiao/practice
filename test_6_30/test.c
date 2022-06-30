#pragma warning(disable:4996)
#include <stdio.h>
int main()
{
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));//1
	printf("%d\n", sizeof(a[0][0]));//2
	printf("%d\n", sizeof(a[0]));//3
	printf("%d\n", sizeof(a[0] + 1));//4
	printf("%d\n", sizeof(*(a[0] + 1)));//5
	printf("%d\n", sizeof(a + 1));//6
	printf("%d\n", sizeof(*(a + 1)));//7
	printf("%d\n", sizeof(&a[0] + 1));//8
	printf("%d\n", sizeof(*(&a[0] + 1)));//9
	printf("%d\n", sizeof(*a));//10
	printf("%d\n", sizeof(a[3]));//11
	return 0;
}