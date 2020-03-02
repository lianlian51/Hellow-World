//这是一个右旋的代码
void Change(int* nums,int left,int right)
{
    while(left < right)
    {
        //数字交换
        int temp = nums[right];
        nums[right] = nums[left];
        nums[left] = temp;
        
        //移动left，right
        left++;
        right--;
    }
}



void rotate(int* nums, int numsSize, int k){
    //如果k大于numsSize，可以用这步
    k %= numsSize;
    //先整体旋转
    Change(nums,0,numsSize-1);
    //部分旋转
    Change(nums,k,numsSize-1);
    Change(nums,0,k-1);   

}

//如果是左旋的话，先部分旋转，之后整体旋转
