#include "sort.h"

int main()
{
	time_t start, end;
	int arr[N];
	srand(time(NULL));//¾àÀë1970ÄêµÄÃëÊı
	for (int i = 0; i < N; ++i) {
		arr[i] = rand() % 10000;
	}
	//arrPrint(arr);
	start = time(NULL);
	//mergeSort(arr, 0, N - 1);
	arrCount(arr);
	end = time(NULL);
	//arrPrint(arr);
	printf("%d\n", end - start);

	system("pause");
	return 0;
}