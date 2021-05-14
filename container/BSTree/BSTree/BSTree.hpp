#pragma once

#include <iostream>

template<class T>
struct BSTNode
{
	BSTNode<T>(const T& data = T())
	: m_pRight(nullptr)
	, m_pLeft(nullptr)
	, val(data)
	{}

	BSTNode<T>* m_pLeft;
	BSTNode<T>* m_pRight;
	T val;
};

template<class T>
class BSTree
{
public:
	BSTree() : root(nullptr)
	{}

	~BSTree()
	{
		Destory(root);
	}

	void InOrder()
	{
		InOrder(root);
	}

	bool Insert(const T& data)
	{
		if (root == nullptr)
		{
			root = new BSTNode<T>(data);
			return true;
		}
		BSTNode<T>* pNode = root;
		BSTNode<T>* pParent = nullptr;
		while (pNode)
		{
			pParent = pNode;
			if (data > pNode->val)
			{
				pNode = pNode->m_pRight;
			}
			else if (data < pNode->val)
			{
				pNode = pNode->m_pLeft;
			}
			else
				return false;
		}

		pNode = new BSTNode<T>(data);

		if (pParent->val > pNode->val)
		{
			pParent->m_pLeft = pNode;
		}
		else if (pParent->val < pNode->val)
		{
			pParent->m_pRight = pNode;
		}
		return true;
	}

	bool Find(const T& data)
	{
		BSTNode<T>* pNode = root;
		while (pNode)
		{
			if (pNode->val == data)
				return true;
			else if (pNode->val < data)
				pNode = pNode->m_pRight;
			else if (pNode->val > data)
				pNode = pNode->m_pLeft;
		}
		return false;
	}


	bool Erase(const T& data)
	{
		// 1.�ҽڵ��λ��
		BSTNode<T>* pNode = root;
		BSTNode<T>* pParent = nullptr;
		while (pNode)
		{
			if (pNode->val == data)
				break;
			else if (pNode->val < data)
			{
				pParent = pNode;
				pNode = pNode->m_pRight;
			}
			else if (pNode->val > data)
			{
				pParent = pNode;
				pNode = pNode->m_pLeft;
			}
		}
		// ѭ���˳�����Ҫ�ж��ǲ�������ҵ���data ��λ��
		// ���û���ҵ����Ǿ�ֱ�ӷ��أ�����ɾ��
		if (pNode == nullptr)
			return false;

		// 2.���ֻ��һ�������������
		//   ������Ϊ�գ�������Ϊ�� 
		if (pNode->m_pRight == nullptr)
		{
			if (pParent->m_pLeft == pNode)
				pParent->m_pLeft = pNode->m_pLeft;
			else if (pParent->m_pRight == pNode)
				pParent->m_pRight = pNode->m_pLeft;
			delete pNode;
		}
		else if (pNode->m_pLeft == nullptr)
		{
			if (pParent->m_pLeft == pNode)
				pParent->m_pLeft = pNode->m_pRight;
			else if (pParent->m_pRight == pNode)
				pParent->m_pRight = pNode->m_pRight;
			delete pNode;
		}
		else
		{
			// 3.�����������ڵ����
			// �ҵ�pNode����������С�Ľڵ��ֵ��ֵ����ɾ���ڵ�
			pParent = pNode;
			BSTNode<T>* delNode = pNode->m_pRight;
			while (delNode->m_pLeft != nullptr)
			{
				pParent = delNode;
				delNode = delNode->m_pLeft;
			}

			// ��ֵ
			pNode->val = delNode->val;
			pParent->m_pLeft = delNode->m_pRight;
			delete delNode;
		}
		return true;
	}

private:
	void Destory(BSTNode<T>* root)
	{
		if (root != nullptr)
		{
			Destory(root->m_pLeft);
			Destory(root->m_pRight);
			delete root;
			root = nullptr;
		}
	}

	void InOrder(BSTNode<T>* root)
	{
		if (root != nullptr)
		{
			InOrder(root->m_pLeft);
			std::cout << root->val << " ";
			InOrder(root->m_pRight);
		}
	}


private:
	BSTNode<T>* root;
};