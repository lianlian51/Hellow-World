//二叉树的基本操作，这次写到了一起，直接写到了.h 文件里，
//问题不大，也可以运行的，只不过你要加一个运行的.c 文件

#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <stdbool.h>

typedef int BTDataType;

typedef struct BinTreeNode{
	struct BinTreeNode*  pleft;
	struct BinTreeNode*  pright;
	BTDataType val;
}BTNode;



BTNode* BuyBinary(BTDataType val)
{
	//创建一个二叉树的节点
	BTNode* pNewNode = (BTNode*)malloc(sizeof(BTNode));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	//赋值
	pNewNode->pleft = NULL;
	pNewNode->pright = NULL;
	pNewNode->val = val;

	return pNewNode;
}

BTNode* CreatBinary()
{
	//此处的二叉树的建立非正式，之后我会补充一下
	BTNode* Node1 = BuyBinary(1);
	BTNode* Node2 = BuyBinary(2);
	BTNode* Node3 = BuyBinary(3);
	BTNode* Node4 = BuyBinary(4);
	BTNode* Node5 = BuyBinary(5);
	BTNode* Node6 = BuyBinary(6);

	BTNode* pRoot = Node1;
	Node1->pleft = Node2;
	Node2->pleft = Node3;
	Node1->pright = Node4;
	Node4->pleft = Node5;
	Node4->pright = Node6;

	return pRoot;

}

//前序遍历
void PreOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		//根左右
		printf("%d ", pRoot->val);
		PreOrder(pRoot->pleft);
		PreOrder(pRoot->pright);
	}
}


//中序遍历
void InOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		//左根右
		InOrder(pRoot->pleft);
		printf("%d ", pRoot->val);
		InOrder(pRoot->pright);
	}
}


//后序遍历
void PostOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		//左右根
		PostOrder(pRoot->pleft);
		PostOrder(pRoot->pright);
		printf("%d ", pRoot->val);
	}
}

//获取二叉树结点的个数
int GetNodeCount(BTNode* pRoot)
{
	if (NULL == pRoot)
		return NULL;

	//直接遍历得结果
	return 1 + GetNodeCount(pRoot->pleft) + GetNodeCount(pRoot->pright);
}


//这个是利用count+前序遍历得出
//int count = 0;
//int GetNodeCount(BTNode* pRoot)
//{
//	if (pRoot)
//	{
//		count++;
//		PreOrder(pRoot->pleft);
//		PreOrder(pRoot->pright);
//	}
//}


//获取二叉树叶子的个数
int GetLeafCount(BTNode* pRoot)
{
	if (NULL == pRoot)
		return NULL;

	//限定叶子节点返回1，否则无论什么，返回的都是0
	if (pRoot->pleft == NULL && pRoot->pright == NULL)
		return 1;

	return GetLeafCount(pRoot->pleft) + GetLeafCount(pRoot->pright);
}

//获取k层结点的个数
int GetkLevelCount(BTNode* pRoot, int k)
{
	if (pRoot == NULL || k <= 0)
		return 0;

	//根节点
	if (k == 1)
		return 1;

	return GetkLevelCount(pRoot->pleft , k - 1) + GetkLevelCount(pRoot->pright , k - 1);
}

//获取树的高度
int GetHeight(BTNode* pRoot)
{
	if (NULL == pRoot)
		return NULL;

	//算出左右子树的高度
	int LeftHeight = GetHeight(pRoot->pleft);
	int RightHeight = GetHeight(pRoot->pright);

	return LeftHeight > RightHeight ? LeftHeight + 1 : RightHeight + 1;
}

//返回x在二叉树中对应的节点
BTNode* Find(BTNode* pRoot, BTDataType x)
{
	BTNode* pNode = NULL;
	if (pRoot == NULL)
		return NULL;

	if (pRoot->val == x)
		return pRoot;

	//不能用 || 的方式返回（返回为bool型）
	if ((pNode = Find(pRoot->pleft, x)) || (pNode = Find(pRoot->pright, x)))
		return pNode;

	return NULL;
}

//获取节点的双亲
BTNode* GetParent(BTNode* pRoot, BTNode* pNode)
{
	BTNode* pParent = NULL;
	if (NULL == pRoot || NULL == pNode || pNode == pRoot)
		return NULL;

	if (pRoot->pleft == pNode || pRoot->pright == pNode)
		return pRoot;

	if ((pParent = GetParent(pRoot->pleft, pNode)) || (pParent = GetParent(pRoot->pright, pNode)))
		return pParent;

	return NULL;
	//不能这样直接返回，因为返回的是一个bool型的真假
	//return GetParent(pRoot->pleft, pNode) || GetParent(pRoot->pright, pNode);
}



////////////////////////
//测试结果
void TestTree()
{
	BTNode* pRoot =  CreatBinary();
	printf("前序遍历的结果：");
	PreOrder(pRoot);
	printf("\n");

	printf("中序遍历的结果：");
	InOrder(pRoot);
	printf("\n");

	printf("后序遍历的结果：");
	PostOrder(pRoot);
	printf("\n");


	printf("二叉树中节点的个数：%d\n", GetNodeCount(pRoot));

	printf("二叉树中叶子的个数：%d\n", GetLeafCount(pRoot));

	printf("二叉树中树的高度：%d\n", GetHeight(pRoot));

	printf("二叉树%d层叶子节点的个数：%d\n",3, GetkLevelCount(pRoot,3));

	if (Find(pRoot, 3))
	{
		printf("3 is found!\n");
	}
	else
	{
		printf("3 is not found!\n");
	}

	BTNode* pParent = GetParent(pRoot, Find(pRoot,3));
	if (pParent)
	{
		printf("3'parent is %d!!\n", pParent->val);
	}
	else
	{
		printf("3'parent is NULL!!\n");
	}
}

//二叉树的基本操作，基本上都是按照递归进行的，看到这类题一般往哪里靠近就好
