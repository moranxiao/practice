#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//	int n = 0;
//	int m = 0;
//	const int* p = &n;
//	int* const p1 = &m;
//	p = &m;
//	*p = 1000;
//	printf("%d", *p1);
//
//	return 0;
//}
#include <stdio.h>
#include <assert.h>
int my_strcmp(const char* p1,const char* p2)
{
	assert(p1 != NULL && p2 != NULL);
	while (*p1 == *p2)
	{
		if (*p1 == '\0')
			return 0;
		p1++;
		p2++;
	}
	return *p1 - *p2;
}
int main()
{
	char* p1 = "abc";
	char* p2 = "abb";
	printf("%d ",my_strcmp(p1, p2));
	return 0;
}