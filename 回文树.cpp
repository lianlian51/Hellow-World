//利用数组求解，将所有的数字均放在一个数组中，然后前后同时
//遍历，如果都相等，则返回true，否则返回false
bool isPalindrome(int x){
    //先排除所有的负数，直接返回false
    if(x < 0)
       return false;


    //定义保存数字的数组，以及之后遍历的变量
    int s[10] = {0};
    int i = 0;
    int j = 0;
    
    
    //保存所有的数组
    while(x)
    {
        s[i] = x%10;
        x/=10;
        i++;
    }
    
    //这里是因为你在保存的时候最后执行代码多加了一次，这里删掉，便于之后计算
    i--;
    
    //数组两边同时开始遍历
    while(j < i)
    {
        if(s[j] == s[i])
        {
            //如果相等，则数组朝中间走
            j++;
            i--;    
        }
        else {
           return false;
        }
 
    }
    return true;
}



//利用temp保存数字x，然后对数字x进行反向存储到res中
bool isPalindrome(int x){

    //定义时为了防止越界，需要用long定义
    long res = 0;
    long temp = x;

    //去掉一些不必要的数字
    if(x < 0||(x % 10 == 0 &&x > 0))
       return false;

    //将数字x反向存储到res中
    while(x != 0)
    {
        res = res*10 + x % 10;
        x/=10;
    }

    //最后返回
    return res==temp?true:false;

}
