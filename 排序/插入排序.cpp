#pragma once
#include <stdio.h>

//打印数据
void Print(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}


//插入排序函数
void Sort(int* array, int size)
{
	for (int i = 1; i < size; i++)
	{
		//key记录要插入的数据
		int key = array[i];
		//end表示要比较的数据
		int end = i - 1;
		//end不能越界（一般是插入时最小的数据的时候）
		while (end >= 0 && key < array[end])
		{
			//插入数据比比较数据小，则将其往后移动，然后end向前搜索
			array[end + 1] = array[end];
			end--;
		}

		//数赋值
		array[end + 1] = key;
	}
}

//测试函数
void TestSort()
{
	int array[] = { 4, 3, 6, 8, 7, 9, 0, 1, 2 };
	Print(array, sizeof(array) / sizeof(array[0]));

	//对比前后的数据差异
	Sort(array, sizeof(array) / sizeof(array[0]));
	Print(array, sizeof(array) / sizeof(array[0]));
}
