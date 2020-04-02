//希尔排序

//属于插入排序，解决数据量大，而且数组还不接近有序

//gap进行分组，对每一组的数据进行排序，最后gap--到1，就很容易排好，这样花费的时间复杂度较小
void ShellSort(int* array, int size)
{
    int gap = 3;

//gap表示间隔，分组数据之间的间隔
    while (gap >= 1)
    {
        for (int i = gap; i < size; i++)
        {
            //key记录要插入的数据
            int key = array[i];
            //end表示要比较的数据
            int end = i - gap;
            //end不能越界（一般是插入时最小的数据的时候）
            while (end >= 0 && key < array[end])
            {
                //插入数据比比较数据小，则将其往后移动，然后end向前搜索
                array[end + gap] = array[end];
                end-=gap;
            }

            //数赋值
            array[end + gap] = key;
        }
        gap--;
    }
}
