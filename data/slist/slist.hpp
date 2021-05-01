#pragma once 

#include <iostream>
#include <assert.h>

typedef int slint;


struct SLNode
{
  SLNode* next;
  slint val;

  SLNode(slint data = 0)
    : next(nullptr)
      , val(data)
  {}

};

//   尾插/删
void PushBack(SLNode** head, slint data)
{
  assert(head);
  SLNode* Node = new SLNode(data);
  if((*head) == nullptr)
  {
    (*head) = Node; 
    return;
  }
  SLNode* cur = *head;
  while(cur->next)
  {
    cur = cur->next;
  }
  cur->next = Node;
}

void PopBack(SLNode** head)
{
  assert(head);
  if(*head == nullptr)
  {
    std::cout << "链表为空，不能删除！！！" << std::endl;
    return;
  }
  else if((*head)->next == nullptr)
  {
    // 考虑是一个节点的情况
    SLNode* cur = *head;
    (*head) = nullptr;
    delete cur;
    cur = nullptr;
  }
  else 
  {
    SLNode* cur = *head;
    SLNode* prev = nullptr;
    while(cur->next)
    {
      prev = cur;
      cur = cur->next;
    }
    prev->next = nullptr;
    delete cur;
    cur = nullptr;
  }

}

//  头插/删
void PushFront(SLNode** head, slint data)
{
  assert(head);
  SLNode* Node = new SLNode(data);
  if(*head == nullptr)
  {
    *head = Node;
    return;
  }
  else 
  {
    SLNode* cur = (*head)->next;
    (*head) = Node;
    Node->next = cur;
  }
}

void PopFront(SLNode** head)
{
  assert(head);
  if(*head == nullptr)
  {
    std::cout << "链表为空，不能删除！！！" << std::endl;
    return;
  }
  else if((*head)->next == nullptr)
  {
    SLNode* del = (*head)->next;
    *head = nullptr;
    delete del;
    del = nullptr;
  }
  else 
  {
    SLNode* del = (*head)->next;
    SLNode* next = del->next;
    (*head)->next = next;
    delete del;
    del = nullptr;
  }
}


//在任意位置插入节点
void SLInsertAfter(SLNode* pos, slint data)
{
  assert(head);
  if(pos == nullptr)
    return;
  SLNode* Node = new SLNode(data);
  // SLNode* next = pos->next;
  // pos->next = Node;
  // Node->next = next;
  Node->next = pos->next;
  pos->next = Node;
}

//在任意位置删除节点
void SLErase(SLNode**head, SLNode* pos)
{
  assert(head);
  SLNode* cur = *head;
  while(cur->next != pos)
  {
    cur = cur->next;
  }
  cur->next = pos->next;
  delete pos;
  pos = nullptr;
}

//链表的长度
int SLSize(SLNode* head)
{
  assert(head);
  SLNode* cur = (head)->next;
  int count = 0;
  while(cur)
  {
    ++count;
    cur = cur->next;
  }
  return count;
}

//寻找值为data的位置
SLNode* SLFind(SLNode* head, int data)
{
  assert(head);
  SLNode* cur = (head)->next;
  while(cur)
  {
    if(cur->val == data)
    {
      return cur;
    }
    cur = cur->next;
  }
  return nullptr;
}

//打印
void Print(SLNode* head)
{
  assert(head);
  SLNode* cur = head->next;
  while(cur)
  {
    std::cout << cur->val << " "; 
  }
  std::cout << std::endl;
}

//销毁链表
void Destroy(SLNode** head)
{
  SLNode* cur = (*head)->next;
  while(cur)
  {
    *head = cur->next;
    delete cur;
    cur = *head;
  }
}
