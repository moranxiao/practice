#pragma once

namespace yyx {
	template<class T,class Container = vector<T>, class Compare = less<T>>
	class priority_queue {
	public:
		priority_queue() = default;
		template<class Iterator>
		priority_queue(Iterator begin, Iterator end)
			: _con(begin, end)
		{
			for (int i = (_con.size() - 2) / 2; i >= 0; i--)
			{
				AdjustDown(i);
			}
		}
		void push(const T& val)
		{
			_con.push_back(val);
			AdjustUp(_con.size() - 1);
		}
		void AdjustUp(size_t son)
		{
			while (son != 0)
			{
				size_t parent = (son - 1) / 2;
				if (Compare()(_con[parent], _con[son]))
				{
					swap(_con[son], _con[parent]);
					son = parent;
				}
				else
				{
					break;
				}
			}
		}
		void AdjustDown(size_t parent)
		{
			size_t son = parent * 2 + 1;
			if (son + 1 < _con.size() && Compare()(_con[son], _con[son + 1]))
			{
				son++;
			}
			while (son < _con.size())
			{
				if (Compare()(_con[parent], _con[son]))
				{
					swap(_con[parent], _con[son]);
					parent = son;
					son = parent * 2 + 1;
					if (son + 1 < _con.size() && Compare()(_con[son], _con[son + 1]))
					{
						son++;
					}
				}
				else
				{
					break;
				}
			}
		}
		T& top()
		{
			return _con[0];
		}
		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(0);
		}
		size_t size()
		{
			return _con.size();
		}
		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;
	};
}