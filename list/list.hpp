#pragma once
#include "reverse_iterator.hpp"
namespace yyx{
	
	template<class T>
	struct list_node {
		T _val;
		list_node* _prev;
		list_node* _next;
		list_node(const T& val = T())
			:_prev(nullptr),
			_next(nullptr),
			_val(val)
		{}
	};
	template<class T,class Ref,class Ptr>
	struct __list_iterator {
		typedef list_node<T> Node;
		typedef __list_iterator<T,Ref,Ptr> iterator;
		Node* _node;
		__list_iterator(Node* node)
			:_node(node)
		{}
		iterator operator++()
		{
			_node = _node->_next;
			return _node;
		}
		iterator operator++(int)
		{
			Node* ret = _node;
			_node = _node->_next;
			return ret;
		}
		iterator operator--()
		{
			_node = _node->_prev;
			return _node;
		}
		iterator operator--(int)
		{
			Node* ret = _node;
			_node = _node->_prev;
			return ret;
		}
		bool operator!=(iterator it)
		{
			return it._node != _node;
		}
		bool operator==(iterator it)
		{
			return it._node == _node;
		}
		Ref operator*()
		{
			return _node->_val;
		}
		Ptr operator->()
		{
			return &(_node->_val);
		}
	};
	template<class T>
	class list {
		typedef list_node<T> Node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T,const T&,const T*> const_iterator;
		typedef __reverse_iterator<iterator, T&, T*> reverse_iterator;
		typedef __reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;
		reverse_iterator rbegin()
		{
			return end();
		}
		reverse_iterator  rend()
		{
			return begin();
		}
		const_reverse_iterator crbegin()const
		{
			return cend();
		}
		const_reverse_iterator crend()const
		{
			return cbegin();
		}
		list()
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;
		}
		void swap(list<T>& lt)
		{
			std::swap(lt._head, _head);
		}
		list(const list<T>& lt)
		{
			new(this)list<T>;
			list<T> tmp(lt.begin(), lt.end());
			swap(tmp);
		}
		list<T>& operator=(list<T> tmp)
		{
			swap(tmp);
			return *this;
		}
		template<class Iterator>
		list(Iterator begin, Iterator end)
		{
			new(this)list<T>;
			while (begin != end)
			{
				push_back(*begin);
				begin++;
			}
		}
		~list()
		{
			auto it = begin();
			while (it != end())
			{
				it = erase(it);
			}
			delete _head;
			_head = nullptr;
		}
		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}
		const_iterator begin()const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end()const
		{
			return const_iterator(_head);
		}
		const_iterator cbegin()const
		{
			return const_iterator(_head->_next);
		}
		const_iterator cend()const
		{
			return const_iterator(_head);
		}

		void push_back(const T& val)
		{
			Node* newnode = new Node(val);
			newnode->_prev = _head->_prev;
			newnode->_next = _head;
			newnode->_prev->_next = newnode;
			_head->_prev = newnode;
		}
		void push_front(const T& val)
		{
			Node* newnode = new Node(val);
			newnode->prev = _head;
			newnode->_next = _head->next;
			newnode->_next->_prev = newnode;
			_head->_next = newnode;
		}
		iterator insert(iterator pos,const T& val)
		{
			Node* newnode = new Node(val);
			newnode->_prev = pos._node->_prev;
			newnode->_next = pos._node;
			newnode->_prev->_next = newnode;
			pos._node->_prev = newnode;
			return iterator(newnode);
		}
		iterator erase(iterator pos)
		{
			pos._node->_next->_prev = pos._node->_prev;
			iterator ret = pos._node->_prev->_next = pos._node->_next;
			delete pos._node;
			return ret;
		}
	private:
		Node* _head;
	};
}