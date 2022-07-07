#pragma warning(disable:4996)
#include <stdio.h>
int main()
{
	int a[] = { 1,2,3,4 };
	printf("%d\n", sizeof(a));//1.
	printf("%d\n", sizeof(a + 0));//2.
	printf("%d\n", sizeof(*a));//3.
	printf("%d\n", sizeof(a + 1));//4.
	printf("%d\n", sizeof(a[1]));//5.
	printf("%d\n", sizeof(&a));//6.
	printf("%d\n", sizeof(*&a));//7.
	printf("%d\n", sizeof(&a + 1));//8.
	printf("%d\n", sizeof(&a[0]));//9.
	printf("%d\n", sizeof(&a[0] + 1));//10.
	return 0;
}