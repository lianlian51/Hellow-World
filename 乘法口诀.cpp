//打印乘法口诀表

#include <stdio.h>
#include <Windows.h>

#pragma warning (disable:4996)  //vs2013的一个小bug，专门应对scanf


//编写乘法口诀函数
MultiTable(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d*%d=%2d  ", i, j, i*j);
		}
		printf("\n");
	}
}


//主函数，实现并打印乘法口诀
int main()
{
	int n = 0;
	scanf("%d", &n);
	MultiTable(n);
	system("pause");
	return 0;
}
