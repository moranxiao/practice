#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int x = 0;
    int y = a * b;
    while (a % b)
    {
        x = b;
        b = a % b;
        a = x;
    }
    printf("%d", y / b);
    return 0;
}