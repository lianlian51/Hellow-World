#pragma once 
#include <stdio.h>
// #include <vld.h>
#include <malloc.h>
#include <assert.h>

#define seqint int
#define SEQLIST_SIZE 8;


struct SeqList
{
  seqint *arr;
  size_t capacity;
  size_t size;
};

// 声明所有的函数
void SeqListInit(SeqList *plist);
void SeqlistDestory(SeqList *plist);
void SeqListPush_back(SeqList *plist, seqint x);
void SeqListPush_front(SeqList *plist, seqint x);
void show_list(SeqList *plist);

size_t SeqListLength(SeqList *plist);
void SeqListPop_back(SeqList *plist);
void SeqListClear(SeqList *plist);
bool SeqListInsertByPos(SeqList*plist, int pos, seqint x);
void SeqListSort(SeqList* plist);
size_t SeqListCapacity(SeqList *plist);

void SeqListPopFront(SeqList* plist);
bool SeqListInsertByVal(SeqList* plist, seqint x);
bool SeqListEraseByPos(SeqList* plist, int pos);
bool SeqListEraseVal(SeqList* plist, seqint x);
bool SeqListFind(SeqList* plist, seqint x);

////////////////////////////////////////////////////////// 
// 判断顺序表是否满
bool isFull(SeqList* plist)
{
  assert(plist != NULL);
  return plist->capacity == plist->size;
}

// 判断顺序表是否为空
bool isZero(SeqList* plist)
{
  assert(plist != NULL);
  return plist->size == 0;
}

// 顺序表扩容
SeqList* check(SeqList* plist)
{
  if(plist->size < plist->capacity)
    return plist;
  int size = plist->size;
  SeqList* temp = (SeqList*)malloc(sizeof(SeqList)* size * 2);
  for(int i = 0; i < size; ++i)
  {
    temp->arr[i] = plist->arr[i];
  }

  temp->capacity = size * 2;
  SeqlistDestory(plist);
  return temp;
}


///////////////////////////////////////////////////////////

// 初始化顺序表
void SeqListInit(SeqList *plist)
{
  plist->capacity = SEQLIST_SIZE;
  plist->size = 0;
  plist->arr =(seqint*)malloc(sizeof(seqint) * plist->capacity);
}

// 销毁顺序表
void SeqlistDestory(SeqList *plist)
{
  assert(plist != NULL);
  plist->capacity = 0;
  plist->size = 0;
  free(plist);
  plist = NULL;
}

// 顺序表尾插
void SeqListPush_back(SeqList *plist, seqint x)
{
  assert(plist != NULL);

  if(isFull(plist)){
    printf("顺序表已满，不能插入！！！\n");
  }
  plist->arr[plist->size] = x;
  plist->size++;
}

// 顺序表尾删
void SeqListPop_back(SeqList *plist)
{
  assert(plist);
  if(isZero(plist))
  {
    printf("顺序表为空，不能删除！！！\n");
    return;
  }
  plist->size--;
}

// 顺序表头插
void SeqListPush_front(SeqList *plist, seqint x)
{
  assert(plist != NULL);
  if(isFull(plist))
  {
    printf("顺序表已满，不能插入！！！\n");
    return;
  }
  for(int i = (int)plist->size - 1; i >= 0; --i)
  {
    plist->arr[i] = plist->arr[i+1];
  }
  plist->size++;
  plist->arr[0] = x;
}

// 顺序表头删
void SeqListPopFront(SeqList* plist)
{
  assert(plist);
  if(isZero(plist))
  {
    printf("顺序表为空，不能删除！！！\n");
    return;
  }
  for(int i = 1; i < (int)plist->size; ++i)
  {
    plist->arr[i] = plist->arr[i+1];
  }
  plist->size--;
}

// 打印顺序表
void show_list(SeqList *plist)
{
  assert(plist);
  for(int i = 0; i < (int)plist->size; ++i)
  {
    printf("%d ", plist->arr[i]);
  }
  printf("\n");
}

// 返回顺序表的有效元素的个数
size_t SeqListLength(SeqList *plist)
{
  assert(plist);
  return plist->size;
}

// 顺序表的容量
size_t SeqListCapacity(SeqList *plist)
{
  assert(plist);
  return plist->capacity;
}

// 查找数字
bool SeqListFind(SeqList* plist, seqint x)
{
  assert(plist);
  for(int i = 0; i < (int)plist->size; ++i)
  {
    if(x == plist->arr[i])
      return true;
  }
  return false;
}

// 顺序表排序
void SeqListSort(SeqList* plist)
{
  assert(plist);
  int endindex = 0;
  // 冒泡排序
  int sortborder = (int)plist->size - 1;
  for(int i = 0; i < (int)plist->size; ++i)
  {
    for(int j = 0; j < sortborder; ++j)
    {
      if(plist->arr[j] > plist->arr[j+1])
      {
        int temp = plist->arr[j];
        plist->arr[j] = plist->arr[j+1];
        plist->arr[j+1] = temp;
        endindex = j;
      }
    }
    sortborder = endindex;
  }
}

// 清空数组
void SeqListClear(SeqList *plist)
{
  assert(plist);
  plist->size = 0;
}

//////////////////////////////////////////////////////////////

// 任意位置插入数字
bool SeqListInsertByPos(SeqList*plist, int pos, seqint x)
{
  assert(plist);
  if(isFull(plist))
  {
    printf("顺序表已满，无法插入！！！\n");
    return false;
  }
  for(int i = (int)plist->size - 1; i >= pos; --i)
  {
    plist->arr[i] = plist->arr[i+1];
  }
  plist->size++;
  plist->arr[pos] = x;
  return true;
}

// 插入值为x的数字（在排序之后）
bool SeqListInsertByVal(SeqList* plist, seqint x)
{
  assert(plist);
  if(isFull(plist))
  {
    printf("顺序表已满，无法插入！！！\n");
    return false;
  }
  int i = -1;
  for(int i = 0; i < (int)plist->size; ++i)
  {
    if(plist->arr[i] > x)
      break;
  }
  return SeqListInsertByPos(plist, i, x); 
}

// 删除任意位置的数字
bool SeqListEraseByPos(SeqList* plist, int pos)
{
  assert(plist);
  if(isZero(plist))
  {
    printf("顺序表为空，不能删除！！！\n");
    return false;
  }
  for(int i = pos; i < (int)plist->size; ++i)
  {
    plist->arr[i] = plist->arr[i+1];
  }

  plist->size--;
  return true;
}

// 删除任意值
bool SeqListEraseVal(SeqList* plist, seqint x)
{
  assert(plist);
  if(isZero(plist))
  {
    printf("顺序表为空，不能删除！！！\n");
    return false;
  }
  int i;
  for(i = 0; i < (int)plist->size; ++i)
  {
    if(plist->arr[i] == x)
      break;
  }

  if(SeqListEraseByPos(plist, i))
    return true;
  return false;
}
