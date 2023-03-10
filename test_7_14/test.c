#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
	#include <assert.h>
	int my_atoi(const char* str)
	{
		assert(str);
		long long ret = 0;
		int flag = 1;
		while (*str == ' ')
		{
			str++;
		}
		if (*str == '+')
		{
			str++;
		}
		else if (*str == '-')
		{
			flag = -1;
			str++;
		}
		while (*str <= '9' && *str >= '0')
		{
			ret = ret * 10 + *str - 48;
			str++;
			if (ret > INT_MAX || ret < INT_MIN)
				return 0;
		}
		return (int)ret * flag;
	}
int main()
{
	char arr[] = " 1234678901234 pig 123";
	printf("%d", my_atoi(arr));
	return 0;
}
