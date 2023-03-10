#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> v(arr, arr + 10);
	cout << v.capacity() << endl;
	return 0;
}