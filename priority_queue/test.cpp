#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#include "priority_queue.hpp"


namespace yyx {
	void test1()
	{
		int arr[] = { 2,1,52,123,12,421,52,12,32 };
		priority_queue<int> heap(arr, arr + sizeof(arr) / sizeof(arr[0]));
		while (!heap.empty())
		{
			cout << heap.top() << ' ';
			heap.pop();
		}
		
	}

}
int main()
{
	yyx::test1();

	return 0;
} 