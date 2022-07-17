#pragma warning(disable:4996)
#include <stdio.h>
struct S
{
	char arr[10];
	int age;
	float score;
};
int main()
{
	struct S s = {0};

	FILE* pf = fopen("test.txt", "w");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}
	//
	//fscanf(pf, "%s %d %f", s.arr, &(s.age), &(s.score));
	//printf("%s %d %f\n", s.arr, s.age, s.score);
	fprintf(stdout, "%s %d %f\n", s.arr, s.age, s.score);

	fclose(pf);
	pf = NULL;
	return 0;
}