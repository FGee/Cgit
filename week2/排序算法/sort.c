#include "sort.h"

void arrPrint(int* arr)
{
	for (int i = 0; i < N; ++i) {
		printf("%5d", arr[i]);
	}
	putchar('\n');
}

void merge(int* ar, int low, int mid, int high)
{//归并
	int temp1[N], temp2[N];
	for (int i = low; i <= mid; ++i) {
		temp1[i] = ar[i];
	}
	for (int j = mid + 1; j <= high; ++j) {
		temp2[j] = ar[j];
	}
	int m = low; int n = mid + 1;
	while (m <= mid && n <= high) {
		if (temp1[m] < temp2[n]) {
			ar[low] = temp1[m];
			++m;
			++low;
		}
		else {
			ar[low] = temp2[n];
			++n;
			++low;
		}
	}
	while (m <= mid) {
		ar[low] = temp1[m];
		++m;
		++low;
	}
	while (n <= high) {
		ar[low] = temp2[n];
		++n;
		++low;
	}
}

void  mergeSort(int* ar, int low, int high)
{//归并排序
	if (low < high) {
		int mid = (low + high) / 2;
		mergeSort(ar, low, mid);
		mergeSort(ar, mid + 1, high);
		merge(ar, low, mid, high);
	}
}

void arrCount(int* arr)
{//基数排序
	int *count = (int*)calloc(R, sizeof(int));// 分类器
	for (int i = 0; i < N; ++i) {
		++count[arr[i]];
	}
	int j = 0;
	for (int m = 0; m < R; ++m) {
		for (int k = 0; k < count[m]; ++k) {
			arr[j] = m;
			++j;
		}
	}
}

