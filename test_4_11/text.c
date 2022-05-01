#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int add(int x, int y)
{
	return x + y;
}
int sub(int x, int y)
{
	return x - y;
}
int mul(int x, int y)
{
	return x * y;
}
int div(int x, int y)
{
	return x / y;
}
void meau()
{
	printf("*********************************\n");
	printf("******1.add     2.sub  **********\n");
	printf("******3.mul     4.div  **********\n");
	printf("******     0.exit     ***********\n");
	printf("*********************************\n");

}
int main()
{
	int input = 0;
	do
	{
		int ret = 0;
		int x = 0;
		int y = 0;
		meau();
		printf("请输入选项\n");
		scanf("%d", &input);
		printf("请输入要计算的数\n");
		scanf("%d %d", &x, &y);
		int (*pfarr[5])(int, int) = {NULL,add,sub,mul,div };
		ret = (pfarr[input])(x,y);
		printf("%d\n", ret);
	} while (input);
	return 0;
}