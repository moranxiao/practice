#pragma warning(disable:4996)
#include <stdio.h>
#include <assert.h>
//size_t my_strlen(const char* str)
//{
//	assert(str != NULL);
//	if (*str)
//	{
//		return 0;
//	}
//	else
//	{
//		return 1 + my_strlen(str+1);
//	}
//}
//size_t my_strlen(const char* str)
//{
//	assert(str != NULL);
//	const char* p = str;
//	while (*str)
//	{
//		str++;
//	}
//	return str - p;
//}
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 == *str2 && *str2)
//	{
//		str1++;
//		str2++;
//	}
//	return *str1 - *str2;
//}
//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (*dest)
//	{
//		dest++;
//	}
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
char* my_strstr(const char* dest, const char* src)
{
	assert(dest && src);
	const char* str1, * str2;
	while (*dest)
	{
		if (*dest == *src)
		{
			str1 = dest;
			str2 = src;
			while (str1 == str2 && *str2)
			{
				str1++;
				str2++;
			}
			if (!*str2)
			{
				return dest;
			}
		}
		dest++;
	}
	return NULL;
}
int main()
{
	printf("%zu", my_strlen("abc"));
	return 0;
}