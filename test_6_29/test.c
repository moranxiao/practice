#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
int main()
{
	char* p = "abcdef";
	printf("%d\n", sizeof(p));//1
	printf("%d\n", sizeof(p + 1));//2
	printf("%d\n", sizeof(*p));//3
	printf("%d\n", sizeof(p[0]));//4
	printf("%d\n", sizeof(&p));//5
	printf("%d\n", sizeof(&p + 1));//6
	printf("%d\n", sizeof(&p[0] + 1));//7
	printf("%d\n", strlen(p));//8
	printf("%d\n", strlen(p + 1));//9
	//printf("%d\n", strlen(*p));//10
	//printf("%d\n", strlen(p[0]));//11
	printf("%d\n", strlen(&p));//12
	printf("%d\n", strlen(&p + 1));//13
	printf("%d\n", strlen(&p[0] + 1));//14
	return 0;
}