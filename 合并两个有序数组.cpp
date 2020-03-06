void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    
    //定义，让数组从后往前遍历
    int i = m-1;
    int j = n-1;
    int len = m+n-1;

    //如果nums2为空的话，直接返回nums1
    if(n == 0)
        return ;
    //如果nums1为空的话，需要将nums2中的所有元素搬移到nums1中
    if(m == 0)
    {
        nums1[len--] = nums2[j--];
    }

    //开始循环
    while(i>=0 && j>=0)
    {
        if(nums1[i] < nums2[j])
        {
            //这里最好进行交换，因为交换的基本都是0，
            //如果是赋值的话，很可能会造成nums2中的元素永远小于nums中的，无法进行赋值
            nums1[len] ^= nums2[j];
            nums2[j] ^= nums1[len];
            nums1[len] ^= nums2[j];

            //继续循环
            len--;
            j--;
        }
        else
        {
            //理由同上
            nums1[len] ^= nums1[i];
            nums1[i] ^= nums1[len];
            nums1[len] ^= nums1[i];

            len--;
            i--;
        }

    }

    //处理nums1中的元素交换完成，nums2中的元素还有交换未完成的情况
    while(j >= 0)
    {
        nums1[len] ^= nums2[j];
        nums2[j] ^= nums1[len];
        nums1[len] ^= nums2[j];

        len--;
        j--;
    }
}
