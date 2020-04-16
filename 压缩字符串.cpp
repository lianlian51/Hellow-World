int compress(char* chars, int charsSize){
	//用来找不是相同字母
	int start = 0;
	//用来标记第一次出现的字母
	int end = 0;
	//表示新的字符串的个数
	int k = 0;
	//标记起始旋转的位置
	int i = 0;
	//表示字母的次数
	int t = 0;
	//反转时用到的
	int j = 0;

	for (; start < charsSize; start++)
	{
        //排除这有一个字符或者第一个和第二个字符不想等的情况
		if (start + 1 == charsSize || chars[start] != chars[start + 1])
		{
            //直接赋值进去
			chars[k++] = chars[end];
			if (start > end)
			{
                //算出重复字符的个数
				t = start - end + 1;
                //标记起始的点
				i = k;
				//将数字填写进去，不过现在是反着的
				while (t > 0)
				{
					chars[k++] = t % 10 + '0';
					t /= 10;
				}
				//反转数字
                //切记for循环中一定要赋初值，不然真的容易错
				for (j = 0; j < (k - i) / 2; j++)
				{
					char temp = chars[j + i];
					chars[j + i] = chars[k - j - 1];
					chars[k - j - 1] = temp;
				}
			}
			end = start + 1;
		}
	}
	return k;
}

