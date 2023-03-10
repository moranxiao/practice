#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//    int a = 0;
//    int b = 0;
//    scanf("%x %o", &a, &b);
//    printf("%d", a + b);
//    return 0;
//}
#include <stdio.h>
int main()
{
	float a = 0;
	scanf("%f", &a);
	printf("%d", ((int)a) % 10);
}