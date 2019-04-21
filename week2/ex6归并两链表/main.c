#include "listMerge.h"

int main()
{
    pNode phead1, ptail1, phead2, ptail2;
	int *parr1 = (int*)calloc(N1, sizeof(int));
	int *parr2 = (int*)calloc(N2, sizeof(int));
	phead1 = ptail1 = phead2 = ptail2 = NULL;
	srand(time(NULL));
	for (int i = 0; i < N1; ++i) {
		list_sort_insert(&phead1, &ptail1, rand() % 100);
	}
	print(phead1);
	for (int j = 0; j < N2; ++j) {
		list_sort_insert(&phead2, &ptail2, rand() % 100);
	}
	print(phead2);
	listMerge(&phead1, &ptail1, &phead2, &ptail2);
	print(phead1);

	system("pause");
	return 0;
}