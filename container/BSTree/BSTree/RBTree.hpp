#pragma once

#include <iostream>

enum Color{RED, BLACK};


// ����ʵ�ֵĺ�����Ľڵ�ֵ�ǲ����ظ���
template<class T>
struct RBTreeNode
{
	RBTreeNode(const T& data = T(), Color c = RED)
	: m_pLeft(nullptr)
	, m_pRight(nullptr)
	, m_pParent(nullptr)
	, val(data)
	, color(c)
	{}

	RBTreeNode<T>* m_pLeft;
	RBTreeNode<T>* m_pRight;
	RBTreeNode<T>* m_pParent;
	T val;
	Color color;
};

// ������ĵ�����
template<class T>
class IteratorRBTree
{
	typedef RBTreeNode<T> Node;
	typedef IteratorRBTree<T> Self;

public:
	IteratorRBTree(Node* n = nullptr)
		: node(n)
	{}

	// ����ָ�����Ƶ���Ϊ
	T& operator*()
	{
		return node->val;
	}

	T* operator->()
	{
		return &(operator*());
	}

	Self& operator++()
	{
		Increment();
		return *this;
	}

	Self operator++(int)
	{
		Self temp(*this);
		Increment();
		return temp;
	}

	Self& operator--()
	{
		Decrement();
		return *this;
	}

	Self operator--(int)
	{
		Self temp(*this);
		Decrement();
		return temp;
	}

	void Increment()
	{
		if (node->m_pRight)
		{
			node = node->m_pRight;
			while (node->m_pLeft)
				node = node->m_pLeft;
		}
		else
		{
			Node* parent = node->m_pParent;
			while (parent->m_pRight == node)
			{
				node = parent;
				parent = node->m_pParent;
			}
			// ע�⣺���ڵ�û�������������---���������պô��ڸ���λ��
			if (node->m_pRight != parent)
				node = parent;
		}
	}

	void Decrement()
	{
		// node��end() ��λ��
		if (node == node->m_pParent->m_pParent && RED == node->color)
		{
			node = node->m_pRight;
		}
		else if (node->m_pLeft)
		{
			node = node->m_pLeft;
			while (node->m_pRight)
				node = node->m_pRight;
		}
		else
		{
			Node* parent = node->m_pParent;
			while (parent->m_pLeft == node)
			{
				node = parent;
				parent = node->m_pParent;
			}

			node = parent;
		}
	}


	bool operator==(const Self& s)const 
	{
		return node == s.node;
	}

	bool operator!=(const Self& s)const 
	{
		return node != s.node;
	}
private:
	Node* node;
};




template<class T, class KOFD>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef IteratorRBTree<T> iterator;
public:
	RBTree()
		: _size(0)
	{
		head = new Node();
		head->m_pLeft = head;
		head->m_pRight = head;
		head->m_pParent = nullptr;
	}

	~RBTree()
	{
		Destory(GetRoot());
		_size = 0;
		delete head;
		head = nullptr;
	}

	// �������Ĳ���
	iterator begin()
	{
		return iterator(head->m_pLeft);
	}

	iterator end()
	{
		return iterator(head);
	}

	// ������صĲ���
	size_t size()const
	{
		return _size;
	}

	bool empty()const 
	{
		return nullptr == head->m_pParent;
	}


	//pair<iterator, bool> 
	std::pair<iterator, bool> Insert(const T& data)
	{
		// ע�⣺root����head->pParent�ı���
		Node* & root = GetRoot();
		if (root == nullptr)
		{
			root = new Node(data, BLACK);
			root->m_pParent = head;
			head->m_pLeft = root;
			head->m_pRight = root;
			_size = 1;
			//return true;
			return std::make_pair(iterator(root), true);
		}
		// 1.�ҵ������λ��
		Node* cur = root;
		Node* parent = head;
		KOFD key;
		while (cur)
		{
			parent = cur;
			if (key(data) < key(cur->val))
				cur = cur->m_pLeft;
			else if (key(data) > key(cur->val))
				cur = cur->m_pRight;
			else
				//return false;
				return std::make_pair(iterator(cur), false);
		}
		// 2.����ýڵ�
		Node* newNode = new Node(data);
		cur = newNode;
		cur = new Node(data);
		if (key(data) < key(parent->val))
			parent->m_pLeft = cur;
		else if (key(data) > key(parent->val))
			parent->m_pRight = cur;

		// �����Ǹ��¸��ڵ�
		cur->m_pParent = parent;

		// 3.Ĭ�Ͻڵ��Ǻ�ɫ�ģ����parent�ĸ��ڵ�Ҳ�Ǻ�ɫ������Ҫ����
		while (head != parent && RED == parent->color)
		{
			// head != parent ˵��parentһ����������Ч�ڵ�
			Node* grandFather = parent->m_pParent;
			if (grandFather->m_pLeft == parent)
			{
				// ���һ�����ڵ������Ϊ��
				Node* uncle = grandFather->m_pRight;
				if (uncle && uncle->color == RED)
				{
					parent->color = BLACK;
					uncle->color = BLACK;
					grandFather->color = RED;
					cur = grandFather;
					parent = cur->m_pParent;
				}
				else
				{
					// �������cur������parent����������
					if (cur == parent->m_pRight)
					{
						RotateLeft(parent);
						std::swap(cur, parent);
					}
					grandFather->color = RED;
					parent->color = BLACK;
					RotateRight(grandFather);
				}
			}
			else if (grandFather->m_pRight == parent)
			{
				Node* uncle = grandFather->m_pLeft;
				if (uncle && uncle->color == RED)
				{
					parent->color = BLACK;
					uncle->color = BLACK;
					grandFather->color = RED;
					cur = grandFather;
					parent = cur->m_pParent;
				}
				else
				{
					if (cur == parent->m_pLeft)
					{
						RotateRight(parent);
						std::swap(cur, parent);
					}

					grandFather->color = RED;
					parent->color = BLACK;
					RotateLeft(grandFather);
				}
			}
		}

		// �����ڵ����ɫ����Ϊ��ɫ
		root->color = BLACK;
		head->m_pLeft = LeftMost();
		head->m_pRight = RightMost();
		++_size;
		//return true;
		return std::make_pair(iterator(newNode), true);
	}

	void InOrder()
	{
		InOrder(GetRoot());
	}

	void Swap(RBTree<T, KOFD>& t)
	{
		std::swap(head, t.head);
		std::swap(_size, t._size);
	}

	void Clear()
	{
		Destory(GetRoot());
		_size = 0;
	}

	iterator Find(const T& data)
	{
		Node* cur = GetRoot();
		KOFD key;
		while (cur)
		{
			if (key(cur->val) == key(data))
				return iterator(cur);
			else if (key(data) < key(cur->val))
				cur = cur->m_pLeft;
			else
				cur = cur->m_pRight;
		}
		return end();
	}

	bool isRBTree()
	{
		Node* root = GetRoot();
		if (root->color == BLACK)
		{
			std::cout << "Υ�� ���ڵ㲻�Ǻ�ɫ�ģ�����" << std::endl;
			return false;
		}

		// ���·����ɫ�ڵ�ĸ���
		int blackCount = 0;
		Node* cur = root;
		while (cur)
		{
			if (cur->color == BLACK)
				blackCount++;

			cur = cur->m_pLeft;
		}

		int pathBlackCount = 0;
		return _isRBTree(root, pathBlackCount, blackCount);
	}

