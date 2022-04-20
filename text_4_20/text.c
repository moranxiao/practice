#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//void exchange(int* a, int* b)
//{
//	int n = 0;
//	n = *a;
//	*a = *b;
//	*b = n;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	exchange(&a, &b);
//	return 0;
//}
//#include <stdio.h>
//void print(int n)
//{
//	int i, j = 0;
//	for (i = 1; i <= n; i++)
//	{
//		for (j = i; j <= n; j++)
//		{
//			printf("%d¡Á%d=%-4d", i, j, i * j);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	print(n);
//	return 0;
//}
//#include <stdio.h>
//#include <math.h>
//int is_prime(int n)
//{
//	int i = 0;
//	for (i = 2; i <= sqrt(n); i++)
//	{
//		if (n % i == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	int n = 0;
//	for (n = 101; n <= 200; n += 2)
//	{
//		if (is_prime(n))
//		{
//			printf("%d ", n);
//		}
//	}
//	return 0;
//}
//#include <stdio.h>
//int is_leap_year(int n)
//{
//	if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0)
//	{
//		return 1;
//	}
//	return 0;
//}
//int main()
//{
//	int n = 0;
//	for (n = 1000; n <= 2000; n++)
//	{
//		if (is_leap_year(n))
//		{
//			printf("%d ", n);
//		}
//	}
//	return 0;
//} 