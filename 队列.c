//队列的声明
#pragma once

typedef int QDataType;

typedef struct QNode{
	struct QNode* next;
	QDataType val;
}QNode;

typedef struct Queue{
	struct QNode* head;
	struct QNode* rear;
	QDataType _size;//记录有效元素的个数
}Queue;

//队列初始化
void QueueInit(Queue* q);

//队列入
void QueuePush(Queue* q, QDataType val);

//队列出
void QueuePop(Queue* q);

//有效元素的个数
int QueueSize(Queue* q);

//判断队列是否为空
int QueueEmpty(Queue* q);

//获取对头元素
QDataType QueueFront(Queue* q);

//获取队尾元素
QDataType QueueBack(Queue* q);

//测试代码
void QueueTest();


//队列的实现

#include "Queue.h"
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>

QNode* BuyNode(int val)
{
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (NULL == newNode)
	{
		assert(0);
		return NULL;
	}

	newNode->next = NULL;
	newNode->val = val;

	return newNode;
}



//队列初始化
void QueueInit(Queue* q)
{
	assert(q);
	q->head = BuyNode(0);
	q->rear = q->head;
	q->_size = 0;
}

//队列入
void QueuePush(Queue* q, QDataType val)
{
	assert(q);
	QNode* newNode = BuyNode(val);
	q->rear->next = newNode;
	q->rear = newNode;
	q->_size++;
}

//判断队列是否为空
int QueueEmpty(Queue* q)
{
	assert(q);
	//if (q->head >= q->rear)
	//{
	//	return true;
	//}

	//return false
	return 0 == q->_size;
}

//队列出
void QueuePop(Queue* q)
{
	QNode* pdelNode = NULL;
	if (QueueEmpty(q))
		return;

	pdelNode = q->head->next;
	q->head->next = pdelNode->next;
	free(pdelNode);
	q->_size--;
	
	
	//如果此时队列为空
	if (q->_size == 0)
		q->head = q->rear;
}

//有效元素的个数
int QueueSize(Queue* q)
{
	assert(q);
	return q->_size;
}



//获取队头元素
QDataType QueueFront(Queue* q)
{
	assert(!QueueEmpty(q));
	return q->head->next->val;
}

//获取队尾元素
QDataType QueueBack(Queue* q)
{
	assert(q);
	return q->rear->val;
}


//测试代码
void QueueTest()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePush(&q, 6);
	printf("Size:%d\n", QueueSize(&q));
	printf("Front:%d\n", QueueFront(&q));
	printf("Back:%d\n", QueueBack(&q));

	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	printf("Size:%d\n", QueueSize(&q));
	printf("Front:%d\n", QueueFront(&q));
	printf("Back:%d\n", QueueBack(&q));

}

int main()
{
	QueueTest();
	system("pause");
	return 0;
}
