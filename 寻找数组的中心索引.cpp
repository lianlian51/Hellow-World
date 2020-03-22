int pivotIndex(int* nums, int numsSize){

    int sum = 0;

    int num = 0;

 

   //先将所有的数字加和起来

    for(int i = 0;i<numsSize;i++)

    {

        sum+=nums[i];

    }

 

    for(int i = 0;i<numsSize;i++)

    {

       //减去nums[i]，若相等，则表示为索引

        if(sum - nums[i] == num*2)

        {

            return i;

        }

 

 

        num+=nums[i];

    }

    return -1;

}


//如果用最普通的遍历的话，会比较麻烦，需要分类

