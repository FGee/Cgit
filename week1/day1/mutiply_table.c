//99乘法表
#include <stdio.h>
#include <stdlib.h>

int main()
{
	for (int i = 1; i != 10; ++i) {
		for (int j = 1; j != i + 1; ++j) {
			printf(" %3dx%-3d=%3d ", j, i, j*i);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}
