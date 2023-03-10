#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<int> s= { 2,3,5,1,9,5,6,2 };
	for (auto e : s)
	{
		cout << e << ' ';
	}
	cout << endl;

	s.erase(3);
	for (auto e : s)
	{
		cout << e << ' ';
	}
	return 0;
}