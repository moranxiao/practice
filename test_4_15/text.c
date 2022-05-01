#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//	int ret = 0;
//	scanf("%d", &ret);
//	int i = 0;
//	for (i = ret - 1; i >= 1; i--)
//	{
//		if (ret % i == 0)
//			break;
//	}
//	printf("%d", i);
//	return 0;
//}
//#include  <stdio.h>
//int main()
//{
//	int x, y, z = 0;
//	for (x = 1; x <= 50 / 3; x++)
//	{
//		for (y = 1; y <= 50 / 5; y++)
//		{
//			for (z = 1; z <= 50 / 7; z++)
//			{
//				if (50 == x * 3 + y * 5 + z * 7)
//					printf("x=%d,y=%d,z=%d\n", x, y, z);
//			}
//		}
//	}
//	return 0;
//}
//#include <math.h>
//#include <stdio.h>
//int main()
//{
//	//int x = 1;
//	//int y = 0;
//	//for (x = 1; x <= 9; x++)
//	//{
//	//	for (y = 0; y <= 9; y++)
//	//	{
//	//		if (((int)sqrt(1100 * x + 11 * y))== sqrt(1100 * x + 11 * y) )
//	//			printf("%d\n", 1100 * x + 11 * y);
//	//	}
//	//}
//	//return 0;
//}
//#include <stdio.h>
//int main() {
//    int line;  // 总行数    
//    int i;  // 行
//    int j;  // 列
//
//    // 保证输入一个大于0的奇数    
//    do {
//        printf("请输入行数(大于0的奇数)：");
//        scanf("%d", &line);
//    }
//    /**********FILL**********/
//    while (line % 2 != 1);
//
//    /**********FILL**********/
//    for (i = 1; i <= i / 2 + 1; i++)  // 输出图形上半部分（含中间行）
//    {
//        for (j = 1; j <= 20 - i; j++)//输出本行前面的空格
//            printf("  ");
//        /**********FILL**********/
//        for (j = 1; j <= 2*i-1; j++) //输出本行的*  
//            printf("* ");
//        /**********FILL**********/
//        printf("\n");
//    }
//    /**********FILL**********/
//    for (i = line / 2; i > 0; i--)//输出图形下半部分
//    {
//        for (j = 1; j <= 20 - i; j++)//输出本行前面的空格
//            printf("  ");
//        for (j = 1; j <= 2 * i - 1; j++) //输出本行的*       
//            printf("* ");
//        printf("\n");
//    }
//    return 0;
//}
//int main()
//{
//	qsort()
//}
//#include <stdio.h>
//int main()
//{
//	int a = 0, b = 0, x1, x2, x3, x4;
//	for (a = 1; b <= 9999; a++) 
//	{
//		b = a * a;
//		x1 = b / 1000;
//		x2 = (b - 1000 * x1) / 100;
//		x3 = (b - 1000 * x1 - 100 * x2) / 10;
//		x4 = b - 1000 * x1-100 * x2 - 10 * x3;
//		if (x1 == x2&& x3 == x4 && x1!=x3)
//		{
//			printf("%d\n", b);
//		}
//
//
//	}
//	return 0;
//}
