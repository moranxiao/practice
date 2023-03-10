#pragma once

namespace yyx {
	template<class T>
	class unorder_map {
		typedef HashTable<T, T> HashTable;
		typedef typename HashTable<T, T>::iterator iteraotr;
	public:
		pair<iterator, bool> insert(const T& data)
		{

		}
		
	private:
		HashTable _ht;
	};
}