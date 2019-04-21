#include <stdio.h>
#include <stdlib.h>

int main()
{
	int row = 5;
	for (int r = 2; r <= row; ++r) {
		for (int b = row - r; b >= 1; --b) {//输出三角左边空白
			printf(" ");
		}

		int n = r - 1;//构建等差数列
		int a = 1 + 2 * n;
		for (int tw = 1; tw <= a; ++tw) {//奇数输出星号，偶数输出空白
			if (tw % 2)
				printf("*");
			else
				printf(" ");
		}

		for (int b = row - r; b >= 0; --b) {//同上，输出三角右边空白
			printf(" ");
		}

		for (int b = row - r; b >= 1; --b) {//输出三角左边空白
			printf(" ");
		}

		//int n = r - 1;//构建等差数列
		//int a = 1 + 2 * n;
		for (int tw = 1; tw <= a; ++tw) {//奇数输出星号，偶数输出空白
			if (tw % 2)
				printf("*");
			else
				printf(" ");
		}

		for (int b = row - r; b >= 0; --b) {//同上，输出三角右边空白
			printf(" ");
		}
		printf("\n");
	}
	row = 10;
	for (int r = row; r >= 1; --r) {
		for (int b = row - r; b >= 1; --b) {//输出三角左边空白
			printf(" ");
		}

		int n = r - 1;//构建等差数列
		int a = 1 + 2 * n;
		for (int tw = 1; tw <= a; ++tw) {//奇数输出星号，偶数输出空白
			if (tw % 2)
				printf("*");
			else
				printf(" ");
		}

		for (int b = row - r; b >= 0; --b) {//同上，输出三角右边空白
			printf(" ");
		}
		printf("\n");
	}

	system("pause");
	return 0;
}

