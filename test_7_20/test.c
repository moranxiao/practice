#pragma warning(disable:4996)
#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include <assert.h>
enum status
{
	VALID,
	INVALID
}S = INVALID;
int my_atoi(const char* str)
{
	assert(str);
	if (*str == '\0')
	{
		return 0;
	}
	while (isspace(*str))
	{
		str++;
	}
	int flag = 1;
	if (*str == '+')
	{
		str++;
	}
	else if(*str == '-')
	{
		flag = -1;
		str++;
	}
	long long ret = 0;
	while (*str)
	{
		if (isdigit(*str))
		{
			ret = ret * 10 + flag * (*str - '0');
			if (ret > INT_MAX || ret < INT_MIN)
			{
				return 0;
			}
		}
		else
		{
			return (int)ret;
		}
		str++;
	}
	S = VALID;
	return (int)ret;
}
int main()
{
	int a = my_atoi(" +12321231231231");
	if (S == VALID)
		printf("合法\n");
	else if (S == INVALID)
		printf("不合法\n");
	printf("%d\n", a);
	return 0;
}