#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    while (n)
    {
        i += n % 10;
        n /= 10;
        if (n )
        i *= 10;
    }
    printf("%d", i);
}