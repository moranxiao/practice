#pragma once

namespace yyx {
	template<class Iterator,class Ref,class Ptr> 
	struct __reverse_iterator {
		__reverse_iterator(Iterator it)
			:_it(it)
		{}
		__reverse_iterator operator++()
		{
			_it--;
			return _it;
		}
		Ref operator*()
		{
			Iterator tmp = _it;
			tmp--;
			return *tmp;
		}
		Ptr operator->()
		{
			Iterator tmp = _it;
			tmp--;
			return &*tmp;
		}
		__reverse_iterator operator--()
		{
			return ++_it;
		}
		bool operator!=(const __reverse_iterator& it)
		{
			return _it != it._it;
		}
		Iterator _it;
	};
}