int myAtoi(char * str){

	const int INF_MIN = -2147483648;
	const int INF_MAX = 2147483647;

	//遍历str
	int i = 0;
	//解决正负问题
	int sign = 1;
	//最后的数字和
	int res = 0;

	//先去掉' '的情况下 
	while (str[i] != '\0' && str[i] == ' ')
		i++;

    //遇到这个直接返回
	if (str[i] == '\0')
		return 0;

    //处理正负的sign
	if (str[i] == '-')
	{
		sign = -1;
		++i;
	}
	else if (str[i] == '+')
	{
		sign = 1;
		++i;
	}

    //除去字符的情况
	if (str[i] > '9' || str[i] < '0')
		return 0;

	while (str[i] >= '0' && str[i] <= '9')
	{
		if (sign == 1)
		{
            //if (res >= 214748364 && str[i] - '0' >= 7)
				//return INF_MAX;
            //这里我开始想的是res >= 214748364 ，但是这样会导致一些数字的漏掉(大于前者小于后者的数字)
			if (res > 214748364 || res == 214748364 && str[i] - '0' >= 7)
				return INF_MAX;
			else
			{
				res *= 10;
				res += str[i] - '0';
			}
		}
		if (sign == -1)
		{
			if (res > 214748364 || res == 214748364 && str[i] - '0' >= 8)
				return INF_MIN;
			else
			{
				res *= 10;
				res += str[i] - '0';
			}
		}
		++i;
	}

	return sign*res;
}
