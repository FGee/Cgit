#include <stdio.h>
#include <stdlib.h>

int main()
{
	int row = 5;
	for (int r = 2; r <= row; ++r) {
		for (int b = row - r; b >= 1; --b) {//���������߿հ�
			printf(" ");
		}

		int n = r - 1;//�����Ȳ�����
		int a = 1 + 2 * n;
		for (int tw = 1; tw <= a; ++tw) {//��������Ǻţ�ż������հ�
			if (tw % 2)
				printf("*");
			else
				printf(" ");
		}

		for (int b = row - r; b >= 0; --b) {//ͬ�ϣ���������ұ߿հ�
			printf(" ");
		}

		for (int b = row - r; b >= 1; --b) {//���������߿հ�
			printf(" ");
		}

		//int n = r - 1;//�����Ȳ�����
		//int a = 1 + 2 * n;
		for (int tw = 1; tw <= a; ++tw) {//��������Ǻţ�ż������հ�
			if (tw % 2)
				printf("*");
			else
				printf(" ");
		}

		for (int b = row - r; b >= 0; --b) {//ͬ�ϣ���������ұ߿հ�
			printf(" ");
		}
		printf("\n");
	}
	row = 10;
	for (int r = row; r >= 1; --r) {
		for (int b = row - r; b >= 1; --b) {//���������߿հ�
			printf(" ");
		}

		int n = r - 1;//�����Ȳ�����
		int a = 1 + 2 * n;
		for (int tw = 1; tw <= a; ++tw) {//��������Ǻţ�ż������հ�
			if (tw % 2)
				printf("*");
			else
				printf(" ");
		}

		for (int b = row - r; b >= 0; --b) {//ͬ�ϣ���������ұ߿հ�
			printf(" ");
		}
		printf("\n");
	}

	system("pause");
	return 0;
}

