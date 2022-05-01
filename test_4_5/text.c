#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//void text2()
//{
//
//}
//void text1()
//{
//	void text2();
//}
//void text()
//{
//	text1();
//
//}
//int main()
//{
//	text();
//		return 0;
//}

//int main()
//
//{
//    char a = 0, ch;
//
//    while ((ch = getchar()) != '\n')
//
//    {
//        if (a % 2 != 0 && (ch >= 'a' && ch <= 'z'))
//
//            ch = ch - 'a' + 'A';
//
//        a++;
//
//        putchar(ch);
//
//    }
//
//    printf("\n");
//
//    return 0;
//
//}
//#include<stdio.h>
//
//int main()
//
//{
//
//	char  c1, c2;
//
//	scanf("%c", &c1);
//
//	while (c1 < 65 || c1>90)     scanf("%c", &c1);
//
//	c2 = c1 + 32;
//
//	printf("%c,%c\n", c1, c2);
//
//	return 0;
//
//}
#include <stdio.h>
int main()
{
	int i = 0;
	int n = 0;
	int a = 0;
	int b = 0;
	int ret = 1;
	scanf("%d", &a);
	for (n = 1; n <= a; n++)
	{
		for (i = 1; i <= n; i++)
		{
			ret *= i;
		}
		b += ret;
		ret = 1;
	}
	printf("%d\n", b);
	return 0;
}