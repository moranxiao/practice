#pragma warning(disable:4996)
#include <stdio.h>
//int main()
//{
//	char* a[] = { "work","at","alibaba" };
//	char** pa = a;
//	pa++;
//	printf("%s\n", *pa);
//	return 0;
//}
int main()
{
	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char*** cpp = cp;
	printf("%s\n", **++cpp);//1
	printf("%s\n", *-- * ++cpp + 3);//2
	printf("%s\n", *cpp[-2] + 3);//3
	printf("%s\n", cpp[-1][-1] + 1);//4
	return 0;
}