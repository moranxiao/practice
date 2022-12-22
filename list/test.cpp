#include <iostream>
#include <list>
#include <assert.h>

using namespace std;

#include "list.hpp"

namespace yyx {
	void list_test1()
	{
		std::list<int> lt1(1);
		for (auto e : lt1)
		{
			cout << e;
		}
	}
	void list_test2()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		lt.push_back(6);

		for (auto& e : lt)
		{
			cout << ++e;
		}
		cout << endl;
		const list<int> lt1;
		lt1.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		lt.push_back(6);
		for (auto e : lt1)
		{
			cout << e;
		}

	}
	void list_test2()
	{

	}
}

int main()
{
	yyx::list_test3();
	return 0;
}