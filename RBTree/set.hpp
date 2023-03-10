#pragma once

namespace yyx {
	template<class	T>
	class set {
		struct KOfT {
			const T& operator()(const T& data)
			{
				return data;
			}
		};
	public:
		typedef typename RBTree<T, T, KOfT>::iterator iterator;
		iterator begin()
		{
			return _t.begin();
		}
		iterator end()
		{
			return _t.end();
		}
		pair<iterator, bool> insert(const T& key)
		{
			return _t.Insert(key);
		}
	private:
		RBTree<T, T, KOfT> _t;
	};
	void test_set()
	{
		set<int> s;

		s.insert(3);
		s.insert(2);
		s.insert(1);
		s.insert(5);
		s.insert(3);
		s.insert(6);
		s.insert(4);
		s.insert(9);
		s.insert(7);


		set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
}