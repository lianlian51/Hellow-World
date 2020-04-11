顺序表
结构体

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* array;
	SLDataType size;
	SLDataType capacity;
}SeqList;

函数

//初始化顺序表
void SeqListInit(SeqList* L);
//摧毁顺序表
void SeqListDestory(SeqList *L);
//尾插
void SeqListPushBack(SeqList* L, SLDataType x);
//尾删
void SeqListPopBack(SeqList* L);
//头插
void SeqListPushFront(SeqList* L, SLDataType x);
//头删
void SeqListPopFront(SeqList* L);
//向第pos位插入数据
void SeqListInsert(SeqList* L, size_t pos, SLDataType x);
//删除第pos位数据
void SeqListRErase(SeqList* L, size_t pos);
//查找数据
int SeqListFind(SeqList* L, SLDataType x);
//顺序表的长度
size_t SeqListSize(SeqList* L);

单链表
结构体

typedef int DataType;

typedef struct SLNode
{
	int data;
	struct SLNode* next;
}SLNode;

函数

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

单链表

双向链表
结构体

struct DListNode{
	struct DListNode* next;
	struct DListNode* prev;
	int val;
};

函数

DListNode* CreatDList();
void DListPushBack(DListNode* pHead, int val);
void DListPopBack(DListNode* pHead);
void DListPushfront(DListNode* pHead, int val);
void DListPopfront(DListNode* pHead);
DListNode* DListFind(DListNode* pHead, int val);
void DListInsert(DListNode* pos, int val);
void DListErase(DListNode* pos);
void DListDestroy(DListNode** pHead);
void DListTest();


双向链表

栈
结构体

typedef int DataType;

typedef struct Stack{
	DataType* array;
	int capacity;
	int size;
}Stack;

函数

//栈的初始化
void StackInit(Stack* ps);
//入栈
void StackPush(Stack* ps, DataType data);
//出栈
void StackPop(Stack* ps);
//获取栈顶元素
DataType StackTop(Stack* ps);
//获取栈中有效元素的个数
int StackSize(Stack* ps);
//检测栈是否为空
int StackEmpty(Stack* ps);
//销毁栈
void StackDestory(Stack* ps);

栈

队列
结构体

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

函数

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

队列

堆
结构体

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

函数

//创建堆
void CreatHeap(Heap* hp, HPDataType arr[], int size, PCOM Compare);
//堆的插入
void HeapPush(Heap* hp, HPDataType data);
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

堆

二叉树
结构体

typedef int BTDataType;

typedef struct BinTreeNode{
	struct BinTreeNode*  pleft;
	struct BinTreeNode*  pright;
	BTDataType val;
}BTNode;

函数

//前序遍历
void PreOrder(BTNode* pRoot);
//中序遍历
void InOrder(BTNode* pRoot);
//后序遍历
void PostOrder(BTNode* pRoot);
//获取二叉树结点的个数
int GetNodeCount(BTNode* pRoot);
//获取二叉树叶子的个数
int GetLeafCount(BTNode* pRoot);
//获取k层结点的个数
int GetkLevelCount(BTNode* pRoot, int k);
//获取树的高度
int GetHeight(BTNode* pRoot);
//返回x在二叉树中对应的节点
BTNode* Find(BTNode* pRoot, BTDataType x);
//获取节点的双亲
BTNode* GetParent(BTNode* pRoot, BTNode* pNode);
