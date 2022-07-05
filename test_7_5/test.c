#pragma warning(disable:4996)
#include <stdio.h>
#include <assert.h>
char* my_strstr(const char* dest, const char* src)
{
	assert(dest && src);
	while (*dest)
	{
		const char* str1 = dest;
		const char* str2 = src;
		while (*str1 == *str2 && *str2)
		{
			str1++;
			str2++;
		}
		if (*str2 == '\0')
			return (char*)dest;
		dest++;
	}
	return NULL;
}
int main()
{
	if (!my_strstr("abbbcdefg", "bbc"))
		printf("NO SEARCH\n");
	printf("%s", my_strstr("abbbcdefg", "bbc"));
	return 0;
}