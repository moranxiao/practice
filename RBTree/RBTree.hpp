#pragma once

  enum Color {
	RED,
	BLACK
};
template <class T>
struct RBTreeNode
{
	typedef RBTreeNode Node;
	RBTreeNode(const T& val)
		:_val(val),
		_parent(nullptr),
		_left(nullptr),
		_right(nullptr),
		_col(RED)
	{}
	RBTreeNode<T>* _parent;
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;

	T _val;
	Color _col;
};
template <class T,class Ref,class Ptr>
struct __RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef __RBTreeIterator<T, Ref, Ptr> iterator;
	Node* _node;
	__RBTreeIterator(Node* node)
		:_node(node)
	{}
	iterator operator++()
	{
		if (_node->_right == nullptr)
		{
			if(_node == _node->_parent->_left)
				_node = _node->_parent;
			else
			{
				Node* prev = _node;
				Node* cur = _node->_parent;
				while (cur && cur->_right == prev)
				{
					prev = cur;
					cur = cur->_parent;
				}
				_node = cur;
			}
		}
		else
		{
			Node* prev = _node->_right;
			Node* cur = prev->_left;
			while (cur)
			{
				prev = cur;
				cur = cur->_left;
			}
			_node = prev;
		}
		return *this;
	}
	iterator operator--()
	{
		if (_node->_left == nullptr)
		{
			if (_node == _node->_parent->right)
				_node = _node->_parent;
			else
			{
				Node* prev = _node;
				Node* cur = _node->_parent;
				while (cur && cur->_left == prev)
				{
					prev = cur;
					cur = cur->_parent;
				}
				_node = cur;
			}
		}
		else
		{
			Node* prev = _node->_left;
			Node* cur = prev->_right;
			while (cur)
			{
				prev = cur;
				cur = cur->_right;
			}
			_node = prev;
		}
		return *this;
	}
	Ref operator*()
	{
		return _node->_val;
	}
	Ptr operator->()
	{
		return &_node->_val;
	 }
	bool operator!=(iterator it)
	{
		return it._node != _node;
	}
	bool operator==(iterator it)
	{
		return it._node == _node;
	}
};


template<class K, class T,class KOfT>
struct RBTree {
	typedef RBTreeNode<T> Node;
	typedef __RBTreeIterator<T, T&, T*> iterator;
	RBTree()
		:_root(nullptr)
	{}
	iterator begin()
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}
		return cur;
	}
	iterator end()
	{
		return nullptr;
	}
	pair<iterator,bool> Insert(const T& data)
	{
		KOfT kot;
		Node* newnode = new Node(data);
		if (_root == nullptr)
		{
			_root = newnode;
			_root->_col = BLACK;
			return make_pair(iterator(newnode),true);
		}
		Node* prev = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (kot(cur->_val) < kot(data))
			{
				prev = cur;
				cur = cur->_right;
			}
			else if (kot(cur->_val)> kot(data))
			{
				prev = cur;
				cur = cur->_left;
			}
			else
			{
				return make_pair(iterator(cur),false);
			}
		}
		if (kot(prev->_val) < kot(data))
		{
			prev->_right = newnode;
			newnode->_parent = prev;
		}
		else if (kot(prev->_val) > kot(data))
		{
			prev->_left = newnode;
			newnode->_parent = prev;
		}
		Node* parent = newnode->_parent;
		cur = newnode;
		while (parent && parent->_col == RED)
		{
			Node* grand = parent->_parent;
			Node* uncle = grand->_left;
			if (uncle == parent)
				uncle = grand->_right;
			if (parent->_col == RED && uncle && uncle->_col == RED)
			{
				parent->_col = BLACK;
				uncle->_col = BLACK;
				grand->_col = RED;
				cur = grand;
				parent = cur->_parent;
			}
			else {
				if (grand->_left == parent && parent->_left == cur)
				{
					//左旋
					rotateL(grand);
					parent->_col = BLACK;
					grand->_col = RED;
				}
				else if (grand->_right == parent && parent->_right == cur)
				{
					//右旋
					rotateR(grand);
					parent->_col = BLACK;
					grand->_col = RED;
				}
				else if (grand->_right == parent && parent->_left == cur)
				{
					rotateL(parent);
					rotateR(grand);
					cur->_col = BLACK;
					grand->_col = RED;
				}
				else
				{
					rotateR(parent);
					rotateL(grand);
					cur->_col = BLACK;
					grand->_col = RED;
				}
				break;
			}
		}
		while (_root->_parent != nullptr)
			_root = _root->_parent;
		_root->_col = BLACK;
		return make_pair(iterator(newnode) ,true);
	}

	bool IsBalance()
	{
		if (_root == nullptr)
		{
			return true;
		}

		if (_root->_col == RED)
		{
			cout << "根节点不是黑色" << endl;
			return false;
		}

		// 黑色节点数量基准值
		int benchmark = 0;
		/*Node* cur = _root;
		while (cur)
		{
		if (cur->_col == BLACK)
		++benchmark;

		cur = cur->_left;
		}*/

		return PrevCheck(_root, 0, benchmark);
	}

