#pragma warning(disable:4996)
#include <stdio.h>
size_t my_strlen(const char* str)
{
	size_t count = 0;
	while (*str++)
	{
		count++;
	}
	return count;
}
#include <assert.h>
char* my_strcpy(char* dest,const char* src)
{
	assert(dest && src);
	char* ret = dest;
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
char* my_strcat(char* dest, const char* src)
{
	assert(dest && src);
	char* ret = dest;
	while (*dest++)
	{
		;
	}
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}