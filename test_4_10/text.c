#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct stu
{
	char name[20];
	char sex[3];
	

};
int main()
{
	struct stu s = { "уехЩ","дп" };
	printf("%s %s", s.name, s.sex);
}