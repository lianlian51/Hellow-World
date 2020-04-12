//冒泡排序
void BubbleSort(int* array, int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		//j从0或者1开始，决定之后的j<size-i-1或size-i
		for (int j = 1; j < size - i; ++j)
		{
			if (array[j - 1]>array[j])
				Swap(&array[j - 1], &array[j]);
		}

		//for (int j = 0; j < size - i-1; ++j)
		//{
		//	if (array[j]>array[j+1])
		//		Swap(&array[j], &array[j+1]);
		//}
	}
}

//稳定性：稳定
//时间复杂度：O(N^2)
//空间复杂度：O(1)
