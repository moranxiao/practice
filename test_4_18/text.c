#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		putchar(ch);
//	}
//	return 0;
//}
#include <stdio.h>
int main()
{
	char password[20] = { 0 };
	printf("����������:>");
	scanf("%s", password);
	while (getchar() != '\n');
	printf("��ȷ������(Y/N)\n");
	int ret = getchar();
	if ('Y' == ret)
		printf("Yes\n");
	else
		printf("NO\n");
	return 0;
}