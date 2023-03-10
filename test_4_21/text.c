#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int main()
{
    char arr[20] = { 0 };
    *arr = 'a';
    printf("%s", arr);
}