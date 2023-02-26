#pragma once

namespace yyx {
	//enum State {
	//	EMPTY,
	//	DELETE,
	//	EXIST
	//};
	//template<class T>
	//struct HashData {

	//	State _st = EMPTY;
	//	T _data;
	//};
	template <class T>
	struct HashNode
	{
		HashNode(const T& data)
			:_data(data)
		{
		}
		T _data;
		HashNode<T>* _next = nullptr;
	};
	template <class K>
	struct HashFunc {
		size_t operator()(const K& key)
		{
			return (size_t)key;
		}
	};
	template <>
	struct HashFunc<string> {
		size_t operator()(const string& str)
		{
			size_t ret = 0;
			for (auto e : str)
			{
				ret *= 131;
				ret += e;
			}
			return ret;
		}
	};
	template<class K, class T, class Hash>
	class HashTable;
	template<class K,class T,class Hash>
	struct __HashIterator {
		typedef HashNode<T> Node;
		typedef __HashIterator<K,T,Hash> iterator;
		Node* _node;
		HashTable<K, T, Hash>* _pht;
		__HashIterator(Node* node= nullptr,HashTable<K, T, Hash>* pht = nullptr)
			:_node(node),
			_pht(pht)
		{}
		bool operator==(const iterator& it)
		{
			return _node == it._node;
		}
		bool operator!=(const iterator& it)
		{
			return _node != it._node;
		}
		T& operator*()
		{
			return _node->_data;
		}
		T* operator->()
		{
			return &_node->_data;
		}
		iterator& operator++()
		{
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				Hash hash;
				size_t	hashi = hash(_node->_data) % _pht->_ht.size();
				hashi++;
				while (hashi < _pht->_ht.size() && _pht->_ht[hashi] == nullptr)
				{
					hashi++;
				}
				if (hashi == _pht->_ht.size())
					_node = nullptr;
				else
				{
					_node = _pht->_ht[hashi];
				}
			}
			return *this;
		}
	};
	template<class K,class T,class Hash = HashFunc<K>>
	class HashTable {
		friend __HashIterator<K,T,Hash>;
	public:
		typedef __HashIterator<K, T, Hash> iterator;
		typedef HashNode<T> Node;
		iterator begin()
		{
			for (size_t i = 0; i < _ht.size(); i++)
			{
				if (_ht[i])
					return iterator(_ht[i], this);
			}
			return iterator(nullptr, this);
		}
		iterator end()
		{
			return iterator(nullptr, this);
		}
		bool insert(const T& data)
		{
			if (find(data))
			{
				return false;
			}
			if (_ht.size() == 0 || _size * 10 / _ht.size() > 7)
			{
				size_t newcapacity = _ht.size() == 0 ? 4 : _ht.size() * 2;
				vector<Node*> newHt;
				newHt.resize(newcapacity,nullptr);
				for (size_t i = 0; i < _ht.size(); i++)
				{
					Hash hash;
					Node* cur = _ht[i];
					while (cur)
					{
						size_t hashi = hash(cur->_data) % newcapacity;
						Node* tmp = cur->_next;
						cur->_next = newHt[hashi];
						newHt[hashi] = cur;
						cur = tmp;
					}
				}
				_ht.swap(newHt);
			}
			Hash hash;
			Node* newnode = new Node(data);
			size_t hashi = hash(data) % _ht.size();
			newnode->_next = _ht[hashi];
			_ht[hashi] = newnode;
			++_size;
			return true;
		}
		bool erase(const T& data)
		{
			if (_size == 0)
				return false;
			Hash hash;
			size_t hashi = hash(data) % _ht.size();
			Node* prev = nullptr;
			Node* cur = _ht[hashi];
			while (cur)
			{
				if (cur->_data == data)
				{
					if (prev == nullptr)
					{
						_ht[hashi] = cur->_next;
						delete cur;
					}
					else
					{
						prev->_next = cur->_next;
						delete cur;
					}
					--_size;
					return true;
				}
				prev = cur;
				cur = cur->_next;
			}
			return false;
		}
		Node* find(const T& data)
		{
			if (_size == 0)
				return nullptr;
			Hash hash;
			size_t hashi = hash(data) % _ht.size();
			Node* cur = _ht[hashi];
			while (cur)
			{
				if (cur->_data == data)
					return cur;
				cur = cur->_next;
			}
			return nullptr;
		}
		//bool insert(const T& data)
		//{
		//	if (find(data))
		//		return false;
		//	if (_ht.size() == 0 || _size * 10 /_ht.size() > 8)
		//	{
		//		size_t capacity = _ht.size() == 0 ? 4 : _ht.size() * 2;
		//		HashTable<K,T,Hash> newHash;
		//		newHash._ht.resize(capacity);
		//		for (auto e : _ht)
		//		{
		//			if (e._st == EXIST)
		//				newHash.insert(e._data);
		//		}
		//		_ht.swap(newHash._ht);
		//	}
		//	Hash hash;
		//	size_t hashi = hash(data) % _ht.size();
		//	while (_ht[hashi]._st == EXIST)
		//	{
		//		hashi++;
		//		hashi %= _ht.size();
		//	}
		//	_ht[hashi]._data = data;
		//	_ht[hashi]._st = EXIST;
		//	_size++;
		//	return true;
		//}
		//Data* find(const T& data)
		//{
		//	if (_size == 0)
		//		return nullptr;
		//	Hash hash;
		//	size_t hashi = hash(data) % _size;
		//	size_t start = hashi;
		//	while (_ht[hashi]._st != EMPTY)
		//	{
		//		if (_ht[hashi]._st != DELETE && _ht[hashi]._data == data)
		//			return &_ht[hashi];
		//		hashi++;
		//		hashi %= _ht.size();
		//		if (hashi == start)
		//			break;
		//	}
		//	return nullptr;
		//}
		//bool erase(const T& data)
		//{
		//	Data* cur = find(data);
		//	if (cur)
		//	{
		//		cur->_st = DELETE;
		//		_size--;
		//		return true;
		//	}
		//	else
		//	{
		//		return false;
		//	}
		//}
	//private:
	//	vector<HashData<T>> _ht;
	//	size_t _size = 0;
	private:
		vector<HashNode<T>*> _ht;
		size_t _size = 0;
	};
	//void test()
	//{
	//	//HashTable<int, int> ht;
	//	//ht.insert(1);
	//	//ht.insert(9);
	//	//ht.insert(7);
	//	//ht.insert(8);
	//	//ht.insert(4);
	//	//ht.insert(6);
	//	//ht.insert(9);
	//	//ht.insert(46);
	//	//ht.insert(56);
	//	//ht.insert(34);
	//	//ht.insert(43);
	//	//ht.insert(25);
	//	HashTable<string, string> ht;
	//	ht.insert("string");
	//	ht.insert("auto");
	//	ht.insert("love");
	//	ht.insert("com");
	//	ht.insert("string");
	//	ht.insert("data");
	//	ht.insert("insert");

	//}
	//void test()
	//{
	//	HashTable<int, int> ht;
	//	ht.insert(4);
	//	ht.insert(3);
	//	ht.insert(2);
	//	ht.insert(1);
	//	ht.insert(5);
	//	ht.insert(7);
	//	ht.insert(6);
	//	ht.insert(8);
	//	ht.insert(9);
	//	ht.insert(9);
	//	ht.erase(9);
	//	ht.erase(10);
	//	ht.erase(1);

	//}
	void test()
	{
		HashTable<int, int> ht;
		ht.insert(2);
		ht.insert(3);
		ht.insert(5);
		ht.insert(7);
		ht.insert(12);
		ht.insert(13);
		for (auto e : ht)
		{
			cout << e << " ";
		}
		cout << endl;
		ht.erase(13);
		ht.erase(12);
		ht.erase(11);
		ht.erase(13);
		ht.erase(3);
		for (auto e : ht)
		{
			cout << e << " ";
		}

	}
}
