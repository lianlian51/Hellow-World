//函数的定义

#pragma once 


typedef int HPDataType;

typedef struct Heap{
    HPDataType* array;
    int capacity;
    int size;
}Heap;

//创建堆
void CreatHeap(Heap* hp,HPDataType arr[],int size);

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

//交换两个数字
void Swap(HPDataType* left, HPDataType* right)
{
    int temp = *left;
    *left = *right;
    *right = *left;
}

void CheckCapacity(Heap* hp)
{
    assert(hp);
    if (hp->size >= hp->capacity)
    {
        int newCapacity = hp->capacity * 2;
        HPDataType* newhp = (HPDataType*)malloc(sizeof(HPDataType)*newCapacity);

        if (newhp == NULL)
        {
            assert(0);
        }
        memcpy(newhp, hp->array, sizeof(HPDataType)*hp->size);

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
        if (child + 1 < hp->size && hp->array[child] < hp->array[child + 1])
        {
            child += 1;
        }
        //父母和孩子进行比较,小的话就进行交换
        if (hp->array[child] > hp->array[parent])
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
    assert(hp);
    int parent = (child - 1) >> 1;
    while (parent >= 0)
    {
        if (hp->array[child] < hp->array[parent])
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
void CreatHeap(Heap* hp, HPDataType arr[], int size)
{
    assert(hp);
    hp->array = (HPDataType*)malloc(sizeof(HPDataType)*size);
    //判断是否申请成功
    if (NULL == hp->array)
    {
        assert(0);
        return ;
    }
    hp->capacity = size;
    memcpy(hp->array, arr, sizeof(HPDataType)*size);
    hp->size = size;

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
    CheckCapacity(hp);
    hp->array[hp->size++] = data;
    AdjustDown(hp, hp->size - 1);
}

//堆的删除
void HeapPop(Heap* hp)
{
    assert(hp);
    if (NULL == hp->array)
        return;
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
    CreatHeap(&Hp, array, sizeof(array)/sizeof(int));

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
