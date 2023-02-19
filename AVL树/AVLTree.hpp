#pragma once

template <class K,class V>
struct AVLNode
{
	AVLNode(const pair<K, V>& kv)
		:_kv(kv),
		_bf(0),
		_parent(nullptr),
		_left(nullptr),
		_right(nullptr)
	{}
	AVLNode<K,V>* _parent;
	AVLNode<K,V>* _left;
	AVLNode<K,V>* _right;

	pair<K, V> _kv;
	int _bf;
};
template<class K,class V,class Compare = less<K>>
struct AVLTree {
	typedef AVLNode<K,V> Node;
	AVLTree()
		:_root(nullptr)
	{}
	bool Insert(const pair<K,V>& data)
	{
		Node* newnode = new Node(data);
		Compare cmp;
		if (_root == nullptr)
		{
			_root = newnode;
			return true;
		}
		Node* prev = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cmp(data.first, cur->_kv.first))
			{
				prev = cur;
				cur = cur->_left;
			}
			else if (cmp(cur->_kv.first, data.first))
			{
				prev = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}
		if (cmp(data.first, prev->_kv.first))
		{
			prev->_left = newnode;
			newnode->_parent = prev;
		}
		else if (cmp(prev->_kv.first, data.first))
		{
			prev->_right = newnode;
			newnode->_parent = prev;
		}
		cur = newnode;
		Node* parent = newnode->_parent;
		while (parent)
		{
			if (parent->_left == cur)
			{
				parent->_bf--;
			}
			else if (parent->_right == cur)
			{
				parent->_bf++;
			}
			if (parent->_bf == 0)
				break;
			else if (abs(parent->_bf) == 1)
			{
				cur = parent;
				parent = cur->_parent;
			}
			else if (parent->_bf == 2)
			{
				if (parent->_right->_bf == 1)
				{
					RotateR(parent);
				}
				else if (parent->_right->_bf == -1)
				{
					RotateLR(parent);
				}
				else
					assert(false);
				break;
			}
			else if (parent->_bf == -2)
			{
				if (parent->_left->_bf == -1)
				{
					RotateL(parent);
				}
				else if (parent->_left->_bf == 1)
				{
					RotateRL(parent);
				} 
				else
					assert(false);
				break;
			}
			else
			{
				assert(false);
			}
		}
		while (_root->_parent != nullptr)
		{
			_root = _root->_parent;
		}
		return true;
	}

	// AVLÊ÷µÄÑéÖ¤
	bool IsBalance()
	{
		return _IsBalance(_root);
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
private:
	// ÓÒµ¥Ðý
	void RotateR(Node* pParent)
	{
		Node* Rnode = pParent->_right;
		Node* RLnode = Rnode->_left;
		Node* parent = pParent->_parent;
		if (parent)
		{
			if (parent->_right == pParent)
			{
				parent->_right = Rnode;
			}
			else
			{
				parent->_left = Rnode;
			}
		}
		Rnode->_parent = parent;
		pParent->_parent = Rnode;
		Rnode->_left = pParent;
		pParent->_right = RLnode;
		if (RLnode)
			RLnode->_parent = pParent;
		pParent->_bf = Rnode->_bf = 0;
	}
	// ×óµ¥Ðý
	void RotateL(Node* pParent)
	{
		Node* Lnode = pParent->_left;
		Node* LRnode = Lnode->_right;
		Node* parent = pParent->_parent;
		if (parent)
		{
			if (parent->_right == pParent)
			{
				parent->_right = Lnode;
			}
			else
			{
				parent->_left = Lnode;
			}
		}
		Lnode->_parent = parent;
		pParent->_parent = Lnode;
		Lnode->_right = pParent;
		pParent->_left = LRnode;
		if (LRnode)
			LRnode->_parent = pParent;
		pParent->_bf = Lnode->_bf = 0;
	}
	// ÓÒ×óË«Ðý
	void RotateRL(Node* pParent)
	{
		Node* Lnode = pParent->_left;
		Node* LRnode = Lnode->_right;
		int bf = LRnode->_bf;
		RotateR(pParent->_left);
		RotateL(pParent);
		LRnode->_bf = 0;
		if (bf == 0)
		{
			pParent->_bf = 0;
			Lnode->_bf = 0;
		}
		else if (bf == -1)
		{
			Lnode->_bf = 0;
			pParent->_bf = 1;
		}
		else if (bf == 1)
		{
			Lnode->_bf = -1;
			pParent->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}
	// ×óÓÒË«Ðý
	void RotateLR(Node* pParent)
	{
		Node* Rnode = pParent->_right;
		Node* RLnode = Rnode->_left;
		int bf = RLnode->_bf;
		RotateL(pParent->_right);
		RotateR(pParent);
		RLnode->_bf = 0;
		if (bf == 0)
		{
			Rnode->_bf = 0;
			pParent->_bf = 0;
		}
		else if (bf == 1)
		{
			pParent->_bf = -1;
			Rnode->_bf = 0;
		}
		else if (bf == -1)
		{
			pParent->_bf = 0;
			Rnode->_bf = 1;
		}
		else
		{
			assert(false);
		}
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}
	bool _IsBalance(Node* root)
	{
		if (root == nullptr)
		{
			return true;
		}

		int leftHT = Height(root->_left);
		int rightHT = Height(root->_right);
		int diff = rightHT - leftHT;

		if (diff != root->_bf)
		{
			cout << root->_kv.first << "Æ½ºâÒò×ÓÒì³£" << endl;
			return false;
		}

		return abs(diff) < 2
			&& _IsBalance(root->_left)
			&& _IsBalance(root->_right);
	}

	int Height(Node* root)
	{
		if (root == nullptr)
			return 0;

		return max(Height(root->_left), Height(root->_right)) + 1;
	}

	Node* _root;
};


