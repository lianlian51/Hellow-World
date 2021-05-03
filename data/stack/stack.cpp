#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef int stackint;


struct Stack 
{
  stackint * arr;
  int capacity;
  int size;
};

bool StackEmpty(Stack* ps);
void check(Stack* ps);


//栈的初始化
void StackInit(Stack* ps)
{
  assert(ps);
  ps->arr = (stackint*)malloc(sizeof(stackint)*10);
  ps->capacity = 10;
  ps->size = 0;
}

//入栈
void StackPush(Stack* ps, stackint data)
{
  assert(ps);
  ps->arr[ps->size++] = data;
}

//出栈
void StackPop(Stack* ps)
{
  assert(ps);
  if(StackEmpty(ps))
  {
    printf("栈空，不能出栈！！！\n");
    return;
  }
  ps->size--;
}

//获取栈顶元素
stackint StackTop(Stack* ps)
{
  return ps->arr[ps->size - 1];
}

//获取栈中有效元素的个数
int StackSize(Stack* ps)
{
  return ps->size;
}

//检测栈是否为空
bool StackEmpty(Stack* ps)
{
  return 0 == ps->size;
}

//销毁栈
void StackDestory(Stack* ps)
{
  assert(ps);
  if(ps)
  {
    free(ps->arr);
    ps->capacity = ps->size = 0;
  }
}


void check(Stack* ps)
{
  assert(ps);
  if(ps->size >= ps->capacity)
  {
    int newcapacity = ps->size * 2;
    stackint* temp = (stackint*)malloc(sizeof(stackint)* ps->size*2);
    if(temp)
    {
      for(int i = 0; i < ps->size; ++i)
        temp[i] = ps->arr[i];

      free(ps->arr);
      ps->arr = temp;
      ps->capacity = newcapacity;
    } 
  }
}
