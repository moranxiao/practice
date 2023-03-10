#pragma warning(disable:4996)

#include "Date.h"

//void test1()
//{
//	Date d1(2022, 9, 22);
//	Date d2(2022, 10, 22);
//	d1 = d2;
//	d2 = d1 + 4000;
//}

void test2()
{
	Date d1(1921, 10, 22);
	Date d2(2022, 9, 26);
	cout << (d2 + 1 ) << endl;
	cin >> d1;
	cout << d1<<endl;
}
int main()
{
	test2();
	return 0; 
}