private:
	bool _isRBTree(Node* root, size_t path, const size_t count)
	{
		if (root == nullptr)
			return true;

		if (root->color == BLACK)
			++path;

		Node* parent = root->m_pParent;
		if (parent != head && RED == parent->color && RED == root->color)
		{
			std::cout << "Υ�� ����һ��ĺ�ɫ�Ľڵ㣡����" << std::endl;
			return false;
		}


		if (root->m_pLeft == nullptr && root->m_pRight == nullptr)
		{
			if (path != count)
			{
				std::cout << "Υ�� ÿ��·���ĺ�ɫ�ڵ������һ��������" << std::endl;
				return false;
			}
		}
		return _isRBTree(root->m_pLeft, path, count) && 
			_isRBTree(root->m_pParent, path, count);
	}


	Node*& GetRoot()
	{
		return head->m_pParent;
	}

	Node* LeftMost()
	{
		Node* root = GetRoot();
		if (root == nullptr)
			return head;
		Node* cur = root;
		while (cur->m_pLeft != nullptr)
		{
			cur = cur->m_pLeft;
		}
		return cur;
	}

	Node* RightMost()
	{
		Node* root = GetRoot();
		if (root == nullptr)
			return head;
		Node* cur = root;
		while (cur->m_pRight != nullptr)
			cur = cur->m_pRight;
		return cur;
	}

	void RotateLeft(Node* parent)
	{
		Node* subR = parent->m_pRight;
		Node* subRL = subR->m_pLeft;

		parent->m_pRight = subRL;
		if (subRL)
			subRL->m_pParent = parent;
		subR->m_pLeft = parent;

		// parent�����Ǹ��ڵ㣬Ҳ����������������Ҫ��¼parent�ĸ��ڵ�
		Node* pParent = parent->m_pParent;
		parent->m_pParent = subR;
		subR->m_pParent = pParent;

		if (pParent == head)
			head->m_pParent = subR;
		else
		{
			if (pParent->m_pLeft == parent)
				pParent->m_pLeft = subR;
			else if (pParent->m_pRight == parent)
				pParent->m_pRight = subR;
		}
	}

	void RotateRight(Node* parent)
	{
		Node* subL = parent->m_pLeft;
		Node* subLR = parent->m_pRight;

		parent->m_pLeft = subLR;
		if (subLR)
			subLR->m_pParent = parent;

		subL->m_pRight = parent;

		Node* pParent = parent->m_pParent;
		parent->m_pParent = subL;
		subL->m_pParent = pParent;

		if (head == pParent)
			head->m_pParent = subL;
		else
		{
			if (pParent->m_pLeft == parent)
				pParent->m_pLeft = subL;
			else if (pParent->m_pRight == parent)
				pParent->m_pRight = subL;
		}
	}

	void InOrder(Node* root)
	{
		if (root)
		{
			InOrder(root->m_pLeft);
			std::cout << root->val << " ";
			InOrder(root->m_pRight);
		}
	}

	void Destory(Node* & pRoot)
	{
		if (pRoot)
		{
			Destory(pRoot->m_pLeft);
			Destory(pRoot->m_pRight);
			delete pRoot;
			pRoot = nullptr;
		}
	}

private:
	Node* head;
	size_t _size;
}; 

struct KOFD
{
	int operator()(int data)
	{
		return data;
	}
};

void TestRBTree()
{
	int array[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	RBTree<int, KOFD> t;
	for (auto& e : array)
		t.Insert(e);

	std::cout << "���������������������" << std::endl;
	auto it = t.begin();
	while (it != t.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

	for (auto & e : t)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
	t.InOrder();
}
