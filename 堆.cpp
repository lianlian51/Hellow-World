//函数的声明

#pragma once 


typedef int HPDataType;

int Less(int left, int right);
int Great(int left, int right);


//Compare:是一个函数指针->返回int型，参数为两个整型的一系列函数
//int (*Compare)(int ledt,int right)

//函数指针类型:这样可以选择是大堆还是小堆
typedef int(*PCOM)(int left, int right);

typedef struct Heap{
	HPDataType* array;
	int capacity;
	int size;
	PCOM Compare;
}Heap;

//创建堆
void CreatHeap(Heap* hp,HPDataType arr[],int size,PCOM Compare);

//堆的插入
void HeapPush(Heap* hp,HPDataType data);

//堆的删除
void HeapPop(Heap* hp);

//获取堆顶元素
HPDataType HeapTop(Heap* hp);

//有效元素个数
int HeapSize(Heap* hp);

//判断堆是否为空
int HeapEmpty(Heap* hp);

//堆的销毁
void HeapDestroy(Heap* hp);


///////////////////////////
//测试
void HeapTest();



//函数的实现

#include "Heap.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>


int Less(int left, int right)
{
	return left < right;
}

int Great(int left, int right)
{
	return left > right;
}

//交换两个数字
void Swap(HPDataType* left, HPDataType* right)
{
	*left ^= *right;
	*right ^= *left;
	*left ^= *right;
}

void CheckCapacity(Heap* hp)
{
	assert(hp);
	//判断是否越界
	if (hp->size >= hp->capacity)
	{
		int newCapacity = hp->capacity * 2;
		//一般扩容都是两倍
		HPDataType* newhp = (HPDataType*)malloc(sizeof(HPDataType)*newCapacity);

		//申请空间成功
		if (newhp == NULL)
		{
			assert(0);
			return;
		}

		//将元素拷贝进去
		memcpy(newhp, hp->array, hp->size*sizeof(HPDataType));

		//释放旧空间
		free(hp->array);
		hp->array = newhp;
		hp->capacity = newCapacity;
	}
}

void AdjustDown(Heap* hp, int parent)
{
	int child = parent * 2 + 1;
	while (child<hp->size)
	{
		//用child标记孩子中小的
		//Compare可以进行比较，在上面的Less 和 Great函数替换
		if (child + 1 < hp->size && hp->Compare(hp->array[child+1] , hp->array[child]))
			child += 1;
		//父母和孩子进行比较,小的话就进行交换
		if (hp->Compare(hp->array[child] , hp->array[parent]))
		{
			Swap(&hp->array[child], &hp->array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
}

//插入时：向上调整
void AdjustUp(Heap* hp, int child)
{

	int parent = (child - 1) >> 1;
	while (child)
	{
		if (hp->Compare(hp->array[child] , hp->array[parent]))
		{
			Swap(&hp->array[child], &hp->array[parent]);

			child = parent;
			parent = (child - 1) >> 1;
		}
		else
		{
			return;
		}
	}
}


//创建堆
void CreatHeap(Heap* hp, HPDataType arr[], int size,PCOM Compare)
{
	assert(hp);
	hp->array = (HPDataType*)malloc(sizeof(HPDataType)*size);
	//判断是否申请成功
	if (NULL == hp->array)
	{
		assert(0);
		return ;
	}

	//接收数据
	hp->capacity = size;
	memcpy(hp->array, arr, sizeof(HPDataType)*size);
	hp->size = size;
	hp->Compare = Compare;

	//调整元素的位置
	for (int root = (size - 2) >> 1; root >= 0; root--)
	{
		AdjustDown(hp, root);
	}
}

//堆的插入
void HeapPush(Heap* hp, HPDataType data)
{
	assert(hp);
	//检测空间是否需要扩容
	CheckCapacity(hp);
	hp->array[hp->size++] = data;
	AdjustUp(hp, hp->size - 1);
}

//堆的删除
void HeapPop(Heap* hp)
{
	assert(hp);
	if (HeapEmpty(hp))
		return;

	//交换元素，Size--，最后调整元素
	Swap(&hp->array[0], &hp->array[hp->size - 1]);
	hp->size--;
	AdjustDown(hp, 0);
}

//获取堆顶元素
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	return hp->array[0];
}

//有效元素个数
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}

//判断堆是否为空
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return 0 == hp->size;
}

//堆的销毁
void HeapDestroy(Heap* hp)
{
	assert(hp);
	if (hp->array)
	{
		free(hp->array);
		hp->array = NULL;
		hp->capacity = 0;
		hp->size = 0;
	}
}

///////////////////////////
//测试
void HeapTest()
{
	int array[] = { 5, 3, 8, 4, 2, 7, 6, 1, 0 };
	Heap Hp;
	CreatHeap(&Hp, array, sizeof(array)/sizeof(array[0]),Great);

	printf("size = %d\n", HeapSize(&Hp));
	printf("top = %d\n", HeapTop(&Hp));

	HeapPop(&Hp);
	printf("size = %d\n", HeapSize(&Hp));
	printf("top = %d\n", HeapTop(&Hp));

	HeapPush(&Hp, 9);
	printf("size = %d\n", HeapSize(&Hp));
	printf("top = %d\n", HeapTop(&Hp));

	HeapPush(&Hp, 0);
	printf("size = %d\n", HeapSize(&Hp));
	printf("top = %d\n", HeapTop(&Hp));
}


#include "Heap.h"
#include <stdlib.h>

int main()
{
	HeapTest();
	system("pause");
	return 0;
}
