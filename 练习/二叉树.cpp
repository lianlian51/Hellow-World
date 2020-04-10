```
#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef int BTDataType;

typedef struct BTNode{
	struct BTNode* left;
	struct BTNode* right;
	BTDataType val;
}BTNode;
``

BTNode* BuyNode(BTDataType val)
{
	BTNode* pNewNode = (BTNode*)malloc(sizeof(BTNode));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}

	pNewNode->left = NULL;
	pNewNode->right = NULL;
	pNewNode->val = val;

	return pNewNode;
}


BTNode* CreatBinTree()
{
	BTNode* Node1 = BuyNode(1);
	BTNode* Node2 = BuyNode(2);
	BTNode* Node3 = BuyNode(3);
	BTNode* Node4 = BuyNode(4);
	BTNode* Node5 = BuyNode(5);
	BTNode* Node6 = BuyNode(6);
	

	BTNode* pRoot = Node1;
	Node1->left = Node2;
	Node2->left = Node3;
	Node1->right = Node4;
	Node4->left = Node5;
	Node4->right = Node6;

	return pRoot;
}



//前序遍历
void PreOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		printf("%d ", pRoot->val);
		PreOrder(pRoot->left);
		PreOrder(pRoot->right);
	}
}

//中序遍历
void InOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		InOrder(pRoot->left);
		printf("%d ", pRoot->val);
		InOrder(pRoot->right);
	}
}

//序后遍历
void PostOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		PostOrder(pRoot->left);
		PostOrder(pRoot->right);
		printf("%d ", pRoot->val);
	}
}



//获取节点的个数
int BinTreeSize(BTNode* pRoot)
{
	assert(pRoot);
	if (NULL == pRoot)
		return NULL;

	return 1 + BinTreeSize(pRoot->left) + BinTreeSize(pRoot->right);
}
//获取叶子节点的个数
int GetLeafCount(BTNode* pRoot)
{
	if (NULL == pRoot)
		return NULL;

	if (pRoot->left == NULL && pRoot->right == NULL)
		return 1;

	return GetLeafCount(pRoot->left) + GetLeafCount(pRoot->right);
}
//获取树的高度
int GetHeight(BTNode* pRoot)
{
	if (NULL == pRoot)
		return NULL;

	int LeftHeight = GetHeight(pRoot->left);
	int RightHeight = GetHeight(pRoot->right);

	return LeftHeight > RightHeight ? LeftHeight + 1 : RightHeight + 1;

}
//获取k层节点的个数
int GetkLevelCount(BTNode* pRoot,int k)
{
	if (NULL == pRoot)
		return NULL;

	if (k == 1)
		return 1;

	return GetkLevelCount(pRoot->left, k - 1) + GetkLevelCount(pRoot->right, k - 1);
}


//返回x在二叉树的中的节点
BTNode* Find(BTNode* pRoot, BTDataType val)
{
	BTNode* pNode = NULL;
	assert(pRoot);

	if (pRoot->val == val)
		return pRoot;

	if ((pNode = Find(pRoot->left, val)) || (pNode = Find(pRoot->right, val)))
		return pRoot;

	return NULL;
}
//获取节点的双亲
BTNode* GetParent(BTNode* pRoot,BTNode* pNode)
{
	BTNode* pParent = NULL;

	if (pRoot == NULL || pNode == NULL || pNode == pRoot)
		return NULL;

	if (pRoot->left == pNode || pRoot->right == pNode)
		return pRoot;

	if ((pParent = GetParent(pRoot->left, pNode)) || (pParent = GetParent(pRoot->right, pNode)))
		return pParent;

	return NULL;
}


//二叉树的层序遍历
 void LevelOrder(BTNode* pRoot)
{
	Queue q;
	if (pRoot == NULL)
		return NULL;

	QueueInit(&q);

	QueuePush(&q,pRoot);//入队列参数记清**加粗样式**

	while (!QueueEmpty(&q))//记得取地址
	{
		BTNode* pCur = QueueFront(&q);
		QueuePop(&q);

		printf("%d ", pCur->val);

		if (pCur->left)
			QueuePush(&q,pCur->left);

		if (pCur->right)
			QueuePush(&q,pCur->right);
	}
	printf("\n");
}

