#include <stdio.h>


int fib(int n)
{
    if (n <= 2)
        return n;
    else
        return fib(n - 1) + fib(n - 2);
}


int main()
{
    int n = 0;
    scanf("%d", &n);
    printf("%d\n", fib(n));
    return 0;
}
