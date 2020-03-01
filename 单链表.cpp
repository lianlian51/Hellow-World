#pragma once

typedef int DataType;

typedef struct SLNode
{
	int data;
	struct SLNode* next;
}SLNode;


//   尾插/删
void PushBack(SLNode** head, DataType data);
void PopBack(SLNode** head);


//   头插/删
void PushFront(SLNode** head, DataType data);
void PopFront(SLNode** head);

//打印
void Print(SLNode* head);

//在任意位置插入节点
void SLInsertAfter(SLNode* pos, DataType data);
//在任意位置删除节点
void SLErase(SLNode**head, SLNode* pos);
//链表的长度
int SLSize(SLNode* head);
//寻找值为data的位置
SLNode* SLFind(SLNode* head, int data);
//销毁链表
void Destroy(SLNode** head);



/////////////////////////////////////////

#include "SList.h"
#include <stdio.h>
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>


SLNode* BuyNode(DataType data)
{
	SLNode* newNode = (SLNode*)malloc(sizeof(SLNode));
	if (newNode == NULL)
	{
		printf("申请点失败!");
		assert(newNode);
	}
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}


//链表都是先连接，后删除

//   尾插/删
//head中的的内容就是&L
//如果改变实参L的指向，*head就是L本身
void PushBack(SLNode** head, DataType data)
{
	//链表是否存在
	assert(head);
	SLNode* newNode = BuyNode(data);
	//链表是否是空链表
	if (*head == NULL)
		//head链表第一个节点的插入方式
		*head = newNode;
	else
	{
		//多个节点的插入方式
		SLNode* tail = *head;
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}


void PopBack(SLNode** head)
{
	assert(head);
	//空链表
	if (head == NULL)
		return head;
	//只有一个节点
	else if ((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		//有多个节点
		SLNode* cur = *head;
		SLNode* prev = NULL;
		while (cur->next)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = cur->next;
		free(cur);
	}
}


//   头插/删
void PushFront(SLNode** head, DataType data)
{
	assert(head);
	SLNode* newNode = BuyNode(data);
	newNode->next = *head;
	*head = newNode;
}


void PopFront(SLNode** head)
{
	assert(head);
	if (*head == NULL)
		//没有节点
		return;
	else if ((*head)->next == NULL)
	{
		//只有一个节点
		free(*head);
		*head = NULL;
	}
	else
	{
		//有多个节点
		SLNode* delNode = *head;
		*head = delNode->next;
		free(delNode);
	}
}

//在任意位置插入节点
void SLInsertAfter(SLNode* pos, DataType data)
{
	SLNode* newNode = BuyNode(data);
	//参数检测
	if (NULL == pos)
		return;
//vs中先定义后使用（在函数刚开始时定义）
	newNode->next = pos->next;
	pos->next = newNode;
}

//在任意位置删除节点
void SLErase(SLNode**head, SLNode* pos)
{
	SLNode* delNode = *head;
	//pos位置不存在或者pos的是最后一个节点
	if (NULL == pos || pos->next == NULL)
		return;
	delNode = pos->next;
	pos->next = delNode->next;
	free(delNode);
}

//链表的长度
int SLSize(SLNode* head)
{
	int count = 0;
	SLNode* cur = head;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

//寻找值为data的位置
SLNode* SLFind(SLNode* head, int data)
{
	SLNode* cur = head;
	while (cur)
	{
		if (cur->data == data)
			return cur;
		cur->next;
	}
	return NULL;
}

//销毁链表
void Destroy(SLNode** head)
{
	SLNode* cur = *head;
	while (cur)
	{
		*head = cur->next;
		free(cur);
		cur = *head;
	}
}


//打印
void Print(SLNode* head)
{
	SLNode* cur = head;
	while (cur)
	{
		printf("%d-->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}


/////////////////////////////////////

void test1()
{
	//测试尾插函数PushBack
	SLNode* L = NULL;
	PushBack(&L, 1);
	PushBack(&L, 2);
	PushBack(&L, 3);
	PushBack(&L, 4);
	PushBack(&L, 5);
	//打印
	Print(L);

	
}

void test()
{
	test1();
}


int main()
{
	test();
	system("pause");
	return 0;
}
