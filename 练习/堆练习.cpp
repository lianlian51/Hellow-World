#pragma once

int Less(int left, int right);
int Great(int left, int right);


typedef int HPDataType;

typedef int(*PCOM)(int left, int right);

typedef struct Heap{
    HPDataType* array;
    int capacity;
    int size;
    PCOM Compare;
}Heap;


void HeapCreat(Heap* hp,HPDataType arr[],int size,PCOM Compare);

void HeapPush(Heap* hp, HPDataType data);

void HeapPop(Heap* hp);

int HeapSize(Heap* hp);

HPDataType HeapTop(Heap* hp);

int HeapEmpty(Heap* hp);

void Destory(Heap* hp);





//堆的实现

#include "Heap.h"
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>

int Less(int left, int right)
{
    return left < right;
}
int Great(int left, int right)
{
    return left > right;
}

void Swap(HPDataType* left, HPDataType* right)
{
    *left ^= *right;
    *right ^= *left;
    *left ^= *right;
}


void CheckCapacity(Heap* hp)
{
    assert(hp);
    if (hp->size >= hp->capacity)
    {
        int NewCapacity = hp->capacity * 2;
        HPDataType* temp = (HPDataType*)malloc(sizeof(HPDataType)*NewCapacity);

        if (NULL == temp)
        {
            assert(0);
            return ;
        }

        memcpy(temp, hp->array, sizeof(HPDataType)*hp->size);

        free(hp->array);
        hp->array = temp;
        hp->capacity = NewCapacity;
    }
}

void AdjustDown(Heap* hp, int parent)
{
    int child = parent * 2 + 1;
    while (child < hp->size)
    {
        if (child + 1 < hp->size && hp->Compare(hp->array[child + 1], hp->array[child]))
            child += 1;

        if (hp->Compare(hp->array[child], hp->array[parent]))
            Swap(&hp->array[child], &hp->array[parent]);

        parent = child;
        child = parent * 2 + 1;
    }
}

void AdjustUp(Heap* hp, int child)
{
    int parent = (child - 1)>>1;

    while (child)
    {
        if (hp->Compare(hp->array[child], hp->array[parent]))
        {
            Swap(&hp->array[child], &hp->array[parent]);
            child = parent;
            parent = (child - 1) >> 1;//这个是在if里面的 ，否则就会一直变换child和parent的值
        }
        else
        {
            return;//如果没有else，就会一直循环
        }
    }
}


void HeapCreat(Heap* hp, HPDataType arr[], int size, PCOM Compare)
{
    assert(hp);

    hp->array = (HPDataType*)malloc(sizeof(HPDataType)*size);

    if (NULL == hp->array)
    {
        assert(0);
        return;
    }

    hp->capacity = size;
    memcpy(hp->array, arr, sizeof(HPDataType)*size);
    hp->size = size;
    hp->Compare = Compare;

    for (int root = (size - 2) >> 1; root >= 0; root--)
    {
        AdjustDown(hp, root);
    }

}

void HeapPush(Heap* hp, HPDataType data)
{
    assert(hp);
    CheckCapacity(hp);
    hp->array[hp->size++] = data;
    AdjustUp(hp, hp->size - 1);
}

void HeapPop(Heap* hp)
{
    assert(hp);
    if (hp->array == NULL)//此时可以用到HeapEmpty函数来判断是否为空
        return ;

    Swap(&hp->array[0], &hp->array[hp->size - 1]);
    hp->size--;
    AdjustDown(hp, 0);
}

int HeapSize(Heap* hp)
{
    assert(hp);
    return hp->size;
}

HPDataType HeapTop(Heap* hp)
{
    assert(hp && !HeapEmpty(hp));
    return hp->array[0];
}

int HeapEmpty(Heap* hp)
{
    assert(hp);
    return 0 == hp->size;
}

void Destory(Heap* hp)
{
    assert(hp);//就算是销毁也要断言
    if (hp->array)
    {
        //若hp->array存在，就释放然后置空
        free(hp->array);
        hp->array = NULL;
        hp->capacity = 0;
        hp->size = 0;
    }

}
