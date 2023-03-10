#include <stdio.h>


int main()
{
    int n = 0;
    int max = 0;
    int min = 100;
    scanf("%d", &n);
    int i = 0;
    int tmp = 0;//存放内次读取的成绩
    for (i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        if (tmp > max)
            max = tmp;
        if (tmp < min)
            min = tmp;
    }
    printf("%d\n", max - min);

    return 0;
}
