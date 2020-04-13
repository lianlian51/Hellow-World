/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	//定义一个result，之后便于返回两个数字 
    int* result = (int*)malloc(sizeof(int)*2);

    for(int i = 0;i < numsSize ;i++)
    {
        for(int j = i+1; j < numsSize; j++)
        {
        	//两值相加==target 
            if(nums[i] + nums[j] == target)
            {
            	//将下标放在result中，之后返回 
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    return result;
}
