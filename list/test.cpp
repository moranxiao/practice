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
		lt.push_back(1);
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
	void list_test3()
	{
		int arr[] = { 1,2,3,45,612,53,51,123,0 };
		list<int> lt(arr, arr + 9);
		for (auto e : lt)
		{
			cout << e << ' ';
		}
		cout << endl;
		auto it = lt.begin();
		while (it != lt.end())
		{
			if (*it == 3)
			{
				it = lt.insert(it, 4);
				it++;
			}
			it++;
		}
		for (auto e : lt)
		{
			cout << e << ' ';
		}
		cout << endl;
		it = lt.begin();
		while (it != lt.end())
		{
			if (*it == 612)
			{
				it = lt.erase(it);
			}
			else
				it++;
		}
		for (auto e : lt)
		{
			cout << e << ' ';
		}
		cout << endl;
	}
	void list_test4()
	{
		int arr[] = { 3,4,1,2,16,6 };
		list<int> lt(arr,arr+6);
		list<int> lt1(lt);
		for (auto&e : lt1)
		{
			cout << ++e << ' ';
		}
		cout << endl;
		lt = lt1;
		for (auto e : lt)
		{
			cout << e << ' ';
		}
	}
	void list_test5()
	{
		int arr[] = { 1,2,3,4,5,6,7,8 };
		list<int> lt(arr, arr + 8);
		auto rit = lt.rbegin();
		while (rit != lt.rend())
		{
			cout << *rit << ' ';
			++rit;
		}
		
	}
}

int main()
{
	yyx::list_test5();
	return 0;
}