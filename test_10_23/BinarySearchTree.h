#pragma once
#include <iostream>

using namespace std;

template<class K>
struct BSTreeNode
{
	BSTreeNode(const K& key)
		:_left(nullptr),
		_right(nullptr),
		_key(key)
	{}
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
	K _key;
};

template <class K>
class BSTree
{
	typedef BSTreeNode<K> Node;
public:
	bool Erase(const K& key)
	{
		if (_root == nullptr)
			return false;
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (key > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				if (cur->_left == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_right;
						return true;
					}
					if (parent->_key > key)
						parent->_left = cur->_right;
					else
						parent->_right = cur->_right;
					delete cur;
				}
				else if (cur->_right == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_left;
						return true;
					}
					if (parent->_key > key)
						parent->_left = cur->_left;
					else
						parent->_right = cur->_left;
					delete cur;
				}
				else
				{
					Node* min_key = cur->_right;
					parent = cur;
					while (min_key->_left)
					{
						parent = min_key;
						min_key = min_key->_left;
					}
					swap(min_key->_key, cur->_key);
					if (parent == cur)
						parent->_right = min_key->_right;
					else
						parent->_left = min_key->_right;
					delete min_key;
				}
				return true;
			}
		}
		return false;
	}
	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
		}
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (key > cur->_key)
			{
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		Node* newnode = new Node(key);
		if (key > parent->_key)
			parent->_right = newnode;
		else
			parent->_left = newnode;
		return true;
	}
	bool InsertR(const K& key)
	{
		return _InsertR(_root,key);
	}
	bool EraseR(const K&key)
	{
		return _EraseR(_root, key);
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
private:
	bool _EraseR(Node*& root, const K& key)
	{
		if (root == nullptr)
			return false;
		if (root->_key > key)
		{
			return _EraseR(root->_left, key);
		}
		else if (root->_key < key)
		{
			return _EraseR(root->_right, key);
		}
		else
		{
			if (root->_left == nullptr)
			{
				Node* d = root;
				root = root->_right;
				delete d;
			}
			else if (root->_right == nullptr)
			{
				Node* d = root;
				root = root->_left;
				delete d;
			}
			else
			{
				Node* cur = root->_right;
				while (cur->_left)
				{
					cur = cur->_left;
				}
				swap(root->_key, cur->_key);
				_EraseR(root->_right,cur->_key);
			}
			return true;
		}
	}
	bool _InsertR(Node*& root,const K& key)
	{
		if (root == nullptr)
		{
			root = new Node(key);
			return true;
		}
		if (root->_key > key)
		{
			return _InsertR(root->_left, key);
		}
		else if (root->_key < key)
		{
			return _InsertR(root->_right, key);
		}
		else
			return false;
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}
private:
	Node* _root = nullptr;
};

void test1()
{
	BSTree<int> t;
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	for (auto e : a)
	{
		t.InsertR(e);
	}
	t.InOrder();
	for (auto e : a)
	{
		t.EraseR(e);
		t.InOrder();
	}
	cout << endl;
}
