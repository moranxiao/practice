#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
    char arr[10001] = { 0 };
    int i = 0;
    while (scanf("%c", &arr[i]) != EOF)
    {
        if (arr[i] == '\n')
            arr[i] = '\0';
        i++;
    }
    int right = strlen(arr) - 1;
    int left = 0;
    char t = 0;
    while (left < right)
    {
        t = arr[left];
        arr[left] = arr[right];
        arr[right] = t;
        left++;
        right--;
    }
    printf("%s", arr);
    return 0;
}