private:

	bool PrevCheck(Node* root, int blackNum, int& benchmark)
	{
		if (root == nullptr)
		{
			//cout << blackNum << endl;
			//return;
			if (benchmark == 0)
			{
				benchmark = blackNum;
				return true;
			}

			if (blackNum != benchmark)
			{
				cout << "某条黑色节点的数量不相等" << endl;
				return false;
			}
			else
			{
				return true;
			}
		}

		if (root->_col == BLACK)
		{
			++blackNum;
		}

		if (root->_col == RED && root->_parent->_col == RED)
		{
			cout << "存在连续的红色节点" << endl;
			return false;
		}

		return PrevCheck(root->_left, blackNum, benchmark)
			&& PrevCheck(root->_right, blackNum, benchmark);
	}
	void rotateL(Node* parent)
	{
		Node* grand = parent->_parent;
		Node* Lnode = parent->_left;
		Node* LRnode = Lnode->_right;
		if (grand != nullptr)
		{
			if (parent == grand->_left)
			{
				grand->_left = Lnode;
			}
			else
			{
				grand->_right = Lnode;
			}
		}
		Lnode->_parent = grand;
		parent->_left = LRnode;
		if (LRnode)
		{
			LRnode->_parent = parent;
		}
		Lnode->_right = parent;
		parent->_parent = Lnode;
	}
	void rotateR(Node* parent)
	{
		Node* grand = parent->_parent;
		Node* Rnode = parent->_right;
		Node* RLnode = Rnode->_left;
		if (grand)
		{
			if (grand->_left == parent)
			{
				grand->_left = Rnode;
			}
			else
			{
				grand->_right = Rnode;
			}
		}
		Rnode->_parent = grand;
		parent->_right = RLnode;
		if (RLnode)
		{
			RLnode->_parent = parent;
		}
		Rnode->_left = parent;
		parent->_parent = Rnode;
	}
	Node* _root;

};
//void TestRBTree1()
//{
//	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14, 0,5,30,25,20,4,13,30,28,27};  // 测试双旋平衡因子调节
//	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
//	RBTree<int, int> t1;
//	for (auto e : a)
//	{
//		t1.Insert(e);
//	}
//
//	cout << "IsBalance:" << t1.IsBalance() << endl;
//}
//void TestRBTree2()
//{
//	size_t N = 1000;
//	srand(time(0));
//	RBTree<int, int> t1;
//	for (size_t i = 0; i < N; ++i)
//	{
//		int x = rand();
//		cout << "Insert:" << x << ":" << i << endl;
//		t1.Insert(x);
//	}
//	cout << "IsBalance:" << t1.IsBalance() << endl;
//}
void TestRBTree3()
{

}