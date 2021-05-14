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
		// 1.找节点的位置
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
		// 循环退出，需要判断是不是真的找到了data 的位置
		// 如果没有找到，那就直接返回，不能删除
		if (pNode == nullptr)
			return false;

		// 2.如果只有一个子树的情况，
		//   右子树为空，左子树为空 
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
			// 3.两个子树都在的情况
			// 找到pNode右子树的最小的节点的值域赋值给待删除节点
			pParent = pNode;
			BSTNode<T>* delNode = pNode->m_pRight;
			while (delNode->m_pLeft != nullptr)
			{
				pParent = delNode;
				delNode = delNode->m_pLeft;
			}

			// 赋值
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