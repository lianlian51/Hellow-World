bool isPalindrome(char * s){
    int len =strlen(s);

    //若字符串中没有字符，那一定是回文串
    if(len == 0)
        return true;
    int i = 0;
    int j = 0;
    
    //用于接收数字和字符
    char* str = (char*)malloc(sizeof(char)*len);

    //将数字和字符传到str中
    //*s和s[i]都可以遍历字符串
    while(*s)
    {
        if((*s >= 'a' && *s <= 'z') || (*s >= '0' && *s <= '9'))
            str[j++] = *s;
        //注意大小写的转化 ‘A’-'a'
        if(*s >= 'A' && *s <= 'Z')
            str[j++] = *s - ('A' - 'a');
        s++;
    }

    //前后进行比较，不相等直接返回false
    for(i = 0; i < (j/2); i++)
    {
        if(str[i] != str[j - i- 1])
            return false;
    }
    return true;
}
