## 1.基本操作
1.交换函数
在排序中交换数字，达到排序的目的

void Swap(int *left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}


2.第一种排序
先标记基准值（这里先取最后一个元素为基准值，记录起来），之后定义两个指针，然后前后遍历，找到比基准值大的或者小的的元素的位置，然后进行标记，标记成功后进行交换，最后添加一个循环，此时的begin和end是在一个位置的，你要将begin和right-1（其实就是基准值的位置）位置的元素交换。


int Partion1(int* array, int left, int right)
{
	int begin = left;
	int end = right - 1;
	//设置基准值，取数组最右侧的元素
	int key = array[end];

	while (begin < end)
	{
		//寻找大于基准值的数
		while (begin < end && array[begin] <= key)
			begin++;

		while (begin < end && array[end] >= key)
			end--;

		if (begin < end)
			Swap(&array[begin], &array[end]);
	}

	//这里将基准值和begin（end）交换
	if (begin != right - 1)
		Swap(&array[begin], &array[right - 1]);

	return begin;//此时应该返回begin，key只是值（这里是下标操作）
}


3.第二种操作（俗称“挖坑法”）
这种还是先标记基准值，依旧是begin和end两个指针，然后begin先找比基准值大的元素，将其填写到right-1的位置上，此时的begin的位置就是一个坑，然后end从后开始遍历，找到比基准值小的元素将其填写到begin的位置，end的位置就是一个坑，循环以上操作，结束后就将标记起来的基准值填写到begin（end）的位置。


int Partion2(int* array, int left, int right)
{
	int begin = left;
	int end = right - 1;
	int key = array[end];//基准值


	while (begin < end)
	{
		//从头开始大于key的值的位置
		while (begin < end && array[begin] <= key)
			begin++;

		//将这个值填到基准值的位置
		if (begin < end)
		{
			array[end--] = array[begin];//这里的end一定要往前走一步
		}

		//从尾开始大于key的值得位置
		while (begin < end && array[end] >= key)
			end--;

		//填坑在begin的位置
		if (begin < end)
		{
			array[begin++] = array[end];
		}
	}
	//将基准值填写到begin的位置（此时的begin和end的位置是一样的）
	array[begin] = key;

	return begin;
}


4.第三种排序
先找基准值，然后cur标记left，prev标记cur-1，然后cur遍历，分为两个阶段：第一个是cur没找到比基准值大的，prev和cur一直紧挨着。第二种是找到了，然后cur++，继续遍历，找到比基准值小的，然后才让++prev，此时prev和cur换一下位置，cur继续遍历，循环结束，最后right-1和++prev位置交换，放好基准值的位置。

int Partion3(int* array, int left, int right)
{
	int cur = left;
	int prev = cur - 1;
	int key = array[right - 1];
	while (cur < right)
	{
		if (array[cur] < key && ++prev != cur)
			Swap(&array[cur], &array[prev]);

		cur++;
	}
	if (++prev != (right - 1))
		Swap(&array[prev], &array[right - 1]);

	return prev;
}

5.快排函数
调用上面写的三种任何一种方式都可。

void QuickSort(int* array, int left, int right)
{
	//right-left>1说明中间必有元素
	if (right - left > 1)
	{
		int div = Partion3(array, left, right);
		QuickSort(array, left, div);
		QuickSort(array, div + 1, right);
	}
}


6.打印函数
这个不用多说

void Print(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

```


7.测试代码

```c
#include "QuickSort.h"

int main()
{
	int array[] = { 9, 3, 8, 6, 7, 2, 1, 0, 4, 5 };
	Print(array, sizeof(array) / sizeof(array[0]));
	QuickSort(array, 0, sizeof(array) / sizeof(array[0]));
	Print(array, sizeof(array) / sizeof(array[0]));
	return 0;
}


## 2.优化代码
在进行三种排序的时候我们会发现一个事情，万一最右边的数字是最大或者最小该怎么办呢？
此时我们就要对取基准值进行优化，保证不至于偏差非常大。

//三值取中法
int GetIndexOfMid(int* array, int left, int right)
{
	int mid = left + ((right - left) >> 1);
	if (array[left] > array[right - 1])
	{
		if (array[mid] > array[left])
			return left;
		else if (array[mid] < array[right - 1])
			return right;
		else
			return mid;
	}
	else
	{
		if (array[mid] < array[left])
			return left;
		else if (array[mid] > array[right - 1])
			return right;
		else
			return mid;
	}
}

记住：三值取中法返回的是下标

此时就需要优化一下里面的三种排序里面的代码


	int ret = GetIndexOfMid(array, left, right);
	int key = array[ret];//基准值
	//将那个放到最后面，就可以和之前的代码连接起来
	Swap(&array[ret], &array[right - 1]);

