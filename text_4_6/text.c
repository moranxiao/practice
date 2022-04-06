#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int i = 0;
    float count = 0;
    char arr[10] = { 0 };
    float ret = 0;
    scanf("%s", arr);
    for (i = 0; i <= 9; i++)
    {
        if (arr[i] >= '0' && arr[i] <= '9')
        {
            count++;
            ret = ret + arr[i]-48;
        }
        else if(arr[i] == '*')
            break;
    }
    ret = ret / count;
    printf("%.3f", ret);
}