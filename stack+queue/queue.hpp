#pragma once 

namespace yyx {
	template<class T,class Container = deque<T>>
	class queue
	{
	public:
		void push(const T& val)
		{
			_con.push_back(val);
		}
		void pop()
		{
			_con.pop_front();
		}
		T& front()
		{
			return _con.front();
		}
		T& back()
		{
			return _con.back();
		}
		bool empty()
		{
			return _con.empty();
		}
		size_t size()
		{
			return _con.size();
		}
	private:
		Container _con;
	};
}