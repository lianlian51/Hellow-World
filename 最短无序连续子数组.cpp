int cmp(const void* a,const void* b)
{
    return *(int*)a - *(int*)b;
}

int findUnsortedSubarray(int* nums, int numsSize){

    //用于接收数组，然后进行排序
    int* temp = (int*)malloc(sizeof(int)*numsSize);

    //将数据拷贝进去
    memcpy(temp, nums, sizeof(int)*numsSize);

    //排序
    qsort(temp, numsSize, sizeof(int), cmp);

    int start = 0;
    int end = 0;
    int i = 0;

    //从头开始寻找第一个不想等的数字的下标
    for(i = 0; i < numsSize && temp[i] == nums[i]; i++){
        ;
    }

    start = i;
    
    //从尾开始找第一个不想等的的下标
    for(i = numsSize - 1; i >= 0 && temp[i] == nums[i]; i--){
        ;
    }

    end = i;

    //如果大于的话就存在，反之不存在
    if(end > start)
    {
        return end - start + 1;
    }
    return 0;
}
