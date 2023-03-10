#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
double power(int n, int k)
{
	if (k > 0)
		return n * power(n, k - 1);
	else if (k == 0)
		return 1;
	else
		return 1.0 / power(n, -k);
}
int main()
{
	int k = 0;
	int n = 0;
	scanf("%d %d", &n, &k);
	double ret = power(n, k);
	printf("%lf\n", ret);
}