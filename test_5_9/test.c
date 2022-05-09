#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d", n / 12 * 4 + 2);
//}
//#include <stdio.h>
//int main()
//{
//	//char a;
//	//printf("%d",sizeof a);
//	int a = 2;
//	printf("%d", a + --a);
//	return 0;
//}
#include <stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    int j = 0;
    for (i = 0; i < n / 2; i++)
    {
        for (j = 0; j < i; j++)
            printf(" ");
        printf("*");
        for (j = 0; j < n - 2 - i; j++)
            printf(" ");
        printf("*\n");
    }
    for (i = n / 2; i; i--)
    {
        for (j = 0; j < i; j++)
            printf(" ");
        printf("*");
        for (j = 0; j < n - 2 - i; j++)
            printf(" ");
        printf("*\n");
    }
    return 0;
}