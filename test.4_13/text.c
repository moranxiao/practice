#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//	int a, b, c, t = 0;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a < b)
//	{
//		t = b;
//		b = a;
//		a = t;
//	}
//	if (a < c)
//	{
//		t = c;
//		c = a;
//		a = t;
//	}
//	if (b < c)
//	{
//		t = c;
//		c = b;
//		b = t;
//	}
//	printf("%d %d %d\n", a, b, c);
//}
//#include <stdio.h>
//int main()
//{
//	int a = 1;
//	while (a <= 100)
//	{
//		if (a % 3 == 0)
//		{
//			printf("%d ", a);
//		}
//		a++;
//	}
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int x, y = 0;
//	scanf("%d %d", &x, &y);
//	while (x % y != 0)
//	{
//		int ret = x;
//		x = y;
//		y = ret % y;
//	}
//	printf("%d\n", y);
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int t = 1000;
//	for (t = 1000; t <= 2000 && t >= 1000; t += 4)
//	{
//		if (t % 400 == 0)
//			printf("%d ", t);
//		if (t % 100 != 0)
//			printf("%d ", t);
//	}
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int n = 0;
//	for (n = 101; n <= 200; n += 2)
//	{
//		int i = 3;
//		while (i <= n / 2)
//		{
//			if (n % i == 0)
//				break;
//			else
//			{
//				if (i == n / 2)
//					printf("%d ", n);
//			}
//			i++;
//		}	
//	}
//	return 0;
//}
