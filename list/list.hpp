#pragma once

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
			_node = _node->next;
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

		list()
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;
		}

		~list()
		{
			
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
		
	private:
		Node* _head;
	};
}