#pragma warning(disable:4996)

//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//int is_legal(char* str)
//{
//    int sz = strlen(str);
//    if (sz < 8)
//        return 0;
//    int a = 0;
//    int b = 0;
//    int c = 0;
//    if (isdigit(*str))
//        return 0;
//    while (*str)
//    {
//        if (isupper(*str))
//            a = 1;
//        else  if (islower(*str))
//            b = 1;
//        else if (isdigit(*str))
//            c = 1;
//        else
//            return 0;
//        str++;
//    }
//    if (a + b + c >= 2)
//        return 1;
//}
//
//int main()
//{
//    int n = 0;
//    int i = 0;
//    scanf("%d", &n);
//    for (i = 0; i < n; i++)
//    {
//        char arr[101] = { 0 };
//        scanf("%s", arr);
//        if (is_legal(arr))
//            printf("YES\n");
//        else
//            printf("NO\n");
//    }
//    return 0;
//}

#include <stdio.h>

#define OFFSETOF(type,memb) (size_t)&((type *)0)->memb

#define EXCH(n,sz) 

struct s
{
	char a;
	int b;
	char c;
};
int main()
{
	printf("%d", OFFSETOF(struct s, c));
	return 0;
}