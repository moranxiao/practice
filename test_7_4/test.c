#pragma warning(disable:4996)
#include <stdio.h>
#include <assert.h>
//size_t my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1&&*str1 == *str2)
//	{
//		str1++;
//		str2++;
//	}
//	return *str1 - *str2;
//}
int main()
{
	printf("%zu", my_strcmp("abcec", "abc"));
	return 0;
}