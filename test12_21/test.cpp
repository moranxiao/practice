#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(0);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	auto it = v.begin();
	while (it != v.end())
	{
		if (*it == 0)
		{
			v.erase(it);
		}
		else
		{
			cout << *it;
		}
		it++;
	}
	return 0;
}