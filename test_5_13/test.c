#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int i = 0;
//	int j = 0;
//	int Sn = 0;
//	for (i = 0; i < 5; i++)
//	{
//		int n = 0;
//		for (j = 0; j <= i; j++)
//		{
//			n += a*pow(10,j);
//		}
//		Sn += n;
//	}
//	printf("%d", Sn);
//	return 0;
//}
//#include <stdio.h>
//int lily(int i)
//{
//	int x = i;
//	int n = 0;
//	while (x)
//	{
//		n++;
//		x /= 10;
//	}
//	int sum = 0;
//	while (i)
//	{
//		int y = 1;
//		int j = n;
//		while (j--)
//		{
//			y *= (i % 10);
//		}
//		sum += y;
//		i /= 10;
//	}
//	return sum;
//}
//int main()
//{
//	int i = 0;
//	for (i = 1; i < 100000; i++)
//	{
//		if (lily(i) == i)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
#include <stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	int line = 0;
	scanf("%d", &line);
	for (i = 1; i <= line; i++)
	{
		for (j = 1; j <= line; j++)
		{
			if (i <= (line+1) / 2)
			{
				if (j > (line + 1) / 2 - i && j < (line + 1) / 2 + i)				
					printf("*");				
				else
					printf(" ");
			}
			else
			{
				if( j > (line+1)/2-(line+1-i)&& j < (line + 1) / 2 + (line + 1 - i))
					printf("*");
				else
					printf(" ");
			}

		}
		printf("\n");
	}
	return 0;
}