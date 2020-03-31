/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    //要注意全9 的情况是要进位的
    
    int i = digitsSize - 1;
    for(i; i>=0; i--)
    {
        //小于9的的话，就直接加即可，然后返回
        if(digits[i] < 9)
        {
            //很巧妙，例如你输入189,9直接为零，8直接加一，然后直接返回，不会继续循环
            digits[i]++;
            *returnSize = digitsSize;//这个东西是必带的，返回的是数组的长度
            return digits;
        }
        else
        {
            //9的话，就直接赋值为0
            digits[i] = 0;
        }
    }

    //全为9的话，就需要进位，此时需要新开辟一段空间，来保存最后的1
    int* New = (int *)malloc((digitsSize + 1)*sizeof(int));
    New[0] = 1;
    for(int i = 1; i <digitsSize + 1; i++)
       New[i] = 0;
    
    *returnSize = digitsSize + 1;
    return New;
}
