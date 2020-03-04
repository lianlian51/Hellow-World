//利用ASCLL（97-122）来求解，magazine这个字符串中，把有的字符都++，也就是ASCLL[i]=1;
//之后在ransomNote字符串所有的字符全部--；就会出现三种情况ASCLL[i]=1,0,-1
//如果是-1的话，那就是magazine没有全部的ransomNote字符，即返回false

bool canConstruct(char * ransomNote, char * magazine){
    //初始化ASCLL数组
    int ASCLL[130] = {0};

    //记录所有magazine的所有字符
    while(*magazine != '\0')
    {
        ASCLL[*magazine]++;
        magazine++;
    }

    //如果为-1，则表示这个字符没有在magazine中
    while(*ransomNote != '\0')
    {
        ASCLL[*ransomNote]--;
        ransomNote++;
    }

    //遍历数组，如果有-1，则返回false，否则返回true
    for(int i = 0;i < 130;i++)
    {
        if(ASCLL[i] < 0)
           return false;
    }
    return true;
}
