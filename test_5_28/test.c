#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a=3, b=2, c=4, d=6, x;
	if (a < b) 
		if (c < d)
			x = 1;
	    else if (a < c)
	        if (b < d)
		     	x = 2;
		    else x = 3;
		else x = 6;
	else x = 7;
}
//#include<stdio.h>
//void main()
//{
//	int  a = 12, b = 7, m = 1;
//	switch (a % 3)
//	{
//	case 0:
//		switch (b % 4)
//		{
//		default:  m++;
//		case  0:  m++; break;
//		}
//	case 1:  m++; break;
//	}
//	printf("%d\n", m);
//}
