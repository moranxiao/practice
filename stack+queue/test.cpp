#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>

using namespace std;

#include "queue.hpp"
#include "stack.hpp"

//void test()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
//	list<int> lt(arr, arr + 9);
//	list<int>::reverse_iterator it = lt.rbegin();
//	while (it != lt.rend())
//	{
//		if (*it == 4)
//		{
//			it = lt.erase(it);
//		}
//	}
//}

namespace yyx
{
	void stack_test()
	{
		stack<int, vector<int>> st;
		for (int i = 0; i < 10; i++)
		{
			st.push(i);
		}
		while (!st.empty())
		{
			cout << st.top() << ' ';
			st.pop();
		}
	}
	void queue_test()
	{
		queue<int, list<int>> st;
		for (int i = 0; i < 10; i++)
		{
			st.push(i);
		}
		while (!st.empty())
		{
			cout << st.front() << ' ';
			st.pop();
		}
	}
}
int main()
{
	yyx::queue_test();
	return 0;
}