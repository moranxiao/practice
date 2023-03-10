#pragma warning(disable:4996)
#include <stdio.h>


int main()
{
    int n = 0;
    int arr[50] = { 0 };
    scanf("%d", &n);
    int i = 0;
    int flag1 = 0;
    int flag2 = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (i > 0)
        {
            if (arr[i] > arr[i - 1])
                flag1 = 1;
            else if (arr[i] < arr[i - 1])
                flag2 = 1;
        }
    }
    //flag1 和 flag2 都为1是乱序的
    if (flag1 + flag2 > 1)
        printf("unsorted\n");
    else
        printf("sorted\n");
    return 0;
}
