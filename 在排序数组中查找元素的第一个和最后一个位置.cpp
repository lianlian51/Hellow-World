/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    //用于最后返回的
    int* ret = (int*)malloc(sizeof(int)*2);
    //遍历数组
    int i = 0 ;
    int j = numsSize - 1;

    //先赋值为-1
    ret[0] = -1;
    ret[1] = -1;

    //找左边的target
    while(i <= j)
    {
        if(nums[i] == target)
        {
            ret[0] = i;
            break;
        }
        else
            i++;
    }

    //找右边的target
    while(i <= j)
    {
        if(nums[j] == target)
        {
            ret[1] = j;
            break;
        }
        else
            j--;
    }

    *returnSize = 2;
    return ret;  
}
