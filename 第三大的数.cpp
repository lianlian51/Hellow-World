int thirdMax(int* nums, int numsSize){
    int Max = nums[0];
    int Min = nums[0];

    for(int i=0; i < numsSize; i++)
    {
        if(Max < nums[i])
        {
            int temp = Max;
            Max = nums[i];
            nums[i] = temp;
        }

        if(Min > nums[i])
        {
            int temp = Min;
            Min = nums[i];
            nums[i] = temp;
        }
    }

    int Mid = Min;

    for(int i = 0; i < numsSize; i++)
    {
        if(Mid < nums[i] && nums[i] < Max)
        {
            int temp = Mid;
            Mid = nums[i];
            nums[i] = temp;
        }

        if(Min < nums[i] && nums[i] < Mid)
        {
            int temp = Min;
            Min = nums[i];
            nums[i] = temp;
        }
    }

    if(Min == Mid)
       return Max;

    return Min;
}


思路：先找出最大值和最小值
确定一个中间值（mid）
然后根据遍历来缩小min，mid，max三个数
使其相靠近，在返回到三
如果数字只有两个的话，就是mid==min，直接返回最大值
