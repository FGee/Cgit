#include <stdio.h>
#include <stdlib.h>

int main()//逐个比较可以降低运算量
{
	int a[5] = { 1,6,5,7,3 };
	int b[5] = { 2,9,7,6,4 };
	int c[7] = { 1,2,3,4,5,6,9 };
	int com[5], ct = 0;
	for (int i = 0; i < 5; ++i) {//逐个遍历
		for (int j = 0; j < 5; ++j) {
			if (a[i] == b[j]) {
				com[ct] = a[i];
				++ct;
			}
		}
	}
	int k = ct;//重置公共元素个数
	ct = 0;//
	for (int i = 0; i < k; ++i) {//判定公共元素与第三个数组的公共元素
		for (int j = 0; j < 7; ++j) {
			if (c[j] == com[i]) {
				com[ct] = c[j];
				++ct;
			}
		}
	}
	printf("%d common elem:\n", ct);//输出公有元素
	for (int i = 0; i < ct; ++i)
		printf(" %d ", com[i]);
	printf("\n");

	system("pause");
	return 0;
}
