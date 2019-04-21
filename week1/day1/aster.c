#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("    *\n");
	for (int i = 3; i >= 0; --i) {//打印上三角
		for (int j = i; j >= 1; --j) {
			printf(" ");
		}
		printf("*");
		int n = 3 - i;//构造一个等差数列
		int a = 1 + 2 * n;//
		for (int k = 1; k <= a; ++k) {
			printf(" ");
		}
		printf("*\n");
	}
	for (int i = 1; i <= 3; ++i) {//打印下三角，循环体与打印上三角时相同
		for (int j = i; j >= 1; --j) {
			printf(" ");
		}
		printf("*");
		int n = 3 - i;
		int a = 1 + 2 * n;
		for (int k = 1; k <= a; ++k) {
			printf(" ");
		}
		printf("*\n");
	}
	printf("    *\n");



	system("pause");
	return 0;
}
