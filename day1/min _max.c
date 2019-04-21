//求数组的最大值和次大值
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int c[7] = { 1,2,3,4,5,6,9 };
	int max = c[0], min = c[0];
	for (int i = 0; i < 7; ++i) {
		if (max < c[i])
			max = c[i];
		if (min > c[i])
			min = c[i];
	}
	printf("max:%d min:%d\n", max, min);

	system("pause");
	return 0;
}
