#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//	int a = 3;
//	int b = -3;
//	printf("%d", a | b);
//	printf("%d", a & b);
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int a = 7;
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if ((a & (1 << i)) != 0)
//			count++;
//	}
//	printf("%d", count);
//}
//int main()
//{
//	int a = 1;
//	int b = 2;
//	a > b ? a++ : b++;
//	printf("%d %d", a, b);
//}
//#include <stdio.h>
//int main()
//{
//    int a, b;
//    scanf("%d %d", &a, &b);
//    a = a ^ b;
//    int i = 0;
//    int count = 0;
//    for (i = 0; i < 32; i++)
//    {
//        if ((a & (1 << i)) != 0)
//            count++;
//    }
//    printf("%d", count);
//    return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	for (i = 31; i >= 0; i -= 2)
//	{
//		printf("%d", (n >> i) & 1);
//	}
//	printf("\n");
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d", (n >> i) & 1);
//	}
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int a = 7;
//	int b = 8;
//	printf("a=%d,b=%d\n", a, b);
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("a=%d,b=%d\n", a, b);
//	return 0;
//}
//#include <stdio.h>
//int fun(int x[], int n)
//
//{
//	static int sum = 0, i;
//
//	for (i = 0; i < n; i++)  sum += x[i];
//
//	return sum;
//
//}
//
//main()
//
//{
//	int a[] = { 1,2,3,4,5 }, b[] = { 6,7,8,9 }, s = 0;
//
//	s = fun(a, 5) + fun(b, 4);
//
//	printf("%d",s);
//
//}
//#include <stdio.h>
//int fun1(double a) { return a *= a; }
//
//int fun2(double x, double y)
//
//{
//    double a = 0, b = 0;
//
//    a = fun1(x);
//
//    b = fun1(y);
//
//    return (int)(a + b);
//
//}
//
//main()
//
//{
//    double w; w = fun2(1.1, 2.0);
//}