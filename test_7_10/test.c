#pragma warning(disable:4996)
#include <stdio.h>
struct s1
{
	char a;
	char b;
	int c;
};
struct s
{
	int a;
	char  b[10];
	char c;
	char d;
	char e;
};
int main()
{
	printf("%zu", sizeof(struct s));
	return 0;
}