//找出数组中数量多于一半的元素
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int c[7] = { 1,1,3,3,5,3,9 };
	int n = 7 / 2;
	int ct = 0;//记录元素出现次数
	int m = 0;//标记已经一次验证的数组元素
	while (ct < n) {//当不满足题目条件时一直循环
		int aim = c[m];
		if (ct < n) {
			ct = 0;
			for (int i = 0; i < 7; ++i)
			{
				if (c[m] == c[i])
					++ct;
			}
		}
		++m;
	}
	printf("%d\n", c[m - 1]);

	system("pause");
	return 0;
}
