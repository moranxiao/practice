#include <iostream>
#include <map>
#include <assert.h>

using namespace std;
#include "AVLTree.hpp"

void test1()
{
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };  // 测试双旋平衡因子调节
//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	AVLTree<int, int> t1;
	for (auto e : a)
	{
		t1.Insert(make_pair(e, e));
	}
	t1.InOrder();
	cout <<t1.IsBalance();
}

void test2()
{
	size_t N = 10000;
	srand(time(0));
	AVLTree<int, int> t1;
	for (size_t i = 0; i < N; ++i)
	{
		int x = rand();
		t1.Insert(make_pair(x, i));
		/*	bool ret = t1.IsBalance();
			if (ret == false)
			{
				int u = 1;
			}
			else
			{
				cout << "Insert:" << x << " IsBalance:" <<ret<< endl;
			}*/
	}
	cout << "IsBalance:" << t1.IsBalance() << endl;
}
int main()
{
	test2();
	return 0;
}