#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct s
{
    char a;
    int  b;
    char c;
};
int main()
{
    printf("%d", sizeof(struct s));
    return 0;
}