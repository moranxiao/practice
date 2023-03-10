#pragma warning(disable:4996)

#include <stdio.h>
int main()
{
    long long n, k;
    scanf("%lld %lld", &n, &k);
    long long count = 0;
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = 1; j <= n; j++)
        {
            if (i % j >= k)
                count++;
        }
    }
    printf("%lld", count);
    return 0;
}