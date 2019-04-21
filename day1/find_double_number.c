#include <stdio.h>
#include <stdlib.h>

int main()
{
	int c[7] = { 762,78,172,345,58,300,90 };
	int dif = abs(c[0] - c[1]);
	int a = 0, b = 1;
	for (int i = 0; i < 7; ++i) {
		for (int j = i + 1; j < 7; ++j) {
			if (dif > abs(c[i] - c[j])) {
				dif = abs(c[i] - c[j]);
				a = i; b = j;
			}
		}
	}
	printf("a:%d b:%d dif:%d\n", a, b, dif);

	system("pause");
	return 0;
}
