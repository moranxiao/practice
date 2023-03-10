#pragma warning(disable:4996)
#include <stdio.h>
#define MAXN 20
void strmcpy(char* t, int m, char* s)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < 20; i++) {
        if (i >= m - 1) {
            s[j] = t[i];
            j++;
        }
    }
}
int main()
{
    char t[MAXN] = "happy new year!";
    char s[MAXN];
    int m = 0;
    scanf("%d\n", &m);
    strmcpy(t, m, s);
    printf("%s\n", s);
    return 0;
}