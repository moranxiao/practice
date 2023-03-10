#pragma warning(disable:4996)

#include <stdio.h>
int main()
{
    int n = 0;
    int i = 0;
    scanf("%d", &n);
    char arr[20] = { 0 };
    arr[i++] = n % 10 + '0';
    n /= 10;
    while (n)
    {
        arr[i++] = n % 10 + '0';
        n /= 10;
    }
    printf("%s", arr);
    return 0;
}