#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[5] = { 1,6,5,7,3 };
	int b[5] = { 2,9,7,6,4 };
	int com[5], ct = 0;
	for (int i = 0; i < 5; ++i) {//逐个遍历
		for (int j = 0; j < 5; ++j) {
			if (a[i] == b[j]) {
				com[ct] = a[i];
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
