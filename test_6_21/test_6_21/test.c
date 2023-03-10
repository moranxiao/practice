#pragma warning(disable:4996)
#include <stdio.h>
int main()
{
    int i = 0;
    for (i = 0; i < 6; i++)
    {
        printf("before %d\n", i);
        if (5 == i)
        {
            printf("continue\n");
            continue;
        }
        printf("after %d\n", i);
    }
}