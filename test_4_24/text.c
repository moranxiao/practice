#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//unsigned int fac(unsigned int n)
//{
//	int ret = 1;
//	for (; n >= 1; n--)
//	{
//		ret *= n;
//	}
//	return ret;
//}
//int main()
//{
//	unsigned int n = 0;
//	scanf("%u", &n);
//	printf("%u\n",fac(n));
//}
//#include <stdio.h>
//int my_strlen(char* src)
//{
//	int i = 0;
//	while (*src++ != '\0')
//	{
//		i++;
//   }
//	return i;
//}
//int main()
//{
//	char arr[] = "abcd";
//	printf("%d\n", my_strlen(arr));
//}
//#include <stdio.h>
//#include <string.h>
//void reverse_string(char* string)
//{
//	int len = strlen(string);
//	char t = 0;
//	t = *string;
//	*string = *(string + len - 1);
//	*(string + len - 1) = '\0';
//	if (strlen(string)>= 2)
//		reverse_string(string + 1);
//	*(string + len - 1) = t;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	reverse_string(arr);
//	printf("%s", arr);
//	return 0;
//}
//#include <stdio.h>
//int each_add(int n)
//{
//	if (n > 9)
//		return n % 10 + each_add(n / 10);
//	else
//		return n % 10;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n",each_add(n));
//	return 0;
//}
//#include <stdio.h>
//int power(int n, int k)
//{
//	if (k > 1)
//		return n * power(n, k - 1);
//	else
//		return n;	
//}
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d %d", &n, &k);
//	printf("%d\n",power(n, k));
//}
#include <stdio.h>
int fib(int n)
{
	int i = 1;
	int k = 1;
	int ret = 1;
	while (n >= 3)
	{
		ret = i + k;
		k = i;
		i = ret;
		n--;
	}
	return ret;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d\n",fib(n));
}