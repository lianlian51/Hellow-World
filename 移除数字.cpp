int removeElement(int* nums, int numsSize, int val){
    //利用res开始遍历，最后返回
    int res = 0;

    for(int i = 0;i < numsSize;++i)
    {
        if(nums[i] == val)
            {}
        else 
        {
            //找到不同的元素，然后赋值过去
            nums[res] = nums[i];
            ++res;
        }
    }

    return res;
}

////////////////////////////////////////////////////////

int RemoveElement(int* nums, int numsSize, int val)
{
  //dst遍历数组，找到不是val的数据和src交换，之后src++
	int src = 0;
	int dst = 0;

	while (src < numsSize)
	{
		if (nums[src] != val)
		{
      //交换数据，src和dst都++
			nums[dst++] = nums[src++];
		}
		else {
      //相等就是不用换的数据，src++寻找不相等的数据
			src++;
		}
	}
	return dst;
}
