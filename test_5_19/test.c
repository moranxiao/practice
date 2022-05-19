#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
        int y, m, d, y1, m1, d1;
        scanf("%d %d %d %d %d %d", &y, &m, &d, &y1, &m1, &d1);
        if (y < y1)
            printf("yes");
        else if (y == y1)
        {
            if (m < m1)
                printf("yes");
            else if (m == m1)
            {
                if (d <= d1)
                    printf("yes");
                else
                    printf("no");
            }
            else
                printf("no");
        }
        else
            printf("no");
        return 0;
}