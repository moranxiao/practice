#pragma once

namespace yyx {
	template <class K, class V>
	class map {
		struct KOfT {
			const K& operator()(const pair<K,V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename RBTree<K, pair<K, V>, KOfT>::iterator iterator;
		iterator begin()
		{
			return _t.begin();
		}
		iterator end()
		{
			return _t.end();
		}
		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _t.Insert(kv);
		}
		V& operator[](const K& key)
		{
			pair<iterator, bool> p = _t.Insert(make_pair(key, V()));
			return p.first->second;
		}
	private:
		RBTree<K, pair<K, V>, KOfT> _t;
	};
	void test_map()
	{
		string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };

		map<string, int> countMap;
		for (auto& str : arr)
		{
			// 1、str不在countMap中，插入pair(str, int()),然后在对返回次数++
			// 2、str在countMap中，返回value(次数)的引用，次数++;
			countMap[str]++;
		}

		map<string, int>::iterator it = countMap.begin();
		while (it != countMap.end())
		{
			cout << it->first << ":" << it->second << endl;
			++it;
		}

		for (auto& kv : countMap)
		{
			cout << kv.first << ":" << kv.second << endl;
		}
	}
}
