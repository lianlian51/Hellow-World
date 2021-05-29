#pragma once
#include <iostream>
using namespace std;

template<class T>
struct AVLTreeNode
{
	AVLTreeNode<T>* m_pLeft;
	AVLTreeNode<T>* m_pRight;
	AVLTreeNode<T>* m_pParent;
	T val;
	int _bf;

	AVLTreeNode(const T& data = T())
		: m_pLeft(nullptr)
		, m_pRight(nullptr)
		, m_pParent(nullptr)
		, val(data)
		, _bf(0)
	{}
};


template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;

public:
	AVLTree()
		: pRoot(nullptr)
	{}

	~AVLTree()
	{
		Destory(pRoot);
	}



	bool Insert(const T& data)
	{
		// ����ǲ��ǵ�һ��Ҫ�����
		if (pRoot == nullptr)
		{
			pRoot = new Node(data);
			return true;
		}

		Node* cur = pRoot;
		Node* parent = nullptr;
		// 1. ����Ҫ�����λ��
		while (cur)
		{
			parent = cur;
			if (cur->val > data)
			{
				cur = cur->m_pLeft;
			}
			else if (cur->val < data)
			{
				cur = cur->m_pRight;
			}
			else
				return false;
		}
		// 2. ���ڵ����
		// 3. ����ƽ������
		cur = new Node(data);
		if (parent->val > data)
		{
			parent->m_pLeft = cur;
		}
		else if (parent->val < data)
		{
			parent->m_pRight = cur;
		}
		cur->m_pParent = parent;

		while (parent)
		{
			// ����ƽ������
			if (cur == parent->m_pLeft)
				parent->_bf--;
			else
				parent->_bf++;

			if (parent->_bf == 0)
				break;
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				// ����֮ǰ����Ҷ�ӣ�������Ҫ���ϸ���
				cur = parent;
				parent = cur->m_pParent;
			}
			else 
			{
				if (parent->_bf == 2)
				{
					if (cur->_bf == 1)
						RotateLeft(parent);
					else
						RotateRL(parent);
				}
				else 
				{
					if (cur->_bf == -1)
						RotateRight(parent);
					else
						RotateLR(parent);
				}
				break;
			}
		}
		return true;
	}

	void InOrder()
	{
		InOrder(pRoot);
		std::cout << std::endl;
	}

	bool isBalanceTree()
	{
		return _isBalanceTree(pRoot);
	}


private:
	int AVLHeight(Node* root)
	{
		if (nullptr == root)
			return 0;
		int leftHeight = AVLHeight(root->m_pLeft);
		int rightHeight = AVLHeight(root->m_pRight);
		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

	bool _isBalanceTree(Node* root)
	{
		if (root == nullptr)
			return true;

		int leftHeight = AVLHeight(root->m_pLeft);
		int rightHeight = AVLHeight(root->m_pRight);
		int bf = rightHeight - leftHeight;
		if (abs(bf) > 1 || bf != root->_bf)
		{
			std::cout << root->val << "�ڵ㲻��ƽ��ģ�����" << std::endl;
			return false;
		}
		return _isBalanceTree(root->m_pLeft) && _isBalanceTree(root->m_pRight);
	}


	void Destory(Node*& pRoot)
	{
		if (pRoot)
		{
			Destory(pRoot->m_pLeft);
			Destory(pRoot->m_pRight);
			delete pRoot;
			pRoot = nullptr;
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


	void RotateLeft(Node* parent)
	{
		Node* subR = parent->m_pRight;
		Node* subRL = subR->m_pLeft; // ����Ϊ��

		parent->m_pRight = subRL;
		// �����е�֧�����
		if (subRL)
			subRL->m_pParent = parent;
		subR->m_pLeft = parent;

		// ע����Ҫ���¸��ڵ�
		Node* pParent = parent->m_pParent;
		parent->m_pParent = subR;

		subR->m_pParent = pParent;

		// �޸�֮ǰ��parent�����Ǹ��ڵ�
		// Ҳ����������
		if (pParent == nullptr)
		{
			pRoot = subR;
		}
		else
		{
			if (pParent->m_pLeft == parent)
				pParent->m_pLeft = subR;
			else if (pParent->m_pRight == parent)
				pParent->m_pRight = subR;
		}

		// ����parent��subR��ƽ������
		parent->_bf = subR->_bf = 0;
	}

	void RotateRight(Node* parent)
	{
		Node* subL = parent->m_pLeft;
		Node* subLR = subL->m_pRight;

		parent->m_pLeft = subLR;
		if (subLR)
			subLR->m_pParent = parent;
		subL->m_pRight = parent;


		Node* pParent = parent->m_pParent;
		parent->m_pParent = subL;
		subL->m_pParent = pParent; // ����

		// parent���Ǹ��ڵ���Ǹ��ڵ�
		if (pParent == nullptr)
		{
			pRoot = subL;
		}
		else
		{
			if (pParent->m_pLeft == parent)
			{
				pParent->m_pLeft = subL;
			}
			else
			{
				pParent->m_pRight = subL;
			}
		}
		parent->_bf = subL->_bf = 0;
	}

	void RotateLR(Node* parent)
	{
		Node* subL = parent->m_pLeft;
		Node* subLR = subL->m_pRight;
		int bf = subLR->_bf;
		RotateLeft(parent->m_pLeft);
		RotateRight(parent);

		if (1 == bf)
			subL->_bf = -1;
		else if (-1 == bf)
			parent->_bf = 1;

	}

	void RotateRL(Node* parent)
	{
		Node* subR = parent->m_pRight;
		Node* subRL = subR->m_pLeft;
		int bf = subRL->_bf;
		RotateRight(parent->m_pRight);
		RotateLeft(parent);

		if (bf == 1)
			parent->_bf = -1;
		else if (bf == -1) // ���ﲻ��ʡ
			subR->_bf = 1;
	}

private:
	AVLTreeNode<T>* pRoot;
};


void TestAVLTree()
{
	//int array[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int array[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };

	AVLTree<int> t;
	for (auto e : array)
		t.Insert(e);

	t.InOrder();

	if (t.isBalanceTree())
	{
		cout << "t is a AVL tree!!!" << endl;
	}
	else
	{
		cout << "t is not a AVL tree!!!" << endl;
	}
}