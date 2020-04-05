void SelectSort(int* array, int size)
{
    //size-1：每次都会排好一个数据，所以每次都需要进行-1
    for (int i = 0; i < size - 1; i++)
    {
        //用maxPos标记最大的数据
        int maxPos = 0;
        //size-i：后面数据已经排好序了，直接不用管
        for (int j = i + 1; j < size - i; j++)
        {
            //找最大的数据
            if (array[j] > array[maxPos])
                maxPos = j;

            //如果最大的数据就是最后一个，就没有比较进行比较
            if (maxPos != size - i - 1)
                Swap(&array[maxPos], &array[size - i - 1]);
        }
    }
}
