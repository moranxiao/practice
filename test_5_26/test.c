#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdio.h>

void main(void)
{
	char string[100] = "The String to End All Strings!";
     _strlwr(string);
	/*_strupr(string);*/
	printf("%s\n", string);
}
